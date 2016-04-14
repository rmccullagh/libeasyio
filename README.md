# libeasyio

One function to read a regular file into a char array.

```c
/**
 * @brief Try to read a file into a byte array
 *
 * @param path the path to the file
 * @return pointer to an unsigned char, or NULL
 */
extern LIBEASY_IO_API char* easy_io_get_contents(const char* path);
```
