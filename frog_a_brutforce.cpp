#include <bits/stdc++.h>
using namespace std;

int frog(int i, vector<int>h)
{
    if(i==0) return 0;
    int cost = INT_MAX;

    cost = min(cost, frog(i-1, h)+abs(h[i]-h[i-1]));

    if(i>1)
    {
        cost = min(cost, frog(i-2, h)+abs(h[i]-h[i-2]));
    }

    return cost;
}

int main()
{
    int n;
    cin >> n;

    vector<int>h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    cout << frog(n-1, h) << endl;
    

    return 0;
}