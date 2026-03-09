// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero_ret_par-plus-div_op.json
//
// Ненулевое значение присваивается комбинацией вызова функции и вычитания.
// Вызываемая функция возвращает свой аргумент. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par; }

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  int divident = 54, divisor = 8, result;

  std::vector<int> vec(35, 0);

  int local_var1 = 36;
  int local_var2 = 64;
  int index1 = 25;
  int index2 = 32;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    divisor = wrapper(21);
    divisor -= 15;
  }

  if (local_var1 == vec[25]) {
    result = divident / divisor;
  }
}
