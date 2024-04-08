#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    int x; int i = 1;
    stack <int> s;
    vector <char> v;
    while(n--) {
        cin >> x;
        if (x >= i) {
            while (x >= i) {
                s.push(i); v.push_back('+'); 
                i++; 
            }
            s.pop(); v.push_back('-');
        }
        else if (x < i) {
            if(s.top()==x){
                s.pop(); v.push_back('-');
            }
            else {
                cout << "NO"; return 0;
            }
        }
    }

    for (auto iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << "\n";
    }
    
    return 0;
}