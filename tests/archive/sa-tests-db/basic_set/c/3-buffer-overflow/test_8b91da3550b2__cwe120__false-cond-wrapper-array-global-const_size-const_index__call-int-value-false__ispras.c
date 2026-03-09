// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант:
// false-cond-wrapper-array-global-const_size-const_index.json
//
// Чтение за правой границей буфера.
// Два буфера выделены в статической памяти.
// Размер буферов является константой.
// Функция в зависимости от условия возвращает указатель на один из буферов.
// Доступ к буферу осуществляется через указатель (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: call-int-value-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// успешна и выполнение прекращается

#include <stdlib.h>

int buffer1[22];
int buffer2[32];

int *get_buffer_func(int temp_flag) {
  if (temp_flag)
    return buffer1;
  return buffer2;
}

int callee(int par1) {
  if (par1 > 41)
    return 20;

  return 10;
}

void func(int param) {
  int result = 0;
  unsigned int index = 0;

  int local_var = 4;

  index = 32;

  if (callee(local_var) == 10) {
    exit(0);
  }

  int *buf_ptr = get_buffer_func(param);
  result = buf_ptr[index];

  return;
}
