#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n,m; cin >> n>>m;
    //~10^3, ~10^6
    map<int, int> mp;
    int x; //~10^9
    int sum = 0; //~10^3

    //10^6 ^6 - 10^12 -> int 초과 
    long long cnt = 0; mp[0]++;
    for (int i = 1; i <= n;i++) {
        cin >> x;
        sum = (sum + x) % m;
        mp[sum]++;
        cnt = cnt + mp[sum]-1;
    }
    cout << cnt;

    return 0;
}
