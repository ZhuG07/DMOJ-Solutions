#include <bits/stdc++.h>

using namespace std;

int arr[10000001];
int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    int currLength = 1;

    int nextWays = 0;
    int curNumber = 1;

    if ((N * (N + 1)) / 2 - ((N - M) * ((N - M) + 1)) / 2 < K || K < N)
    {
        cout << -1;
        return 0;
    }

    for (int i = 1; i <= N; i++)
    {
        // this value precalcualtes from last round
        arr[i] = curNumber;

        // calculate next value if curNumber += 1;
        if (currLength + 1 <= M)
        {
            nextWays += curNumber + 1;
        }
        else
        {
            nextWays += 2;
        }

        cout << i << ": " << K - nextWays << " "<< N - i<< "\n";
        //------------------------------------------
        // if the nextWays is small enough assuming the rest after j gets filled with 1s
        if (K - nextWays >  (N - i ))//fix this part 
        {
            curNumber++;
            currLength++;
        }
        else
        {
            currLength = 1;

            curNumber = 1;
        }
        if (curNumber > M)
        {
            curNumber = 1;
            currLength = 1;
        }
        cout<<"next Number: "<< curNumber<<"\n";
    }

    for (int i = 1; i <= N; i++)
    {
        cout << arr[i] << " ";
    }
}