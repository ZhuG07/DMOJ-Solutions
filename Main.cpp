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

int sx, sy, sz;
int tx, ty, tz;

long long arrX[10000];
long long arrY[10000];

bool eaten[10000];
vector<int> tempEat;

int main()
{
#define int long long
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        double x, y;
        cin>>x>>y;
       arrX[i]  = 1000*x;
       arrY[i] = 1000*y;
    }

    int x = 0;

    while (x <= 1000000)
    {
        int best = 100000000000000;
        int bestI = 10;
        for (int i = 0; i < N; i++)
        {
            int distance = (x - arrX[i]) * (x - arrX[i]) + (arrY[i] * arrY[i]);
            if (distance < best)
            {
                best = distance;
                tempEat.clear();
                tempEat.push_back(i);
            }
            else if (distance == best)
            {
                tempEat.push_back(i);
            }
        }

        for (int i : tempEat)
            eaten[i] = true;
        tempEat.clear(); 

        x += 1;
    }

    for(int i = 0 ; i < N; i ++){
        if(eaten[i]){
            cout<<"The sheep at ("<<fixed<<setprecision(2)<<arrX[i]/1000.0<<","<<arrY[i]/1000.0<<") might be eaten."<<"\n";
        }
    }
}