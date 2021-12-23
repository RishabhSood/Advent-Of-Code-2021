#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int v;

    int x = 0;
    int y = 0;

    while(cin >> s && cin >> v)
    {
        if(s == "forward")
        {
            x += v;
        } else if (s == "down") {
            y += v;
        } else if (s == "up") {
            y -= v;
        }
    }

    cout << x*y;
}
