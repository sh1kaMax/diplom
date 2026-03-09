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
// Поточный вариант: diamond-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых простых
// условий, результат которых зависит от параметра функции.

#include <stdlib.h>

int buffer1[30];
int buffer2[40];

int *get_buffer_func(int temp_flag) {
  if (temp_flag)
    return buffer1;
  return buffer2;
}

void func(int param) {
  int result = 0;
  unsigned int index = 0;

  if (param > 4) {
    index = 40;
  }

  if (param < 17) {
    int *buf_ptr = get_buffer_func(param);
    result = buf_ptr[index]; // FLAW
  }

  return;
}
