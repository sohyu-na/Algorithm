#include <iostream>
#include <vector>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;
int N;
vector<vector<int>> v;
queue<pair<int, int>> q;

vector<int> ans;

int bfs(int a, int b);
int main() {
	cin >> N;
	v.resize(N);

	string arr;
	for (int i = 0; i < N; i++) {
		cin >> arr;
		for (int j = 0; j < arr.length(); j++) {
			//stoi 보다 -'0' 가 나음 
			v[i].push_back(arr[j] - '0');
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i][j]) {
				v[i][j] = 0;
				q.push(make_pair(i, j));
				ans.push_back(bfs(i, j));				
			}
		}
	}
	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
	
	
}

int bfs(int a, int b) {
	//cout << a << b<<"..";
	int k = 1;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		//cout << a << b << "]]";
		q.pop();
		if (a != 0 and v[a - 1][b]) {
			v[a - 1][b] = 0;
			q.push(make_pair(a - 1, b));
			//cout << a-1 << b << "//";
			k++;
		}
		if (b != 0 and v[a][b - 1]) {
			v[a][b - 1] = 0;
			q.push(make_pair(a, b - 1));
			//cout << a  << b-1 << "//";
			k++;
		}
		if (a != N - 1 and v[a + 1][b]) {
			v[a + 1][b] = 0;
			q.push(make_pair(a + 1, b));
			//cout << a + 1 << b << "//";
			k++;
		}
		if (b != N - 1 and v[a][b + 1]) {
			v[a][b + 1] = 0;
			q.push(make_pair(a, b + 1));
			//cout << a  << b +1<< "//";
			k++;
		}
	}
	//cout << k << '\n';
	return k;
}