/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
 6.5. а) Ошибки разыменования нулевого указателя.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 4) данные передаются через одну или несколько функций.

Детектор PVS-Studio: V522. Possible null pointer dereference.
Документация: https://pvs-studio.ru/ru/docs/warnings/v522/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v522/
*/

#include <iostream>

namespace Error_Example
{
  struct NP_Class_A
  {
    int m_a;
    virtual ~NP_Class_A() {}
  };

  struct NP_Class_B : public NP_Class_A
  {
    int m_b;
    virtual ~NP_Class_B() {}
  };

  void NP_Set(NP_Class_B *ptr)
  {
    ptr->m_b = 1; // FLAW
  }

  void NP_SetPass(NP_Class_B *ptr)
  {
    NP_Set(ptr);
  }

  void DynCastTestNullPtr_err(NP_Class_A *a)
  {
    NP_Class_B *b = dynamic_cast<NP_Class_B *>(a);
    NP_SetPass(b);
  }
}