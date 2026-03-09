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
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  char name[1024];

  std::vector<int> vec(17, 0);

  int local_var1 = 12;
  int local_var2 = 87;
  int index1 = 7;
  int index2 = 9;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    scanf("%1023s", name);
  }

  if (local_var1 == vec[7]) {
    sethostname(name, sizeof(name)); // FLAW
  }
}
