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
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdlib.h>

int buffer1[27];
int buffer2[37];

int *get_buffer_func(int temp_flag) {
  if (temp_flag)
    return buffer1;
  return buffer2;
}

void callee(int *pointer_param) { *pointer_param = 245; }

void func(int param) {
  int result = 0;
  unsigned int index = 0;

  int var = 0;

  index = 37;

  callee(&var);

  if (var > 935) {
    exit(0);
  }

  int *buf_ptr = get_buffer_func(param);
  result = buf_ptr[index]; // FLAW

  return;
}
