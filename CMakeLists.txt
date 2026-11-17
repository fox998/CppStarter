cmake_minimum_required(VERSION 3.20)
project(app LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Automatically symlink compile_commands.json to the workspace root for clangd
if(CMAKE_EXPORT_COMPILE_COMMANDS)
    file(CREATE_LINK "${CMAKE_BINARY_DIR}/compile_commands.json"
                     "${CMAKE_SOURCE_DIR}/compile_commands.json"
                     SYMBOLIC COPY_ON_ERROR)
endif()

add_executable(app src/main.cpp)
target_compile_features(app PRIVATE cxx_std_23)
set_target_properties(app PROPERTIES CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(app PRIVATE -Wall -Wextra -Werror -Wpedantic)
else()
    message(WARNING "Compiler not recognized. Please add appropriate compiler flags for your compiler.")
endif()
