/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.3. в) Ошибки переполнения буфера (записи или чтения за пределами выделенной для буфера памяти).

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V643. Suspicious pointer arithmetic. Value of 'char' type is added to a string pointer.
Документация: https://pvs-studio.ru/ru/docs/warnings/v643/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v643/
*/

#include <iostream>
#include <string>
#include <algorithm>

std::string escape_ok(std::string v)
{
  size_t i = 0;
  for (;;) {
    i = v.find_first_of("\\\'\"", i);
    if (i == std::string::npos)
      break;
    std::string h = "\\";
    h += v[i];
    v.insert(i, "\\");
    i = i + 2;
  }
  return v;
}