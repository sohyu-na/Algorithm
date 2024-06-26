#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
int n;
bool isPrime(int num) {
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
void DFS(int num,int c){
    if (c == n) {
        if (isPrime(num)) {
            //출력
            cout << num << "\n";
        }
        return;
    }
    for (int i = 1; i < 10; i += 2) {
        if (isPrime(num * 10 + i)){
            DFS(num*10+i,c+1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    
    //연산
    DFS(2, 1);
    DFS(3, 1);
    DFS(5, 1);
    DFS(7, 1);

    return 0;
}