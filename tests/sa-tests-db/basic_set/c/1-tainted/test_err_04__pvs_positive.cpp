/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
 6.3. а) Ошибки непроверенного использования чувствительных данных (ввода пользователя, файлов сети и пр.).

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 4) данные передаются через одну или несколько функций.

Детектор PVS-Studio: V1010. Unchecked tainted data is used in expression.
Документация: https://pvs-studio.ru/ru/docs/warnings/v1010/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v1010/
*/

#include <iostream>
#include <stdio.h>

int get_index_9() {
  int index;
  scanf("%d", &index);
  return index;
}

void use_index_9(char *buf, int index) {
  buf[index] = 1;
}

void U_Scanf_4() {
  char buf[10];
  int i = get_index_9();
  use_index_9(buf, i); // FLAW
}