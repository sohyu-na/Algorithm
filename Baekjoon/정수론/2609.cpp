#include <iostream>

using namespace std;

int main()
{
    int a,b; cin >> a >> b;
    int l = a > b ? a : b;
    int s = a > b ? b : a;

    while (s) {
        l %= s;
        swap(l, s);
    }
    cout <<l<<'\n';
    cout << a * b / l;

}
