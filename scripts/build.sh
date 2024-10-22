#!/bin/bash

# Set the build directory
BUILD_DIR="build"

# Create the build directory if it doesn't exist
mkdir -p $BUILD_DIR

# Change to the build directory
cd $BUILD_DIR

# Run CMake
cmake ..

# Build the project
cmake --build .

# Return to the original directory
cd ..