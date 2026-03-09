/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.5. в) ошибки управления динамической памятью (выделения, освобождения, использования освобожденной памяти).

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V726. Attempt to free memory containing the 'int A[10]' array by using the 'free(A)' function.
Документация: https://pvs-studio.ru/ru/docs/warnings/v726/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v726/
*/

#include <iostream>
#include <cstdlib>
#include <cstring>

void Ok8(bool b, char *src)
{
    char buf[512];
    char* message_buf = buf;

    if (src == nullptr || b)
    {
        strcpy(buf, "aaa");
    }
    else
    {
        message_buf = src;
    }
    if (message_buf != buf)
    {
        std::free(message_buf);
    }
}