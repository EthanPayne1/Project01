cmake_minimal_required(VERSION 3.17)
set(PROJECT_NAME Driver_Project)

project(
  ${PROJECT_NAME}
  LANGUAGES CXX 
)

include(FetchContent)
FetchContent_Declare(
  appLib
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/app
)
FetchContent_MakeAvailable(appLib)

add_subdirectory(src)

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")


