cmake_minimum_required(VERSION 3.20.0)

set(BOARD esp32_devkitc/esp32/procpu)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(radio_app)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)




target_sources(app PRIVATE
src/Radio.cpp
)

add_subdirectory(threads )
# add_executable()
