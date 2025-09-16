

if(CONFIG_RADIO_THREADS)
  target_sources(app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/ThreadOne.cpp
  )
endif()

target_include_directories(app PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)
