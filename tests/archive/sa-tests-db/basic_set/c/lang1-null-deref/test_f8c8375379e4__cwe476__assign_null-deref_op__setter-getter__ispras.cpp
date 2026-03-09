// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-deref_op.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
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
  int *pointer, other, dummy;
  pointer = &dummy;

  setVal(9);

  pointer = NULL;

  setVal(5);

  if (isTrue()) {
    setVal(8);

    *pointer = 0;
  }
}
