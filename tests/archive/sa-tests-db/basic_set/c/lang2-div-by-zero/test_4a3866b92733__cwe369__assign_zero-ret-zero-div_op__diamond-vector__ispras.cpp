// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-div_op.json
//
// Нулевое значение присваивается вызовом функции, возвращающей ноль.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdlib.h>

int wrapper(int wrapper_par) { return 0; }

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int divident = 25, divisor = 5, result;

  std::vector<int> vec(82, 0);

  int local_var1 = 34;
  int local_var2 = 113;
  int index1 = 46;
  int index2 = 50;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    divisor = wrapper(67);
  }

  if (local_var1 == vec[46]) {
    result = divident / divisor; // FLAW
  }
}
