#include <bits/stdc++.h>
using namespace std;

int minCoin(vector<int> coins,int sum)
{
    int n = coins.size();

    vector<vector<int>> dp(n+1, vector<int>(sum+1, INT_MAX));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if(coins[i-1] <= j)
            {
                dp[i][j] = min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main()
{
    vector<int> coins = {1, 2, 5}; 
    int sum = 11;

    cout << minCoin(coins, sum) << endl;

    return 0;
}