add_executable(${PROJECT_NAME} app/main.c)

target_include_directories(${PROJECT_NAME} PRIVATE 
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1
)
target_link_libraries(${PROJECT_NAME} PRIAVTE DriverApp)
