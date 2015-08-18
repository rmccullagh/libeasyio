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

