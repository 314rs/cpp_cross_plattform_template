# C++ cross-plattform template

<!-- make shure to adjust all the links! -->
[![CMake and CTest](https://github.com/314rs/cpp_cross_plattform_template/actions/workflows/cmake.yml/badge.svg?branch=main)](https://github.com/314rs/cpp_cross_plattform_template/actions/workflows/cmake.yml)
<!-- todo codecov (coveralls, coverty) -->
<!-- todo codeql -->
<!-- todo doxygen tag -->
[![GitHub License](https://img.shields.io/github/license/314rs/cpp_cross_plattform_template)](LICENSE.txt)
<!-- todo release tag -->

some boilerplate for my C++ projects.

with:

- cmake
- conan
- doxygen
- github actions
<!-- delete/change above in actual project -->

## Download

Download the program for your platform from the latest [build action](https://github.com/314rs/cpp_cross_plattform_template/actions/workflows/cmake.yml).

## Build yourself

### Dependencies

- CMake
- Conan
  - boost (program_options)
  - gtest

### Build

```sh
conan install conanfile.txt --build=missing
cmake -DCMAKE_TOOLCHAIN_FILE=./build/generators/conan_toolchain.cmake -S. -B./build -G "YourGeneratorHere"
cmake --build build
```
<!-- TODO is this correct? check manual build commands. -->

### Testing

```sh
cd build
ctest
```

## Doxygen

Doxygen documentation can be found [here](https://314rs.github.io/cpp_cross_plattform_template/).
<!-- acually it cannot at the moment. gh-pages are not allowed for private repos -->

## Wiki

For further information check out the [wiki](https://github.com/314rs/cpp_cross_plattform_template/wiki).

## License

This software is open source and released under the [MIT License](LICENSE.txt).
