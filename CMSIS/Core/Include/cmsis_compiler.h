/**************************************************************************//**
 * @file     cmsis_compiler.h
 * @brief    CMSIS compiler specific macros, functions, instructions
 * @version  V5.00
 * @date     25. August 2016
 ******************************************************************************/
/*
 * Copyright (c) 2009-2016 ARM Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __CMSIS_COMPILER_H
#define __CMSIS_COMPILER_H

#include <stdint.h>

/*
 * ARM Compiler 4/5
 */
#if   defined ( __CC_ARM )
  #include "cmsis_armcc.h"


/*
 * ARM Compiler 6 (armclang)
 */
#elif defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #include "cmsis_armclang.h"


/*
 * GNU Compiler
 */
#elif defined ( __GNUC__ )
  #include "cmsis_gcc.h"


/*
 * IAR Compiler
 */
#elif defined ( __ICCARM__ )
  #ifndef   __ASM
    #define __ASM                     __asm
  #endif
  #ifndef   __INLINE
    #define __INLINE                  inline
  #endif
  #ifndef   __STATIC_INLINE
    #define __STATIC_INLINE           static inline
  #endif
  #ifndef   __NO_RETURN
    #define __NO_RETURN               __noreturn
  #endif
  #ifndef   __USED
    #warning No compiler specific solution for __USED. __USED is ignored.
    #define __USED
  #endif
  #ifndef   __WEAK
    #define __WEAK                    __weak
  #endif
  #ifndef   __UNALIGNED_UINT32
    __packed struct T_UINT32 { uint32_t v; };
      #define __UNALIGNED_UINT32(x)     (((struct T_UINT32 *)(x))->v)
  #endif
  #ifndef   __ALIGNED
    #warning No compiler specific solution for __ALIGNED. __ALIGNED is ignored.
    #define __ALIGNED(x)
  #endif
  #ifndef   __PACKED
    #define __PACKED                  __packed
  #endif

  #include <cmsis_iar.h>


/*
 * TI ARM Compiler
 */
#elif defined ( __TI_ARM__ )
  #ifndef   __ASM
    #define __ASM                     __asm
  #endif
  #ifndef   __INLINE
    #define __INLINE                  inline
  #endif
  #ifndef   __STATIC_INLINE
    #define __STATIC_INLINE           static inline
  #endif
  #ifndef   __NO_RETURN
    #define __NO_RETURN               __attribute__((noreturn))
  #endif
  #ifndef   __USED
    #define __USED                    __attribute__((used))
  #endif
  #ifndef   __WEAK
    #define __WEAK                    __attribute__((weak))
  #endif
  #ifndef   __UNALIGNED_UINT32
    struct __attribute__((packed)) T_UINT32 { uint32_t v; };
    #define __UNALIGNED_UINT32(x)     (((struct T_UINT32 *)(x))->v)
  #endif
  #ifndef   __ALIGNED
    #define __ALIGNED(x)              __attribute__((aligned(x)))
  #endif
  #ifndef   __PACKED
    #define __PACKED                  __attribute__((packed))
  #endif

  #include <cmsis_ccs.h>


/*
 * TASKING Compiler
 */
#elif defined ( __TASKING__ )
  #ifndef   __ASM
    #define __ASM                     __asm
  #endif
  #ifndef   __INLINE
    #define __INLINE                  inline
  #endif
  #ifndef   __STATIC_INLINE
    #define __STATIC_INLINE           static inline
  #endif
  #ifndef   __NO_RETURN
    #define __NO_RETURN               __attribute__((noreturn))
  #endif
  #ifndef   __USED
    #define __USED                    __attribute__((used))
  #endif
  #ifndef   __WEAK
    #define __WEAK                    __attribute__((weak))
  #endif
  #ifndef   __UNALIGNED_UINT32
    struct __packed__ T_UINT32 { uint32_t v; };
    #define __UNALIGNED_UINT32(x)     (((struct T_UINT32 *)(x))->v)
  #endif
  #ifndef   __ALIGNED
    #define __ALIGNED(x)              __align(x)
  #endif
  #ifndef   __PACKED
    #define __PACKED                  __packed__
  #endif

  /*
   * The CMSIS functions have been implemented as intrinsics in the compiler.
   * Please use "carm -?i" to get an up to date list of all intrinsics,
   * Including the CMSIS ones.
   */


/*
 * COSMIC Compiler
 */
#elif defined ( __CSMC__ )
  #ifndef   __ASM
    #define __ASM                     _asm
  #endif
  #ifndef   __INLINE
    #define __INLINE                  inline
  #endif
  #ifndef   __STATIC_INLINE
    #define __STATIC_INLINE           static inline
  #endif
  #ifndef   __NO_RETURN
    #warning No compiler specific solution for __NO_RETURN. __NO_RETURN is ignored.
    #define __NO_RETURN
  #endif
  #ifndef   __USED
    #warning No compiler specific solution for __USED. __USED is ignored.
    #define __USED
  #endif
  #ifndef   __WEAK
    #warning No compiler specific solution for __WEAK. __WEAK is ignored.
    #define __WEAK
  #endif
  #ifndef   __UNALIGNED_UINT32
    #warning No compiler specific solution for __UNALIGNED_UINT32. __UNALIGNED_UINT32 is ignored.
    #define __UNALIGNED_UINT32(x)     (*x)
  #endif
  #ifndef   __ALIGNED
    #warning No compiler specific solution for __ALIGNED. __ALIGNED is ignored.
    #define __ALIGNED(x)
  #endif
  #ifndef   __PACKED
    #warning No compiler specific solution for __PACKED. __PACKED is ignored.
    #define __PACKED
  #endif

  #include <cmsis_csm.h>


#else
  #error Unknown compiler.
#endif


#endif /* __CMSIS_COMPILER_H */
