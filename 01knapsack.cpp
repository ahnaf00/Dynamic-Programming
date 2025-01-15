#include <bits/stdc++.h>
using namespace std;

void knapSack(vector<int> &val, vector<int> &wt, int W)
{
    int n = wt.size();

    vector<vector<int>> dp(n+1, vector<int>(W+1));

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if(i == 0 || w == 0)
            {
                dp[i][w] == 0;
            }
            else if(wt[i-1] <= w)
            {
                dp[i][w] = max(dp[i-1][w-wt[i-1]]+val[i-1], dp[i-1][w]);
            }
            else
            {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    cout << dp[n][W] << endl;
    
}

int main()
{
    vector<int> profit = {60, 100, 120};
    vector<int> weight = {10, 20, 30};

    int W = 50;

    knapSack(profit, weight, W);

    return 0;
}