#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,k; cin >> n>>k;
    vector <int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    //이미 오름차순 정렬되어있으므로 
    //인덱스를 뒤로 부터 접근하면 소팅안해도됨
    sort(v.begin(), v.end(), greater<>());
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (k >= v[i]) {
            m += k / v[i];
            k = k % v[i];
            if (k == 0) {
                break;
            }
        }
    }
    cout << m;
    return 0;
}


