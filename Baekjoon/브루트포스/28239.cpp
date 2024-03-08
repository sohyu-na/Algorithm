#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//long long -> 8바이트,64비트
typedef long long ll;
//10^18 이 대략 2^60 이기 때문
const int MAX = 60;

pair <int, int> getPair(ll m) {
    int x, y;
    //m이 제곱수인 경우 -> 비트마스킹 시 1이 하나라 따로 계산
    //x==y 
    //m = 2^i -> x=y=i-1
    for (int i = 1; i < MAX; i++) {
        if (m == ((ll)1 << i)) {
            return { i - 1,i - 1 };
        }
    }
    //m이 제곱수가 아닌 경우 
    //x<y , x먼저 계산 후 y=x+1부터 계산
    for (x = 0; x < MAX; x++) {
        if (m & ((ll)1 << x)) {
            break;
        }
    }
    for (y = x + 1; y < MAX; y++) {
        if (m & ((ll)1 << y)) {
            break;
        }
    }
    return { x,y };
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    ll m; //m의 범위가 10^18이라 long long 자료형
    pair <int, int> p;
    while(n--){
        cin >> m;
        p =getPair(m);
        cout << p.first << " " << p. second << "\n";
    }

    return 0;
}
