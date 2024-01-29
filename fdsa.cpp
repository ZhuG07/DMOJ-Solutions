#include <bits/stdc++.h>
using namespace std;

/*
struct pair_hash
{
    size_t operator()(const pair<int,int>&v) const{
        return v.first * 31 + v.second;
    }
}*/

int arr[500000];
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    string s;
    cin >> s;

    for (int i = 0; i < N; i++)
    {
        arr[i] = (int)s[i] - '0';
    }

    int count = 0;
    int finalCount = 10000000;
    for (int i = 0; i < N+1; i++)
    {
        if (arr[i] == 1)
            count++;
        else
        {
            if (count != 0)
                finalCount = min(count, finalCount);
            count = 0;
        }
    }

    int days;
    if (finalCount % 2 == 1)
        days = (finalCount - 1) / 2+1;
    else
    {
        finalCount-=1;
        days = (finalCount - 1) / 2 + 1;
    }
    //cout<<finalCount<<"\n";

    //loop once more 
    int ans = 0 ; 
    count = 0 ; 
    for (int i = 0; i < N+1; i++)
    {
        
        if (arr[i] == 1)
            count++;
        else
        {
            if(count!=0)
            ans += ceil(count/(double)finalCount); 
            count = 0 ; 
        }

        if(count==2*days-1&&count!=0){
            ans +=  ceil(count/(double)finalCount);
            count = 0 ; 
        }
    }
    cout<<ans<<"\n";



}
