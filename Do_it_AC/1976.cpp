#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n,m; 
int arr[1000001];
int find(int a) {
	if (a != arr[a]) return arr[a] = find(arr[a]);
	else return a;
}

int main() {
	cin >> n >> m;
	//노드 간 연결 여부 확인 -> 유니온파인드 트리구조
	//부모 노드 초기화 
	for (int i = 1; i <= n; i++) {
		arr[i] = i;//1 2 3
	}
	//연결 => 동일 부모 노드 값 
	int a;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a;
			if (j > i and a==1) {//대각선 위의 값만 
				int x = find(i);
				int y = find(j);
				if (x != y) {
					arr[x] = y;
				}
			}
		}
	}
	int k = 0;
	for (int i = 0; i < m; i++) {
		cin >> a;
		if (k == 0) {
			k = find(a);
		}
		else {
			if (k != find(a)) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}