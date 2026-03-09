// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-auto-const_size-computed_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс вычисляется (передаётся в качестве параметра
// функции).
//
// Поточный вариант: error-path-check-flag-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки, фильтрация и последующий
// переход по метке со стоком.

#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

int func(unsigned int param) {
  int buffer[32];
  int result = 0;
  unsigned int index = 0;

  int flag = 0;

  if (param > 0 && param < 27) {
    index = (param * 2 + 1);
  } else {
    exit(0);
    ;
  }

  if (index > 32)
    flag = 1;

  if (flag != 0) {

    index = 32;

    goto error_label;
  }

  exit(0);

error_label:
  memset(buffer, 0, index * sizeof(int));
  use_mem_to_keep_memset(buffer);

  return result;
}
