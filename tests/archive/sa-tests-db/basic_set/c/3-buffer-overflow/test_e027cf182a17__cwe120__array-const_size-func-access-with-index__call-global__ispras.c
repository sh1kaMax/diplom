// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-const_size-func-access-with-index.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется с помощью вызова функции, в которую передаётся
// массив по указателю. Индекс является константой.
//
// Поточный вариант: call-global.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения глобальной переменной, значение которой
// устанавливается перед вызовом; возвращаемое из вызываемой функции значение
// нулевое, поэтому проверка в вызывающей функции неуспешна и выполнение
// достигает стока.

#include <stdlib.h>

int get_buffer_elem(int *buf_ptr_par, int buf_index_par) {
  return buf_ptr_par[buf_index_par];
}

int global_var = 0;

int callee(void) {
  if (global_var > 0)
    return 1;
  else
    return 0;
}

void func(void) {
  int buffer[20];
  int result = 0;
  unsigned int index = 0;

  global_var = -1;

  index = 20;

  if (callee()) {
    exit(0);
  }

  result = get_buffer_elem(buffer, index); // FLAW

  return;
}
