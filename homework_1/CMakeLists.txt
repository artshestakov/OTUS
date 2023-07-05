cmake_minimum_required(VERSION 3.12)

# Переменные, которые можем переопределять при запуске cmake
set(VER_REVISION 1 CACHE INTERNAL "Patch version")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DIS_DEBUG")
string(TIMESTAMP TS_TIME "%H:%M:%S")
string(TIMESTAMP TS_DATE "%d.%m.%Y")

option(IS_UBUNTU "Build for Ubuntu" OFF)
option(IS_WINDOWS "Build for Windows" OFF)

project(homework VERSION ${VER_REVISION})

# Автогенерация файлов
configure_file(version.h.in version.h)

# Исходники, добавляемые в проект
add_executable(homework main.cpp)

target_include_directories(homework
    PRIVATE "${CMAKE_BINARY_DIR}"
)

if(IS_UBUNTU)
    install(TARGETS homework RUNTIME DESTINATION bin)

    set(CPACK_GENERATOR DEB)
    set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
    set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
    set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
    set(CPACK_PACKAGE_CONTACT art.shestakov@icloud.com)
    include(CPack)
endif()
