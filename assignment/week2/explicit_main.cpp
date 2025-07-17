#include <iostream>
#include <limits>
#include <dlfcn.h>

struct Operands
{
    double operand1;
    double operand2;
};

void clearBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int inputOperationCode()
{

    int opCode{0};
    std::cout << "Select the operation to perform:" << '\n';
    std::cout << "1. Addition" << '\n';
    std::cout << "2. Subtraction" << '\n';
    std::cout << "3. Multiplication" << '\n';
    std::cout << "4. Division" << '\n';
    std::cout << "Enter your choice (1-4): ";

    std::cin >> opCode;

    while (std::cin.fail() || (opCode < 1 || opCode > 4))
    {

        clearBuffer();
        std::cout << "Enter the valid choice(1-4): ";
        std::cin >> opCode;
    }

    return opCode;
}

double inputOperand()
{
    double operand{0};
    std::cin >> operand;

    while (std::cin.fail())
    {
        clearBuffer();
        std::cout << "Enter a valid number: ";
        std::cin >> operand;
    }

    return operand;
}

void handleOperation(int opCode, Operands &operands, void *mathLibhandler)
{

    double result{0};
    switch (opCode)
    {
    case 1:
    {
        double (*add)(double, double) = (double (*)(double, double))dlsym(mathLibhandler, "add");
        if (add == NULL)
        {
            std::cout << "Error in accessing add funciton" << '\n';
        }
        else
        {
            std::cout << "Resut is: " << add(operands.operand1, operands.operand2) << '\n';
        }
        break;
    }

    case 2:
    {
        double (*subtract)(double, double) = (double (*)(double, double))dlsym(mathLibhandler, "subtract");
        if (subtract == NULL)
        {
            std::cout << "Error in accessing subtract funciton" << '\n';
        }
        else
        {
            std::cout << "Resut is: " << subtract(operands.operand1, operands.operand2) << '\n';
        }
        break;
    }

    case 3:
    {
        double (*multiple)(double, double) = (double (*)(double, double))dlsym(mathLibhandler, "multiple");
        if (multiple == NULL)
        {
            std::cout << "Error in accessing multiple funciton" << '\n';
        }
        else
        {
            std::cout << "Resut is: " << multiple(operands.operand1, operands.operand2) << '\n';
        }
        break;
    }

    case 4:
    {
        double (*divide)(double, double) = (double (*)(double, double))dlsym(mathLibhandler, "divide");
        if (divide == NULL)
        {
            std::cout << "Error in accessing divide funciton" << '\n';
        }
        else
        {
            std::cout << "Resut is: " << divide(operands.operand1, operands.operand2) << '\n';
        }
        break;
    }

    default:
        std::cout << "Something went wrong" << '\n';
        return;
    }
}

int main()
{

    void *mathLibhandler = dlopen("./lib/libdynamicMathLib.so", RTLD_LAZY);

    if (mathLibhandler == NULL)
    {
        std::cout << "Error in loading library" << '\n';
    }

    std::cout << "Welcome to the calculator: " << '\n';
    int opCode = inputOperationCode();

    Operands operands{0, 0};

    std::cout << "Enter first operand: ";
    operands.operand1 = inputOperand();

    std::cout << "Enter second operand: ";
    operands.operand2 = inputOperand();

    handleOperation(opCode, operands, mathLibhandler);

    dlclose(mathLibhandler);

    return 0;
}
