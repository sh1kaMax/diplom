// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: basic-array-auto-tainted_size-const_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера получен от пользователя.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdio.h>

void func(void) {
  int iter_var;

  unsigned int size;
  scanf("%u", &size);
  int buffer[size];
  int result = 0;
  unsigned int index = 0;

  for (iter_var = 3; iter_var < 21; iter_var++) {
    index = 32;

    result = buffer[index]; // FLAW
  }

  return;
}
