/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
 6.5. д) Ошибки использования неинициализированных переменных.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
  6.7. a) 1) прямолинейный участок кода.
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
  6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V573. Use of uninitialized variable 'Foo'. The variable was used to initialize itself.
Документация: https://pvs-studio.ru/ru/docs/warnings/v573/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v573/
*/

#include <iostream>
#include <string>

class ClassErr2
{
public:
  std::string dir;
  std::string fullname;
  std::string Foo(const std::string &filename);
};

std::string ClassErr2::Foo(const std::string &filename)
{
  if (filename.empty())
    return "";
  std::string fullname = dir + std::string("\\") + fullname; // FLAW
  return fullname;
}