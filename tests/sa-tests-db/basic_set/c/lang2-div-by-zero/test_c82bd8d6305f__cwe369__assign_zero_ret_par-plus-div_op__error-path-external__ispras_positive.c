// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero_ret_par-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Вызываемая функция возвращает свой аргумент. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: error-path-external.c
// Достижимый путь от источника до стока с проверкой результата вызова
// неизвестной внешней функции между ними, переход по метке со стоком в случае
// истинности проверки.

#include <stdlib.h>

int external_func(void);

int wrapper(int wrapper_par) { return wrapper_par; }

void func(void) {
  int divident = 16, divisor = 9, result;

  divisor = wrapper(29);
  divisor -= 29;

  if (external_func())
    goto error_label;

  divisor = 9;

  exit(0);

error_label:
  result = divident / divisor; // FLAW
}
