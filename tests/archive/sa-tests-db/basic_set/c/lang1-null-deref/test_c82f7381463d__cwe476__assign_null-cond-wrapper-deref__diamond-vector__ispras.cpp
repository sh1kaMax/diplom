// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-cond-wrapper-deref.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется с помощью вызова функции, которая
// разыменовывает свой указатель, если второй параметр больше нуля.
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdlib.h>

void wrapper(int *ptr, int flag_par) {
  if (flag_par > 0)
    *ptr = 1;
}

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  std::vector<int> vec(54, 0);

  int local_var1 = 54;
  int local_var2 = 114;
  int index1 = 25;
  int index2 = 28;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    pointer = NULL;
  }

  if (local_var1 == vec[25]) {
    wrapper(pointer, 98); // FLAW
  }
}
