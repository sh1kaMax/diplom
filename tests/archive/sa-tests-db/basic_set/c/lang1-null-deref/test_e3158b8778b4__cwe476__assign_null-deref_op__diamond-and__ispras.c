// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-deref_op.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
//
// Поточный вариант: diamond-and.c
// Достижимый путь от источника до стока с проверками одного и того же условия с
// использованием битового и.

#include <stdlib.h>

void func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;

  if (param & 0x1D) {
    pointer = NULL;
  }

  if (param & 0x1D) {
    *pointer = 0; // FLAW
  }
}
