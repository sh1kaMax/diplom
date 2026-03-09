// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: double.json
//
// Память выделяется дважды с помощью стандартной функции malloc.
// Адреса ыыделенных блоков памяти сохраняются в двух локальных переменных.
// Один из блоков освобождается дважды.
//
// Поточный вариант: call-pstruct-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения второго поля локальной для вызывающей
// функции структуры с константными значениями; структура передаётся по
// указателю в вызываемую функцию через её аргумент; возвращаемое из вызываемой
// функции значение равно единице, поэтому проверка в вызывающей функции успешна
// и выполнение завершается, не достигнув стока.

#include <stdlib.h>

struct struct_type {
  int field1;
  int field2;
  int field3;
};

int callee(struct struct_type *struct_param) {
  if (struct_param->field2 >= 0)
    return 1;
  else
    return 0;
}

void func(void) {
  int *pointer1 = NULL;
  int *pointer2 = NULL;
  int freed_flag = 0;

  struct struct_type struct_var;
  struct_var.field1 = 5;
  struct_var.field2 = 10;
  struct_var.field3 = 99;

  pointer1 = (int *)malloc(18 * sizeof(int));
  pointer2 = (int *)malloc(18 * sizeof(int));
  free(pointer2);
  freed_flag = 1;

  if (callee(&struct_var)) {
    exit(0);
  }

  free(pointer1);
  free(pointer2);
  pointer1 = NULL;

  free(pointer1);
}
