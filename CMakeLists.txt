cmake_minimum_required(VERSION 3.16)
project(cpp_labs LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Если тип сборки не указан, собираем релиз (та самая релизная сборка из лабы 2).
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Тип сборки" FORCE)
endif()

# Все программы складываются в build/bin, так их проще искать и запускать.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(MSVC)
    # /utf-8 нужен, чтобы русские строки из исходников попали в exe как UTF-8.
    add_compile_options(/utf-8 /W4)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

enable_testing()

add_subdirectory(common)

# Одна программа = один исполняемый файл. Ко всем подключаем console.h.
function(add_task name)
    add_executable(${name} ${ARGN})
    target_link_libraries(${name} PRIVATE console)
endfunction()

# Тест: запускаем программу, подаём ей ввод (строки разделены символом |)
# и проверяем, что в выводе есть ожидаемый текст.
function(add_io_test name target input expected)
    add_test(NAME ${name}
        COMMAND ${CMAKE_COMMAND}
            "-DPROGRAM=$<TARGET_FILE:${target}>"
            "-DINPUT=${input}"
            "-DEXPECTED=${expected}"
            "-DNAME=${name}"
            -P ${PROJECT_SOURCE_DIR}/cmake/RunWithInput.cmake)
endfunction()

add_subdirectory(lab01_basics)
add_subdirectory(lab02_control_flow)
add_subdirectory(lab03_pointers)
add_subdirectory(lab04_classes)
add_subdirectory(lab05_inheritance)
add_subdirectory(lab06_exceptions)
add_subdirectory(lab07_stdlib)
add_subdirectory(lecture_recursion)
add_subdirectory(lecture_quicksort)
