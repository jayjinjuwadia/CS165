#include "hasher.cc"
#include "omp.h"
#include <chrono>
#include <thread>
#include <queue>
using namespace std;

int main() {
    ifstream ifs;
    
    ifs.open("combos.txt");
    //string hash = "OuCy/cfigw2ZVyQ0bkOOU.";
    if (!ifs.is_open()) {
        exit(1);
    }
    string password;
   // string hash2;
    vector<thread>tharray;
    int i = 0;
    queue<string> q;
    while (!(ifs.eof())) {
    /*for (int i = 0; i < 321272406; i++) {
        if(!(ifs >> password)) {
            exit(1);
        }*/
      while (q.size() < 4) {
	ifs>> password;
        q.push(password);
      }

      //auto start = chrono::high_resolution_clock::now();
      for (int i = 0; i < 4; i++) {
	//	cout << q.front() << endl;
	tharray.push_back(thread(hasher,q.front() ));
	q.pop();
	
      }
      for (int g = 0; g < 4; g++) {
	tharray.at(g).join();
      }
      tharray.clear();

    }

        //t.join();
	//hasher(password);
        //auto stop = chrono::high_resolution_clock::now();
        //hash2 = hasher("hfT7jp2q", password);
        //chrono::duration<double> elapsed = stop - start;
        //password.clear();
        //cout << elapsed.count() << endl;
    
    /*r (int u = 0; u < tharray.size(); u++) {
      tharray.at(u).join();
      }*/
    //}
    /*auto start = chrono::high_resolution_clock::now();
    string poo = hasher("hfT7jp2q", "abcdef");
    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = stop - start;
    cout << elapsed.count() << endl;
    cout << poo << endl;*/
    return 0;
}
