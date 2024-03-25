#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//이거 안써도 걍 sort하면 이렇게 정렬됨 ...
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    else  {
        return a.first < b.first;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector <pair<int,int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].second>> v[i].first;
    }
    sort(v.begin(), v.end());
    
    int sum = 1;
    int temp;
    auto iter = v.begin();
    temp = iter->first;
    iter++;
    for (iter; iter != v.end(); iter++) {
        if (temp <= iter->second) {
            sum++;
            temp = iter->first;
        }
    }
    
    cout << sum;
    return 0;
}


