#include <bits/stdc++.h>
using namespace std;

long long plants[2000000][3];
tuple<int, int, int> plantTuples[2000000];

long long countTallerPlants(long long days, long long index, long long N);

int main()
{

#define int long long
    cin.sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;

    for (int z = 0; z < T; z++)
    {

        int N;
        cin >> N;

        for (int i = 0; i < N; i++)
        {
            cin >> plants[i][0];
        }
        for (int i = 0; i < N; i++)
        {
            cin >> plants[i][1];
        }
        for (int i = 0; i < N; i++)
        {
            cin >> plants[i][2];
        }

        for (int i = 0; i < N; i++)
        {

            plantTuples[i] = make_tuple(plants[i][0], plants[i][1], plants[i][2]);
        }

        // Custom sorting based on the first column
        sort(plantTuples, plantTuples + N);

        int minimumIncrease = 1000000000000;
        int indexOfMin = 0;
        for (int i = 0; i < N; i++)
        {
            if (get<1>(plantTuples[i]) < minimumIncrease)
            {
                minimumIncrease = get<1>(plantTuples[i]);
                indexOfMin = i;
            }
        }

        for (int i = 0; i < N; i++)
        {
            cout << get<0>(plantTuples[i]) << " "
                 << get<1>(plantTuples[i]) << " "
                 << get<2>(plantTuples[i]) << endl;
        }
        

        int low = 0;
        int high = 100000000LL;
        int mid = 0 ; 
        while (low < high)
        {
           mid = low + (high - low) / 2;

            int count = countTallerPlants(mid, indexOfMin, N);
                cout << "low: " << low << ", high: " << high << ", mid: " << mid << ", count: " << count << endl;
cout<<get<2>(plantTuples[indexOfMin])<<"\n";

            if (count > get<2>(plantTuples[indexOfMin]))
            {
                 high = mid ;
            }
            else
            {
                low = mid + 1;
            }
        }
        cout<<"mid "<<mid<<"\n";
        cout << "\n";
    }

    return 0;
}

long long countTallerPlants(long long days, long long index, long long N)
{
    #define int long long 
    int count1 = 0 ; 
    int height = get<0>(plantTuples[index]);
    int growth = get<1>(plantTuples[index]);
    int calc = height + days*growth; 
    for (int i = 0; i < N; i++)
    {
        if (i != index)
        {
            int temp = get<0>(plantTuples[i]) + get<1>(plantTuples[i]) * days;
            if(temp>calc)
            count1++;
        }
    }
    return count1;
}


