#ifndef CONSTANTS_H
#define CONSTANTS_H

/* ------------------ Integer limits ------------------ */
/* signed char */
#define SCHAR_MIN  ((signed char) (-128))
#define SCHAR_MAX   ((signed char) 127)
/* unsigned char */
#define UCHAR_MAX   ((unsigned char) 255)

/* signed short */
#define SHRT_MIN    ((short) (-32768))
#define SHRT_MAX    ((short) 32767)
/* unsigned short */
#define USHRT_MAX   ((unsigned short) 65535U)

/* signed int */
#define INT_MIN     ((int) (-2147483648))
#define INT_MAX     ((int) 2147483647)
/* unsigned int */
#define UINT_MAX    4294967295U

/* signed long */
#define LONG_MIN    ((long) (-9223372036854775807L-1))
#define LONG_MAX    ((long) 9223372036854775807L)
/* unsigned long */
#define ULONG_MAX   ((unsigned long) 18446744073709551615UL)

/* signed long long */
#define LLONG_MIN   (-9223372036854775807LL-1)
#define LLONG_MAX   9223372036854775807LL
/* unsigned long long */
#define ULLONG_MAX  18446744073709551615ULL

/* ------------------ Size and pointer types ------------------ */
#define SIZE_MAX    18446744073709551615U
#define PTRDIFF_MIN (-9223372036854775807L-1)
#define PTRDIFF_MAX 9223372036854775807L

/* ------------------ Limits for char ------------------ */
#define CHAR_MIN    SCHAR_MIN
#define CHAR_MAX    SCHAR_MAX

#endif /* CONSTANTS_H */
