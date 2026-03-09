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
// Поточный вариант: call-global-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения глобальной переменной, значение которой
// устанавливается перед вызовом; возвращаемое из вызываемой функции значение
// равно единице, поэтому проверка в вызывающей функции успешна и выполнение
// завершается, не достигнув стока

#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

int global_var = 0;

int callee(void) {
  if (global_var > 0)
    return 1;
  else
    return 0;
}

int func(unsigned int param) {
  int buffer[36];
  int result = 0;
  unsigned int index = 0;

  global_var = 1;

  if (param > 0 && param < 28) {
    index = (param * 2 + 1);
  } else {
    exit(0);
    ;
  }

  if (callee()) {
    exit(0);
  }

  memset(buffer, 0, index * sizeof(int));
  use_mem_to_keep_memset(buffer);

  return result;
}
