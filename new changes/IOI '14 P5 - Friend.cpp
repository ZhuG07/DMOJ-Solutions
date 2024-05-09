#include <bits/stdc++.h>
using namespace std;

int findSample(int n, int confidence[], int Host[], int protocol[])
{
    //friend 
    int ans = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        int host = Host[i];
        if (protocol[i] == 0)
        {
            ans += confidence[i];
            confidence[host] = max(confidence[host] - confidence[i], 0);
        }
        else if (protocol[i] == 1)
        {
            confidence[host] += confidence[i];
        }
        else
        {
            confidence[host] = max(confidence[i], confidence[host]);
        }
    }
    return (ans + confidence[0]);
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    //just use findSample function for standard I/O
#define long long long
}
