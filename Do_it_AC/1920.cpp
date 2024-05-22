#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector <int>& v, int t, int n) {
    int left = 0; int right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (v[mid] == t) {
            return 1;
        }
        else if ( v[mid]<t) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector <int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(),nums.end());//정렬

    int t;
    int m; cin >> m;
    while (m--) {
        cin >> t;
        ///이분 탐색
        cout << binarySearch(nums, t, n)<<"\n";
    }
    
    return 0;
}