#include <iostream>

using namespace std;

int getGCD(int a, int b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}
int main()
{
    int a,b; cin >> a >> b;
    /*
    int l = a > b ? a : b;
    int s = a > b ? b : a;
    
    while (s) {
        l %= s;
        swap(l, s);
    }
    cout <<l<<'\n';
    cout << a * b / l;
    */
   if(b>a)
        swap(a,b);
    int gcd = getGCD(a,b);
    
    cout << gcd <<"\n";
    cout << a*b/gcd;

}
