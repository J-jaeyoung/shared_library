#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stddef.h>
#include <sys/mount.h>
#include <stdio.h>
void XXXXX(){}
//
//
//
void __attribute__((constructor)) exploit(){
    printf("constructor - A.c\n");
    return;
}
void __XXXXX()
{
    printf("XXXXX\n");
//    YYYYY();
}
void __attribute__((destructor)) exploit__(){
    printf("destructor - A.c\n");
    return;
}
