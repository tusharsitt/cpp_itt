
void passByRef(int &b)
{
}

void passByPointer(int *c)
{
}

void passByValue(int d) {}

int main()
{

    int a = 34;
    //     int &b = a;

    //     int second =45;
    // b = second;

    // int *ptr = &a;

    passByPointer(&a);
    passByRef(a);
    passByValue(a);
}