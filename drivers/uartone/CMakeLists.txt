

zephyr_library()

zephyr_library_include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)




if(CONFIG_RADIO_UART_INSTANCE)
zephyr_library_sources(uartone.cpp)
endif()




