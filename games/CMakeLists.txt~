include_directories(${Boost_INCLUDE_DIRS})

include_directories(${CMAKE_CURRENT_BINARY_DIR})
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h @ONLY)

add_executable(templight
  main.cc
)

target_link_libraries(templight
  game0
  ${Boost_LIBRARIES}
)

install(
  TARGETS templight
  RUNTIME DESTINATION games
)
