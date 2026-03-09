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
// Поточный вариант: if-check-param-interval.c
// Достижимый путь от источника до стока с проверкой составного условия,
// результат которого зависит от параметра функции.

#include <stdlib.h>

int buffer1[35];
int buffer2[45];

int *get_buffer_func(int temp_flag) {
  if (temp_flag)
    return buffer1;
  return buffer2;
}

void func(int param) {
  int result = 0;
  unsigned int index = 0;

  index = 45;

  if (param > 46 && param < 69) {
    int *buf_ptr = get_buffer_func(param);
    result = buf_ptr[index]; // FLAW
  }

  return;
}
