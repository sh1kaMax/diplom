// Авторы теста: ИСП РАН
// CWE: 129
// Название: Basic improper validation of array index
// Модельный вариант: basic.json
//
// Чтение данных от пользователя с помощью функции scanf.
// Использование прочитанного значения без проверки в качестве индекса для
// чтения элемента массива фиксированного размера.
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdio.h>
#include <stdlib.h>

int store;

class ExceptionClass {};

void func(void) {
  int index = 0, array[5] = {0, 1, 2, 3, 4};

  try {
    scanf("%d", &index);
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    store = array[index]; // FLAW
  }
}
