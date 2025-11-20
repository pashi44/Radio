cmake_minimum_required(VERSION 3.20.0)

set(BOARD esp32_devkitc/esp32/procpu)
set(DTC_OVERLAY_FILE boards/espressif/esp32_devkitc/Radio.overlay)

# Ensure Zephyr discovers local modules. This must be set before
# calling find_package(Zephyr) so module metadata (zephyr/module.yaml)
# is read during configure.
    set(ENV{ZEPHYR_EXTRA_MODULES} "$ENV{ZEPHYR_EXTRA_MODULES};${CMAKE_CURRENT_SOURCE_DIR}/drivers/uart")

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(uart_manual_driver)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

target_sources(app  PRIVATE
    src/Radio.cpp
)
