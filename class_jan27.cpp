#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[10005];
int visited[10001];
int previous[10001];

bool Acylic = true; 

// https://dmoj.ca/problem/graph2p2

void dfs(int x, int parent)
{
    
    for (int v : adjList[x])
    {   
        if (!visited[v])
        {
            visited[v] = true;
            previous[v] = x;   
            dfs(v, x);
            
        }else if(visited[v]&&previous[v]!=x){
        Acylic = false; 
        }
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int start = 0 ; 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int x;
            cin>>x;
            if(x==1){
                adjList[i].push_back(j);
                start = i;
            }
        }
    }
    visited[start] = true; 
    dfs(start, 0);

    if(Acylic)
    cout<<"YES";
    else
    cout<<"NO";




    adjList[1].push_back(2);
    adjList[2].push_back(1);
    adjList[2].push_back(3);
    adjList[3].push_back(4);
}
