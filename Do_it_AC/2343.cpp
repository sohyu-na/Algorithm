#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool psb(vector <int> v,int m,int k) {
    int key = k;
    for (int i = 0; i < v.size(); i++) {
        key -= v[i];
        while (key < 0) {
            m--; 
            if (m==0) {
                return false;
            }
            key = k - v[i];
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m; cin >> n >> m;
    vector <int> v(n);
    int max = 0; int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (max < v[i]) {
            max = v[i];
        }
        sum += v[i];
    }
    
    //이진 탐색 
    //start - 한 강의 길이 최댓값 max
    //*모든 강의의 합/강의의 개수보다 한 강의의 길이가 길면 
    //강의의 최소길이는 한 강의의 길이가 되므로 start 주의
    //end - 모든 강의의 합 sum
    while (max <= sum) {
        int key = (max + sum) / 2;
        if (psb(v, m, key)) {
            sum = key - 1;
        }
        else {
            max = key + 1;
        }
    }
    cout << max;

    
    return 0;
}