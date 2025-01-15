#include <bits/stdc++.h>
using namespace std;

int frog(int i, vector<int>dp, vector<int>h)
{
    if(i==0) return 0;

    if(dp[i] != -1) return dp[i];

    int cost = INT_MAX;

    cost = min(cost, frog(i-1, dp, h)+abs(h[i]-h[i-1]));

    if(i>1)
    {
        cost = min(cost, frog(i-2, dp, h)+abs(h[i]-h[i-2]));
    }

    return dp[i] = cost;
}

int main()
{
    int n;
    cin >> n;

    vector<int> dp(n+1, -1);
    vector<int> h(n);

    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    

    cout << frog(n-1, dp, h) << endl;

    return 0;
}