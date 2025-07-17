void add(int a, int b)
{
    int c = a + b;
}

void add(int a, float b)
{
    float c = a + b;
}

int main()
{
    add(23, 6);
    add(23, 56.4f);
}