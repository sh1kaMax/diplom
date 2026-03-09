/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
 6.5. а) Ошибки разыменования нулевого указателя.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V769. The pointer in the expression equals nullptr. The resulting value is senseless and it should not be used.
Документация: https://pvs-studio.ru/ru/docs/warnings/v769/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v769/
*/

#include <iostream>
#include <string>
#include <cstring>

class OffsetOk
{
  std::string m_str;
  void add(const char *begin, const char *end)
  {
    while (begin < end)
      m_str.push_back(*begin++);
  }

  OffsetOk init(const char* beg, const char* end)
  {
    OffsetOk offset;
    if (beg == 0)
      return offset;
    if (end == 0) {
      end = beg + strlen(beg);
    }
    offset.add(beg, end);
    return offset;
  }
};