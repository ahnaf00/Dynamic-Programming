#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstr(string &s1, string & s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
                ans = max(ans, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return ans;
    
}

int main()
{
    string s1 = "geeksforgeeks";
    string s2 = "ggeegeeksquizpractice";
    cout << longestCommonSubstr(s1, s2) << endl;
    return 0;

    return 0;
}