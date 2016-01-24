#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


void lexicographicNext( string& word )
{
    if( word.empty() || word.size() < 2 ) 
    {
        word = "no answer";
        return;
    }
    
    int i = word.size() - 2;

    // find the largest index from the end where all the indices after are in descending order
    while( i >= 0 && word[i] >= word[i+1] ) --i;

    // everything is in descending order, so no more permutations
    if( i < 0 ) 
    {
        word = "no answer";
        return;
    }


    // so we know the index to be increased, so now we find the index of the next greater value
    int j = word.size() - 1;
    while( j >= i && word[i] >= word[j] ) --j;

    if( j < i ) 
    {
        word = "no answer";
        return;
    }

    // now we can swap i and j, we know since i and j are the smallest left
    char tmp = word[i];
    word[i] = word[j];
    word[j] = tmp;

    // now we reverse the descending indices to be in ascending
    std::reverse( word.begin() + i + 1, word.end() );
}

int main()
{
    int t;
    cin >> t;
    for( int i = 0; i < t; ++i )
    {
        string s;
        cin >> s;
        lexicographicNext( s );
        cout << s << endl;
    }
} 
