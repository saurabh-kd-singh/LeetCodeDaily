#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool canConstruct(string s, int k) {
        if (s.length() < k) return false;

        sort(s.begin(), s.end());
        int oddCount = 0;

        for (int i = 0; i < s.length(); ) {
            char current = s[i];
            int count = 0;
            while (i < s.length() && s[i] == current) {
                count++;
                i++;
            }
            if (count % 2 != 0) oddCount++;
        }

        return oddCount <= k;
    }

int main()
{
   string s = "annabelle";
   int k = 2;
   cout << canConstruct(s,k);

    return 0;
}