#include <bits/stdc++.h>
using namespace std;

int frog(int i, int k, vector<int>dp, vector<int>h)
{
    if(i == 0) return 0;

    if(dp[i] != -1) return dp[i];

    int cost  = INT_MAX;

    for (int j = 1; j <= k; j++)
    {
        if(i-j >= 0)
        {   
            cost = min(cost, frog(i-j, k, dp, h)+abs(h[i]-h[i-j]));
        }
    }
    return dp[i] = cost;
}

int main()
{
    int n, k; 
    cin >> n >> k;

    vector<int>dp(n, -1);
    vector<int>h(n);

    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    
    cout << frog(n-1, k, dp, h) << endl;

    return 0;
}