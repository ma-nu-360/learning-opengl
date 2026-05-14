#include "logger.h"

void consoleLog(     const char *context, const char *message, enum ELogLevel level) {
    const char* logLevel = 
        level == LOG_LEVEL_ERROR   ? "ERROR"   :
        level == LOG_LEVEL_WARNING ? "WARNING" : "INFO";
    printf("[%s] %s: %s", context, logLevel, message);
}

void consoleInfo(    const char *context, const char *message) {
    consoleLog(context, message, LOG_LEVEL_INFO);
}

void consoleWarning( const char *context, const char *message) {
    consoleLog(context, message, LOG_LEVEL_WARNING);
}

void consoleError(   const char *context, const char *message) {
    consoleLog(context, message, LOG_LEVEL_ERROR);
}
