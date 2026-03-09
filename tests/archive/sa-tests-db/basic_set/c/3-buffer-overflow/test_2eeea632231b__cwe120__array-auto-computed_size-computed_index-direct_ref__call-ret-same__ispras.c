// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-auto-computed_size-computed_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера вычисляется (передаётся в качестве параметра функции).
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс вычисляется (передаётся в качестве параметра функции).
//
// Поточный вариант: call-ret-same.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которая просто возвращает свой аргумент. Поэтому проверка в
// вызывающей функции успешна и выполнение не достигает стока

#include <stdlib.h>

int callee(unsigned int par1) { return par1; }

int func(unsigned int param) {
  int buffer[param];
  int result = 0;
  unsigned int index = 0;

  int local_res = callee(param);

  index = param * 2;

  if (local_res == param) {
    exit(0);
  }

  result = buffer[index];

  return result;
}
