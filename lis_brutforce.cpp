#include <bits/stdc++.h>
using namespace std;

int lisEndingAtIndex(vector<int>&arr, int indx)
{
    if(indx == 0)
    {
        return 1;
    }

    int maxLength = 1;
    for (int prev = 0; prev < indx; prev++)
    {
        if(arr[prev] < arr[indx])
        {
            maxLength = max(maxLength, lisEndingAtIndex(arr, prev)+1);
        }
    }
    return maxLength;
}

int lis(vector<int>&arr)
{
    int n = arr.size();
    int maxLength = 1;
    for (int i = 1; i < n; i++)
    {
        maxLength = max(maxLength, lisEndingAtIndex(arr, i));
    }
    return maxLength;
}

int main()
{
    vector<int>arr =  { 10, 22, 9, 33, 21, 50, 41, 60 };
    cout << lis(arr);

    return 0;
}