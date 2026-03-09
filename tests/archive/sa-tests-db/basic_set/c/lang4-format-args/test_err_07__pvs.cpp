/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.5. г) Ошибки использования форматной строки.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V510. The 'Foo' function receives class-type variable as Nth actual argument. This is unexpected behavior.
Документация: https://pvs-studio.ru/ru/docs/warnings/v510/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v510/
*/

#include <cstddef>
#include <cstdio>
#include <string>
#include <cstdarg>

namespace Error
{
  void PrintStdStrings(size_t n, ...)
  {
    std::va_list args;
    va_start(args, n);
    for (size_t i = 0; i < n; ++i)
    {
      auto arg = va_arg(args, std::string);
      printf("%s\n", arg.c_str());
    }

    va_end(args);
  }

  void Err1(const std::string &str1, const std::string &str2, const std::string &str3)
  {
    PrintStdStrings(3, str1, str2, str3); // FLAW
  }
}