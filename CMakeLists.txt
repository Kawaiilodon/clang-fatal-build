cmake_minimum_required(VERSION 3.20)

project(Test VERSION ${SHORT_VERSION} LANGUAGES CXX)
set(PROJECT_NAME Test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(MODULES_DIR ${PROJECT_SOURCE_DIR}/.)
set(VISUALIZATION_DIR ${MODULES_DIR}/Visualization/src)

add_subdirectory(Visualization)

option (FORCE_COLORED_OUTPUT "Always produce ANSI-colored output (GNU/Clang only)." FALSE)
if (${FORCE_COLORED_OUTPUT})
  add_compile_options (-fcolor-diagnostics)
  add_compile_options (-fno-char8_t)
  add_compile_options (-fdiagnostics-color=always)
endif ()
