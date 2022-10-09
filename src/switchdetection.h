/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2022 The Stockfish developers (see AUTHORS file)

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SWITCHDETECTION_H_INCLUDED
#define SWITCHDETECTION_H_INCLUDED

#ifdef DETECT_SWITCHES

#if defined(__LP64__) || defined(_WIN64)
#  define IS_64BIT 1
#endif

#if !defined(__SSE__) && !defined(__AVX__) && _M_IX86_FP < 1 && !defined(__ppc64__)
#  define NO_PREFETCH 1
#endif

#if defined(__POPCNT__) || defined(__AVX__) || defined(__ARM_NEON) || defined(__ppc64__)
#  define USE_POPCNT 1
#endif

#if defined(__AVX2__)
#  define USE_AVX2 1
#endif

#if defined(__AVXVNNI__)
#  define USE_AVXVNNI 1
#  define USE_VNNI 1
#elif defined(__AVX512VNNI__)
#  define USE_VNNI 1
#endif

#if defined(__AVX512BW__)
#  define USE_AVX512 1
#endif

#if defined(__SSE4_1__) || defined(__AVX__)
#  define USE_SSE41 1
#endif

#if defined(__SSSE3__) || defined(__AVX__)
#  define USE_SSSE3 1
#endif

#if defined(__SSE2__) || defined(__AVX__) || _M_IX86_FP >= 2
#  define USE_SSE2 1
#endif

#if defined(__MMX__) || defined(__AVX__) || _M_IX86_FP >= 1
#  define USE_MMX 1
#endif

#if defined(__ARM_NEON)
#  define USE_NEON __ARM_ARCH
#endif

#if defined(__BMI2__)
#  define USE_PEXT 1
#endif

#endif

#endif // #ifndef SWITCHDETECTION_H_INCLUDED
