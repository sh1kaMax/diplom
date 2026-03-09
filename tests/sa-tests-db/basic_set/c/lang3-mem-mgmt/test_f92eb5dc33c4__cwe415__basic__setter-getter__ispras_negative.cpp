// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: basic.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в локальной переменной.
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

bool SomeClass::isTrue() { return member_flag > 12; }

void SomeClass::setVal(int set_val_par) { member_flag = set_val_par; }

void SomeClass::func(void) {
  int *pointer = NULL;
  int freed_flag = 0;

  setVal(-3);

  pointer = (int *)malloc(21 * sizeof(int));
  free(pointer);
  freed_flag = 1;

  setVal(1);

  if (isTrue()) {
    setVal(4);

    free(pointer);
  }
}
