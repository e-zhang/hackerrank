#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdint>

using namespace std;

int64_t maximize_sum( const vector<int64_t>& numbers, const int64_t m )
{
    // calculate prefix array for sum up to i, so subarray [i, j) is prefix[j] - prefix[i]
    vector<int64_t> prefix( numbers.size() );
    prefix[0] = numbers[0] % m;
    for( int64_t i = 1; i < numbers.size(); ++i )
    {
        prefix[i] = (prefix[i-1] + numbers[i] % m) % m;
    }

    int64_t maxSum = 0;
    set<int64_t> sorted;
    for( int64_t i = 0; i < prefix.size(); ++i )
    {
        auto it = sorted.upper_bound( prefix[i] );
        // no higher prefix sum, so this subarray is max [0, i)
        if( it == sorted.end() ) 
        {
            maxSum = max( maxSum, prefix[i] );
        }
        else
        {
            // find first prefix where index is < i )
            int64_t sum = (prefix[i] - *it + m) % m;
            maxSum = max( maxSum, sum );
        }

        sorted.emplace( prefix[i] );
    }

    return maxSum; 
}


int main() 
{
    int64_t t;
    cin >> t;
    for( int64_t i = 0; i < t; ++i )
    {
        int64_t n, m;
        cin >> n;
        cin >> m;
        vector<int64_t> numbers( n );
        for( int64_t j = 0; j < n; ++j )
        {
            cin >> numbers[j];
        }

        cout << maximize_sum( numbers, m ) << endl;
    } 

}
