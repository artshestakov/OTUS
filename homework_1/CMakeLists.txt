cmake_minimum_required(VERSION 3.12)

# Переменные, которые можем переопределять при запуске cmake
set(PROJECT_VERSION "1" CACHE INTERNAL "Patch version")

project(my_binary VERSION ${PROJECT_VERSION})

# Автогенерация файлов
configure_file(version.h.in version.h)

# Исходники, добавляемые в проект
add_executable(my_binary main.cpp)
