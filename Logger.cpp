//
// Created by Andre Jacques on 2019-02-21.
//

#include "Logger.h"

LogLevel Logger::level = Debug;

void
Logger::logEvent(LogLevel _level, const char * module, const char * message)
{
    char result[6];

    if (_level >= level) {
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
    }

    printf("[%s] %s - %s\r\n", module, result, message);
}

void
Logger::logDebug(const char * module, const char * message, ...)
{
    va_list arg;
    va_start(arg, message);

    char buffer[80];
    vsprintf(buffer, message, arg);

    va_end(arg);

    logEvent(Debug, module, buffer);
}

void
Logger::logInfo(const char * module, const char * message, ...)
{
    va_list arg;
    va_start(arg, message);

    char buffer[80];
    vsprintf(buffer, message, arg);

    va_end(arg);

    logEvent(Info, module, buffer);
}

void
Logger::logWarning(const char * module, const char * message, ...)
{
    va_list arg;
    va_start(arg, message);

    char buffer[80];
    vsprintf(buffer, message, arg);

    va_end(arg);

    logEvent(Warning, module, buffer);
}

void
Logger::logError(const char * module, const char * message, ...)
{
    va_list arg;
    va_start(arg, message);

    char buffer[80];
    vsprintf(buffer, message, arg);

    va_end(arg);

    logEvent(Error, module, buffer);
}
