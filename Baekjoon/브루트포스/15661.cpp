#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

void calculate(int n,int k, vector<vector<int>> &v, vector <int>& linkV, vector <int>& startV,int &bet) {
    if (k == n) { //종료
        int link = 0; int start = 0;
        if (linkV.size() > 0 and startV.size() > 0) { //한 명 이상일때
            //cout << linkV.size() << "//" << startV.size() << "//";
            for (int i = 0; i < linkV.size(); i++) {
                for (int j = i; j < linkV.size(); j++) {
                    link += v[linkV[i]][linkV[j]];
                    link += v[linkV[j]][linkV[i]];
                }
            }
            for (int i = 0; i < startV.size(); i++) {
                for (int j = i; j < startV.size(); j++) {
                    start += v[startV[i]][startV[j]];
                    start += v[startV[j]][startV[i]];
                }
            }
            //cout << start << "  " << link << "\n";
            if (abs(start - link) < bet) {
                bet = abs(start - link);
            }
        }
        return;
    }
    //i가 start
    linkV.push_back(k); //cout << k << "link\n ";
    calculate(n, k + 1, v, linkV, startV, bet);
    linkV.erase(linkV.begin() + linkV.size()-1);

    //i가 link 
    startV.push_back(k);// cout << k << "start\n ";
    calculate(n, k + 1, v, linkV, startV, bet);
    startV.erase(startV.begin() + startV.size()-1);
    
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<vector<int>>v(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    vector <int> linkV;
    vector <int> startV;

    int bet = INT16_MAX;
    calculate(n, 0, v, linkV, startV,bet);
    
    cout << bet;
    return 0;
}
