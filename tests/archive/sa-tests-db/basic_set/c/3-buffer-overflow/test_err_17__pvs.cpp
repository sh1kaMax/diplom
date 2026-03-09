/*
Тест предложен командой разработчиков ООО "ПВС" (PVS-Studio), 2025
Примеры ошибок, классифицируемых как критические, согласно ГОСТ Р 71207—2024.
  6.3. в) Ошибки переполнения буфера (записи или чтения за пределами выделенной для буфера памяти).

Вариант потока управления, согласно ГОСТ Р 71207—2024 (пункты 6.7 а и 6.7.1 а):
 6.7. a) 1) прямолинейный участок кода;
Вариант потока данных, согласно ГОСТ Р 71207—2024 (пункты 6.7 б и 6.7.1 б):
 6.7. б) 1) поток данных заключен полностью в одной функции;

Детектор PVS-Studio: V557. Possible array overrun.
Документация: https://pvs-studio.ru/ru/docs/warnings/v557/
Примеры ошибок, найденные этим детектором: https://pvs-studio.ru/ru/blog/examples/v557/
*/

#include <iostream>
#include <array>

typedef enum {
  GDK_MEMORY_B8G8R8A8_PREMULTIPLIED,
  GDK_MEMORY_A8R8G8B8_PREMULTIPLIED,
  GDK_MEMORY_R8G8B8A8_PREMULTIPLIED,
  GDK_MEMORY_B8G8R8A8,
  GDK_MEMORY_A8R8G8B8,
  GDK_MEMORY_R8G8B8A8,
  GDK_MEMORY_A8B8G8R8,
  GDK_MEMORY_R8G8B8,
  GDK_MEMORY_B8G8R8,
  GDK_MEMORY_R16G16B16,
  GDK_MEMORY_R16G16B16A16_PREMULTIPLIED,
  GDK_MEMORY_R16G16B16A16,
  GDK_MEMORY_R16G16B16_FLOAT,
  GDK_MEMORY_R16G16B16A16_FLOAT_PREMULTIPLIED,
  GDK_MEMORY_R16G16B16A16_FLOAT,
  GDK_MEMORY_R32G32B32_FLOAT,
  GDK_MEMORY_R32G32B32A32_FLOAT_PREMULTIPLIED,
  GDK_MEMORY_R32G32B32A32_FLOAT,
  GDK_MEMORY_G8A8_PREMULTIPLIED,
  GDK_AVAILABLE_ENUMERATOR_IN_4_12,
  GDK_MEMORY_N_FORMATS
} GdkMemoryFormat;

const char *format_name[] = {
  "BGRAp", "ARGBp", "RGBAp",
  "BGRA", "ARGB", "RGBA", "ABGR",
  "RGB", "BGR", NULL
};

const char *format_to_string_err(GdkMemoryFormat format)
{
  if (format < GDK_MEMORY_N_FORMATS)
    return format_name[format]; // FLAW
  else
    return "ERROR";
}