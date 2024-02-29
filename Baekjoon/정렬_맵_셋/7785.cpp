#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n; cin >> n;
    set <string> s_log ;
    string k, l ;
    for (int i=0;i<n;i++){
        cin >> k >> l;
        if(l=="enter")
            s_log.insert(k);
        else
            s_log.erase(k);
    }
    for(auto iter = s_log.end();iter !=s_log.begin();){
        iter--;
        cout << *iter <<'\n';
    }
    /*참고코드
    for (auto iter =s_log.rbegin();iter!=s_log.rend();iter++)
        cout << *iter << "\n";
    */
    return 0;
}