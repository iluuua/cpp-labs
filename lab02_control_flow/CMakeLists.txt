add_task(lab02_conditions 01_conditions.cpp)
add_task(lab02_loops 02_loops_and_arrays.cpp)
add_task(lab02_functions 03_functions_and_references.cpp)
add_task(lab02_modules
    04_modules/main.cpp
    04_modules/previous_sum.cpp
    04_modules/previous_sum.h)

add_io_test(lab02_conditions_multiply lab02_conditions "8|4|*" "8 * 4 = 32")
add_io_test(lab02_conditions_zero lab02_conditions "8|0|/" "На ноль делить нельзя")
add_io_test(lab02_loops lab02_loops "-3|abc|4" "1 + 2 + 3 + 4 = 10")
add_io_test(lab02_functions lab02_functions "" "sumUpTo() = 1")
add_io_test(lab02_modules lab02_modules "" "3 + 10 = 13")
