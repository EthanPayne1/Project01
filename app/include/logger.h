#ifndef LOGGER_H_
#define LOGGER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>

typedef struct {
  char *app_name;
  FILE *fd;
  char *log_file;
  int log_opts;
} LoggerConfig;

// Warning: Might cause ODR violations
LoggerConfig init_logger(char *app_name, char *log_file, int log_opts) {
  LoggerConfig logger_config = {
    .app_name = app_name,
    .fd = NULL,
    .log_file = log_file == NULL ? (char*) "/dev/stderr" : log_file
  };
  return logger_config;
}

void log(LoggerConfig config, char *message, ...) {
  va_list args;
  va_start(args, message);

  config.fd = fopen(config.log_file, "w");
  time_t seconds; // What is the exact format?
  seconds = time(NULL);

  fprintf(config.fd, "[%s] ", config.app_name);
  vfprintf(config.fd, message, args);
  fprintf(config.fd, "\n");
  va_end(args);

  fclose(config.fd);
}

#ifdef __cplusplus
}
#endif

#endif
