#include <iostream>

using namespace std;

int checkSIX(int i) {
    while(i>=666){
        if(i%1000==666){//마지막 세자리 검사 
            return 1;
        }
        i /=10;//뒤에서부터 하나씩 날려가면서 검사
    }
    
    /*int a = 0;
    while (i / 10) {
        if (i % 10 == 6) {
            a++;
            if (a == 3) {
                return 1;
            }
        }
        else {
            a=0;
        }
        i /= 10;
    }
    if (i % 10 == 6) {
        a++;
        if (a == 3) {
            return 1;
        }
    }*/
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    int check; int cnt=0;
    for (int i = 666; ; i++) {
        check =checkSIX(i);
        if (check) {
            cnt++; 
            if (cnt == n) {
                cout << i;
                return 0;

            }
        }
    }
}
