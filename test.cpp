#include <bits/stdc++.h>
using namespace std;

deque<pair<int, int>> maxMonoDeque;
int maxMonoDequeSize = 0;

//----------------------------------------------------------
// a data strcture to find the max/min of a sliding window. implemented usinga deque of pairs
//  push, find max/min, pop are all O(1) time.
deque<pair<int, int>> minMonoDeque;

void maxPush(int val)
{
    maxMonoDequeSize++;
    int count = 0;
    while (!maxMonoDeque.empty() && maxMonoDeque.back().first < val)
    {
        count += maxMonoDeque.back().second + 1;
        maxMonoDeque.pop_back();
    }
    maxMonoDeque.push_back({val, count});
}

void minPush(int val)
{
    int count = 0;
    while (!minMonoDeque.empty() && minMonoDeque.back().first > val)
    {
        count += minMonoDeque.back().second + 1;
        minMonoDeque.pop_back();
    }
    minMonoDeque.push_back({val, count});
}

int findMax()
{
    return maxMonoDeque.front().first;
}

int findMin()
{
    return minMonoDeque.front().first;
}

void maxPop()
{
    maxMonoDequeSize--;
    if (maxMonoDeque.front().second > 0)
        maxMonoDeque.front().second--;
    else
        maxMonoDeque.pop_front();
}

void minPop()
{
    if (minMonoDeque.front().second > 0)
        minMonoDeque.front().second--;
    else
        minMonoDeque.pop_front();
}

int main()
{
    cin.sync_with_stdio();
    cin.tie(0);

#define int long long

    int N;
    int K;
    cin >> N >> K;
    long long total = 0;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        minPush(x);
        maxPush(x);
        while (findMax() - findMin() > K)
        {
            minPop();
            maxPop();
        }
        total += maxMonoDeque.size() + minMonoDeque.size();
    }
    cout << total;
}
