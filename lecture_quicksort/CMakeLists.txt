add_task(quicksort_thousand 01_thousand_numbers.cpp quick_sort.h random_int.h)
add_task(quicksort_50_100 02_random_50_100.cpp quick_sort.h random_int.h)
add_task(quicksort_matrix_column 03_matrix_column.cpp quick_sort.h random_int.h)
add_task(quicksort_students_qsort 04_students_qsort.cpp)

add_io_test(quicksort_thousand quicksort_thousand "" "Отсортировано: да")
add_io_test(quicksort_50_100 quicksort_50_100 "" "Отсортировано: да")
add_io_test(quicksort_matrix_column quicksort_matrix_column "" "Первый столбец отсортирован: да")
add_io_test(quicksort_students_qsort quicksort_students_qsort "" "1. Александрова Мария")
