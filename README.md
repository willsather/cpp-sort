# C++ Sort

This repository contains implementations of various sorting strategies in C++.

## Table of Contents

1. [Setup](#setup)
    - [Build](#build)
    - [Testing](#testing)

2. [Sorting Strategies](#sorting-strategies)
    - [Bubble Sort](#bubble-sort)
    - [Quick Sort](#quick-sort)
    - [Merge Sort](#merge-sort)

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
> Each sorting strategy is implemented as a separate class that inherits from a common [`Sort`](./src/sort.hpp)
> interface, allowing for easy interchangeability and extension.

### Bubble Sort

Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps
them if they are in the wrong order. The pass through the list is repeated until the list is sorted.

### Quick Sort

Quick Sort is a divide-and-conquer algorithm that works by selecting a 'pivot' element from the array and partitioning
the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. The
sub-arrays are then sorted recursively.

### Merge Sort

Merge Sort is also a divide-and-conquer algorithm. It divides the input array into two halves, recursively sorts them,
and then merges the two sorted halves.


