// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_no_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции на ненулевую константу.
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par / 15; }

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int divident = 35, divisor = 6, result;

  std::vector<int> vec(40, 0);

  int local_var1 = 86;
  int local_var2 = 89;
  int index1 = 22;
  int index2 = 27;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    divisor = 0;
  }

  if (local_var1 == vec[22]) {
    result = wrapper(divisor);
  }
}
