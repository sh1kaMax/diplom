/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.3. в) Ошибки переполнения буфера (записи или чтения за пределами выделенной для буфера памяти).

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V1111. The index was used without check after it was checked in previous lines.
Документация: https://pvs-studio.ru/ru/docs/warnings/v1111/
*/

#include <iostream>
#include <array>

struct UseWithoutCheckOk
{
  static constexpr unsigned size = 10;
  int buf[size];
  void Use(unsigned i)
  {
    if (i < size)
    {
      buf[i] *= 2;
      buf[i]++;
    }
  }
};