// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: cond-wrapper-array-global-const_size-const_index.json
//
// Чтение за правой границей буфера.
// Два буфера выделены в статической памяти.
// Размер буферов является константой.
// Функция в зависимости от условия возвращает указатель на один из буферов.
// Доступ к буферу осуществляется через указатель (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: pass-array-par-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

int buffer1[24];
int buffer2[34];

int *get_buffer_func(int temp_flag) {
  if (temp_flag)
    return buffer1;
  return buffer2;
}

void func(int param) {
  int result = 0;
  unsigned int index = 0;

  int arr[100];
  int some_var = 44;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[51] = 7;

  if (some_var) {
    index = 34;
  }

  if (arr[param]) {
    int *buf_ptr = get_buffer_func(param);
    result = buf_ptr[index]; // FLAW
  }

  return;
}
