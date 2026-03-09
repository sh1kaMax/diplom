// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-auto-const_size-computed_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс вычисляется (передаётся в качестве параметра
// функции).
//
// Поточный вариант: call-struct.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения второго поля локальной для вызывающей
// функции структуры с константными значениями; структура передаётся по значению
// в вызываемую функцию через её аргумент; возвращаемое из вызываемой функции
// значение нулевое, поэтому проверка в вызывающей функции неуспешна и
// выполнение достигает стока

#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

struct struct_type {
  int field1;
  int field2;
  int field3;
};

int callee(struct struct_type struct_param) {
  if (struct_param.field2 > 0)
    return 1;
  else
    return 0;
}

int func(unsigned int param) {
  int buffer[40];
  int result = 0;
  unsigned int index = 0;

  struct struct_type struct_var = {-5, 0, 5};

  if (param > 0 && param < 31) {
    index = (param * 2 + 1);
  } else {
    exit(0);
    ;
  }

  if (callee(struct_var)) {
    exit(0);
  }

  memset(buffer, 0, index * sizeof(int)); // FLAW
  use_mem_to_keep_memset(buffer);

  return result;
}
