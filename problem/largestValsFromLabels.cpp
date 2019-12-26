#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>
#include <algorithm>
using namespace std;

class Solution
{
private:
    //struct cmp
    //{
    //    bool operator()(pair<int, int> left, pair<int, int> right)
    //    {
    //        return left.first < right.first;
    //    }
    //};

    //public:
    //    int largestValsFromLabels(vector<int> &values, vector<int> &labels, int num_wanted, int use_limit)
    //    {
    //        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    //        int len = values.size();
    //        for (int i = 0; i < len; i++)
    //        {
    //            q.push({values[i], labels[i]});
    //        }
    //        unordered_map<int, int> m;
    //        int c = 0, sum = 0;
    //        while (c < num_wanted && !q.empty())
    //        {
    //            auto [val, lab] = q.top();
    //            if (m[lab] == use_limit)
    //            {
    //                q.pop();
    //                continue;
    //            }
    //            else
    //            {
    //                m[lab]++;
    //                sum += val;
    //                q.pop();
    //                c++;
    //            }
    //        }
    //        return sum;
    //    }

public:
    int largestValsFromLabels(vector<int> &values, vector<int> &labels, int num_wanted, int use_limit)
    {
        vector<pair<int, int>> q;
        int len = values.size();
        for (int i = 0; i < len; i++)
        {
            q.push_back({values[i], labels[i]});
        }
        sort(q.begin(), q.end(), greater<pair<int, int>>());
        unordered_map<int, int> m;
        int c = 0, sum = 0, i = 0;
        while (c < num_wanted && i < len)
        {
            auto [val, lab] = q[i];
            if (m[lab] == use_limit)
            {
                i++;
                continue;
            }
            else
            {
                m[lab]++;
                sum += val;
                i++;
                c++;
            }
        }
        return sum;
    }
};

int main()
{
    Solution solution;
    vector<int> v = {5, 4, 3, 2, 1}, l = {1, 1, 2, 2, 3};
    auto result = solution.largestValsFromLabels(v, l, 3, 1);
    cout << result;
}