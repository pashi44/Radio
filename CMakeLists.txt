cmake_minimum_required(VERSION 3.20.0)

set(BOARD esp32_devkitc/esp32/procpu)
set(DTC_OVERLAY_FILE boards/xtensa/esp32_devkit/Radio_esp32.overlay)


# list(APPEND $ENV{ZEPHYR_EXTRA_MODULES}
# #  ${CMAKE_CURRENT_SOURCE_DIR}/interrupt
# #   ${CMAKE_CURRENT_SOURCE_DIR}/threads


# )


find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(${CMAKE_PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)




target_sources(app PRIVATE
src/Radio.cpp
)


board_runner_args(espressif "--flash-freq=80m")



# add_executable()