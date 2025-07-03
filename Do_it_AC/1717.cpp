#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n,m; 
int arr[1000001];
int find(int a) {//경로 압축
	if (a == arr[a]) return a;
	else return (arr[a] = find(arr[a]));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	//1~n 노드 인접리스트 표현-> union-find 트리구조
	//v.resize(n + 1);
	for (int i = 0; i < n+1; i++) {
		arr[i] = i;//부모 노드 초기화 
	}
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a == 0) {//합집합 -> union연산
			int x = find(b);
			int y = find(c);
			if (x != y) { //한쪽으로 
				arr[y] = x;
			}
		}
		else {//같은 집합인지 확인-> find연산
			if (find(b) == find(c)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
}