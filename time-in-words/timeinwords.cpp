#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

string intToString(int value)
{
    switch(value)
    {
        case 1: return "one";
        case 2: return "two";
        case 3: return "three";
        case 4: return "four";
        case 5: return "five";
        case 6: return "six";
        case 7: return "seven";
        case 8: return "eight";
        case 9: return "nine";
        case 10: return "ten";
        case 11: return "eleven";
        case 12: return "twelve";
        case 13: return "thirteen";
        case 14: return "fourteen";
        case 15: return "quarter";
        case 16: return "sixteen";
        case 17: return "seventeen";
        case 18: return "eighteen";
        case 19: return "nineteen";
        case 20: return "twenty";
        case 21: return "twenty one";
        case 22: return "twenty two";
        case 23: return "twenty three";
        case 24: return "twenty four";
        case 25: return "twenty five";
        case 26: return "twenty six";
        case 27: return "twenty seven";
        case 28: return "twenty eight";
        case 29: return "twenty nine";
        case 30: return "half";
    }

    return "";
}

string getTime( const int h, const int m )
{
    if( m == 0 )
    {
        return intToString(h) + " o' clock";
    }

    else if( m > 30 )
    {
        return intToString(60 - m) + (m == 45 ? "" : string(" minute") + (m == 59 ? "" : "s")) + 
                " to " + intToString(h+1);
    }
    else
    {
        return intToString(m) + (m == 15 || m == 30 ? "" : string(" minute") + (m == 1 ? "" : "s")) + 
                " past " + intToString(h);
    }
}


int main(){
    int h;
    cin >> h;
    int m;
    cin >> m;

    cout << getTime(h, m) << endl;

    return 0;
}

