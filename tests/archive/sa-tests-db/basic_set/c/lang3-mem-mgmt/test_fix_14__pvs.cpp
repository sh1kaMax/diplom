/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.5. в) ошибки управления динамической памятью (выделения, освобождения, использования освобожденной памяти).

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7.1. б) 3) данные передаются через сложные структуры данных (списки, коллекции и т. п.).

Детектор PVS-Studio: V611. Memory allocation and deallocation methods are incompatible.
Документация: https://pvs-studio.ru/ru/docs/warnings/v611/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v611/
*/

#include <iostream>

struct ArrayOk2
{
  int *m_arr;
  void Init(size_t n) { m_arr = new int[n]; }
  ArrayOk2(size_t n) { Init(n); }
  ~ArrayOk2() { delete [] m_arr; }
  void Resize(size_t n)
  {
    delete [] m_arr;
    m_arr = nullptr;
    m_arr = new int[n];
  }
};