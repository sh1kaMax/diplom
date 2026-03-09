// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: basic-array-auto-tainted_size-tainted_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в автоматической памяти.
// Буфер является обычным массивом.
// Размер буфера получен от пользователя.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс получен от пользователя.
//
// Поточный вариант: class-member-class.cpp
// Тест содержит 2 класса. Один из классов содержит указатель на другой класс.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

class Class1 {
  int member1;

public:
  Class1(int ctor_par) : member1(ctor_par) {}

  void setVal(int set_val_par) { member1 = set_val_par; }

  int getVal() { return member1; }
};

class Class2 {
  int member1;
  Class1 *member2;

public:
  Class2(int ctor_par) : member1(ctor_par) { member2 = new Class1(ctor_par); }

  ~Class2() { delete member2; }

  void setVal(int set_val_par) { member1 = set_val_par; }

  void setVal(Class1 *set_val_par) {
    delete member2;
    member2 = set_val_par;
  }

  int getVal1() { return member1; }

  int getVal2() { return member2->getVal(); }
};

void func(void) {
  unsigned int size;
  scanf("%u", &size);
  int buffer[size];
  int result = 0;
  unsigned int index = 0;

  Class1 *cl_var1 = new Class1(17);
  Class2 *cl_var2 = new Class2(19);

  scanf("%u", &index);

  cl_var1->setVal(0);
  cl_var2->setVal(122);
  cl_var2->setVal(cl_var1);

  if (cl_var2->getVal2() < 5) {
    memset(buffer, 0, index * sizeof(int)); // FLAW
    use_mem_to_keep_memset(buffer);
  }

  delete cl_var2;

  return;
}
