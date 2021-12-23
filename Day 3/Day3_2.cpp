#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    // store valid string sets pertaining to each diagnostic
    vector<string> diag_ogr;
    vector<string> diag_co2sr;

    // count of zeros and ones at current index
    int z_ogr = 0;
    int o_ogr = 0;
    int z_co2sr = 0;
    int o_co2sr = 0;

    // initially get complete diagnostic from stdin
    while(cin >> s)
    {
        if(s[0] == '0')
        {
            z_ogr++;
        }
        else
        {
            o_ogr++;
        }
        diag_ogr.push_back(s);
    }

    // will be the same at start
    diag_co2sr = diag_ogr;
    z_co2sr = z_ogr;
    o_co2sr = o_ogr;

    // decoded oxygen and co2 ratings
    string ogr;
    string co2sr;

    // number of bits
    int n = diag_ogr[0].size();

    // to stop loop if one element is left
    bool of = false;
    bool cf = false;

    // loop until sizes of both ogr and co2 don't become n(no. of bits)
    while(ogr.size() < n || co2sr.size() < n)
    {
        // set flag and copy element to ogr if 1 left
        if(diag_ogr.size() == 1)
        {
            ogr = diag_ogr[0];
            of = true;
        }

        // set flag and copy element to co2sr if 1 left
        if(diag_co2sr.size() == 1)
        {
            co2sr = diag_co2sr[0];
            cf = true;
        }

        // stores newly evaluated sets
        vector<string> diag_new;
        // current length of ogr/co2sr
        int idx;

        // evaluate new valid set for ogr and update ones/zeros count
        if(!of)
        {   
            char ch_ogr = (o_ogr >= z_ogr) ? '1' : '0';
            ogr.push_back(ch_ogr);

            z_ogr = 0;
            o_ogr = 0;

            idx = ogr.size();

            for(auto elem : diag_ogr)
            {
                if(elem.substr(0, idx) == ogr)
                {
                    if(elem[idx] == '0')
                        z_ogr++;
                    else
                        o_ogr++;
                    diag_new.push_back(elem);
                }
            }

            diag_ogr = diag_new;
        }
        
        // evaluate new valid set for co2sr and update ones/zeros count
        if(!cf)
        {
            char ch_co2sr = (o_co2sr >= z_co2sr) ? '0' : '1';
            co2sr.push_back(ch_co2sr);

            z_co2sr = 0;
            o_co2sr = 0;

            diag_new.clear();

            idx = co2sr.size();

            for(auto elem : diag_co2sr)
            {
                if(elem.substr(0, idx) == co2sr)
                {
                    if(elem[idx] == '0')
                        z_co2sr++;
                    else
                        o_co2sr++;
                    diag_new.push_back(elem);
                }
            }

            diag_co2sr = diag_new;
        }
    }

    cout << stoi(ogr, 0, 2) << " * " << stoi(co2sr, 0, 2);
}
