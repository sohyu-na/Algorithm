#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;
int n;
vector<pair<int, int>> v;
int change1(int k) {
	if (k == 1) {
		return 2;
	}
	else if (k == 2) {
		return 3;
	}
	else {
		return 1;
	}
}
int change2(int k) {
	if (k == 1) {
		return 3;
	}
	else if (k == 2) {
		return 1;
	}
	else {
		return 2;
	}
}
void input() {

}
void top(int i,int k) {//1-3 0-2로
	if (i > n) {
		return;
	}
	int s = v.size();
	v.push_back(make_pair(1, k + 2)); 
	int a, b;
	if (k == 0) {
		for (int j = 0; j < s; j++) {
			a = change2(v[j].first);
			b = change2(v[j].second);
			v.push_back(make_pair(a, b));
		}
	}
	else {
		for (int j = 0; j < s; j++) {
			a = change1(v[j].first);
			b = change1(v[j].second);
			v.push_back(make_pair(a, b));
		}
	} 
	top(i + 1, (k + 1) % 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	top(1, n % 2);
	cout << v.size() << "\n";
	for (auto iter = v.begin(); iter != v.end(); iter++) {
		cout<<((*iter).first)<<" "<<(*iter).second<<"\n";
	}
}  