#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int candy(vector<int> &ratings) {
    vector<int> candies(ratings.size(), -1);
    vector<int> valley;
    for (int i = 0; i < ratings.size(); ++i) {
      if ((i == 0 || ratings[i - 1] >= ratings[i]) &&
          (i == ratings.size() - 1 || ratings[i + 1] >= ratings[i])) {
        candies[i] = 1;
        valley.push_back(i);
      }
    }
    for (int i = 0; i < valley.size(); ++i) {
      int ptr1 = valley[i] - 1;
      int ptr2 = valley[i] + 1;
      int cur = 1;
      while (ptr1 >= 0 && ratings[ptr1] > ratings[ptr1 + 1] &&
             candies[ptr1] < cur + 1)
        candies[ptr1--] = ++cur;
      cur = 1;
      while (ptr2 < ratings.size() && ratings[ptr2] > ratings[ptr2 - 1] &&
             candies[ptr2] < cur + 1)
        candies[ptr2++] = ++cur;
    }
    int result = 0;
    for (int &i : candies)
      result += i;
    return result;
  }
};

// class Solution
//{
// public:
//    int candy(vector<int> &ratings)
//    {
//        if (ratings.empty())
//            return 0;
//        int size = ratings.size();
//        int candies = 1;
//        int sum = 1;
//        int max = 0;
//        int downIndex = 0;
//        for (int i = 1; i < size; i++)
//        {
//            if (ratings[i] < ratings[i - 1])
//            {
//                if (downIndex == 0)
//                {
//                    max = candies;
//                    downIndex = i;
//                }
//                candies = 1;
//                sum += i - downIndex;
//                if (i - downIndex + 1 >= max)
//                    sum += 1;
//            }
//            else if (ratings[i] > ratings[i - 1])
//            {
//                downIndex = 0;
//                candies += 1;
//            }
//            else
//            {
//                downIndex = 0;
//                candies = 1;
//            }
//            sum += candies;
//        }
//        return sum;
//    }
//};

int main() {
  Solution solution;
  vector<int> r = {1, 3, 2, 2, 1};
  auto result = solution.candy(r);
  cout << result;
}