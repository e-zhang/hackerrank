#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

class RotateIterator : iterator<forward_iterator_tag, int>
{
private:
    Matrix& _mat;
    int _offset;

public:
    RotateIterator( Matrix& mat, int offset );
};

void rotate( Matrix& mat )
{
}


int main() {
    Matrix mat;
    int m = 0, n = 0, R = 0;
    cin >> m;
    cin >> n;
    cin >> R;

    mat.reserve(m);
    for( int i = 0; i < m; ++i )
    {
        mat.emplace_back();
        auto& row = mat.back();
        row.reserve(n);
        for( int j = 0; j < n; ++j )
        {
            int v = 0;
            cin >> v;
            row.push_back(v);
        }
    }

    return 0;
}

