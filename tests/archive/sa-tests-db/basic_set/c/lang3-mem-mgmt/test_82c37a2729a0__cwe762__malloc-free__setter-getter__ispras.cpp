// Авторы теста: ИСП РАН
// CWE: 762
// Название: Mismatched Memory
// Модельный вариант: malloc-free.json
//
// Память выделяется с помощью стандартной функции malloc.
// Память освобождается с помощью стандартной функции free.
//
// Поточный вариант: setter-getter.cpp
// Путь от источника до стока зависит от функции, которая всегда возвращает bool
// значение, зависящее от члена класса. Есть setter, который это значение
// выставляет.

#include <stdlib.h>

class SomeClass {
  int member_flag;

public:
  bool isTrue();

  void setVal(int set_val_par);

  void func(void);
};

bool SomeClass::isTrue() { return member_flag > 19; }

void SomeClass::setVal(int set_val_par) { member_flag = set_val_par; }

void SomeClass::func(void) {
  int *pointer = NULL;
  int freed_flag = 0;

  setVal(14);

  pointer = (int *)malloc(26 * sizeof(int));

  setVal(32);

  if (isTrue()) {
    setVal(14);

    free(pointer);
  }
}
