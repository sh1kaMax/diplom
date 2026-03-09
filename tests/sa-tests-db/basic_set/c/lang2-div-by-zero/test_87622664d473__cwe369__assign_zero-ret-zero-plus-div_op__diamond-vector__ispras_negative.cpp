// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdlib.h>

int wrapper(int wrapper_par) { return 53; }

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int divident = 62, divisor = 10, result;

  std::vector<int> vec(24, 0);

  int local_var1 = 52;
  int local_var2 = 77;
  int index1 = 17;
  int index2 = 21;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    divisor = wrapper(40);
    divisor -= 53;
  }

  if (local_var1 == vec[21]) {
    result = divident / divisor;
  }
}
