#include <iostream>
using namespace std;
// extended euclidean algorithm
int extended_euclidean(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        cout << a << " " << b << " : x = " << x << " y = " << y << endl;
        return a;
    }
    int x1, y1;
    int d = extended_euclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    cout << a << " " << b << " : x = " << x << " y = " << y << endl;
    return d;
}
void inverse(int a, int m)
{
    int x, y;
    int g = extended_euclidean(a, m, x, y);
    if (g != 1)
    {
        cout << "No solution!";
    }
    else
    {
        x = (x % m + m) % m;
        cout << a << "^-1 ≡ " << x << " modulo " << m << endl;
    }
    cout << endl;
}
int main()
{
    inverse(4, 10);

}

