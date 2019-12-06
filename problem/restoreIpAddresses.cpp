#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> res;
        stringstream ss;
        for (int a = 1; a < 4; ++a)
            for (int b = 1; b < 4; ++b)
                for (int c = 1; c < 4; ++c)
                    for (int d = 1; d < 4; ++d)
                        if (a + b + c + d == s.length())
                        {
                            int n1, n2, n3, n4;
                            ss << s.substr(0, a);
                            ss >> n1;
                            ss.clear();
                            ss << s.substr(a, b);
                            ss >> n2;
                            ss.clear();
                            ss << s.substr(a + b, c);
                            ss >> n3;
                            ss.clear();
                            ss << s.substr(a + b + c, d);
                            ss >> n4;
                            ss.clear();
                            if (n1 <= 255 && n2 <= 255 && n3 <= 255 && n4 <= 255)
                            {
                                stringstream ip;
                                ip << n1 << '.' << n2 << '.' << n3 << '.' << n4;
                                if (ip.str().length() == s.length() + 3)
                                    res.push_back(ip.str());
                            }
                        }
        return res;
    }
};

int main()
{
    Solution solution;
    string s = "25525511135";
    auto result = solution.restoreIpAddresses(s);
    for (auto &&i : result)
    {
        cout << i << endl;
    }
}