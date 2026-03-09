// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант:
// basic-array-static-const_size-tainted_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс получен от пользователя.
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdio.h>

int buffer[36];

void func(void) {
  int iter_var;

  int result = 0;
  unsigned int index = 0;

  for (iter_var = 4; iter_var < 29; iter_var++) {
    scanf("%u", &index);

    result = buffer[index]; // FLAW
  }

  return;
}
