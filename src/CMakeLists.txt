cmake_minimum_required (VERSION 2.6)
project (tiny)

ADD_DEFINITIONS(-Wall)

set (tiny_VERSION_MAJOR 1)
set (tiny_VERSION_MINOR 0)

#configure_file (
#	"${PROJECT_SOURCE_DIR}/lotConfig.h.in"
#	"${PROJECT_SOURCE_DIR}/lotConfig.h"
#)

include_directories("${PROJECT_BINARY_DIR}")

ADD_LIBRARY(depend dsQueue dsQueue.cpp dsQueue.h
FileHandler FileHandler.cpp FileHandler.h
Node Node.h
TagParser TagParser.cpp TagParser.h
TinyStoryEngine TinyStoryEngine.cpp TinyStoryEngine.h
Tokenizer Tokenizer.cpp Tokenizer.h
)

add_executable(
tiny main.cpp
)

target_link_libraries(tiny depend)

