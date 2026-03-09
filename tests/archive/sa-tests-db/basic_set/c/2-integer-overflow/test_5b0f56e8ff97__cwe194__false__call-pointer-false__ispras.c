// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: call-pointer-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения локальной для вызываемой функции
// переменной, адрес которой непосредственно передаётся в вызываемую функцию
// через её аргумент; возвращаемое из вызываемой функции значение равно единице,
// поэтому проверка в вызывающей функции успешна и выполнение завершается, не
// достигнув стока.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

int callee(int *pointer_param) {
  if (*pointer_param >= 0)
    return 1;
  else
    return 0;
}

void func(void) {
  char string[99];
  short number = 98;

  int var = 0;

  scanf("%hd", &number);
  if (number > 98)
    number = 98;

  if (callee(&var)) {
    exit(0);
  }

  strncpy(string, source_string, number);
  string[98] = '\0';
}
