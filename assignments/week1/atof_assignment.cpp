#include <iostream>
#include <string>
#include <cmath>

using std::string;

bool atofAcceptableChar(char ch)
{
    return ch == 'e' || ch == 'E' || ((int)ch >= 48 && (int)ch <= 57) || ch == '-' || ch == '+' || ch == '.';
}

int parseWhitespaces(string numberString, int &index, int length)
{

    while (index < length && numberString[index] == ' ')
        index++;

    if (index == length)
        return -1;

    return 0;
}

int parseNumberSign(string numberString, int &index, int length, bool &isPositive)
{

    if (index < length)
    {
        if (numberString[index] == '+')
        {
            index++;
        }
        else if (numberString[index] == '-')
        {
            isPositive = false;
            index++;
        }
    }

    return 0;
}

int parseWholePart(string numberString, int &index, int length, double &wholePart)
{

    while (index < length)
    {

        if (numberString[index] == '.' || numberString[index] == 'e' || numberString[index] == 'E')
        {
            return 0;
        }
        else if (numberString[index] >= '0' && numberString[index] <= '9')
        {
            wholePart = wholePart * 10 + (numberString[index] - '0');
            index++;
        }
        else
        {
            return -1;
        }
    }

    return 0;
}

int parseDecimalPoint(string numberString, int &index, int length, bool &hasDecimalPoint)
{
    if (index < length && numberString[index] == '.')
    {
        hasDecimalPoint = true;
        index++;
    }
    return 0;
}

int parseFractionalPart(string numberString, int &index, int length, double &fractionalPart)
{

    while (index < length)
    {

        if (numberString[index] == 'e' || numberString[index] == 'E')
        {
            return 0;
        }
        else if (numberString[index] >= '0' && numberString[index] <= '9')
        {
            fractionalPart = fractionalPart * 10 + (numberString[index] - '0');
            index++;
        }
        else
        {
            return -1;
        }
    }

    return 0;
}

int parseHasExponent(string numberString, int &index, int length, bool &hasExponent)
{
    if (index < length && (numberString[index] == 'e' || numberString[index] == 'E'))
    {
        hasExponent = true;
        index++;
    }
    return 0;
}

int parseExponentSign(string numberString, int &index, int length, bool &hasPostiveExponent)
{
    if (index < length)
    {
        if (numberString[index] == '+')
        {
            index++;
        }
        else if (numberString[index] == '-')
        {
            hasPostiveExponent = false;
            index++;
        }
    }

    return 0;
}

int parseExponent(string numberString, int &index, int length, double &exponent)
{

    while (index < length)
    {

        if (numberString[index] >= '0' && numberString[index] <= '9')
        {
            exponent = exponent * 10 + (numberString[index] - '0');
            index++;
        }
        else
        {
            return -1;
        }
    }

    return 0;
}

double calcParsedDouble(double wholePart, double fractionalPart, double exponent, bool hasDecimalPoint, bool hasExponent, bool isPositive, bool hasPositiveExponent)
{

    double parsedDouble{0};

    if (hasExponent)
    {
        if (fractionalPart == 0)
        {
            if (hasPositiveExponent)
            {
                parsedDouble = wholePart * (pow(10, exponent));
            }
            else
                parsedDouble = wholePart / (pow(10, exponent));
        }
        else
        {
            std::string ss = std::to_string((int)fractionalPart);
            int fractionalPartLength = ss.length();

            if (hasPositiveExponent)
            {
                exponent -= fractionalPartLength;
            }
            else
                exponent += fractionalPartLength;

            wholePart = (wholePart * (pow(10, fractionalPartLength))) + fractionalPart;

            if (hasPositiveExponent)
            {
                return parsedDouble = wholePart * (pow(10, exponent));
            }
            else
                parsedDouble = wholePart / (pow(10, exponent));
        }
    }
    else
    {
        std::string ss = std::to_string((int)fractionalPart);
        int fractionalPartLength = ss.length();

        parsedDouble = wholePart + (fractionalPart / pow(10, fractionalPartLength));
    }

    if (!isPositive)
        return -1 * parsedDouble;
    else
        return parsedDouble;
}

double customAtof(string numberString)
{
    double wholePart{0};
    double fractionalPart{0};
    double exponent{0};

    bool hasDecimalPoint = false;
    bool hasExponent = false;
    bool isPositive = true;
    bool hasPostiveExponent = true;

    int length = numberString.length();

    int index = 0;

    // parsing whitespaces
    int parseWhitespacesResutl = parseWhitespaces(numberString, index, length);
    if (parseWhitespacesResutl == -1)
        return 0;

    // parsing initial sign
    parseNumberSign(numberString, index, length, isPositive);

    int parseWholePartResult = parseWholePart(numberString, index, length, wholePart);

    if (parseWholePartResult == -1)
    {
        // Implement this
        return calcParsedDouble(wholePart, fractionalPart, exponent, hasDecimalPoint, hasExponent, isPositive, hasPostiveExponent);
    }

    parseDecimalPoint(numberString, index, length, hasDecimalPoint);

    int parseFractionalPartResult = parseFractionalPart(numberString, index, length, fractionalPart);
    if (parseFractionalPartResult == -1)
    {

        // Implement this
        return calcParsedDouble(wholePart, fractionalPart, exponent, hasDecimalPoint, hasExponent, isPositive, hasPostiveExponent);
    }

    parseHasExponent(numberString, index, length, hasExponent);

    parseExponentSign(numberString, index, length, hasPostiveExponent);

    int parseExponentResult = parseExponent(numberString, index, length, exponent);

    return calcParsedDouble(wholePart, fractionalPart, exponent, hasDecimalPoint, hasExponent, isPositive, hasPostiveExponent);
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