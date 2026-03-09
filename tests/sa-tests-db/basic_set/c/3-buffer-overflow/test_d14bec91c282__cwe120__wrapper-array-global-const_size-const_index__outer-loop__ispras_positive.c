// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: wrapper-array-global-const_size-const_index.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Указатель на буфер получен с помощью вызова функции, которая всегда
// возвращает буфер. Доступ к буферу осуществляется через указатель (с помощью
// операции индексации). Индекс является константой.
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdlib.h>

int buffer[30];
int *get_buffer_func() { return buffer; }

void func(void) {
  int iter_var;

  int result = 0;
  unsigned int index = 0;
  int *buf_ptr;

  for (iter_var = 10; iter_var < 29; iter_var++) {
    index = 30;

    buf_ptr = get_buffer_func();
    result = buf_ptr[index]; // FLAW
  }

  return;
}
