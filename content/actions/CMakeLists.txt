add_library(actions
  rest.cpp
  move.cpp
  close_door.cpp
  open_door.cpp
  wander.cpp
  attack.cpp
  )

target_include_directories(actions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(actions PUBLIC engine events)
