// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: array-auto-const_size-const_index-from-func.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Индекс получен за счёт вызова функции.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: two-instances.cpp
// Тест содержит 2 экземпляра одного класса. Путь от источника до стока зависит
// от вызова функции одного из экземпляров.

#include <stdlib.h>

int result = 0;

int index_change_func(int func_par) { return func_par + 8; }

class SomeClass {
  int member1;

public:
  SomeClass(int ctor_par) : member1(ctor_par) {}

  int getVal() { return member1; }
};

void func(void) {
  int buffer[23];
  unsigned int index = 0;

  SomeClass *cl_var1 = new SomeClass(75);
  SomeClass *cl_var2 = new SomeClass(-27);

  index = 23;

  if (cl_var1->getVal() > 73) {
    index = index_change_func(index);
    result = buffer[index]; // FLAW
  }

  delete cl_var1;
  delete cl_var2;

  return;
}
