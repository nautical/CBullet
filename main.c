#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "pie.h"

main {
    var value;

    value = data(100);
    printf("%d\n", get(value));

    value = data(0, 2, 3, 4, 5, 6);
    printf("%d\n", get(value, 0));
    printf("%d\n", get(value, 1));
    printf("%d\n", get(value, 2));
    printf("%d\n", get(value, 3));
    printf("%d\n", get(value, 4));
    printf("%d\n", get(value, 5));

    value = data("single");
    printf("%s\n", get(value));

    value = data("hello", "bye", "test");
    printf("%s\n", get(value, 0));
    printf("%s\n", get(value, 1));
    printf("%s\n", get(value, 2));

    return 0;
}