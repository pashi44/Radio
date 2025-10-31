zephyr_library()


if(CONFIG_RADIO_INTERRUPTS)
    zephyr_library_sources(Interrupt.cpp)
endif()
zephyr_include_directories(include)

