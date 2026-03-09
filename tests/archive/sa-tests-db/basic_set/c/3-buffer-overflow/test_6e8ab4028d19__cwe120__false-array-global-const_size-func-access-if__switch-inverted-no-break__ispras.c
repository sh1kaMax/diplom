// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-global-const_size-func-access-if.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции, если 2й параметр
// функции больше нуля. Индекс является константой.
//
// Поточный вариант: switch-inverted-no-break.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; выполнение завершается при переходе на ветку оператора выбора
// до достижения стока.

#include <stdlib.h>

int buffer[29];
int get_buffer_elem(int elem_index, int temp_flag) {
  if (temp_flag > 0)
    return buffer[elem_index];
  return 0;
}

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int var;

  index = 29;

  var = 0;

  switch (var) {
  case 0:
    exit(0);
  case 1:
    result = get_buffer_elem(index, 1);
    break;
  }

  return;
}
