#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    int l1 = s1.length(), l2 = s2.length();
    int sum = 0, c = 1, p = 0;
    vector<int> cnt(n1 + 1, 0), nxt(n1 + 1, 0);
    while (c <= n1) {
      for (int i = 0; i < l1; i++) {
        if (s1[i] == s2[p]) {
          if (p == l2 - 1) {
            p = 0;
            sum++;
          } else {
            p++;
          }
        }
      }
      cnt[c] = sum;
      nxt[c] = p;
      for (int i = 0; i < c; i++) {
        if (nxt[i] == p) {
          int ite = c - i;
          int N = (n1 - i) / ite;
          int itecnt = N * (cnt[c] - cnt[i]);
          int lcnt = cnt[i + (n1 - i) % ite];
          return (itecnt + lcnt) / n2;
        }
      }
      c++;
    }
    return cnt[n1] / n2;
  }
};

int main() {
  Solution solution;
  auto result = solution.getMaxRepetitions("acb", 4, "ab", 2);
  cout << result;
}