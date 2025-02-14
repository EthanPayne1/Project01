add_library(DriverApp src/logger.c)

target_include_directories(DriverApp PUBLIC 
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include  
)
add_subdirectory(test)
