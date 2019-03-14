//
// Created by Andre Jacques on 2019-02-21.
//

#include "Logger.h"

void
Logger::logEvent(LogLevel level, const char * message)
{
    char result[6];

    switch(level)
    {
    case Debug:
    {
        strcpy(result, LOG_DEBUG_TITLE);
        break;
    }

    case Info:
    {
        strcpy(result, LOG_INFO_TITLE);
        break;
    }

    case Warning:
    {
        strcpy(result, LOG_WARNING_TITLE);
        break;
    }

    case Error:
    {
        strcpy(result, LOG_ERROR_TITLE);
        break;
    }
    }

    printf("[%s] %s\r\n", result, message);
}

void
Logger::logDebug(const char * message, ...)
{
    va_list arg;
    va_start(arg, message);

    char buffer[80];
    vsprintf(buffer, message, arg);

    va_end(arg);

    logEvent(LogLevel::Debug, buffer);
}

void
Logger::logInfo(const char * message, ...)
{
    va_list arg;
    va_start(arg, message);

    char buffer[80];
    vsprintf(buffer, message, arg);

    va_end(arg);

    logEvent(LogLevel::Info, buffer);
}

void
Logger::logWarning(const char * message, ...)
{
    va_list arg;
    va_start(arg, message);

    char buffer[80];
    vsprintf(buffer, message, arg);

    va_end(arg);

    logEvent(LogLevel::Warning, buffer);
}

void
Logger::logError(const char * message, ...)
{
    va_list arg;
    va_start(arg, message);

    char buffer[80];
    vsprintf(buffer, message, arg);

    va_end(arg);

    logEvent(LogLevel::Error, buffer);
}
