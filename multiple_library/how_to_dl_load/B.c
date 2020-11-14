#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stddef.h>
#include <sys/mount.h>
#include <stdio.h>
void __attribute__((constructor)) exploitB(){
    printf("constructor - B.c\n");
    return;
}
void _YYYYY()
{
    printf("YYYYY\n");
}
void __attribute__((destructor)) exploitBB__(){
    printf("destructor - B.c\n");
    return;
}
