// Динамическое выделение памяти
// Динамическое выделение памяти позволяет программисту выделять память во время выполнения программы.
// Язык C предоставляет четыре функции из заголовочного файла <stdlib.h> для динамического выделения памяти, которые являются malloc(), calloc(), realloc() и free().
// 1. malloc()
// Функция malloc() выделяет блок определенного размера в памяти и возвращает указатель типа void, который можно привести к указателю любого типа.
// Она не инициализирует память во время выполнения, поэтому она инициализирует каждый блок значением мусора по умолчанию.
// Синтаксис malloc() в C
// ptr = (cast-type*) malloc (byte-size)
// Например:
// ptr = (int*) malloc (100 * sizeof (int));
// Поскольку размер int равен 4 байтам, это выражение выделит 400 байтов памяти.
// И указатель ptr будет хранить адрес первого байта в выделенной памяти.
// Если места недостаточно, выделение памяти не удастся и вернется нулевой указатель.
// Пример malloc() в C
#include <stdio.h>
#include <stdlib.h>
int main ()
{
int* ptr;
int n, i;
printf("Введите количество элементов: ");
scanf("%d", &n);
printf("Введенное количество элементов: %d\n", n);
ptr = (int*)malloc(n * sizeof(int));
if (ptr == NULL)
{
printf("Память не выделена.\n");
exit(0);
}
else
{
printf("Память успешно выделена с помощью malloc.\n");
for (i = 0; i < n; ++i)
{
ptr [i] = i + 1;
}
printf("Элементы массива: ");
for (i = 0; i < n; ++i)
{
printf("%d, ", ptr [i]);
}
}
return 0;
}
// Вывод
Введите количество элементов: 5
Введенное количество элементов: 5
Память успешно выделена с помощью malloc.
Элементы массива: 1, 2, 3, 4, 5,

// 2. calloc()
// Функция calloc() выделяет указанное количество блоков памяти заданного типа и возвращает указатель типа void, который можно привести к указателю любого типа.
// Она очень похожа на malloc(), но имеет две отличительные особенности:
// Она принимает два аргумента: количество блоков и размер каждого блока.
// Она инициализирует каждый блок значением 0.
// Синтаксис calloc() в C
// ptr = (cast-type*)calloc(n, element-size);
// Например:
// ptr = (float*)calloc(25, sizeof(float));
// Это выражение выделит последовательный блок памяти для 25 элементов типа float и инициализирует их нулями.
// Пример calloc() в C
#include <stdio.h>
#include <stdlib.h>
int main()
{
int* ptr;
int n, i;
printf("Введите количество элементов: ");
scanf("%d", &n);
printf("Введенное количество элементов: %d\n", n);
ptr = (int*)calloc(n, sizeof(int));
if (ptr == NULL)
{
printf("Память не выделена.\n");
exit(0);
}
else
{
printf("Память успешно выделена с помощью calloc.\n");
for (i = 0; i < n; ++i)
{
ptr [i] = i + 1;
}
printf("Элементы массива: ");
for (i = 0; i < n; ++i)
{
printf("%d, ", ptr [i]);
}
}
return 0;
}
// Вывод
Введите количество элементов: 5
Введенное количество элементов: 5
Память успешно выделена с помощью calloc.
Элементы массива: 1, 2, 3, 4, 5,

// 3. realloc()
// Функция realloc() изменяет размер ранее выделенного блока памяти и возвращает указатель на новый блок памяти.
// Она позволяет увеличивать или уменьшать размер выделенной памяти в зависимости от потребностей программы.
// Синтаксис realloc() в C
// ptr = realloc(ptr, x);
// Здесь ptr - это указатель на ранее выделенный блок памяти, а x - это новый размер блока в байтах.
// Пример realloc() в C
#include <stdio.h>
#include <stdlib.h>
int main()
{
int* ptr;
int n, i;
printf("Введите количество элементов: ");
scanf("%d", &n);
printf("Введенное количество элементов: %d\n", n);
ptr = (int*)malloc(n * sizeof(int));
if (ptr == NULL)
{
printf("Память не выделена.\n");
exit(0);
}
else
{
printf("Память успешно выделена с помощью malloc.\n");
for (i = 0; i < n; ++i)
{
ptr [i] = i + 1;
}
printf("Элементы массива: ");
for (i = 0; i < n; ++i)
{
printf("%d, ", ptr [i]);
}
}
printf("\nВведите новое количество элементов: ");
scanf("%d", &n);
printf("Введенное новое количество элементов: %d\n", n);
ptr = realloc(ptr, n * sizeof(int));
if (ptr == NULL)
{
printf("Память не выделена.\n");
exit(0);
}
else
{
printf("Память успешно перевыделена с помощью realloc.\n");
for (i = 0; i < n; ++i)
{
ptr [i] = i + 1;
}
printf("Элементы массива: ");
for (i = 0; i < n; ++i)
{
printf("%d, ", ptr [i]);
}
}
free(ptr);
return 0;
}
// Вывод
Введите количество элементов: 5
Введенное количество элементов: 5
Память успешно выделена с помощью malloc.
Элементы массива: 1, 2, 3, 4, 5,
Введите новое количество элементов: 10
Введенное новое количество элементов: 10
Память успешно перевыделена с помощью realloc.
Элементы массива: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,

// 4. free()
// Функция free() освобождает блок памяти, ранее выделенный с помощью malloc(), calloc() или realloc().
// Она принимает указатель на блок памяти, который нужно освободить, и возвращает void.
// Синтаксис free() в C
// free(ptr);
// Здесь ptr - это указатель на блок памяти, который нужно освободить.
// Пример free() в C
#include <stdio.h>
#include <stdlib.h>
int main()
{
int* ptr;
int n, i;
printf("Введите количество элементов: ");
scanf("%d",
