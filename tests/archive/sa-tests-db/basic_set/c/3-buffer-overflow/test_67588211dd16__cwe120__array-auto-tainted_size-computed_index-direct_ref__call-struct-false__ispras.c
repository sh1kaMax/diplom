// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-auto-tainted_size-computed_index-direct_ref.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера получен от пользователя.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс вычисляется (передаётся в качестве параметра функции).
//
// Поточный вариант: call-struct-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения второго поля локальной для вызывающей
// функции структуры с константными значениями; структура передаётся по значению
// в вызываемую функцию через её аргумент; возвращаемое из вызываемой функции
// значение равно единице, поэтому проверка в вызывающей функции успешна и
// выполнение завершается, не достигнув стока

#include <stdio.h>
#include <stdlib.h>

struct struct_type {
  int field1;
  int field2;
  int field3;
};

int callee(struct struct_type struct_param) {
  if (struct_param.field2 >= 0)
    return 1;
  else
    return 0;
}

int func(unsigned int param) {
  unsigned int size;
  scanf("%u", &size);
  int buffer[size];
  int result = 0;
  unsigned int index = 0;

  struct struct_type struct_var = {-5, 0, 5};

  index = param;

  if (callee(struct_var)) {
    exit(0);
  }

  result = buffer[index];

  return result;
}
