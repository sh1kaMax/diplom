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
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

int buffer[32];
int *get_buffer_func() { return buffer; }

void func(void) {
  int result = 0;
  unsigned int index = 0;
  int *buf_ptr;

  int var;

  index = 32;

  var = 0;

  for (var = 0; var < 12; var++)
    ;

  buf_ptr = get_buffer_func();
  result = buf_ptr[index]; // FLAW

  return;
}
