zephyr_library()
zephyr_include_directories(include)


if(CONFIG_BINZ_ITWOC)
zephyr_library_sources(Binzitwoc.cpp)
endif()

