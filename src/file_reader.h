#ifndef FILE_READER_H
#define FILE_READER_H



#include "_include.h"



ssize_t read_syscall(int fd, void *buf, size_t count);
ssize_t read_from_file(int fd, void *buf, size_t count);



#endif