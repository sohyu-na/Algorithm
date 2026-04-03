#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    // 그래프 
    vector<vector<int>> graph(n+1);
    for(int i=0;i<edge.size();i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    
    // bfs
    vector<int> dist(n+1,INT_MAX);
    queue<int> q;
    q.push(1);
    dist[1]=0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(auto next : graph[node]){
            if(dist[next]==INT_MAX){
                dist[next]=dist[node]+1;
                q.push(next);
            }
        }
    }
    
    int maxDist = 0;
    
    for(int i=1;i<=n;i++){
        if(dist[i] == INT_MAX) continue;
        
        if(dist[i] > maxDist){
            maxDist = dist[i];
            answer = 1;
        } else if(dist[i] == maxDist){
            answer++;
        }
    }
    return answer;
}