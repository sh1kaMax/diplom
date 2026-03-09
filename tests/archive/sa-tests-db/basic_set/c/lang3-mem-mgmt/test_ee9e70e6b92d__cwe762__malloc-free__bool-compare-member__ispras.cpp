// Авторы теста: ИСП РАН
// CWE: 762
// Название: Mismatched Memory
// Модельный вариант: malloc-free.json
//
// Память выделяется с помощью стандартной функции malloc.
// Память освобождается с помощью стандартной функции free.
//
// Поточный вариант: bool-compare-member.cpp
// Путь от источника до стока зависит от функции, которая сравнивает аргумент со
// значением члена класса.

#include <stdlib.h>

class SomeClass {
  int member_flag;

public:
  bool isTrue(int is_true_par);

  void setVal(int set_val_par);

  void func(void);
};

bool SomeClass::isTrue(int is_true_par) { return member_flag > is_true_par; }

void SomeClass::setVal(int set_val_par) { member_flag = set_val_par; }

void SomeClass::func(void) {
  int *pointer = NULL;
  int freed_flag = 0;

  setVal(97);

  pointer = (int *)malloc(24 * sizeof(int));

  setVal(110);

  if (isTrue(100)) {
    setVal(-14);

    free(pointer);
  }
}
