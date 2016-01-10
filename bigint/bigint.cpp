#include <string>
#include <vector>
#include <iostream>

using namespace std;

class BigInt 
{
public:
    BigInt() : BigInt( 0 ) {}
    BigInt( int value ) 
    {
        if( value == 0 ) 
            _digits.push_back(0);
        else
        {
            while(value > 0)
            {
                _digits.push_back(value % 10);
                value /= 10;
            }
        }
    }

    void shiftBy10( const int powers ) 
    {
       _digits.insert( _digits.begin(), powers, 0 );
    }

    BigInt operator*(const BigInt& other) const
    {
        BigInt result;
        for( int i = 0; i < other._digits.size(); ++i )
        {
            BigInt res; 
            for( int j = 0; j < _digits.size(); ++j )
            {
                BigInt r( other._digits[i] * _digits[j] );
                r.shiftBy10( j );
                res = res + r;
            }

            res.shiftBy10(i);
            result = result + res;
        }

        return result;
    }

    BigInt operator+( const BigInt& other ) const
    {
        int size = max( other._digits.size(), _digits.size() );
        BigInt result;
        result._digits.resize( size );
        int carry = 0;
        for( int i = 0; i < size; ++i )
        {
            int o = i < other._digits.size() ? other._digits[i] : 0;
            int d = i < _digits.size() ? _digits[i] : 0;
            int res = d + o + carry;
            result._digits[i] = ( res % 10 );
            carry = res / 10;
        }

        if( carry > 0 ) result._digits.push_back( carry ); 
        
        return result;
    }

    string print() const
    {
        string result(_digits.size(), ' ');
        for( int i = 0; i < result.size(); ++i )
        {
            result[result.size() - i -1] = _digits[i] + '0';
        }

        return result;
    }

private:
    vector<int> _digits;
};


int main()
{
    int n;
    cin >> n;
    BigInt result(n);
    for( int i = n-1; i > 0; --i )
    {
        result = result * BigInt(i);
    }

    cout << result.print() << endl;
}
