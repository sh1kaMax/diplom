/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.5. в) ошибки управления динамической памятью (выделения, освобождения, использования освобожденной памяти).

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V599. The virtual destructor is not present, although the 'Foo' class contains virtual functions.
Документация: https://pvs-studio.ru/ru/docs/warnings/v599/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v599/
*/

#include <cstddef>
#include <cstdio>
#include <string>
#include <string_view>
#include <memory>
#include <iostream>
#include <set>

namespace Error1
{
  class Control
  {
  public:
    virtual bool is_visible() const;
    virtual void show() const;
    virtual void hide() const;
    /* .... */
  };
  
  class Button : public Control { /* .... */ };
  class RadioButton : public Control { /* .... */ };
  
  std::set<Control *> Controls;
  
  void RemoveControl(Control *ctrl)
  {
    if (ctrl->is_visible())
    {
      ctrl->hide();
    }
    else
    {
      Controls.erase(ctrl);
      delete ctrl;          // FLAW
    }
  }
}