// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-auto-const_size-const_index-from-func.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Индекс получен за счёт вызова функции.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdlib.h>

int result = 0;

int index_change_func(int func_par) { return func_par + 5; }

void func(void) {
  int buffer[30];
  unsigned int index = 0;

  int flag = 0;

  index = 30;

  if (index >= 30)
    flag = 1;

  if (flag != 0)
    goto error_label;

  index = 30 - 1 - 5;

  exit(0);

error_label:
  index = index_change_func(index);
  result = buffer[index]; // FLAW

  return;
}
