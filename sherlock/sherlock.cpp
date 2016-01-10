#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

int anagramPairs( const string& s )
{
    // store map of frequencies of times we see each sorted substring
    // store sorted since we want to consider anagrams
    unordered_map<string, int> frequencies;
    // loop through all substring sizes
    for( int sz = 1; sz <= s.size(); ++sz )
    {
        // create all substrings of size sz
        for( int i = 0; i <= s.size() - sz; ++i )
        {
            auto sub = s.substr(i, sz);           
            sort(sub.begin(), sub.end());
            // up count that we've seen this anagram
            frequencies[sub]++;
        }
    }  

    int pairs = 0;
    for( auto& p : frequencies )
    {
        // for each anagram, we have the total count of substrings that are anagrams
        // we need the total number of pairs of substrings (n * (n-1)/2)
        pairs += p.second * (p.second - 1) / 2;
    }

    return pairs;
}

int main() {
    int t = 0;
    cin >> t;

    for( int i = 0; i < t; ++i )
    {
        string s;
        cin >> s;
        cout << anagramPairs(s) << endl;
    }

    return 0;
}
