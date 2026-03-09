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
// Поточный вариант: call-pointer-alias-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения локальной для вызываемой функции
// переменной, адрес которой сначала сохраняется в локальную
// переменную-указатель, а затем с его помощью передаётся в вызываемую функцию
// через её аргумент; возвращаемое из вызываемой функции значение равно единице,
// поэтому проверка в вызывающей функции успешна и выполнение завершается, не
// достигнув стока

#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

int callee(int *pointer_param) {
  if (*pointer_param >= 0)
    return 1;
  else
    return 0;
}

int func(unsigned int param) {
  int buffer[34];
  int result = 0;
  unsigned int index = 0;

  int local_var = 0, *local_pointer = &local_var;

  if (param > 0 && param < 26) {
    index = (param * 2 + 1);
  } else {
    exit(0);
    ;
  }

  if (callee(local_pointer)) {
    exit(0);
  }

  memset(buffer, 0, index * sizeof(int));
  use_mem_to_keep_memset(buffer);

  return result;
}
