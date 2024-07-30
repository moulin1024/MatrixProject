cmake_minimum_required(VERSION 3.10)

# Set the project name
project(MatrixProject)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add the source files
set(SOURCES
    src/SparseMatrix.cpp
    src/DenseMatrix.cpp
    main.cpp
)

# Add the executable
add_executable(MatrixProject ${SOURCES})
