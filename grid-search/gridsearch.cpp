#include <string>
#include <vector>
#include <iostream>

using namespace std;

// based off boyer moore algorithm
int containsMatch( const string& g, const string& p )
{
    // seed the lookup table for each digit to be length of the pattern
    vector<int> badCharTable(10, p.size());
    // preprocess skip table
    for(int i = 0; i < p.size()-1; ++i) 
        badCharTable[p[i] - '0'] = min<int>(p.size() - i - 1, badCharTable[p[i] - '0']); 

    for(int i = p.size() - 1; i < g.size(); )
    {
        int j = p.size() - 1; 
        while( j >= 0 && p[j] == g[i - (p.size() - 1 - j)] ) --j;       

        // found match, return index where match begins
        if( j < 0 ) return i - (p.size() - 1);

        // if not a match, skip by however much we can
        i += badCharTable[g[i] - '0'];
    }

    // no match found
    return -1;
}


bool contains( const vector<string>& G, const vector<string>& P )
{
    for(int i = P.size()-1; i < G.size(); ++i)
    {
        int j = P.size() - 1;
        int index = containsMatch(G[i], P[j]);        
        // found a match
        if( index >= 0 )
        {
            // loop back and check for substring matches
            for(; j >= 0; --j)
            {
                string g = G[i - (P.size() - 1 - j)].substr(index, P[j].size());
                if( g != P[j] ) break;
            }
        }

        if( j < 0 ) return true;
    }

    // no match
    return false;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int R;
        int C;
        cin >> R >> C;
        vector<string> G(R);
        for(int G_i = 0;G_i < R;G_i++){
           cin >> G[G_i];
        }
        int r;
        int c;
        cin >> r >> c;
        vector<string> P(r);
        for(int P_i = 0;P_i < r;P_i++){
           cin >> P[P_i];
        }
        cout << (contains(G, P) ? "YES" : "NO") << endl;
    }

    return 0;
}

