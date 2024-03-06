#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;  cin >> n;
	vector <pair<int,int>> v(n);
	vector <int> v_1(n);
	
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		v[i] = make_pair(i, x);
	}
	stable_sort(v.begin(), v.end(), cmp);

	auto iter = v.begin();  int cnt = 0;
	v_1[iter->first] = cnt;
	for (iter; iter != v.end()-1; iter++) {
		if (iter->second == (iter + 1)->second) {
			v_1[(iter+1)->first] = cnt;
		}
		else {
			v_1[(iter + 1)->first] = ++cnt;
		}
			
	}
	for (int i = 0; i < n; i++) {
		cout << v_1[i] << " ";
	}
}