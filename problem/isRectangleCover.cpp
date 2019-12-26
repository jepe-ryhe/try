#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
    //private:
    //    struct cmp
    //    {
    //        bool operator()(vector<int> l, vector<int> r)
    //        {
    //            return (l[1] > r[1]) || (l[1] == r[1]) && (l[0] > r[0]);
    //        }
    //    };
    //
    //public:
    //    bool isRectangleCover(vector<vector<int>> &rectangles)
    //    {
    //        int len = rectangles.size();
    //        if (len == 1)
    //            return true;
    //        priority_queue<vector<int>, vector<vector<int>>, cmp> q(rectangles.begin(), rectangles.end());
    //        vector<int> h;
    //        for (int i = 0; i < q.top()[0]; i++)
    //        {
    //            h.push_back(0);
    //        }
    //        for (int i = 0; i < len; i++)
    //        {
    //            vector<int> p = q.top();
    //            for (int t = p[0]; t < p[2]; t++)
    //            {
    //                if (t == h.size())
    //                {
    //                    h.push_back(p[3]);
    //                }
    //                else if (t > h.size())
    //                {
    //                    return false;
    //                }
    //                else
    //                {
    //                    if (h[t] < p[1] || h[t] > p[1])
    //                    {
    //                        return false;
    //                    }
    //                    h[t] = p[3];
    //                }
    //            }
    //            for_each(p.begin(), p.end(), [](int i) { cout << i << ' '; });
    //            cout << endl;
    //            for_each(h.begin(), h.end(), [](int i) { cout << i << ' '; });
    //            cout << endl;
    //            q.pop();
    //        }
    //        int mh = 0;
    //        for (int i = 0; i < h.size(); i++)
    //        {
    //            if (h[i] != 0 && mh != 0)
    //            {
    //                if (h[i] != mh)
    //                    return false;
    //            }
    //            mh = h[i];
    //        }
    //        return true;
    //    }
};

int main()
{
    Solution solution;
    vector<vector<int>> r = {{0, 0, 4, 1}, {7, 0, 8, 2}, {6, 2, 8, 3}, {5, 1, 6, 3}, {4, 0, 5, 1}, {6, 0, 7, 2}, {4, 2, 5, 3}, {2, 1, 4, 3}, {0, 1, 2, 2}, {0, 2, 2, 3}, {4, 1, 5, 2}, {5, 0, 6, 1}};
    //auto result = solution.isRectangleCover(r);
    //cout << result;
}