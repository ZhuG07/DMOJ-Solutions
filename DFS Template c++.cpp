#include <bits/stdc++.h>
using namespace std;

long long PP[1000005];
vector<int> adjList[1000005];
bool visited[1000005];
long long Total = 0;

int LocateCentre(int N, int P[], int S[], int D[]);

long long Min = 1000000000000000000LL;
long long posOfMin = 0;

long long dfs(int v, long long total)
{
    // cout<<v<<" "<<Total-total<<" "<<total<<"\n";

    long long mostTraffic = 0;
    long long totalTraffic = PP[v];
    visited[v] = true;
    for (int x : adjList[v])
    {
        if (!visited[x])
        {
            long long t = dfs(x, total);
            mostTraffic = max(mostTraffic, t);
            totalTraffic += t;
        }
    }
    mostTraffic = max(mostTraffic, Total - totalTraffic);
    if (mostTraffic < Min)
    {
        Min = mostTraffic;
        posOfMin = v;
    }
    return totalTraffic;
}

int LocateCentre(int N, int P[], int S[], int D[])
{

    for (int i = 0; i < N; i++)
    {
        PP[i] = P[i];
        Total += P[i];
    }

    for (int i = 0; i < N - 1; i++)
    {
        int x = S[i];
        int y = D[i];
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    dfs(0, 1);
    return posOfMin;
}

int a[1000000];
int b[1000000];
int c[1000000];
int main()
{

    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;


    for (int i = 0 ;i < N; i ++)
    cin>>a[i];

    for(int i = 0 ; i < 2*N; i++){
        cin>>b[i]>>c[i];
    }

        cout << LocateCentre(N, a, b, c);

    return 0;
}
