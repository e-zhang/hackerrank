#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void swap(vector<int>& list, int i, int j)
{
    int tmp = list[i];
    list[i] = list[j];
    list[j] = tmp;
}

int partition(vector<int>& list, int begin, int end)
{
    int i = begin;

    for( int j = begin; j < end; ++j )
    {
        if( list[j] < list[end] )
        {
            swap(list, i, j);
            ++i;
        }      
    }

    swap(list, i, end);

    return i;
}

void quicksort(vector<int>& list, int begin, int end)
{
    if(end - begin < 1) return;

    int p = partition(list, begin, end);

    for(int o = 0; o < list.size(); ++o )
    {
        cout << list[o];
        if( o != list.size() - 1 ) cout << " ";
    }    
    cout << endl;

    quicksort(list, begin, p-1);
    quicksort(list, p+1, end);
}
 

int main() {
    int n = 0;
    cin >> n;

    vector<int> list;
    list.reserve(n);
    for( int i = 0; i < n; ++i )
    {
        int v = 0;
        cin >> v;
        list.emplace_back(v);
    }

    quicksort(list, 0, n-1);
    return 0;
}

