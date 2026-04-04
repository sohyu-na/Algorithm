#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
    vector<set<int>> v(9);
    int ten = N;
    v[1].insert(ten); if(ten==number) return 1;
    
    for(int i=2;i<9;i++){
        ten = ten*10+N;
        v[i].insert(ten); if(ten==number) return i;
        
        for(int x=1;x<i;x++){
            for(auto s: v[i-x]){
                for(auto y : v[x]){
                    v[i].insert(s+y); if(s+y==number) return i;
                    v[i].insert(s-y); if(s-y==number) return i;
                    v[i].insert(s*y); if(s*y==number) return i;
                    if(y!=0){ 
                        v[i].insert(s/y);
                        if(y!= 0 && s/y==number) return i;
                    }
                }
            }
        }
    }
    return -1;
}