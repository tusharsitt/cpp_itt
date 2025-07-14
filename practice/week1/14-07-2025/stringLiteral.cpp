#include <iostream>

// here you can return, cause the "hello" will be stored in the static duration
const char *getStringLiteral()
{
    const char *s = "hello";
    return s;
}

// you can't return here, cause c-style string decays and the
// actual string object also, will go out of scope.
char *getStringButDifferent()
{
    char s[]{"stringThePowerHouse"};
    return s;
}

char *getStaticString()
{
    static char s[]{"staticString"};
    return s;
}

int main()
{

    const char *s = getStringLiteral();
    const char *s2 = getStringLiteral();

    // return same string literal, cause of string pooling
    // string literal have "const char *" type and have
    // static storage duration.
    std::cout << (s == s2) << std::endl;

    // char *stringModified1 = getStringButDifferent();
    // char *stringModified2 = getStringButDifferent();

    // stringModified1[0] = 'J';
    // std::cout << stringModified1 << std::endl;
    // std::cout << stringModified2 << std::endl;

    char *staticString1 = getStaticString();
    char *staticString2 = getStaticString();

    staticString1[0] = 'J';
    // Here both will be modified, cause pointing to the same literal stored
    // in the static scope.
    std::cout << staticString1 << std::endl;
    std::cout << staticString2 << std::endl;
}
