// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero_ret_par-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
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
  int divident = 35, divisor = 3, result;

  std::vector<int> vec(75, 0);

  int local_var1 = 22;
  int local_var2 = 49;
  int index1 = 42;
  int index2 = 52;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    divisor = wrapper(42);
    divisor -= 42;
  }

  if (local_var1 == vec[42]) {
    result = divident / divisor; // FLAW
  }
}
