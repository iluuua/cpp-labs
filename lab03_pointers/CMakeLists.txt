add_task(lab03_pointers 01_pointers.cpp)
add_task(lab03_function_pointers 02_function_pointers.cpp)

add_io_test(lab03_pointers lab03_pointers "" "five после *fixed = 55: 55")
add_io_test(lab03_function_pointers lab03_function_pointers "" "10 - 3 = 7")
