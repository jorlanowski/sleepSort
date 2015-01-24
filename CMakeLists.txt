cmake_minimum_required( VERSION 2.8 )
project( SleepSort )

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -D_GLIBCXX_USE_NANOSLEEP" ) # _GLIBCXX_USE_NANOSLEEP - workaround for gcc4.7 problems with this_thread::sleep
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" )

include_directories( include )

add_subdirectory( src )
add_subdirectory( test )
