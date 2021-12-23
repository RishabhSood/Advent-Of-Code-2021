#include <bits/stdc++.h>
using namespace std;

int main() {
    string packet;
    cin >> packet;

    map<char, string> hexParser;
    char res[4];
    char c;
    for(int i = 0; i < 10; i++)
    {
        c = i;
        hexParser[c] = bitset<4>(i).to_string();
    }
    c = 'A';
    for(int i = 0; i < 6; i++)
    {
        char k = c + i;
        hexParser[k] = bitset<4>(10 + i).to_string();
    }
    
}
