

zephyr_library()
zephyr_include_directories(./include)

zephyr_library_sources_ifdef(
    CONFIG_RADIO_CUSTOM_ITWOC 
    CustomItwoc.cpp)
