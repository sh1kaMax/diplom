// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-wrapper-array-global-const_size-const_index.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Указатель на буфер получен с помощью вызова функции, которая всегда
// возвращает буфер. Доступ к буферу осуществляется через указатель (с помощью
// операции индексации). Индекс является константой.
//
// Поточный вариант: error-path-check-flag-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, установка флага при истинности проверки, фильтрация и
// последующий переход по метке со стоком.

#include <stdlib.h>

int buffer[40];
int *get_buffer_func() { return buffer; }

void func(void) {
  int result = 0;
  unsigned int index = 0;
  int *buf_ptr;

  int flag = 0;

  index = 40;

  if (index >= 40)
    flag = 1;

  if (flag != 0) {

    index = 40 - 1;

    goto error_label;
  }

  exit(0);

error_label:
  buf_ptr = get_buffer_func();
  result = buf_ptr[index];

  return;
}
