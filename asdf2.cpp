#include <bits/stdc++.h>
using namespace std;

long long diff[1000001];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);


    int N, T, L;
    cin >> N >> T;

    for (int i = 0; i < T; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        diff[a] += c;
        diff[b + 1] -= c;
    }

    for (int i = 0; i <= N; i++)
    {
        if (i > 0)
            diff[i] += diff[i - 1];

        // cout << diff[i] << " ";
    }
    cin >> L;

    int i = 1, j = 1;
    int maxCups = 0;
    int currentSum = 0;

    while (j < N)
    {
        currentSum += diff[j];
        //  cout << "test " << currentSum << "\n";

        if (currentSum <= L)
            maxCups = max(maxCups, j - i + 1);

        while (currentSum >= L)
        {
            currentSum -= diff[i];
            i++;
        }
        j++;
    }
   
    cout << maxCups << "\n";
}