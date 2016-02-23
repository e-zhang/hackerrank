#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

size_t find_pairs( vector<int>& inputs )
{
    sort(inputs.begin(), inputs.end());

    size_t i = 1;
    size_t pairs = 0;

    while( i < inputs.size() )
    {
        if( inputs[i] != inputs[i-1] )
        {
            ++i;
            continue;
        }

        // found a pair
        int start = i-1;
        while( i < inputs.size() && inputs[i] == inputs[i-1] ) ++i; 
        size_t count = i - start;
        pairs += count * (count - 1);
    }

    return pairs;
}

size_t find_pairs_map( const vector<int>& inputs )
{
    unordered_map<int, size_t> map;

    for( const auto& a : inputs ) ++map[a];

    return accumulate( map.begin(), map.end(), (size_t)0, 
            []( const size_t acc, const pair<int, size_t>& a ) {
                return acc + (a.second * (a.second - 1)); 
            } ); 
}

int main()
{
    int T;
    cin >> T;

    for( int i = 0; i < T; ++i )
    {
        int n;
        cin >> n;
        vector<int> inputs;
        inputs.reserve(n);
        for( int i = 0; i < n; ++i )
        {
            int a;
            cin >> a;
            inputs.emplace_back(a);
        }

        cout << find_pairs_map(inputs) << endl;
    }

    return 0;
}
