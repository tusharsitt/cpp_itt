#include <iostream>
#include <string>
#include <cmath>

using std::string;

void parseWhitespaces(string &numberString, int &index, int length)
{

    while (index < length && numberString[index] == ' ')
        index++;
}

bool parseNumberSign(string &numberString, int &index, int length)
{

    if (index < length)
    {
        if (numberString[index] == '+')
        {
            index++;
        }
        else if (numberString[index] == '-')
        {

            index++;
            return false;
        }
    }

    return true;
}

int parseWholePart(string &numberString, int &index, int length)
{

    int wholePart{0};
    while (index < length && (numberString[index] >= '0' && numberString[index] <= '9'))
    {

        wholePart = wholePart * 10 + (numberString[index] - '0');
        index++;
    }

    return wholePart;
}

bool parseDecimalPoint(string &numberString, int &index, int length)
{
    if (index < length && numberString[index] == '.')
    {
        index++;
        return true;
    }
    return false;
}

int parseFractionalPart(string &numberString, int &index, int length, int &decimalPlaces)
{
    int fractionalPart{0};
    decimalPlaces = 0;

    while (index < length && numberString[index] >= '0' && numberString[index] <= '9')
    {
        fractionalPart = fractionalPart * 10 + (numberString[index] - '0');
        decimalPlaces++;
        index++;
    }

    return fractionalPart;
}

bool parseHasExponent(string &numberString, int &index, int length)
{
    if (index < length && (numberString[index] == 'e' || numberString[index] == 'E'))
    {
        index++;
        return true;
    }
    return false;
}

bool parseExponentSign(string &numberString, int &index, int length)
{
    if (index < length)
    {
        if (numberString[index] == '+')
        {
            index++;
        }
        else if (numberString[index] == '-')
        {
            index++;
            return false;
        }
    }

    return true;
}

int parseExponent(string &numberString, int &index, int length)
{

    int exponent{0};
    while (index < length && (numberString[index] >= '0' && numberString[index] <= '9'))
    {

        exponent = exponent * 10 + (numberString[index] - '0');
        index++;
    }

    return exponent;
}

double calcParsedDouble(int wholePart, int fractionalPart, int exponent, bool hasDecimalPoint, bool hasExponent, bool isPositive, bool hasPostivieExponent, int decimalPlaces)
{

    double parsedDouble{0};

    if (hasExponent)
    {

        if (!hasPostivieExponent)
            exponent *= -1;

        if (fractionalPart == 0)
        {
            parsedDouble = wholePart * (pow(10, exponent));
        }
        else
        {

            exponent -= decimalPlaces;

            wholePart = (wholePart * (pow(10, decimalPlaces))) + fractionalPart;

            parsedDouble = wholePart * (pow(10, exponent));
        }
    }
    else
    {

        parsedDouble = wholePart + (fractionalPart / pow(10, decimalPlaces));
    }

    if (!isPositive)
        return -1 * parsedDouble;
    else
        return parsedDouble;
}

double customAtof(string &numberString)
{
    int length = numberString.length();

    int index = 0;

    parseWhitespaces(numberString, index, length);
    if (index == length)
        return 0;

    bool isPositive = parseNumberSign(numberString, index, length);

    int wholePart = parseWholePart(numberString, index, length);

    bool hasDecimalPoint = parseDecimalPoint(numberString, index, length);

    int decimalPlaces{0};
    int fractionalPart = parseFractionalPart(numberString, index, length, decimalPlaces);

    bool hasExponent = parseHasExponent(numberString, index, length);

    bool hasPostivieExponent = parseExponentSign(numberString, index, length);

    int exponent = parseExponent(numberString, index, length);

    return calcParsedDouble(wholePart, fractionalPart, exponent, hasDecimalPoint, hasExponent, isPositive, hasPostivieExponent, decimalPlaces);
}

int main()
{

    string numberString;

    std::cout << "Enter the string to process: ";

    std::cin >> numberString;

    double parsedDoubleValue = customAtof(numberString);

    std::cout << "Final Parsed value: " << parsedDoubleValue << std::endl;

    return 0;
}