#include <iostream>
#include <cmath>
#include "addition.h"
#include "multiplication.h"
#include "division.h"
#include "subtraction.h"

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

    while (std::cin.fail() || std::cin.peek() != '\n' || (opCode < 1 || opCode > 4))
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

double handleOperation(int opCode, Operands &operands)
{
    double result{0};

    switch (opCode)
    {
    case 1:
        result = add(operands.operand1, operands.operand2);
        break;

    case 2:
        result = subtract(operands.operand1, operands.operand2);
        break;

    case 3:
        result = multiply(operands.operand1, operands.operand2);
        break;

    case 4:
        result = divide(operands.operand1, operands.operand2);
        break;
    }

    return result;
}

int main()
{

    std::cout << "Welcome to the calculator: " << '\n';
    int opCode = inputOperationCode();

    Operands operands{0, 0};

    std::cout << "Enter first operand: ";
    operands.operand1 = inputOperand();

    std::cout << "Enter second operand: ";
    operands.operand2 = inputOperand();

    double result = handleOperation(opCode, operands);
    if (!std::isnan(result))
    {
        std::cout << "Result is: " << result << '\n';
    }

    return 0;
}
