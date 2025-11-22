cmake_minimum_required(VERSION 3.20.0)

set(BOARD esp32_devkitc/esp32/procpu)
set(DTC_OVERLAY_FILE boards/espressif/esp32_devkitc/Radio.overlay)

list(APPEND ZEPHYR_EXTRA_MODULES
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/uartone
    )


find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(uart_manual_driver)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


target_sources(app  PRIVATE
    src/Radio.cpp

)



add_subdirectory(drivers)