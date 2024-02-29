#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
struct xy {
    int x;
    int y;
};

bool cmp(const xy &s1,const xy &s2) {
    if (s1.x != s2.x)
        return s1.x < s2.x;
    else
        return s1.y < s2.y;
}
int main()
{
    int n; cin >> n ;
    
    vector <xy> v(n);
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v[i].x = a;
        v[i].y = b;
    }
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << v[i].x << " "<<v[i].y<<"\n";
    }
    return 0;
}
