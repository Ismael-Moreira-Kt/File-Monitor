#include "logger.h"



void log_error(const char *message) {
    fprintf(stderr, "ERROR: %s\n", message);
}



void log_info(const char *message, size_t length) {
    fprintf(stdout, "INFO: %.*s\n", (int)length, message);
}