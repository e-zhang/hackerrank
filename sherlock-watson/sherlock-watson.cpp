#include <vector>
#include <iostream>

using namespace std;

int main() 
{
    int N, K, Q;
    cin >> N;
    cin >> K;
    cin >> Q;

    vector<int> elements;
    elements.reserve( N );

    for( int i = 0; i < N; ++i ) 
    {
        int e;
        cin >> e;
        elements.emplace_back( e );
    }

    for( int i = 0; i < Q; ++i )
    {
        int q;
        cin >> q;
        auto index = (N + q - (K%N)) % N;
        cout << elements[index] << std::endl;
    }

}
