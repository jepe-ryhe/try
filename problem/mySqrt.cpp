#include <iostream>
using namespace std;

class Solution {
public:
  int mySqrt(int x) {
    long r = x;
    while (r * r > x)
      r = (r + x / r) / 2;
    return (int)r;
  }
};

int main() {
  Solution solution;
  auto result = solution.mySqrt(8);
  cout << result;
}