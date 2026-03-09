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

int wrapper(int wrapper_par) { return 1832 / wrapper_par; }

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int divident = 42, divisor = 10, result;

  std::vector<int> vec(15, 0);

  int local_var1 = 1;
  int local_var2 = 50;
  int index1 = 3;
  int index2 = 6;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    divisor = 0;
  }

  if (local_var1 == vec[6]) {
    result = wrapper(divisor);
  }
}
