#include <dlfcn.h>
#include <stdio.h>
int main(){
    void *handle = 0;
    handle = dlopen("./A.so", RTLD_LAZY);

    if(!handle){
        printf("Error!\n");
        return 0;
    }
    printf("Success\n");
}