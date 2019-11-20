#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start(0),end(0),length(0),result(0),size = s.size();
        vector<int> chars(128,-1);
        while(end<size){
            auto ch = s[end];
            if(chars[int(ch)] >= start) {
                start = chars[int(ch)]+1;
                length = end-start;
            }
            chars[int(ch)] = end;
            end++;
            length++;
            result = max(result,length);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string s = "pwwekew";
    auto result = solution.lengthOfLongestSubstring(s);
    cout<<result;
}