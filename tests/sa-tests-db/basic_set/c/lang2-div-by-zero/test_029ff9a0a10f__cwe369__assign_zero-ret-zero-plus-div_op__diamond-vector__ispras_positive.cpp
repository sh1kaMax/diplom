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

int wrapper(int wrapper_par) { return 70; }

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int divident = 19, divisor = 5, result;

  std::vector<int> vec(25, 0);

  int local_var1 = 94;
  int local_var2 = 168;
  int index1 = 10;
  int index2 = 23;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    divisor = wrapper(19);
    divisor -= 70;
  }

  if (local_var1 == vec[10]) {
    result = divident / divisor; // FLAW
  }
}
