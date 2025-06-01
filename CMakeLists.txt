cmake_minimum_required(VERSION 3.10)
project(ransac_line C)

# Output compiled files to 'build' folder
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add warnings
add_compile_options(-Wall -Winline)

# Add src directory
include_directories(src)

# Create the static library
add_library(ransac_line STATIC src/ransac_line.c)

# Add tests
enable_testing()
add_subdirectory(tests)