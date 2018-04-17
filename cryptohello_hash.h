#ifndef CRYPTONIGHT_H
#define CRYPTONIGHT_H

#include <stdbool.h>
#include <stdint.h>

void cryptonight_hash(void* output, const void* input, const int inputlen);

void bestcpu_feature(char *outbuf, int maxsz);
float cpu_temp(int core);

#endif /* CRYPTONIGHT_H */
