#include <iostream>
#include <dlfcn.h>
#include <cmath>
#include <limits>

typedef double (*MathFunction)(double, double);

struct Operands
{
    double operand1;
    double operand2;
};

void clearBuffer()
{
    std::cin.clear();
    while (std::cin.get() != '\n')
        ;
}

bool isValidOpCode(char opCode)
{

    return (opCode == '+' || opCode == '-' || opCode == '*' || opCode == '/');
}

char inputOperationCode()
{

    char opCode{};
    std::cout << "Select the operation to perform:" << '\n';
    std::cout << "Addition (+)" << '\n';
    std::cout << "Subtraction (-)" << '\n';
    std::cout << "Multiplication (*)" << '\n';
    std::cout << "Division (/)" << '\n';
    std::cout << "Enter your choice: ";

    std::cin >> opCode;

    while (std::cin.fail() || std::cin.peek() != '\n' || !isValidOpCode(opCode))
    {

        clearBuffer();
        std::cout << "Enter the valid choice: ";
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

double callLibraryFunction(Operands &operands, void *mathLibHandler, const char *operationString)
{
    MathFunction operation = (MathFunction)dlsym(mathLibHandler, operationString);
    if (operation == nullptr)
    {
        std::cout << "Error in accessing funciton" << '\n';
        return std::numeric_limits<double>::quiet_NaN();
    }
    return operation(operands.operand1, operands.operand2);
}

double handleOperation(char opCode, Operands &operands, void *mathLibHandler)
{
    double result{0};
    switch (opCode)
    {
    case '+':
    {
        result = callLibraryFunction(operands, mathLibHandler, "add");
        break;
    }

    case '-':
    {
        result = callLibraryFunction(operands, mathLibHandler, "subtract");
        break;
    }

    case '*':
    {
        result = callLibraryFunction(operands, mathLibHandler, "multiply");
        break;
    }

    case '/':
    {
        result = callLibraryFunction(operands, mathLibHandler, "divide");
        break;
    }
    }
    return result;
}

int main()
{

    void *mathLibHandler = dlopen("libdynamicMathLib.so", RTLD_LAZY);

    if (mathLibHandler == nullptr)
    {
        std::cout << "Error in loading library" << '\n';
        return 0;
    }

    std::cout << "Welcome to the calculator: " << '\n';
    char opCode = inputOperationCode();

    Operands operands{0, 0};

    std::cout << "Enter first operand: ";
    operands.operand1 = inputOperand();

    std::cout << "Enter second operand: ";
    operands.operand2 = inputOperand();

    double result = handleOperation(opCode, operands, mathLibHandler);

    if (!std::isnan(result))
    {
        std::cout << "Result is: " << result << '\n';
    }

    dlclose(mathLibHandler);

    return 0;
}
