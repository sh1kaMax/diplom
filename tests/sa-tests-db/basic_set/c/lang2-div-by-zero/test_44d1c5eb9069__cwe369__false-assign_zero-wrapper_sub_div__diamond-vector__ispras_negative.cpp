// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания не является нулём.
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1132 / (wrapper_par - 19); }

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int divident = 46, divisor = 7, result;

  std::vector<int> vec(95, 0);

  int local_var1 = 100;
  int local_var2 = 160;
  int index1 = 20;
  int index2 = 64;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    divisor = 34;
  }

  if (local_var1 == vec[20]) {
    result = wrapper(divisor);
  }
}
