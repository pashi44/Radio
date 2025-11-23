

zephyr_library()

zephyr_include_directories(include)




if(CONFIG_RADIO_UART_INSTANCE)
zephyr_library_sources(uartone.cpp)
endif()




