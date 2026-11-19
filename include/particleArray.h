#ifndef PARTICLEARRAY_H
#define PARTICLEARRAY_H

#include "particle.h"
#include <stddef.h>

typedef struct ParticleArr {
    struct Particle *data;
    size_t particles;
    size_t reserved;
} ParticleArr_t;

ParticleArr_t ParticleArr_new(const size_t reserve);
int ParticleArr_pushBack(ParticleArr_t *arr, const struct Particle particle);
int ParticleArr_popBack(ParticleArr_t *arr);
int ParticleArr_insertUnordered(ParticleArr_t *arr, const size_t i, struct Particle particle);
int ParticleArr_removeUnordered(ParticleArr_t *arr, const size_t i);
int ParticleArr_pushArr(ParticleArr_t *dest_arr, const ParticleArr_t *src_arr);

#endif
