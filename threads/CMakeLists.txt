# threads/CMakeLists.txt

zephyr_library()

if(CONFIG_RADIO_THREADS)
  zephyr_library_sources(ThreadOne.cpp)
endif()

zephyr_include_directories(include)
