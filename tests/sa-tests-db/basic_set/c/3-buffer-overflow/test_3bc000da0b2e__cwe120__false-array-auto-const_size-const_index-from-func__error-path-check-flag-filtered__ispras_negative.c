// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-auto-const_size-const_index-from-func.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Индекс получен за счёт вызова функции.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: error-path-check-flag-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, установка флага при истинности проверки, фильтрация и
// последующий переход по метке со стоком.

#include <stdlib.h>

int result = 0;

int index_change_func(int func_par) { return func_par + 4; }

void func(void) {
  int buffer[22];
  unsigned int index = 0;

  int flag = 0;

  index = 22;

  if (index >= 22)
    flag = 1;

  if (flag != 0) {

    index = 22 - 1 - 4;

    goto error_label;
  }

  exit(0);

error_label:
  index = index_change_func(index);
  result = buffer[index];

  return;
}
