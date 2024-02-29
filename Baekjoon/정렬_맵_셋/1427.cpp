#include <iostream>
#include <algorithm>
#include <set>
#include <string>

using namespace std;
int main()
{
    int n; cin >> n ;
    multiset <int> s;
   
    for (int i = 0; i < 10; i++) {
        s.insert(n % 10);
        if (n / 10 == 0)
            break;
        else
            n = n / 10;
    }

    for (auto iter=s.rbegin();iter!=s.rend();iter++) {
        cout << *iter;
    }    
    return 0;
}
