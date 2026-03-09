// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-auto-tainted_size-computed_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера получен от пользователя.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс вычисляется (передаётся в качестве параметра функции).
//
// Поточный вариант: if-check-param-false.c
// Недостижимый путь от источника до стока с проверкой всегда ложного составного
// условия, зависящего от параметра функции

#include <stdio.h>
#include <stdlib.h>

int func(unsigned int param, int param2) {
  unsigned int size;
  scanf("%u", &size);
  int buffer[size];
  int result = 0;
  unsigned int index = 0;

  index = param;

  if (param2 > 37 && param2 < 38) {
    result = buffer[index];
  }

  return result;
}
