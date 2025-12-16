# ConsoleLib

- [About](#about)
- [Project guide](#project-guide)
- [Compilation](#compilation)
- [Testing](#testing)
- [Donate](#donate)

## About

Library for easier working with console/terminal and other stuff as well. I made this out of boredom so implementation might not be ideal as this used to be part of another project, but my other C++ projects might benefit from this library/collection of utility classes.

## Project guide

- .hpp is used when there is no coresponding .cpp file

## Compilation

### Compiled & Tested on

| OS | Compiler |
| :------: | :----------: |
| Ubuntu | g++ 15.2.0 |
| Windows 10 | MSVC 19.50.35719.0 |

### CMake

   ```bash
   git clone https://github.com/Riyufuchi/ConsoleLib.git
   cd ConsoleLib
   
   # CMake for Linux, macOS, MinGW, Ninja (single-config)
   cmake -DCMAKE_BUILD_TYPE=Release -S . -B build
   cmake --build build
   
   # CMake for Visual Studio, Xcode, Ninja Multi-Config
   cmake -S . -B build
   cmake --build build --config Release
   ```

## Testing

### Using makefile

For testing Google Test framework is used

   ```bash
   # Install dependency
   sudo apt install libgtest-dev
   # Then use makefile
   make test
   ```

## Donate

Few dollars will be enough. If you are planning to use this library in a commercial application, then it would be fair if you would send more, possibly a small share of 5-10% of monthly profits.

[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/P5P11WTFL)
