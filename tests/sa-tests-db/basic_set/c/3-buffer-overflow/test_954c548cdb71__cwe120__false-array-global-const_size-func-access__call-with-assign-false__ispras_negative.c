// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-global-const_size-func-access.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции.
// Индекс является константой.
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <stdlib.h>

int buffer[29];
int get_buffer_elem(int elem_index) { return buffer[elem_index]; }

void callee(int *pointer_param) { *pointer_param = 148; }

void func(void) {
  int result = 0;
  unsigned int index = 0;

  int var = 0;

  index = 29;

  callee(&var);

  if (var > 9) {
    exit(0);
  }

  result = get_buffer_elem(index);

  return;
}
