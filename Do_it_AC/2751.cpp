#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
vector <int> temp;

void mergeSort(vector <int> &v,int start, int end) {
    if (end-start < 1) {
        return;
    }

    //분할 - 중간값
    int m = start + (end - start) / 2;
    mergeSort(v,start, m);
    mergeSort(v, m + 1, end);

    for (int i = start; i <= end; i++) {
        temp[i] = v[i];
    }

    //병합 - 투 포인터
    int re = start;
    int p1 = start;
    int p2 = m + 1;

    while (p1 <= m and p2 <= end) {
        if (temp[p1] > temp[p2]) {
            v[re++] = temp[p2++]; //더 작은 값 저장
        }
        else {
            v[re++] = temp[p1++];
        }
    }

    while (p1 <= m) {
        v[re++] = temp[p1++];
    }
    while (p2 <= end) {
        v[re++] = temp[p2++];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //입력
    int n; cin >> n;
    vector <int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    temp.assign(n,0);

    //병합 정렬으로 구현하기
    mergeSort(v,0, n-1);

    //출력
    for (int i = 0; i < n; i++) {
        cout << v[i]<<"\n";
    }
    return 0;
}