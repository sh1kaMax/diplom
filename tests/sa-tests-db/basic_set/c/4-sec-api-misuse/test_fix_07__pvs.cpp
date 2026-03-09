/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
 6.3. г) Ошибки некорректного использования системных процедур и интерфейсов, связанных с обеспечением информационной безопасности (шифрования, разграничения доступа и пр.).

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio:  V642. Function result is saved inside the 'byte' type variable. Significant bits may be lost. This may break the program's logic.
Документация: https://pvs-studio.ru/ru/docs/warnings/v642/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v642/
*/

#include <iostream>
#include <string>
#include <cstring>
#include <cstdint>
#include <limits.h>
#include <stdio.h>
#include <string.h>

typedef short SSHORT;

SSHORT compare_ok(unsigned long len1, const unsigned long* str1,
                 unsigned long len2, const unsigned long* str2)
{
  int cmp = memcmp(str1, str2, std::min(len1, len2));
  if (cmp == 0)
    cmp = (len1 < len2 ? -1 : (len1 > len2 ? 1 : 0));
  if (cmp < 0)
    return -1;
  return 1;
}