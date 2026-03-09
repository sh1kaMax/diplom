// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-wrapper-array-global-const_size-const_index.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Указатель на буфер получен с помощью вызова функции, которая всегда
// возвращает буфер. Доступ к буферу осуществляется через указатель (с помощью
// операции индексации). Индекс является константой.
//
// Поточный вариант: two-instances.cpp
// Тест содержит 2 экземпляра одного класса. Путь от источника до стока зависит
// от вызова функции одного из экземпляров.

#include <stdlib.h>

int buffer[22];
int *get_buffer_func() { return buffer; }

class SomeClass {
  int member1;

public:
  SomeClass(int ctor_par) : member1(ctor_par) {}

  int getVal() { return member1; }
};

void func(void) {
  int result = 0;
  unsigned int index = 0;
  int *buf_ptr;

  SomeClass *cl_var1 = new SomeClass(11);
  SomeClass *cl_var2 = new SomeClass(-60);

  index = 22;

  if (cl_var2->getVal() > -57) {
    buf_ptr = get_buffer_func();
    result = buf_ptr[index];
  }

  delete cl_var1;
  delete cl_var2;

  return;
}
