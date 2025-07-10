#include <iostream>

struct IDs
{
    unsigned short manufactureId;
    unsigned int productId;
};

union DeviceId
{
    unsigned char byteArray[6];
    IDs id;
};

int main()
{

    DeviceId dId;

    dId.id.manufactureId = 1001;
    dId.id.productId = 23456;

    for (int i = 0; i < 6; i++)
    {
        std::cout << (int)dId.byteArray[i] << std::endl;
    }
}