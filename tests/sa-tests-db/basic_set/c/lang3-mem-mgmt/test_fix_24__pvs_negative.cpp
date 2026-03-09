/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.5. в) ошибки управления динамической памятью (выделения, освобождения, использования освобожденной памяти).

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V772. Calling a 'delete' operator for a void pointer will cause undefined behavior.
Документация: https://pvs-studio.ru/ru/docs/warnings/v772/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v772/
*/

#include <iostream>

struct Example2
{
  Example2() { std::cout << "Example" << std::endl; }
  ~Example2() { std::cout << "~Example" << std::endl; }
};

void Ok10()
{
  auto *ptr = new Example2;
  std::cout << ptr << std::endl;
  delete ptr;
}