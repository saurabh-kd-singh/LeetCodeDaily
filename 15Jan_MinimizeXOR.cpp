#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int minimizeXor(int num1, int num2)
{
    int a = __builtin_popcount(num1);
    int b = __builtin_popcount(num2);
    int res = num1;
    for (int i = 0; i < 32; ++i)
    {
        if ((a > b) && ((1 << i) & num1))
        {
            res = res ^ (1 << i);
            --a;
        }
        if ((a < b) && !((1 << i) & num1))
        {
            res = res ^ (1 << i);
            --b;
        }
    }
    return res;
}

int main()
{
    cout << minimizeXor(3, 5);
    return 0;
}