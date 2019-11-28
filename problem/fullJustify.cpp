#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> res;
        int len = words.size();
        for (int i = 0; i < len;)
        {
            int l = 0, n = -1;
            while (l + n < maxWidth && i < len)
            {
                l += words[i].length();
                i++;
                n++;
            }
            if (l + n > maxWidth)
            {
                i--;
                n--;
                l -= words[i].length();
            }
            if (i != len)
            {
            }
        }
    }
};