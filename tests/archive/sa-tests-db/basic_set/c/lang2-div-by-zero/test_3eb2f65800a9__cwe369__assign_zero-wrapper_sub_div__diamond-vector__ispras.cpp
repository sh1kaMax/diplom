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

int wrapper(int wrapper_par) { return 1544 / (wrapper_par - 16); }

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int divident = 61, divisor = 4, result;

  std::vector<int> vec(34, 0);

  int local_var1 = 92;
  int local_var2 = 145;
  int index1 = 20;
  int index2 = 24;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    divisor = 16;
  }

  if (local_var1 == vec[20]) {
    result = wrapper(divisor); // FLAW
  }
}
