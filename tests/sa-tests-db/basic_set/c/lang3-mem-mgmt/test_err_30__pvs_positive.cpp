/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.5. в) ошибки управления динамической памятью (выделения, освобождения, использования освобожденной памяти).

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7.1. б) 3) данные передаются через сложные структуры данных (списки, коллекции и т. п.).

Детектор PVS-Studio: V1002. Class that contains pointers, constructor and destructor is copied by the automatically generated operator= or copy constructor.
Документация: https://pvs-studio.ru/ru/docs/warnings/v1002/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v1002/
*/

#include <iostream>
#include <algorithm>

class SomeClassArrErr
{
  int *m_storagePtr;
public:
  SomeClassArrErr(size_t n)
  {
    m_storagePtr = new int[n];
    std::fill(m_storagePtr, m_storagePtr + n, 1);
  }
  int Get(size_t i) const { return m_storagePtr[i]; }
  ~SomeClassArrErr()
  {
    delete[] m_storagePtr;
  }
};

void SomeClassArrErrUse()
{
  SomeClassArrErr A(10);
  std::cout << A.Get(0) << std::endl;
  SomeClassArrErr B(A); // FLAW
  std::cout << B.Get(0) << std::endl;
}