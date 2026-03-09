// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_ret_null-cond-wrapper-deref-cond.json
//
// Нулевое значение присваивается с помощью вызова функции, которая возвращает
// ноль в зависимости от параметра. Разыменование указателя осуществляется с
// помощью вызова функции, которая разыменовывает указатель под условием.
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdlib.h>

int glob_var;

int *null_func(int null_func_arg) {
  if (null_func_arg > 0)
    return NULL;
  return &glob_var;
}

void wrapper_func(int wrapper_arg, int *ptr_arg) {
  if (wrapper_arg > 0)
    *ptr_arg = wrapper_arg;
}

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  std::vector<int> vec(66, 0);

  int local_var1 = 48;
  int local_var2 = 138;
  int index1 = 23;
  int index2 = 63;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    pointer = null_func(100);
  }

  if (local_var1 == vec[23]) {
    wrapper_func(100, pointer); // FLAW
  }
}
