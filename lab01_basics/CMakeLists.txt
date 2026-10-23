add_task(lab01_hello 01_hello.cpp)
add_task(lab01_variables 02_variables.cpp)
add_task(lab01_operators 03_operators.cpp)

add_io_test(lab01_hello lab01_hello "" "Вторая строка")
add_io_test(lab01_variables lab01_variables "" "smallNumber = 250")
add_io_test(lab01_operators lab01_operators "" "expression = 395")
