cmake_minimum_required(VERSION 3.12)

# Переменные, которые можем переопределять при запуске cmake
set(PROJECT_VERSION "1" CACHE INTERNAL "Patch version")

project(homework1 VERSION ${PROJECT_VERSION})

# Автогенерация файлов
configure_file(version.h.in version.h)

# Исходники, добавляемые в проект
add_executable(homework1 main.cpp)

target_include_directories(homework1
    PRIVATE "${CMAKE_BINARY_DIR}"
)
