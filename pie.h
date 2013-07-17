/* 
 * File:   pie.h
 * Author: nautical
 *
 * Created on 17 July, 2013, 4:53 PM
 */

#ifndef PIE_H
#define	PIE_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#define main int main(int argc,char**argv)
#define ln printf("------> %d \n",__LINE__);fflush(stdout);
#define br printf("---------\n");fflush(stdout);
#define Max_ITEMS() 6, 5, 4, 3, 2, 1, 0 
#define __VA_ARG_N(_1, _2, _3, _4, _5, _6, N, ...) N
#define _Num_ARGS_(...) __VA_ARG_N(__VA_ARGS__) 
#define NUM_ARGS(...) (_Num_ARGS_(_0, ## __VA_ARGS__, Max_ITEMS()) - 1) 
#define CHECK_ARGS_MAX_LIMIT(t) if(NUM_ARGS(args)>t)
#define CHECK_ARGS_MIN_LIMIT(t) if(NUM_ARGS(args) 
#define TYPEOF(A) (A.type)
#define __GET_DATA__(A) (A.data)
#define I (int)
#define C (char*)
#define getI_(A) \
({ \
int i; \
i = (int)A.data; \
i ; \
}) 
#define getC_(A) \
({ \
char *i; \
i = (char*)A.data; \
i ; \
}) 
#define getI(A,K) \
({ \
int i; \
i = (int)((int*)(A.data))[K]; \
i ; \
}) 
#define getC(A,K) \
({ \
char* i; \
i = (char*)((char**)A.data)[K]; \
i ; \
}) 

    typedef struct {
        void *data;
        int type; // 0 for int , 1 for char , 2 for list of int , 3 for list of char
    } var;

    var _intCB(int number, int a, ...) {
        var ret_;
        if (number == 0) {
            ret_.data = (void*) a;
            ret_.type = 0;
        } else {
            int* arr = calloc(number + 1, sizeof (int));
            va_list arguments;
            va_start(arguments, number);
            int x;
            arr[0] = a;
            for (x = 1; x <= number; x++) {
                arr[x] = va_arg(arguments, int);
            }
            va_end(arguments);
            ret_.data = arr;
            ret_.type = 2;
        }
        return ret_;
    }

    var _chrCB(int number, char *buff, ...) {
        var ret_;
        if (number == 0) {
            ret_.data = (void*) buff;
            ret_.type = 1;
        } else {
            char** arr = calloc(number + 1, sizeof (char*));
            va_list arguments;
            va_start(arguments, number);
            arr[0] = buff;
            int x = 0;
            for (x = 1; x <= number; x++) {
                arr[x] = va_arg(arguments, char*);
            }
            va_end(arguments);
            ret_.data = arr;
            ret_.type = 3;
        }
        return ret_;
    }

#define data(x , args ...) \
({ \
var num; \
if (__builtin_types_compatible_p (typeof (x), int)) \
num = _intCB(NUM_ARGS(args),x, ##args); \
else \
num = _chrCB (NUM_ARGS(args),x,##args); \
num; \
})

    void *getI_data(var A, int num, ...) {
        va_list arguments;
        va_start(arguments, num);
        int position;
        position = va_arg(arguments, int);
        return (void*)getI(A, position);
    }

    void *getC_data(var A, int num, ...) {
        va_list arguments;
        va_start(arguments, num);
        int position;
        position = va_arg(arguments, int);
        return (void*)getC(A, position);
    }

#define get(A,args ...) \
({ \
void *data; \
if(A.type==0) \
data = getI_(A); \
if(A.type==1) \
data = getC_(A); \
if(A.type==2) \
data = getI_data(A,NUM_ARGS(args) ,##args); \
if(A.type==3) \
data = getC_data(A,NUM_ARGS(args) ,##args); \
data; \
})

#ifdef	__cplusplus
}
#endif

#endif	/* PIE_H */

