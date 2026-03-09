/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.3. б) Ошибки целочисленного переполнения и некорректного совместного использования знаковых и беззнаковых чисел.

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V1083. Signed integer overflow in arithmetic expression. This leads to undefined behavior.
Документация: https://pvs-studio.ru/ru/docs/warnings/v1083/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v1083/
*/

#include <iostream>

class ClassErr4
{
    enum
    {
        MAX_WIDTH = (1 << 24),
        MAX_HEIGHT = (1 << 24),
        MAX_PIXELS = 268435456
    };

    bool initialize_data(int p_width, int p_height)
    {
        if (p_width > MAX_WIDTH) return false;
        if (p_height > MAX_HEIGHT) return false;
        if (p_width * p_height > MAX_PIXELS) return false; // FLAW
        return true;
    }
};