#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool doesValidArrayExist(vector<int> &derived)
{
    int total = 0;
    for (int &a : derived)
        total = total ^ a;
    return total == 0;
}

int main()
{
    vector<int> nums1 = {1, 0, 1};
    cout << doesValidArrayExist(nums1);
    return 0;
}