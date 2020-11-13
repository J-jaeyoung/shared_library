#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include <sys/utsname.h>

int main() {
    char buf[80];
    struct utsname uts = {};
    uname(&uts);
    printf("%s\n",uts.nodename);
    mkdir(uts.nodename, 0755);
}
