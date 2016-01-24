#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Value
{
    int originalIdx;
    int index;
    string value;
};

int main() 
{
    int t;
    cin >> t;
    std::vector<Value> values;
    values.reserve( t );

    for( int i = 0; i < t; ++i )
    {
        int j;
        cin >> j;
        string s;
        cin >> s;
        values.push_back( { i, j, s } );
    }

    std::stable_srt( values.begin(), values.end(), []( const auto& a, const auto& b )
    {
        return a.index < b.index;   
    } );

    for( int i = 0; i < t; ++i )
    {
        const auto& v = values[i]; 

        if( v.originalIdx < ( t / 2 ) ) cout << "-";
        else cout << v.value;

        if( i < t-1 ) cout << " "; 
    }
    cout << endl;
}
