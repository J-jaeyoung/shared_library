#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char buf[80];
    gethostname(buf,sizeof(buf));
    mkdir(buf, 0755);
}
