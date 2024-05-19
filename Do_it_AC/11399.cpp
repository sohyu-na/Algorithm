#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector <int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    //삽입정렬으로 구현하기
    for (int i = 1; i < n; i++) {
        int idx = i;
        int ins = v[i];
        for (int j = i-1; j >= 0; j--) { //뒤에서부터 
            if (v[j] > ins) {//인덱스 +1
                v[j + 1] = v[j];
            }
            else {
                idx = j+1;
                break;
            }
            if (j == 0) {
                idx = 0;
            }
        }
        v[idx] = ins;
    }
    
    //sort(v.begin(), v.end());

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i] * (n-i);
    }
    cout << sum;
    return 0;
}