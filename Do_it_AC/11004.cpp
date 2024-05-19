#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int findPivot(int start, int end, vector <int>& v) {
    if (start + 1 == end) {//2개
        if (v[start] > v[end]) {
            swap(v[start], v[end]);
        }
        return end;
    }
    int m = (start + end) / 2;
    swap(v[start], v[m]);

    int piv = v[start];
    int i = start + 1;
    int j = end;

    while (i <= j) {
        while (i <= end and piv > v[i]) {
            i++;
        }
        while (j >= start + 1 and piv < v[j]) {
            j--;
        }
        if (i < j) {
            swap(v[i++], v[j--]);
        }
        else {
            break;
        }
    }
    v[start] = v[j];
    v[j] = piv;

    return j;
}
//
void quickSort(vector<int>& v, int start, int end, int k) {
    int piv = findPivot( start, end,v);
    if (piv == k) {
        return; 
    }
    else if (piv > k) {//범위 : start~piv-1
        quickSort(v, start, piv - 1, k);
    }
    else {//범위 : piv+1~end
        quickSort(v, piv + 1, end, k);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,k; cin >> n >> k;
    vector <int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    //퀵정렬으로 구현하기
    quickSort(v, 0, n - 1, k - 1);
    cout << v[k - 1];
    
    return 0;
}