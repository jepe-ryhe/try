#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
    int zeroCheck[26];
    int visit[26];
    int nums[26];

    bool dfs(int curr, vector<int> &ch, int sum)
    {
        if (curr == ch.size())
        {
            return sum == 0;
        }
        for (int i = 0; i <= 9; ++i)
        {
            if (i == 0 && zeroCheck[ch[curr]])
            {
                continue;
            }
            if (visit[i])
            {
                continue;
            }
            visit[i] = 1;
            if (dfs(curr + 1, ch, sum + nums[ch[curr]] * i))
            {
                return true;
            }
            visit[i] = 0;
        }

        return false;
    }

    bool isSolvable(vector<string> &words, string result)
    {
        int n = result.size();
        int curr = 0;
        vector<int> ch;

        memset(zeroCheck, 0, sizeof(zeroCheck));
        memset(visit, 0, sizeof(visit));
        memset(nums, 0, sizeof(nums));

        for (auto w : words)
        {
            zeroCheck[w[0] - 'A'] = 1;
            reverse(w.begin(), w.end());
            curr = 1;
            for (auto &c : w)
            {
                nums[c - 'A'] += curr;
                curr = curr * 10;
            }
        }

        zeroCheck[result[0] - 'A'] = true;
        reverse(result.begin(), result.end());
        curr = 1;
        for (auto &c : result)
        {
            nums[c - 'A'] -= curr;
            curr = curr * 10;
        }
        for (int i = 0; i < 26; ++i)
        {
            if (nums[i] != 0)
            {
                ch.push_back(i);
            }
        }

        return dfs(0, ch, 0);
    }
};