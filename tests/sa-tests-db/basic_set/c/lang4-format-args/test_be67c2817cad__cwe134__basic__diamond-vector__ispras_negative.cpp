// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: diamond-vector.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// содержимого slt vector.

#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

class SomeClass {
public:
  void func(void);
};

void SomeClass::func(void) {
  char format[68] = "Initial format string";

  std::vector<int> vec(78, 0);

  int local_var1 = 96;
  int local_var2 = 147;
  int index1 = 12;
  int index2 = 77;

  vec[index1] = local_var1;
  vec[index2] = local_var2;

  if (local_var1 == vec[index1]) {
    scanf("%67s", format);
  }

  if (local_var1 == vec[77]) {
    printf(format);
  }
}
