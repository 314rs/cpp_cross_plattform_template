# C++ cross-plattform template

<!-- make shure to adjust all the links! -->
[![CMake and CTest](https://github.com/314rs/cpp_cross_plattform_template/actions/workflows/cmake.yml/badge.svg?branch=main)](https://github.com/314rs/cpp_cross_plattform_template/actions/workflows/cmake.yml)
[![CodeQL](https://github.com/314rs/cpp_cross_plattform_template/actions/workflows/codeql.yml/badge.svg?branch=main)](https://github.com/314rs/cpp_cross_plattform_template/actions/workflows/codeql.yml)
![Codecov](https://img.shields.io/codecov/c/gh/314rs/cpp_cross_plattform_template?logo=codecov)
![Coveralls](https://img.shields.io/coverallsCoverage/github/314rs/cpp_cross_plattform_template?logo=coveralls)
[![doxygen](https://img.shields.io/badge/-doxygen?logo=doxygen&logoSize=auto&color=2c4aa8)](https://314rs.github.io/cpp_cross_plattform_template/)
[![GitHub License](https://img.shields.io/github/license/314rs/cpp_cross_plattform_template)](LICENSE.txt)
![GitHub Tag](https://img.shields.io/github/v/tag/314rs/cpp_cross_plattform_template?logo=github)

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

Or build it yourself:

```sh
git clone https://github.com/jothepro/doxygen-awesome-css.git docs/doxygen-awesome-css
echo "PROJECT_NUMBER = $(git describe --tags --always --dirty=-dev)" > docs/PROJECT_NUMBER   # always before calling doxygen
doxygen
```

## Wiki

For further information check out the [wiki](https://github.com/314rs/cpp_cross_plattform_template/wiki).

## License

This software is open source and released under the [MIT License](LICENSE.txt).
