#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;

    long long ar[21];
    set <int> s;
    long long cnt = 1;//순열의 개수 
    for (int i = 1; i <= n; i++) {
        cnt *= i;
        ar[i] = cnt;//1 2 6 24
        s.insert(i);
    }

    int t; cin >> t;
    if (t == 1) {
        long long k; cin >> k;
        //k번째 순열 구하기
        k--;
        for (int i = 1; i <= n; i++) {
            long long q = (k / ar[n - i]);
            auto iter = s.begin();
            for (int j = 0; j < q; j++) {
                iter++;
            }
            cout << *iter << " ";
            s.erase(*iter);
            k = k % ar[n - i];
        }

    }
    else {
        //주어진 수열의 순서 찾기
        int t;
        long long total = 1;
        for (int i = 1; i <= n; i++) {
            cin >> t;
            auto iter = s.begin();
            for (int j = 0; j < s.size(); j++) {
                if (*iter == t) {
                    total += j * ar[n - i];
                    break;
                }
                iter++;
            }
            s.erase(t);
        }        
        cout << total;
    }
    return 0;
}