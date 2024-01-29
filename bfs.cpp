#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[100];
bool visited[100];
int parent[100]; //backtracking the path 

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    adjList[1].push_back(2);
    adjList[1].push_back(3);
    adjList[2].push_back(3);
    adjList[2].push_back(4);
    adjList[3].push_back(4);
    adjList[4].push_back(5);
    adjList[3].push_back(5);

    deque<int> dq;

    dq.push_back(1);
    while (!dq.empty())
    {
        int u = dq.front();
        visited[u] = true;
        dq.pop_front();

        for (int v : adjList[u])
        {
            if (!visited[v])
            {
                parent[v] = u ; 
                dq.push_back(v);
            }
        }
    }
}