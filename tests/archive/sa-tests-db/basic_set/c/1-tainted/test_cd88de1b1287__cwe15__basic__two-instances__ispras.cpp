// Авторы теста: ИСП РАН
// CWE: 15
// Название: External control of system or configuration settings
// Модельный вариант: basic.json
//
// Источник загрязненного значения - пользовательский ввод
// Ошибка реализуется путем передачи загрязненного значения в вызов функции
// sethostname. (Ошибка может устраняться путем проверки загрязненного значения
// на соответствие безопасному значению или переопредением его на безопасное
// значение.)
//
// Поточный вариант: two-instances.cpp
// Тест содержит 2 экземпляра одного класса. Путь от источника до стока зависит
// от вызова функции одного из экземпляров.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

class SomeClass {
  int member1;

public:
  SomeClass(int ctor_par) : member1(ctor_par) {}

  int getVal() { return member1; }
};

void func(void) {
  char name[1024];

  SomeClass *cl_var1 = new SomeClass(67);
  SomeClass *cl_var2 = new SomeClass(-94);

  scanf("%1023s", name);

  if (cl_var1->getVal() > 60) {
    sethostname(name, sizeof(name)); // FLAW
  }

  delete cl_var1;
  delete cl_var2;
}
