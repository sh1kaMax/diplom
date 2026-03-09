// Авторы теста: ИСП РАН
// CWE: 415
// Название: Double Free
// Модельный вариант: double.json
//
// Память выделяется дважды с помощью стандартной функции malloc.
// Адреса ыыделенных блоков памяти сохраняются в двух локальных переменных.
// Один из блоков освобождается дважды.
//
// Поточный вариант: class-member-class.cpp
// Тест содержит 2 класса. Один из классов содержит указатель на другой класс.

#include <stdlib.h>

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
  int *pointer1 = NULL;
  int *pointer2 = NULL;
  int freed_flag = 0;

  Class1 *cl_var1 = new Class1(80);
  Class2 *cl_var2 = new Class2(29);

  pointer1 = (int *)malloc(18 * sizeof(int));
  pointer2 = (int *)malloc(18 * sizeof(int));
  free(pointer2);
  freed_flag = 1;

  cl_var1->setVal(-66);
  cl_var2->setVal(186);
  cl_var2->setVal(cl_var1);

  if (cl_var2->getVal2() < -63) {
    free(pointer1);
    free(pointer2); // FLAW
    pointer1 = NULL;
  }

  delete cl_var2;

  free(pointer1);
}
