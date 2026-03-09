/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
 6.5. е) Ошибки утечек памяти, незакрытых файловых дескрипторов и дескрипторов сетевых соединений.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 3) данные передаются через структуры;

Детектор PVS-Studio: V773. Function exited without releasing the pointer/handle. A memory/resource leak is possible.
Документация: https://pvs-studio.ru/ru/docs/warnings/v773/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v773/
*/

#include <iostream>

class TestStructLeakErr
{
  int *m_buf;
  public:
  TestStructLeakErr(size_t N)
  {
    m_buf = new int[N];
  }
  ~TestStructLeakErr() { } // FLAW
};