#include <dlfcn.h>
#include "./myLibExtern/printExternShubham.h"

int main()
{

    void *handler = dlopen("./libmyLibExtern.so", RTLD_LAZY);

    void (*printShubhamHandler)() = (void (*)())dlsym(handler, "printShubham");

    printShubhamHandler();

    dlclose(handler);
}