#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
typedef struct edge {
    int s, e, v;
    //> 연산자 오버로딩- 가중치 
    bool operator > (const edge& t) const {
        return v > t.v;
    }
};

vector<int> unf;//유니온 파인드 벡터
//find 연산
int find(int a) {
    if (a == unf[a]) {
        return a;
    }
    else {
        return unf[a] = find(unf[a]);
    }
}
//union 연산
void uni(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        unf[b] = a;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int v,e; cin >> v >> e;
    priority_queue <edge,vector<edge>,greater<edge>> pq; //에지 리스트 

    unf.resize(v+1);  
    for (int i = 1; i <= v; i++) {
        unf[i] = i;
    }

    //에지 정보 입력
    int a, b, c;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        pq.push(edge{ a,b,c });
    }

    int edge_cnt = 0; //에지 개수
    int edge_cost = 0; //에지 비용

    while (edge_cnt < v - 1) {
        edge n = pq.top();//가중치가 작은 에지 선택
        pq.pop();

        if (find(n.s) != find(n.e)) {//사이클이 생기지 않을 때
            uni(n.s, n.e); //union 연산
            edge_cost += n.v; //가중치 합산
            edge_cnt++;//에지 개수 ++
        }
    }

    cout << edge_cost; //총 비용 출력
   
    return 0;
}