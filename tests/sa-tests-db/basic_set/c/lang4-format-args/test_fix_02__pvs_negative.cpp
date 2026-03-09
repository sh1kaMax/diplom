/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.5. г) Ошибки использования форматной строки.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V618. Dangerous call of 'Foo' function. The passed line may contain format specification. 
Документация: https://pvs-studio.ru/ru/docs/warnings/v618/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v618/
*/

#include <cstddef>
#include <cstdio>
#include <iostream>
#include <string>

void Ok12()
{
  std::string buf;
  std::cin >> buf;

  printf("%s", buf.c_str());
}