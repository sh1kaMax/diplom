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
// Поточный вариант: diamond-plus-call.c
// Достижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdlib.h>

int buffer1[24];
int buffer2[34];

int *get_buffer_func(int temp_flag) {
  if (temp_flag)
    return buffer1;
  return buffer2;
}

int ret_func(int param1) { return param1; }

void func(int param) {
  int result = 0;
  unsigned int index = 0;

  int func_res = ret_func(10);

  if (param + func_res > 37) {
    index = 34;
  }

  if (param + func_res > 37) {
    int *buf_ptr = get_buffer_func(param);
    result = buf_ptr[index]; // FLAW
  }

  return;
}
