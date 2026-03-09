// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-deref_memset.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя в вызове стандартной функции memset.
//
// Поточный вариант: ternary.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними с помощью тернарного оператора, выполнение достигает стока в
// случае истинности проверки.

#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int var;

  pointer = NULL;

  var = (pointer == NULL ? 1 : 0);

  if (var) {
    memset(pointer, 0, sizeof(int)); // FLAW
    use_mem_to_keep_memset(pointer);
  }
}
