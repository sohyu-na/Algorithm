#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
int n,m,t,a,b; 
vector<int> v;//진실을 아는 사람 
int arr[51];
int find(int a) {
	if (a != arr[a]) return arr[a] = find(arr[a]);
	else return a;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		arr[i] = i;//1 2 3
	}
	cin >> t;
	if (t == 0) {
		cout << m;
		return 0;
	}
	for (int i = 0; i < t; i++) {
		cin >> a;
		v.push_back(a);
	}
	vector<int> key(m);
	for (int i = 0; i < m; i++) {
		cin >> a;
		cin >> b;
		int x = find(b);
		for (int j = 1; j < a; j++) {
			cin >> b;
			int y = find(b);
			if (x != y) {
				arr[y] = x;
			}
		}
		key[i] = x;
	}
	set<int> s1;
	set<int> s2;
	vector<int> total;
	for (int i = 0; i < t; i++) {
		s1.insert(find(v[i]));
	}
	for (int i = 1; i <=n; i++) {
		s2.insert(find(arr[i]));
	}
	for (auto iter = s1.begin(); iter != s1.end(); iter++) {
		int s = s2.size();
		s2.insert(*iter);
		if (s == s2.size()) {//중복되어 존재하면
			s2.erase(*iter);
		}
	}
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		for (auto iter = s2.begin(); iter != s2.end(); iter++) {
			if (find(key[i]) == *iter) {
				cnt++;
			}
		}
	}
	cout << cnt;
}
