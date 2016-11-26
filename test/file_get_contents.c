/*
 * Copyright (c) 2016 Ryan McCullagh <me@ryanmccullagh.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <easyio.h>

#include "test_common.h"

void test_file_get_contents(void)
{
	const char* expected_contents = "Ryan McCullagh\n";
	const char* path = "test.txt";

	char* buffer = file_get_contents(path);

	expect(str_equal(buffer, expected_contents));

	expect(buffer[15] == '\0');
	
	free(buffer);

}

int main(void)
{

	test_file_get_contents();

	return 0;
}

