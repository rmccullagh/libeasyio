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

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <easyio.h>

#define REQUIRED(p) do { \
	if(!p) { \
		return NULL; \
	} \
} while(0)


#ifdef __cplusplus
extern "C" {
#endif

static inline void debug_log(const char* s)
{
	#if LIBEASY_IO_DEBUG
		fprintf(stderr, "%s:%d:%s: %s\n",
			__FILE__, __LINE__, __func__, s);
	#endif
}

/**
 * file_get_contents:
 * @path: the path to use to open the file
 *
 * Attempts to read the full contents of file located
 * at @path into a null terminated buffer. The file is only
 * read if it is a regular file.
 *
 * Returns: a pointer to the start of the buffer, or NULL
 */
LIBEASY_IO_API char* file_get_contents(const char* path)
{
	REQUIRED(path);
	
	struct stat buffer;
	int 	    status;
	char* content;
	FILE*	    fp;
	size_t      bytes_read;

	status = stat(path, &buffer);

	if(status == -1) {
		debug_log("cannot stat file");
		return NULL;
	}

	if(!S_ISREG(buffer.st_mode)) {
		debug_log("not a regular file");
		return NULL;
	}

	content = malloc(buffer.st_size + 1);
	
	if(!content) {
		debug_log("malloc failed");
		return NULL;
	}

	fp = fopen(path, "rb");

	if(!fp) {
		debug_log("cannot open file");
		return NULL;
	}
	
	bytes_read = fread(content, buffer.st_size, 1, fp);

	fclose(fp);

	content[buffer.st_size] = '\0';

	return content;
}	

#ifdef __cplusplus
}
#endif
