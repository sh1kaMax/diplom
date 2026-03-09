/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.3. в) Ошибки переполнения буфера (записи или чтения за пределами выделенной для буфера памяти).

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V645. Function call may lead to buffer overflow. Bounds should not contain size of a buffer, but a number of characters it can hold.
Документация: https://pvs-studio.ru/ru/docs/warnings/v645/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v645/
*/

#include <iostream>
#include <string>
#include <cstring>

#define uprv_strncat1(dst, src, n) strncat(dst, src, n)
char plugin_file1[13] = "";

void uplug_init_ok(const char *name)
{
  plugin_file1[0] = '\0';
  uprv_strncat1(plugin_file1, name, 12);
  uprv_strncat1(plugin_file1, ".txt" , 12 - strlen(plugin_file1));
}