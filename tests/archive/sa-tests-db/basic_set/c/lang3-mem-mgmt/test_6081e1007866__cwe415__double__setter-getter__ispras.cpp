// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: double.json
//
// Память выделяется дважды с помощью стандартной функции malloc.
// Адреса ыыделенных блоков памяти сохраняются в двух локальных переменных.
// Один из блоков освобождается дважды.
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

bool SomeClass::isTrue() { return member_flag > 17; }

void SomeClass::setVal(int set_val_par) { member_flag = set_val_par; }

void SomeClass::func(void) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;
  int freed_flag = 0;

  setVal(13);

  pointer1 = (int *)malloc(12 * sizeof(int));
  pointer2 = (int *)malloc(12 * sizeof(int));
  free(pointer2);
  freed_flag = 1;

  setVal(28);

  if (isTrue()) {
    setVal(10);

    free(pointer1);
    free(pointer2); // FLAW
    pointer1 = NULL;
  }

  free(pointer1);
}
