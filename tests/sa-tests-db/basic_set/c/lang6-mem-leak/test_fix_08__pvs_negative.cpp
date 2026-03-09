/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
 6.5. е) Ошибки утечек памяти, незакрытых файловых дескрипторов и дескрипторов сетевых соединений.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V1023. A pointer without owner is added to the container by the 'emplace_back' method. A memory leak will occur in case of an exception.
Документация: https://pvs-studio.ru/ru/docs/warnings/v1023/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v1023/
*/

#include <iostream>
#include <vector>
#include <memory>

void TestEmplacebackOk()
{
  std::vector<std::unique_ptr<int>> pointers;
  pointers.push_back(std::make_unique<int>(42));
};