// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero_ret_par-plus-div_op.json
//
// Ненулевое значение присваивается комбинацией вызова функции и вычитания.
// Вызываемая функция возвращает свой аргумент. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: error-path-check.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, переход по метке в случае истинности проверки.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par; }

void func(void) {
  int divident = 51, divisor = 4, result;

  divisor = wrapper(39);
  divisor -= 31;

  if (divisor == 0)
    goto error_label;

  divisor = 4;

  exit(0);

error_label:
  result = divident / divisor;
}
