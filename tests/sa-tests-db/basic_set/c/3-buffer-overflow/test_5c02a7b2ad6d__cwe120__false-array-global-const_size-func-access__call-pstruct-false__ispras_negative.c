// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-global-const_size-func-access.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции.
// Индекс является константой.
//
// Поточный вариант: call-pstruct-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения второго поля локальной для вызывающей
// функции структуры с константными значениями; структура передаётся по
// указателю в вызываемую функцию через её аргумент; возвращаемое из вызываемой
// функции значение равно единице, поэтому проверка в вызывающей функции успешна
// и выполнение завершается, не достигнув стока.

#include <stdlib.h>

int buffer[36];
int get_buffer_elem(int elem_index) { return buffer[elem_index]; }

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
  int result = 0;
  unsigned int index = 0;

  struct struct_type struct_var;
  struct_var.field1 = 0;
  struct_var.field2 = 3;
  struct_var.field3 = 97;

  index = 36;

  if (callee(&struct_var)) {
    exit(0);
  }

  result = get_buffer_elem(index);

  return;
}
