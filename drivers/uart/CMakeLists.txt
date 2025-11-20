# This declares a Zephyr library for your UART driver
zephyr_library()

# Only compile the optional C++ source if the driver instance is enabled
zephyr_library_sources_ifdef(CONFIG_RADIO_UART_INSTANCE uart.cpp)

# Export the headers under "include/" to consumers of this library
zephyr_library_include_directories(include)
