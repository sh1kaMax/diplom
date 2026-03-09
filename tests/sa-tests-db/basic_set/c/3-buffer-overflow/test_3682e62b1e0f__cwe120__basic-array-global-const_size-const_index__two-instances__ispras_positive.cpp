// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: basic-array-global-const_size-const_index.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется непосредственно (с помощью операции
// индексации). Индекс является константой.
//
// Поточный вариант: two-instances.cpp
// Тест содержит 2 экземпляра одного класса. Путь от источника до стока зависит
// от вызова функции одного из экземпляров.

#include <stdlib.h>

int buffer[32];

class SomeClass {
  int member1;

public:
  SomeClass(int ctor_par) : member1(ctor_par) {}

  int getVal() { return member1; }
};

void func(void) {
  int result = 0;
  unsigned int index = 0;

  SomeClass *cl_var1 = new SomeClass(17);
  SomeClass *cl_var2 = new SomeClass(-93);

  index = 32;

  if (cl_var1->getVal() > 14) {
    result = buffer[index]; // FLAW
  }

  delete cl_var1;
  delete cl_var2;

  return;
}
