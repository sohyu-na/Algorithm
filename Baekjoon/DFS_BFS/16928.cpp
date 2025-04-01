#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N;

queue < int> q;

int a[] = { 1,2,3,4 ,5,6};


int main() {
	cin >> N >> M;
	vector<int> v(101,0);
	vector<int> checked(101,100);
	
	int k=0;
	for (int i = 0; i < N; i++) {
		cin >> k;
		cin >> v[k]; //한번에 쓰면 v[k]로 입력 못받음음
	}
	for (int i = 0; i < M; i++) {
		cin >> k;
		cin >> v[k];
	}

	q.push(1);
	checked[1] = 0;

	while (!q.empty()) {
		k = q.front();
		q.pop();
		for (int i = 5; i >=0; i--) {
			if (k + a[i] <= 100 ) {
				if (v[k + a[i]] == 0 and checked[k + a[i]] > checked[k] + 1) {
					q.push(k + a[i]);
					checked[k + a[i]] = checked[k] + 1;
				}
				if (checked[v[k + a[i]]] > checked[k] + 1) {
					q.push(v[k + a[i]]);
					checked[v[k + a[i]]] = checked[k] + 1;

				}
			}
		}
	}
	
	cout << checked[100];
}