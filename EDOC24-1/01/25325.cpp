#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b) {
    if(a.first == b.first){
        return a.second<b.second;
    }
        return a.first > b.first;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    string str;
    map <string, int> m;
    for (int i = 0; i < n; i++) {
        cin >> str;
        m[str] = 0;
    }
    getline(cin, str);
    for (int i = 0; i < n; i++) {
        string name = ""; 
        string input = "";
        getline(cin, input);

        for (int j = 0; j < input.length(); j++) {
            if (input[j] == ' ') {
                m[name]++;
                name = "";
            }
            else {
                name += input[j];
            }
        }
        m[name]++;
    }
    vector <pair<int, string>> v;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        v.push_back(make_pair(iter->second, iter->first));
    }
    sort(v.begin(), v.end(), cmp);
    for (auto iter = v.begin(); iter != v.end(); iter++) {
        cout << iter->second << " " << iter->first << "\n";
    }

    return 0;
}


