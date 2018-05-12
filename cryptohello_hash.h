#ifndef CRYPTOHELLO_H
#define CRYPTOHELLO_H

#include <stdbool.h>
#include <stdint.h>

void cryptohello_hash(void* output, const void* input, const int inputlen);

void bestcpu_feature(char *outbuf, int maxsz);
float cpu_temp(int core);

#endif /* CRYPTOHELLO_H */
