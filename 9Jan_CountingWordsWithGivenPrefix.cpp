#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int prefixCount(vector<string> &words, string pref)
{
    int count = 0;
    for (const auto &word : words)
    {
        if (word.find(pref) == 0)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    vector<string> words = {"Hello", "Hi", "Apple", "Help", "Hen", "Hat"};
    int result = prefixCount(words, "He");
    cout << result;
    return 0;
}