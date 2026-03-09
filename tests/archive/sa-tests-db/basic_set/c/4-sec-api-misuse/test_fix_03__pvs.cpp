/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
 6.3. г) Ошибки некорректного использования системных процедур и интерфейсов, связанных с обеспечением информационной безопасности (шифрования, разграничения доступа и пр.).

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 5) сложные циклы, вложенные циклы;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio:  V642. Function result is saved inside the 'byte' type variable. Significant bits may be lost. This may break the program's logic.
Документация: https://pvs-studio.ru/ru/docs/warnings/v642/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v642/
*/

#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <string.h>

int char_strcmp_ok(const char **arr1, size_t n1, const char **arr2, size_t n2)
{
  for (size_t i = 0; i < n1; i++)
    for (size_t j = 0; j < n2; j++)
    {
      int c = strcmp(arr1[i], arr2[j]);
      if (c == 0)
        return 1;
    }
  return -1;
}