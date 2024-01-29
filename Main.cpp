#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adjList[100001];
bool visited[100001];
int parent[100001];
int distance1[100001];
int distance2[100001];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adjList[a].push_back(make_pair(b, c));
        adjList[b].push_back(make_pair(a, c));
    }

    for (int i = 2; i <= N; i++)
    {
        distance1[i] = 1000000000;
        distance2[i] = 0;
    }

    deque<int> dq;

    dq.push_back(1);
    while (!dq.empty())
    {
       visited[N] = true; 

        int u = dq.front();
        dq.pop_front();

        for (auto fdsa : adjList[u])
        {
            int v = fdsa.first;
            int danger = fdsa.second;

            if (distance1[u] + fdsa.second < distance1[v])
            {
                distance1[v] = distance1[u] + fdsa.second;

                parent[v] = u;
                if (danger == 0)
                {
                    dq.push_front(v);
                }
                else
                {
                    dq.push_back(v);
                }
            }
            else if (distance1[u] + danger == distance1[v])
            {
                if (distance2[u] + 1 < distance2[v])
                {
                    distance2[v] = distance2[u] + 1;
                    dq.push_back(v);
                }
            }
        }
    }
    int node = N;

    if (visited[N])
        cout << distance1[N] << " " << distance2[N] << "\n";
    else
    {
        cout << -1;
    }
}