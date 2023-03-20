cmake_minimum_required (VERSION 3.8)

file(GLOB vultiveSRC
     "include/*.h"
     "src/*.cpp"
)

add_library(
    vultive
    ${vultiveSRC}
)

set_property(TARGET vultive PROPERTY CXX_STANDARD 17)
set_property(TARGET vultive PROPERTY CXX_STANDARD_REQUIRED ON)

target_include_directories(vultive PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")