zephyr_library()
# Header-only: add this directory to the include path so `uart.hpp` can be used
zephyr_library_include_directories(include)

zephyr_library_sources_ifdef(CONFIG_MAN_DRIVER_UART 

${CMAKE_CURRENT_SOURCE_DIR}/uart.cpp)