# C++ Sort

This repository contains implementations of various sorting strategies in C++.

## Table of Contents

1. [Setup](#setup)
2. [Sorting Strategies](#sorting-strategies)

## Setup

To set up this project locally, follow these steps:

1. Ensure you have CMake (version 3.29 or higher) and a C++20 compatible compiler installed.

### Build

To build the project, you can use the provided build script:

```bash
./scripts/build.sh
```

This script will create a `build` directory, run CMake, and build the project.

### Testing

To run the tests, use the provided test script:

```bash
./scripts/run_tests.sh
```

This script will build the project and run all tests using CTest.

## Sorting Strategies

> [!NOTE]  
> Each caching strategy is implemented as a separate class that inherits from a common [`Sort`](./src/sort.hpp) interface, allowing for easy interchangeability and extension.
