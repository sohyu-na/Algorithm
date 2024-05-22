#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
bool checkcnt(int n,int t,int k) {
    int cnt = 0;
    for (int i = 1; i < n + 1; i++) {
        cnt += min(t / i,n); //핵심 아이디어 
        if (cnt >= k) {
            return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k; cin >> n >> k;
    
    int left = 1;
    int right = k;
    while (left <= right) {
        int temp = (left + right) / 2;
        if (checkcnt(n, temp, k)) {
            left = temp + 1;
        }
        else {
            right = temp - 1;
        }
    }
    cout << right+1;

    return 0;
}
