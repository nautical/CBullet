CBullet
=======

A small play to see if we can make C look good .


Our Little Variable
===================

var value;

Single Value(int)
============
value = data(100);
printf("%d\n", get(value));


Multiple Values(int)
===============
value = data(0, 2, 3, 4, 5, 6);
printf("%d\n", get(value, 0));
printf("%d\n", get(value, 1));
...
printf("%d\n", get(value, 5));


Single Value(char)
==================
value = data("single");
printf("%s\n", get(value));

Multiple Values(char)
======================
value = data("hello", "bye", "test");
printf("%s\n", get(value, 0));
printf("%s\n", get(value, 1));
printf("%s\n", get(value, 2));
