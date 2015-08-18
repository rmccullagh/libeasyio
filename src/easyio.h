/*
 *  Copyright (c) 2015 Ryan McCullagh <me@ryanmccullagh.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __LIBEASY_IO_H
#define __LIBEASY_IO_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#ifdef HAVE_LIBEASY_IO_DEBUG
  #define LIBEASY_IO_DEBUG 1
#else
  #define LIBEASY_IO_DEBUG 0
#endif

#if defined _WIN32 || defined __CYGWIN__
  #define LIBEASY_IO_HELPER_DLL_IMPORT __declspec(dllimport)
  #define LIBEASY_IO_HELPER_DLL_EXPORT __declspec(dllexport)
  #define LIBEASY_IO_HELPER_DLL_LOCAL
#else
  #if __GNUC__ >= 4
    #define LIBEASY_IO_HELPER_DLL_IMPORT __attribute__ ((visibility ("default")))
    #define LIBEASY_IO_HELPER_DLL_EXPORT __attribute__ ((visibility ("default")))
    #define LIBEASY_IO_HELPER_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
  #else
    #define LIBEASY_IO_HELPER_DLL_IMPORT
    #define LIBEASY_IO_HELPER_DLL_EXPORT
    #define LIBEASY_IO_HELPER_DLL_LOCAL
  #endif
#endif

#ifdef BUILDING_LIBEASY_IO
  #define LIBEASY_IO_API LIBEASY_IO_HELPER_DLL_EXPORT
#else
  #define LIBEASY_IO_API LIBEASY_IO_HELPER_DLL_IMPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Try to read a file into a byte array
 *
 * @param path the path to the file
 * @return pointer to an unsigned char, or NULL
 */
extern LIBEASY_IO_API char* file_get_contents(const char* path);

#ifdef __cplusplus
}
#endif

#endif /* __LIBEASY_IO_H */
