#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
vector<tuple<int, int, int>> v[10];//벡터-배열
long d[10];
bool visited[10];
void dfs(int n) {
	//현재 노드 방문 표시 
	visited[n] = true;
	//현재 노드와 인접한 노드를 탐색 
	for (tuple<int, int, int> i : v[n]) {
		int t = get<0>(i);
		if (!visited[t]) {
			//현재 노드와 다음 노드의 비율로 다음 노드값 업데이트 
			d[t] = d[n] * get<2>(i) / get<1>(i);
			dfs(t);
		}
	}
}
int main() {
	int n; cin >> n;
	int a, b, p, q;
	long k = 1;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b >> p >> q;
		//순서대로 입력을 받으면 비율을 연관지어 표시할 방법이 없음 
		//일단 인접 리스트로 입력을 다 받은 후 탐색하기 
		v[a].push_back(make_tuple(b, p, q));
		v[b].push_back(make_tuple(a, q, p));

		//비율에 관한 수(p,q)에 대해 전체 최소공배수 구하기 
		k *= ((p * q) / __gcd(p, q));
	}
	//0에 전체 최소 공배수를 대입하고 dfs 시작 - 비율에 맞춰 업데이트됨 
	d[0] = k;
	dfs(0);

	long m = d[0];
	for (int i = 1; i < n; i++) {
		m = __gcd(m, d[i]); //전체 최대 공약수 찾기 
	}
	for (int i = 0; i < n; i++) {
		cout << d[i] / m << " "; // 최대 공약수로 나누어 출력 
	}
	
}