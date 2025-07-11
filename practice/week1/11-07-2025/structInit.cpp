#include <iostream>

// pragma is a preprcossor directive, here its telling compiler to not
// apply any padding to the struct Foo, or more specifically set 1-byte aligment
// for each data type, instead of their multiple
#pragma pack(1)
struct Foo
{
    int a{};
    int b{};
    int c{};
};
#pragma pack()

struct NoDefaultInit
{
    int a;
    long b;
};

// underlying type is long for the enum here
enum ActiveElement : long
{

    noneActive,
    steveIsActive,
    rdjIsActive,
    clintIsActive

};

struct StructWithUnion
{

    ActiveElement activeUnionMember;
    union
    {
        long steve;
        int rdj;
        double clint;
    } aveneger;
};

std::ostream &operator<<(std::ostream &out, const Foo &f)
{
    out << f.a << ' ' << f.b << ' ' << f.c;
    return out;
}

std::ostream &operator<<(std::ostream &out, const NoDefaultInit &f)
{
    out << f.a << ' ' << f.b;
    return out;
}

int main()
{
    Foo foo{1, 2, 3};

    Foo x = foo; // copy-initialization
    Foo y(foo);  // direct-initialization
    Foo z{foo};  // direct-list-initialization

    Foo listInit{3, 54, 53};

    x = {432, 54, 6};

    std::cout << x << '\n';
    std::cout << y << '\n';
    std::cout << z << '\n';
    std::cout << listInit << std::endl;

    NoDefaultInit st;
    std::cout << st << '\n';

    StructWithUnion avngStruct;
    avngStruct.activeUnionMember = steveIsActive;
    avngStruct.aveneger.steve = 34343;

    std::cout << "Size of StructWithUnion: " << sizeof(avngStruct) << std::endl;

    return 0;
}