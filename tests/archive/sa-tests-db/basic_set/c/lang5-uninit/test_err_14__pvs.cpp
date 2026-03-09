/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
 6.5. д) Ошибки использования неинициализированных переменных.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
  6.7. б) 4) данные передаются через одну или несколько функций.

Детектор PVS-Studio:  V679. The 'X' variable was not initialized. 
                      This variable is passed by reference to the 'Foo' function in which its value will be used.
Документация: https://pvs-studio.ru/ru/docs/warnings/v679/
*/

#include <iostream>

void ErrUse3(int &x, int &y)
{
  x = y;
}

void ErrGet12()
{
  int x, y;
  ErrUse3(x, y); // FLAW
}