// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: local-array-const_size-func-access.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти в вызываемой функции.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции, в которой этот буфер
// определён. Индекс является константой.
//
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdlib.h>

int get_buffer_elem(int elem_index) {
  int buffer[37];
  int cur_index = 0;
  for (; cur_index < 37; cur_index++)
    buffer[cur_index] = 80;
  return buffer[elem_index];
}

void callee(int *pointer_param) { *pointer_param = 68; }

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int var = 0;

  index = 37;

  callee(&var);

  if (var > 532) {
    exit(0);
  }

  result = get_buffer_elem(index); // FLAW

  return;
}
