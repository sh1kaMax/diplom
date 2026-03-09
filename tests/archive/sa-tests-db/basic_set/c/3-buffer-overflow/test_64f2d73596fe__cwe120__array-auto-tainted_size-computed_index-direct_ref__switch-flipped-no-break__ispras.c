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
// Поточный вариант: switch-flipped-no-break.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора

#include <stdio.h>
#include <stdlib.h>

int func(unsigned int param) {
  unsigned int size;
  scanf("%u", &size);
  int buffer[size];
  int result = 0;
  unsigned int index = 0;

  int var;

  index = param;

  var = 0;

  switch (var) {
  case 1:
    exit(0);
  case 0:
    result = buffer[index]; // FLAW
    break;
  }

  return result;
}
