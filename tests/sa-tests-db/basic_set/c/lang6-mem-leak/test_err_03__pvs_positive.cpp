/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
 6.5. е) Ошибки утечек памяти, незакрытых файловых дескрипторов и дескрипторов сетевых соединений.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V773. Function exited without releasing the pointer/handle. A memory/resource leak is possible.
Документация: https://pvs-studio.ru/ru/docs/warnings/v773/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v773/
*/

#include <cstddef>
#include <cstdio>
#include <string>
#include <string_view>
#include <memory>

std::string ProcessData(std::string_view);

bool Err1_FILE_Leak(const std::string &path, std::string &res)
{
  res.clear();
  FILE *in = fopen(path.c_str(), "rb");
  if (!in)
  {
    fprintf(stderr, "Error: could not read file '%s'\n", path.c_str());
    return false;
  }

  char buf[16];
  size_t read;
  while ((read = fread(buf, 1, sizeof(buf), in)) > 0)
  {
    res += ProcessData({ buf, read });
  }
  
  return true; // FLAW
}