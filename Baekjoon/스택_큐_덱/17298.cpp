#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	//입출력 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	stack <pair<int,int>> s;
	vector <int> v(n,-1);


	for (int i = 0; i < n;i++) {
		int a; cin >> a;
		while (!s.empty() && s.top().second < a) {
			v[s.top().first] = a;
			s.pop();
		}
		s.push(make_pair(i,a));
	}
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	return 0;
}