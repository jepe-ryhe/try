#include <iostream>
#include <string.h>
using namespace std;
int *next(char *p)
{
    int m = strlen(p);
    if (m < 0)
        return 0;
    int *n = new int[m];
    if (!n)
        return 0;
    n[0] = 0;
    for (int i = 1; i < m; i++)
    {
        int k = n[i - 1];
        while (k > 0 && p[i] != p[k])
            k = n[k - 1];
        if (p[i] == p[k])
            n[i] = k + 1;
        else
            n[i] = 0;
    }
    return n;
}
int kmp(string t, char *p)
{
    int i, j = 0;
    int *n = next(p); //cout<<strlen(p);
    for (i = 0; i < t.length(); i++)
    {
        while (p[j] != t[i] && j > 0)
            j = n[j - 1];
        if (p[j] == t[i])
            j++;
        if (j == strlen(p))
            return 1;
        //cout<<j<<'\t';
    }
    return 0;
}
int comp(char **strs, char *str)
{
    for (int i = 0; strs[i] != 0; i++)
        if (!strcmp(strs[i], str))
            return 1;
    return 0;
}
int main()
{
    int num, i, len, n = 0;
    float rate;
    cin >> num >> len >> rate;
    string strs[num];
    char *subs[1000] = {0};
    for (i = 0; i < num; i++)
        cin >> strs[i];
    int s, l, j;
    for (i = 0; i < num; i++)
        for (s = 0; s < len; s++)
            for (l = s; l < len; l++)
            { //cout<<i<<s<<l<<endl;
                char *tem = new char[l - s + 2];
                for (j = s; j <= l; j++)
                    tem[j - s] = strs[i][j];
                tem[l - s + 1] = '\0';
                if (comp(subs, tem))
                    break;
                int sum = 0;
                for (int k = 0; k < num; k++)
                {
                    /*cout<<strs[k]<<'\t';
                    for(j = 0;j<l-s+1;j++)
                        cout<<tem[j];
                    cout<<kmp(strs[k],tem)<<endl;*/
                    if (kmp(strs[k], tem) == 1)
                        sum++;
                }
                if ((float)sum / (float)num >= rate)
                {
                    subs[n] = tem;
                    n++;
                }
            }
    for (i = 0; i < n; i++)
    {
        cout << subs[i] << endl;
    }
}
