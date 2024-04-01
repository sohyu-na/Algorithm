#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector <int> v(n);
    bool zero = false; int z = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == 0) {
            zero = true; z++;
        }
    }
    int cnt = 0; 
    int x = 0; int y = 1;
    set <int> s;
    if (zero) {
        if (z > 2) {
            cnt = n;
        }
        else {
            //0이 1개 
            //0 1 -1 >1
            //0 1 1 >2
            //0 1 2 >0

            while (true) {
                if (x == n - 1) {
                    break;
                }
                if (v[x] != 0 and v[y]!=0) {
                    if (v[x] == v[y]) {
                        s.insert(v[x]);
                    }
                    s.insert(v[x] + v[y]);
                }
                
                if (y != n - 1) {
                    y++;
                }
                else {
                    x++; y = x + 1;
                }
            }
            for (int i = 0; i < n; i++) {
                if (s.find(v[i]) != s.end()) {
                    cnt++;
                }
            }
        }
    }
    else {
        while (true) {
            if (x == n - 1) {
                break;
            }
            s.insert(v[x] + v[y]);
            if (y != n - 1) {
                y++;
            }
            else{
                x++; y = x + 1;
            }
        }
        for(int i=0;i<n;i++){
            if (s.find(v[i])!=s.end()) {
                cnt++; 
            }
        }
    }
    cout << cnt;
    return 0;
}
