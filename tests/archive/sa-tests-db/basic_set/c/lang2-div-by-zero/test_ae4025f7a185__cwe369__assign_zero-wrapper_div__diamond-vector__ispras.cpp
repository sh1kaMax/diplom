// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1602 / wrapper_par; }

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int divident = 54, divisor = 10, result;

  std::vector<int> vec(95, 0);

  int local_var1 = 14;
  int local_var2 = 51;
  int index1 = 22;
  int index2 = 73;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    divisor = 0;
  }

  if (local_var1 == vec[22]) {
    result = wrapper(divisor); // FLAW
  }
}
