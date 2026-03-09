// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-static-const_size-computed_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс вычисляется (передаётся в качестве параметра функции).
//
// Поточный вариант: call-ret-same.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которая просто возвращает свой аргумент. Поэтому проверка в
// вызывающей функции неуспешна и выполнение достигает стока

#include <stdlib.h>

int buffer[32];

int callee(unsigned int par1) { return par1; }

int func(unsigned int param) {
  int result = 0;
  unsigned int index = 0;

  int local_res = callee(param);

  if (param > 0 && param < 23) {
    index = (param * 2 + 1);
  } else {
    exit(0);
    ;
  }

  if (local_res != param) {
    exit(0);
  }

  result = buffer[index]; // FLAW

  return result;
}
