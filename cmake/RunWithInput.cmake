# Запускает PROGRAM, подаёт на вход INPUT (строки разделены символом |)
# и проверяет, что в выводе встречается EXPECTED.
string(REPLACE "|" "\n" input_text "${INPUT}")
set(input_file "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.input.txt")
file(WRITE "${input_file}" "${input_text}\n")

execute_process(
    COMMAND "${PROGRAM}"
    INPUT_FILE "${input_file}"
    OUTPUT_VARIABLE output
    ERROR_VARIABLE errors
    RESULT_VARIABLE exit_code)

if(NOT exit_code EQUAL 0)
    message(FATAL_ERROR "Программа завершилась с кодом ${exit_code}\n${output}\n${errors}")
endif()

string(FIND "${output}" "${EXPECTED}" position)
if(position EQUAL -1)
    message(FATAL_ERROR "В выводе нет «${EXPECTED}». Вот что программа напечатала:\n${output}")
endif()
