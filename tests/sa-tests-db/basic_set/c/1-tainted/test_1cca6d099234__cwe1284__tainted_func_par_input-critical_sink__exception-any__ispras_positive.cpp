// Авторы теста: ИСП РАН
// CWE: 1284
// Название: Improper validation of specified quantity in input
// Модельный вариант: tainted_func_par_input-critical_sink.json
//
// Количество получено от пользователя и присваивается в переменную через вызов
// функции, возвращающую свой аргумент. Отсутствуют проверки выхода количества
// за пределы допустимых значений. Количество передаётся в функцию, которая
// вызывает malloc.
//
// Поточный вариант: exception-any.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdio.h>
#include <stdlib.h>

void critical_sink(int func_param) {
  ;
  char *malloc_res = (char *)malloc(func_param);
  malloc_res[0] = 0;
  free(malloc_res);
}

int get_source(int get_source_param) {
  ;
  return get_source_param;
}

class ExceptionClass {};

void func(void) {
  int quantity = 8;
  int template_local_var;

  try {
    scanf("%d", &template_local_var);
    quantity = get_source(template_local_var);
    throw ExceptionClass();
  } catch (...) {
    critical_sink(quantity); // FLAW
  }
}
