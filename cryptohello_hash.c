// Copyright (c) 2012-2013 The Cryptonote developers
// Copyright (c) 2018 The UlordChain developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

// Modified for CPUminer by Lucas Jones
// Modified for Sumo Easy Miner by Bill Aue (Sumokoin.org) 

#include "miner.h"
#include "compat.h"
#include "cryptohello_hash.h"
#include "PoW.h"

#if defined(__MINGW32__) 
#if defined(__MINGW64__)
#define MINGW_x64 (1) // MINGW 64-bit
#else
#define MINGW_x86 (1) // MINGW 32-bit
#endif
#endif

#if defined(__arm__) || defined(_MSC_VER) || defined(MINGW_x86)
#ifndef NOASM
#define NOASM
#endif
#endif

//#include "crypto/hash-ops.h"

#if USE_INT128
#if __GNUC__ == 4 && __GNUC_MINOR__ >= 4 && __GNUC_MINOR__ < 6
typedef unsigned int uint128_t __attribute__ ((__mode__ (TI)));
#elif defined (_MSC_VER) || defined(MINGW_x86)
#undef  USE_INT128
#define USE_INT128 (0)
#else
typedef __uint128_t uint128_t;
#endif
#endif


#define MEMORY         (1 << 21) /* 2 MiB */
#define ITER           (1 << 20)

// Lite
//#define MEMORY (1 << 20)
//#define ITER   (1 << 19)

#define AES_BLOCK_SIZE  16
#define AES_KEY_SIZE    32 /*16*/
#define INIT_SIZE_BLK   8
//#define INIT_SIZE_BYTE (INIT_SIZE_BLK * AES_BLOCK_SIZE)

void cryptonight_hash(void* output, const void* input, const int inputlen) 
{
   // printf("crypt night  %d %d %d\n",inputlen,output,input); 
    InitpowFunction((uint8_t*)input, 140, (uint8_t *)output);
    
}


