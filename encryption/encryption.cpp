#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>


using namespace std;


int main(){
    string s;
    cin >> s;

    // remove all the spaces
    // s.erase(remove(s.begin(), s.end(), ' '), s.end()); 
    
    // calculate the rows/columns
    // take floor
    int rows = static_cast<int>( sqrt(s.size()) + 0.5 );
    int cols = s.size() / rows;
    cols += (rows * cols) < s.size();

    // set up resulting string with extra spaces
    string result((rows+1) * cols, ' '); 

    for(int i = 0; i < result.size(); ++i)
    {
        // get location of current char in encryption matrix
        int r = i % rows;
        int c = i / rows;

        int index = r*cols + c;
        if( index >= s.size() ) continue;

        result[i + min<int>(c, cols - (rows*cols - s.size()))] = s[index];
    }

    result.erase(result.begin() + result.find_last_of(' '), result.end());
    cout << result << endl;

    return 0;
}
