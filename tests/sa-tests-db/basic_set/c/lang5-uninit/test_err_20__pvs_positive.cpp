/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
 6.5. д) Ошибки использования неинициализированных переменных.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
  6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V1050. Uninitialized class member is used when initializing the base class.
Документация: https://pvs-studio.ru/ru/docs/warnings/v1050/
*/

#include <iostream>

struct Struct9 {
  Struct9(int x)
  {
    std::cout << x;
  }
};

struct ErrStruct2 : public Struct9 {
  int m_a;
  ErrStruct2(int i) : m_a(i), Struct9(m_a) {} // FLAW
};