// Авторы теста: ИСП РАН
// CWE: 120
// Название: Buffer Overflow
// Модельный вариант: false-array-static-const_size-const_index-memset.json
//
// Чтение за правой границей буфера.
// Буфер выделен в статической памяти.
// Буфер является обычным массивом.
// Размер буфера является константой.
// Доступ к буферу осуществляется через вызов стандартной функции заполнения
// блока памяти memset. Индекс является константой.
//
// Поточный вариант: ternary-inverted.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними с помощью тернарного оператора, выполнение не достигает
// стока в случае истинности проверки.

#include <stdlib.h>
#include <string.h>

int result = 0;
int buffer[34];
void use_mem_to_keep_memset(int *);

void func(void) {
  unsigned int index = 0;

  int var;

  index = 34 + 1;

  var = (index > 34 ? 0 : 1);

  if (var) {
    memset(buffer, 0, index * sizeof(int));
    use_mem_to_keep_memset(buffer);
  }

  return;
}
