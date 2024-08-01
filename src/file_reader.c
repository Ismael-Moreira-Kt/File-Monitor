#include "file_reader.h"



ssize_t read_from_file(int fd, void *buf, size_t count) {
    ssize_t bytes_read = read_syscall(fd, buf, count);
    
    if (bytes_read < 0) {
        return -errno;
    }
    
    return bytes_read;
}