#include <iostream>

void passByRef(int &ref)
{
}

void passByConstRef(const int &ref)
{
}

int main()
{

    int a = 43;

    // this will refer to a temporary implicity converted rvalue i.e 43,
    // cause const lvalue refernces can refer to the rvalue expressions.
    // so dref and a are independent and not refering to the same object.
    const double &cdref = a;

    // this will go for compilation error, umcomment and hover.
    // double &dref = a;

    a++;

    // this will print different values
    std::cout << a << std::endl;
    std::cout << cdref << std::endl;

    double nonConstV = 45.52;
    const double &constRef = nonConstV;

    // cant, cuz constRef is of type const, and const can;t be refed by nonConst type
    // double &nonConstRef = constRef;
    // but can
    double &nonConstRef = nonConstV;

    // can't do , cuz const type ref, but the refrent is non const, so can change that
    // constRef = 43;
    nonConstV = 44;

    // can be const ref only
    const float &reftoRvalue = 54;

    const int varrr = 43;
    double passingDob = 65.6;
    // will do compiler error, cuz the refrence is non-const type in function parameter,
    // and non-const type lvalue ref cant ref to rvalue, or const varibales
    // passByRef(34);
    // passByRef(varrr);
    // passByRef(passingDob);

    passByConstRef(passingDob);
}
