// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1169 / (wrapper_par - 13); }

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int divident = 46, divisor = 8, result;

  std::vector<int> vec(86, 0);

  int local_var1 = 35;
  int local_var2 = 53;
  int index1 = 23;
  int index2 = 32;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    divisor = 13;
  }

  if (local_var1 == vec[32]) {
    result = wrapper(divisor);
  }
}
