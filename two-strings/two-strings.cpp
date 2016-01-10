#include <iostream>
using namespace std;


bool hasSubstring( const string& a, const string& b )
{
    // since we only need to check if the two strings share a substring,
    // we only need to check that a given letter is in both, since in order
    // to share a single substring, AT LEAST 1 letter must be in common
    for( int i = 0; i < a.size(); ++i )
    {
        if( b.find(a[i]) != string::npos ) return true;
    }

    return false;
}


int main() {
    int t = 0;
    cin >>  t;

    for( int i = 0; i < t; ++i )
    {
        string a, b;

        cin >> a;
        cin >> b;
        
        cout << (hasSubstring(a, b) ? "YES" : "NO") << endl;
    }

    return 0;
}

