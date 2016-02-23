#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check_sorted( const vector<int>& a )
{
    for( int i = 1; i < a.size(); ++i )
    {
        if( a[i] < a[i-1] ) return false;
    }

    return true;
}

bool check_swap( vector<int>& a )
{
    vector<int> sorted = a;
    sort(sorted.begin(), sorted.end());

    vector<int> diffs;
    // compare against sorted array
    for( int i = 0; i < a.size(); ++i )
    {
        if( a[i] == sorted[i] ) continue;

        diffs.emplace_back(i+1);
    }

    if( diffs.size() == 2 )
    {
        cout << "yes" << endl;
        cout << "swap " << diffs[0] << " " << diffs[1] << endl;
    }

    return diffs.size() == 2;
}

bool check_reverse( vector<int>& a )
{
    int i = 1;

    // find first index where no longer sorted
    while( i < a.size() )
    {
        if( a[i] < a[i-1] ) break;
        ++i;
    }
    
    if( i == a.size() ) return false;

    int prev = i-2;
    int start = i-1;
    // find first index where sequence is no longer descending
    while( i < a.size() )
    {
        if(a[i] > a[i-1]) break;
        ++i;
    }
    
    int end = i;
    // sequence doesn't fit into larger array
    if( (prev >= 0 && (a[prev] > a[end-1] || a[end] < a[prev] ) ) || 
        a[start] > a[end] ) return false;

    while( i < a.size() )
    {
        if( a[i] < a[i-1] ) break;
        ++i;
    }

    // only one reversible sequence
    if( i == a.size() )
    {
        cout << "yes" << endl;
        cout << "reverse " << (start + 1) << " " << end << endl;
    } 

    return i == a.size();
}

int main()
{
    int n;
    cin >> n;

    vector<int> array;
    array.reserve( n );

    for( int i = 0; i < n; ++i )
    {
        int d;
        cin >> d;
        array.emplace_back( d );
    }

    if( check_sorted( array ) )
    {
        cout << "yes" << endl;
        return 0;
    }

    if( check_swap( array ) )
    {
        return 0;
    }

    if( check_reverse( array ) )
    {
        return 0;
    }

    cout << "no" << endl;

    return 0;
}
