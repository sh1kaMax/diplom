// Авторы теста: ИСП РАН
// CWE: 416
// Название: Use After Free
// Модельный вариант: global-read-direct_ref.json
//
// Память выделяется с помощью стандартной функции malloc.
// Выделенная память сохраняется в глобальной переменной.
// Освобожденная память читается с использованием операции разыменования.
//
// Поточный вариант: call-global-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения глобальной переменной, значение которой
// устанавливается перед вызовом; возвращаемое из вызываемой функции значение
// равно единице, поэтому проверка в вызывающей функции успешна и выполнение
// завершается, не достигнув стока

#include <stdlib.h>

int *pointer = NULL;

int global_var = 0;

int callee(void) {
  if (global_var > 0)
    return 1;
  else
    return 0;
}

int func(int param) {
  int result = 0;
  int freed_flag = 0;

  global_var = 1;

  pointer = malloc(sizeof(int));
  *pointer = param;
  free(pointer);
  freed_flag = 1;

  if (callee()) {
    exit(0);
  }

  result = pointer == NULL ? -1 : *pointer;

  if (!freed_flag) {
    free(pointer);
  }
  return result;
}
