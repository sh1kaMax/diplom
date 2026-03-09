// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции только, если 2й аргумент
// больше нуля.
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 0;
  return 1997 / wrapper_par1;
}

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int divident = 37, divisor = 8, result;

  std::vector<int> vec(48, 0);

  int local_var1 = 56;
  int local_var2 = 68;
  int index1 = 39;
  int index2 = 43;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    divisor = 0;
  }

  if (local_var1 == vec[43]) {
    result = wrapper(divisor, divident);
  }
}
