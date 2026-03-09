/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
 6.5. д) Ошибки использования неинициализированных переменных.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 4) данные передаются через одну или несколько функций.

Детектор PVS-Studio: V614. Use of 'Foo' uninitialized variable.
Документация: https://pvs-studio.ru/ru/docs/warnings/v614/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v614/
*/

#include <iostream>

typedef double Type;
constexpr size_t Size = 3;

void FixUse2(size_t **ptr, size_t s )
{
}

void FixGet7()
{
  size_t *ptr;
  size_t s = sizeof(ptr);
  FixUse2(&ptr, s);
}