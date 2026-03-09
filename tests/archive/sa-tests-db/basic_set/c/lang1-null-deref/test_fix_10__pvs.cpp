/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
 6.5. а) Ошибки разыменования нулевого указателя.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V664. Pointer was used before its check for nullptr. Check lines: N1, N2.
Документация: https://pvs-studio.ru/ru/docs/warnings/v664/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v664/
*/

#include <iostream>

namespace TestInit_Ok
{
  struct Canvas
  {
    int name;
    int coord;
  };

  struct About
  {
    int m_name;
    int m_coord;
    About() : m_name(0), m_coord(0) {}
    About(int name, int coord) : m_name(name), m_coord(coord) {}
    void set(int name, int coord) { m_name = name; m_coord = coord; }
  };

  class Layer
  {
    About about;
    Layer(const Canvas* canvas)
    {
      if (canvas)
      {
        about.set(canvas->name, canvas->coord);
        std::cout << "Layer";
      }
    }
  };
}