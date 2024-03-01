#include <iostream>

using namespace std;

//반복문
int gcdIter(int a, int b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}
//재귀함수
int gcdRecur(int a, int b){
    if(!b)//b가 0이면 
        return a;
    else
        gcdRecur(b,a%b);
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
