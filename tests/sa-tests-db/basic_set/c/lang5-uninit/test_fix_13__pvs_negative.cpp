/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
 6.5. д) Ошибки использования неинициализированных переменных.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 3) данные передаются через структуры;

Детектор PVS-Studio:  V670. Uninitialized class member is used to initialize another member.
                      Remember that members are initialized in the order of their declarations inside a class.
Документация: https://pvs-studio.ru/ru/docs/warnings/v670/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v670/
*/

#include <iostream>

struct Struct6
{
  double x;
  double y;
  Struct6(double z) : y(z), x(10.0) { }
};