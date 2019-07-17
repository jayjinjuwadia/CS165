#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <fstream>

using namespace std;

//string generator () {
int main () {
    vector<string> combos;
    string s,a;
    ofstream ofs;
    unsigned oldcsz = 0;
    ofs.open("combos.txt");
    for (unsigned i = 97; i <123; i++) {
         s.clear();
         s.push_back(static_cast<char>(i));
        combos.push_back(s);
        //cout << combos.at(combos.size() - 1) << endl;
    }
    for (unsigned j = 0; j < 2; j++ ) {
        unsigned csz = combos.size();
        for (unsigned k = oldcsz; k < csz; k++) {
            for (unsigned l = 97; l <123; l++ ) {
                a.clear();
                a.push_back(static_cast<char>(l));
                combos.push_back(combos.at(k) + a);
               // cout << combos.at(combos.size() - 1) << endl;
            }
        }
        oldcsz = csz;
    }
    for (unsigned p = 0; p < combos.size(); p++) {
        ofs << combos.at(p) << endl;
    }
    //ofs << combos.size() << endl;
    //vector<string>::iterator it;
    //std::sort(combos.begin(), combos.end());
    //it = std::unique (combos.begin(), combos.end());
    //combos.resize( std::distance(combos.begin(),it) );
    //ofs << combos.size() << endl;
    ofs.close();
    
    //return "combos.txt";
}