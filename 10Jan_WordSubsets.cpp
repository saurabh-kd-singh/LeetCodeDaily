#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
{
    vector<string> answer;
    vector<int> word2CharacterMap(26, 0);

    for (string word2 : words2)
    {
        vector<int> word2CharacterMapLocal(26, 0);
        for (char c : word2)
        {
            word2CharacterMapLocal[c - 'a']++;
            if (word2CharacterMapLocal[c - 'a'] > word2CharacterMap[c - 'a'])
            {
                word2CharacterMap[c - 'a'] = word2CharacterMapLocal[c - 'a'];
            }
        }
    }

    for (string word1 : words1)
    {
        bool valid = true;
        vector<int> word1CharacterMap(26, 0);
        for (char c : word1)
        {
            word1CharacterMap[c - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (word2CharacterMap[i] > word1CharacterMap[i])
            {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            answer.push_back(word1);
        }
    }
    return answer;
}

int main()
{
    vector<string> words1 = {"amazon","apple","facebook","google","leetcode"};
    vector<string> words2 = {"e","o"};
    vector<string> answer = wordSubsets(words1, words2);

    for(string word : answer) {
        cout << word << " ";
    }

    return 0;
}