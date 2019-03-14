/**
 *  A simple Logger that can be configured to triggered considering a log level.
 *
 *  @author A. Jacques
 *  @date 2019-02-21
 */

#ifndef LOGGY_LOGGER_H
#define LOGGY_LOGGER_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define LOG_DEBUG_TITLE "DEBUG"
#define LOG_INFO_TITLE "INFO "
#define LOG_WARNING_TITLE "WARN "
#define LOG_ERROR_TITLE "ERROR"

/**
 *  Represents the importance of the loged event. Debug is the lowest.
 */
typedef enum LogLevel
{
    Debug = 0,
    Info,
    Warning,
    Error
} LogLevel;

class Logger {
public:
    /**
     *  The only way to access the class since it is a singleton.
     */
    static Logger &getLogger()
    {
        static Logger logger;

        return logger;
    }

    /**
     *  Log a debug event,
     */
    void logDebug(char const *, ...);

    /**
     *  Log an information event.
     */
    void logInfo(char const *, ...);

    /**
     *  Log a warning event.
     */
    void logWarning(char const *, ...);

    /**
     *  Log an error event.
     */
    void logError(char const *, ...);
private:
    /**
     *  Constructor (private because is a singleton)
     */
    Logger() {};

    /**
     *  Copy constructor (private because is a singleton)
     */
    Logger(Logger const &) {};

    /**
     *  Equal operator (private because is a singleton)
     */
    Logger& operator=(Logger const &) {};

    /**
     *  Log an event
     */
    void logEvent(LogLevel, char const *);
};


#endif //LOGGY_LOGGER_H

