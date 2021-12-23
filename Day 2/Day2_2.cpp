#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int v;

    int x = 0;
    int y = 0;
    int aim = 0;

    while(cin >> s && cin >> v)
    {
        if(s == "forward")
        {
            x += v;
            y += aim*v;
        } else if (s == "down") {
            aim += v;
        } else if (s == "up") {
            aim -= v;
        }
    }

    cout << x*y;
}
