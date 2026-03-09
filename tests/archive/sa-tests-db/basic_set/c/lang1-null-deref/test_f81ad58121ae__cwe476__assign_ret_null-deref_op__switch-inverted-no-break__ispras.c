// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_ret_null-deref_op.json
//
// Нулевое значение присваивается с помощью вызова функции, которая всегда
// возвращает ноль. Разыменование указателя осуществляется непосредственно (с
// помощью операции разыменования).
//
// Поточный вариант: switch-inverted-no-break.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; выполнение завершается при переходе на ветку оператора выбора
// до достижения стока.

#include <stdlib.h>

int *null_func(int null_func_arg) { return NULL; }

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int var;

  pointer = null_func(31);

  var = 0;

  switch (var) {
  case 0:
    exit(0);
  case 1:
    *pointer = 0;
    break;
  }
}
