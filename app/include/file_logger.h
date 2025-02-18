#ifndef FILE_LOGGER_H
#define FILE_LOGGER_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum FileLogLevel {
  FILE_LOG_LEVEL_ERROR,
  FILE_LOG_LEVEL_WARN,
  FILE_LOG_LEVEL_INFO,
  FILE_LOG_LEVEL_FINE,
  FILE_LOG_LEVEL_DEBUG
} FileLogLevel;

void file_logger_set_level(FileLogLevel level);

FileLogLevel file_logger_get_level(void);

bool file_logger_is_enabled(FileLogLevel level);

void file_logger_log(FileLogLevel level, const char* file, int32_t line, const char* format, ..)  __attribute__((format(printf, 4, 5)));

#define LOG_ERROR(/*format, */...) file_logger_log(FILE_LOG_LEVEL_ERROR, __FILE__, __LINE__, __VA_ARGS__);

#ifdef __cplusplus
}
#endif
#endif
