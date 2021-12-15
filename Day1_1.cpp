#include <iostream>
using namespace std;

int main() {
    int prev = -1;
    int curr;

    int inc = 0;

    while(cin >> curr)
    {
        if(prev != -1)
            if(curr > prev)
                inc++;
        prev = curr;
    }

    cout << inc;
}
