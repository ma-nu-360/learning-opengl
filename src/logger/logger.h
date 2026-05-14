#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

enum ELogLevel {
    LOG_LEVEL_INFO,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_WARNING
};

void consoleLog(     const char* context, const char* message, enum ELogLevel logLevel);

void consoleInfo(    const char* context, const char* message);

void consoleWarning( const char* context, const char* message);

void consoleError(   const char* context, const char* message);

#endif