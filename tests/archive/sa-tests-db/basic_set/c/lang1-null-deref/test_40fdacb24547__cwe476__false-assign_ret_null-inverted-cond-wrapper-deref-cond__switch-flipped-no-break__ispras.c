// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант:
// false-assign_ret_null-inverted-cond-wrapper-deref-cond.json
//
// Нулевое значение присваивается с помощью вызова функции, которая возвращает
// ноль в зависимости от параметра. Разыменование указателя осуществляется с
// помощью вызова функции, которая разыменовывает указатель под условием.
// Условия в функциях несовместимы.
//
// Поточный вариант: switch-flipped-no-break.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора

#include <stdlib.h>

int glob_var;

int *null_func(int null_func_arg) {
  if (null_func_arg == 16)
    return NULL;
  return &glob_var;
}

void wrapper_func(int wrapper_arg, int *ptr_arg) {
  if (wrapper_arg != 16)
    *ptr_arg = wrapper_arg;
}

int func(int param) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int var;

  pointer = null_func(param);

  var = 0;

  switch (var) {
  case 1:
    exit(0);
  case 0:
    wrapper_func(param, pointer);
    break;
  }

  return 0;
}
