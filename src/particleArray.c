#include "../include/particleArray.h"
#include "../include/particle.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
static inline void *safe_malloc(size_t amount, size_t data_unit_size) {
    if (data_unit_size == 0 || amount == 0) {
        return NULL;
    }
    if (amount > SIZE_MAX / data_unit_size) {
        return NULL;
    }
    return malloc(amount * data_unit_size);
}
static inline void *safe_realloc(void *data, size_t amount, size_t data_unit_size) {
    if (data_unit_size == 0 || amount == 0) {
        return NULL;
    }
    if (amount > SIZE_MAX / data_unit_size) {
        return NULL;
    }
    return realloc(data, amount * data_unit_size);
}
ParticleArr_t ParticleArr_new(const size_t reserve) {
    ParticleArr_t arr = (ParticleArr_t){.data = NULL, .particles = 0};
    arr.data = safe_malloc(reserve, sizeof(struct Particle));
    if (!arr.data) {
        fprintf(stderr,
                "[ERROR] ParticleArr_new: Failed to create particle array\n");
        exit(EXIT_FAILURE);
    }
    arr.reserved = reserve;
    return arr;
}
int ParticleArr_pushBack(ParticleArr_t *arr, const struct Particle particle) {
    if (!arr || !arr->data) {
        return -1;
    }
    if (arr->particles >= arr->reserved) {
        arr->reserved *= 2;
        struct Particle *tmp = safe_realloc((void *)arr->data, arr->reserved, sizeof(struct Particle));
        if (!tmp) {
            return -1;
        } else {
            arr->data = tmp;
        }
    }
    arr->data[arr->particles++] = particle;
    return 0;
}
int ParticleArr_popBack(ParticleArr_t *arr) {
    if (!arr || !arr->data) {
        return -1;
    }
    if (arr->particles <= arr->reserved / 2) {
        if (arr->reserved > 1) {
            arr->reserved /= 2;
            struct Particle *tmp =
                safe_realloc(arr->data, arr->reserved, sizeof(struct Particle));
            if (!tmp) {
                return -1;
            } else {
                arr->data = tmp;
            }
        }
    }
    if (arr->particles > 0) {
        arr->particles--;
    }
    return 0;
}
int ParticleArr_insertUnordered(ParticleArr_t *arr, const size_t i, const struct Particle particle) {
    if (!arr || !arr->data || i >= arr->particles) {
        fprintf(stderr, "[ERROR] ParticleArr_insertUnordered: Acess out of bounds");
        exit(EXIT_FAILURE);
    }
    if (ParticleArr_pushBack(arr, arr->data[i]) != 0) {
        return -1;
    }
    arr->data[i] = particle;
    return 0;
}
int ParticleArr_removeUnordered(ParticleArr_t *arr, const size_t i) {
    if (!arr || !arr->data || i >= arr->particles) {
        fprintf(stderr, "[ERROR] ParticleArr_removeUnordered: Access out of bounds\n");
        exit(EXIT_FAILURE);
    }
    arr->data[i] = arr->data[arr->particles - 1];
    return ParticleArr_popBack(arr);
}
int ParticleArr_pushArr(ParticleArr_t *dest_arr,const ParticleArr_t *src_arr){
    for(size_t i = 0; i<src_arr->particles;i++){
        if(ParticleArr_pushBack(dest_arr, src_arr->data[i])!=0){
            return -1;
        }
    }
    return 0;
}
