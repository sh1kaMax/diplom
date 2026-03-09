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
// Поточный вариант: error-path-check-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, фильтрация и переход по метке в случае истинности
// проверки.

#include <stdlib.h>

int buffer[30];
int *get_buffer_func() { return buffer; }

void func(void) {
  int result = 0;
  unsigned int index = 0;
  int *buf_ptr;

  index = 30;

  if (index >= 30) {

    index = 30 - 1;

    goto error_label;
  }

  exit(0);

error_label:
  buf_ptr = get_buffer_func();
  result = buf_ptr[index];

  return;
}
