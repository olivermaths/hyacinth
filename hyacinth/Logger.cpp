#include "headers/logger.h"

HCT_Bool initialize_logging() {
  FILE *file = fopen("log/logs.txt", "a");
  if (file == NULL) {
    fclose(file);
    return HCT_FALSE;
  } else {
    fclose(file);
    return HCT_TRUE;
  }
};

void write_log(const char *priority_message, const char *message) {
  FILE *file = fopen("log/logs.txt", "r+");
  fseek(file, 0, SEEK_END);
  fprintf(file, "%s %s\n", priority_message, message);
  fclose(file);
}

void log_output(LogPriority priority, const char *message, ...) {

  const char *priority_message[6] = {
      "[TRACE]:", "[DEBUG]:", "[INFO]:", "[WARN]:", "[ERROR]:", "[FATAL]:"};
  const char *text_highlith[6] = {"\x1b[36m", "\x1b[34m", "\x1b[32m",
                                  "\x1b[33m", "\x1b[31m", "\x1b[41m"};
  char out_message[1000];
  va_list args;
  va_start(args, message);
  vsnprintf(out_message, sizeof(out_message), message, args);
  va_end(args);
  printf("%s%s\x1b[0m ", text_highlith[priority], priority_message[priority]);
  printf("%s\n", out_message);
  write_log(priority_message[priority], out_message);
}

