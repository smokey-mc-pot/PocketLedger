# PocketLedger

A command-line personal finance tracker built with C++23.
Track income and expenses, review spending by category, and keep your records in local CSV files.

## Features

- Income and expense tracking with categories and notes
- Balance and category reports
- CSV import and export
- Interactive command-line interface

## Build and test

The project is being set up with CMake, GoogleTest, and CTest. Once the build configuration is available:

```sh
cmake -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build build
ctest --test-dir build --output-on-failure
```

Requires a C++23-capable compiler and CMake. GoogleTest will be fetched during configuration.

## Project layout

| Directory | Contents |
| --- | --- |
| `include/` | Public headers |
| `src/` | Implementation and CLI |
| `tests/` | Unit tests |
