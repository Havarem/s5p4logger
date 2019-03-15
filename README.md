# Session 5 Project Team 4 Logger Library

This project implement a simple logger that can be used in embedded system to
give logging capabilities based on different level of messaging.

## Concept

Logger is a singleton, meaning that it can be only one instance at any time of
itself.

## Initialisation

The `Logger` class expose a static attribut called `level` that you can set to
any `LogLevel` you want to print out. It will filter all level under the one
set.

*NOTE*: It is not a good idea to change that value at runtime after the
initialisation phase, meaning that changing it during an operation will have
an impact eventually on other module.

	int
	main()
	{
		// Initialisation phase
		// Will only print out Warning and Error events
		Logger::level = LogLevel::Warning
		// Application loop
		while(1)
		{
			...
		}
	}

## Usage

At any point in your code where you want to log an event, you need to specify
the module in which the event is occuring and a message explaining the situation.

    Logger.getLogger().logError("Module name", "Message");

It will work the same way for `logWarning`, `logInfo` and `logDebug`.

Furthermore, you can also those methods the same way to use `printf`, like so:

	Logger.getLogger().logError("Module name", "There is %d memory left.", varMem);

*NOTE*: Be aware that the message print out should be only 80 characters long. This
represents the default terminal output (80x25). You should make sure your message
never exceeds that limit and should log twice for longer message.
