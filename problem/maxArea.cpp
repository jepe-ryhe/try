#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int result(0), left(0), right(height.size() - 1), size(height.size());
        while (left < right)
        {
            int tmp = min(height[left], height[right]) * (right - left);
            if (tmp > result)
                result = tmp;
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> h({1, 8, 6, 2, 5, 4, 8, 3, 7});
    auto result = solution.maxArea(h);
    cout << result;
}