// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания не является нулём.
//
// Поточный вариант: switch-flipped-no-break.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1846 / (wrapper_par - 14); }

void func(void) {
  int divident = 67, divisor = 8, result;

  int var;

  divisor = 27;

  var = 0;

  switch (var) {
  case 1:
    exit(0);
  case 0:
    result = wrapper(divisor);
    break;
  }
}
