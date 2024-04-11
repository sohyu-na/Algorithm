#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,p; cin >> n>>p;
    int x,y;
    vector<priority_queue<int>>v(7);
    int cnt = 0;
    while (n--) {
        cin >> x>>y;
        while (!v[x].empty() and v[x].top()>y){
            v[x].pop(); cnt++;
        }
        if (!v[x].empty() and v[x].top() == y) {
            continue;
        } 
        v[x].push(y); cnt++;   
    }
    cout << cnt;
    return 0;
}