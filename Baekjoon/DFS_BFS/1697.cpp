#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, K;
vector<int> v;
queue <int> q;

int ans = 0;

int main() {
	cin >> N >> K;
	int big = N > K ? N : K;
	ans = K > N ? K - N : N - K;

	v.resize(2 * (big + 1), ans);

	v[N] = 0;
	q.push(N);

	int t;
	while (!q.empty()) {
		t = q.front();
		q.pop();
		//+1
		if (t + 1 <= K and v[t + 1] >= v[t] + 1) {
			//cout << t+1 << " " << v[t] + 1 << "-1\n";
			q.push(t + 1);
			v[t + 1] = v[t] + 1;
		}
		//-1
		if (t - 1 > 0 and v[t - 1] >= v[t] + 1) {
			//cout << t-1 << " " << v[t] + 1 << "-2\n";
			q.push(t - 1);
			v[t - 1] = v[t] + 1;
		}
		//*2
		if (2 * t < 2 * big and v[2 * t] >= v[t] + 1) {
			//cout << t*2 << " " << v[t] + 1 << "-3\n";
			q.push(2 * t);
			v[2 * t] = v[t] + 1;
		}
	}

	cout << v[K];
	return 0;
}
