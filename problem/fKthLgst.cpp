#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
   int findKthLargest(vector<int> &nums, int k)
    {
        int result = 0;
        int numsSize = int(nums.size());
        if (numsSize == 0 || k > numsSize)
        {
            return 0;
        }
        //寻找第kMIN小的数
        int kMin = numsSize - k + 1;
        result = select(nums, 0, numsSize - 1, kMin);
        return result;
    }

    int select(vector<int> &nums, int left, int right, int target)
    {
        if (left == right)
        {
            return nums[left];
        }
        int cut = partition(nums, left, right);
        //当前第currentResult小的元素
        int currentResult = cut - left + 1;
        if (target == currentResult)
        {
            return nums[cut];
        }
        else if (target < currentResult)
        {
            return select(nums, left, cut - 1, target);
        }
        else
        {
            //寻找接下来第target - currentResult小的数
            return select(nums, cut + 1, right, target - currentResult);
        }
        return 0;
    }

    int partition(vector<int> &nums, int left, int right)
    {
        int cut = nums[right];
        //i指向大堆的最左边的数，j指向下一个判断的数
        int i = left;
        for (int j = left; j < right; j++)
        {
            if (nums[j] <= cut)
            {
                exchange(nums[i], nums[j]);
                i++;
            }
        }
        exchange(nums[i], nums[right]);
        return i;
    }

    void exchange(int &a, int &b)
    {
        int tmpInt = a;
        a = b;
        b = tmpInt;
        return;
    }
    //int findKthLargest(vector<int> &nums, int k)
    //{
    //    int result = 0;
    //    int size = nums.size();
    //    if (size == 0 || size < k)
    //        return 0;
    //    priority_queue<int, vector<int>, greater<int>> heap;
    //    for (auto &&i : nums)
    //    {
    //        heap.push(i);
    //        if (heap.size() > k)
    //            heap.pop();
    //    }
    //    return heap.top();
    //}
};

int main()
{
    Solution solution;
    vector<int> nums({3, 2, 1, 5, 6, 4});
    auto result = solution.findKthLargest(nums, 2);
    cout << result;
}