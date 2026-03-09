// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_ret_null-deref_op.json
//
// Нулевое значение присваивается с помощью вызова функции, которая всегда
// возвращает ноль. Разыменование указателя осуществляется непосредственно (с
// помощью операции разыменования).
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdlib.h>

int *null_func(int null_func_arg) { return NULL; }

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  std::vector<int> vec(88, 0);

  int local_var1 = 48;
  int local_var2 = 102;
  int index1 = 54;
  int index2 = 75;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    pointer = null_func(28);
  }

  if (local_var1 == vec[54]) {
    *pointer = 0; // FLAW
  }
}
