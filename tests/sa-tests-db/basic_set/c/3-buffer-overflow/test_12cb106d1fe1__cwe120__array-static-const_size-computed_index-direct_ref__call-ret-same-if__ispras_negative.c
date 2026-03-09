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
// Поточный вариант: call-ret-same-if.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которая возвращает свой аргумент, в зависимости от другого
// параметра. Проверка в вызывающей функции успешна и выполнение не достигает
// стока

#include <stdlib.h>

int buffer[40];

int callee(unsigned int par1, int par2) {
  if (par2 <= 10)
    return par1;

  return 10;
}

int func(unsigned int param) {
  int result = 0;
  unsigned int index = 0;

  int local_res = callee(param, 20);

  if (param > 0 && param < 30) {
    index = (param * 2 + 1);
  } else {
    exit(0);
    ;
  }

  if (local_res == 10) {
    exit(0);
  }

  result = buffer[index];

  return result;
}
