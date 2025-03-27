#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> vv;
vector<vector<int>> v;
int I;

queue <pair<int,int>> q;

int ac[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
int bc[] = { 1, 2, 2, 1, -1, -2, -2, -1 };


int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> I;
		vv.resize(I, 0);
		v.resize(I,vv);

		int A, B; cin >> A >> B;
		int c, d; cin >> c >> d;
		
		q.push(make_pair(A, B));
		
		while (!q.empty()) {
			int a = q.front().first;
			int b = q.front().second;
			
			int k = v[a][b];
			q.pop();
			for (int i = 0; i < 8; i++) {  
				if (a + ac[i] >= 0 and a + ac[i] < I and b + bc[i] >= 0 and b + bc[i] < I) {
					if (!v[a + ac[i]][b + bc[i]] and !(a + ac[i]==A and b+bc[i]==B)) {
						v[a + ac[i]][b + bc[i]] = k + 1; 
						q.push(make_pair(a + ac[i], b + bc[i]));
					}
				}
			}
		}
		cout << v[c][d]<<"\n";
		vv.clear();
		v.clear();
	}
}