// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdlib.h>

int wrapper(int wrapper_par) { return 24; }

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int divident = 70, divisor = 7, result;

  std::vector<int> vec(39, 0);

  int local_var1 = 74;
  int local_var2 = 157;
  int index1 = 10;
  int index2 = 30;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    divisor = wrapper(70);
    divisor -= 14;
  }

  if (local_var1 == vec[10]) {
    result = divident / divisor;
  }
}
