cmake_minimum_required(VERSION 3.10)

# Set the project name
project(MatrixSolver)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files
add_executable(MatrixSolver
    src/main.cpp
    src/matrix/DenseMatrix.cpp
    src/matrix/SparseMatrix.cpp
    src/matrix/Operation.cpp
    src/solvers/RedBlackGaussSeidelSolver.cpp
    src/solvers/GaussSeidelSolver.cpp
    src/solvers/SolverFactory.cpp
)

# Include directories
target_include_directories(MatrixSolver PRIVATE 
    ${PROJECT_SOURCE_DIR}/src/matrix
    ${PROJECT_SOURCE_DIR}/src/solvers
)
