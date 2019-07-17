#ifndef __HASHER__CC__
#define __HASHER__CC__
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <bitset>
#include <mutex>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <openssl/md5.h>
using namespace std;

void hasher(string password) {
   mutex mtx;
   auto start = chrono::high_resolution_clock::now();
       string salt = "hfT7jp2q";
       string prealtsum = password + salt + password;
       string magic = "$1$";
       unsigned char result[16];
       unsigned char result2[16];
       unsigned char result3[16];
       char cry[] = {'.','/','0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
       //vector<char> crypt64 = ('.','/','0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z');
       MD5_CTX context;
       MD5_Init(&context);
       MD5_Update(&context, prealtsum.c_str(), prealtsum.size());
       MD5_Final(result, &context);
       basic_string<unsigned char> altsum;
       //string altsum(static_cast<char>(result));
       //cout << altsum << endl;
       //cout << std::hex << '\n';
       for (unsigned i = 0; i < 16; i++ ) {
           ///cout  << std::dec << int(result[i]) << endl;
           /*if (int(result[i]) >127) {
                //cout << hex << ~int(result[i]) << endl;
                altsum = altsum + result[i];
                cout << hex << int(altsum[altsum.size()-1]) << endl;
           }
           else {*/
            altsum = altsum + result[i];
           //}
           //cout << hex << result[i] << endl;
       } 
       //for (unsigned w = 0; w < altsum.size();w++) {
           //cout << std::hex << int(altsum[w]) << endl;
           //cout << std::dec << int(altsum[w]) << endl;
       //}
       //cout << altsum.size() << endl;
       //string preintsum = password + magic + salt + 
       //cout << prealtsum << endl;
       basic_string<unsigned char> preinterm0;
       
       for (int aa = 0; aa < password.size(); aa++) {
           preinterm0 = preinterm0 + static_cast<unsigned char>(password[aa]);
       }
       for (int bb = 0; bb < magic.size(); bb++) {
           preinterm0 = preinterm0 + static_cast<unsigned char>(magic[bb]);
       }
       for (int cc = 0; cc < salt.size(); cc++) {
           preinterm0 = preinterm0 + static_cast<unsigned char>(salt[cc]);
       }
       //string preinterm0 = password + magic + salt;
       if (password.size() < 16) {
                preinterm0 = preinterm0 + altsum.substr(0,password.size());
       }
       else {

       }
       string binary = std::bitset<8>(password.size()).to_string();
       //cout << binary << endl;
       int flag = binary.find('1');
       
       //cout << binary.size() << endl;
       //cout << flag << endl;
       for (int k = binary.size() -1; k >= flag ; k--) {
           if (binary[k] == '1') {
               preinterm0 = preinterm0 + static_cast<unsigned char>('\0');
           }
           else {
               preinterm0 = preinterm0 + static_cast<unsigned char>(password[0]);
           }
       }
       //for (int y = 0; y < preinterm0.size(); y++) {
          // cout << hex << int(preinterm0[y]) << endl;
          
   // }
       //cout << preinterm0 << endl;
       MD5_CTX context2;
       MD5_Init(&context2);
       MD5_Update(&context2, preinterm0.c_str(), preinterm0.size());
       MD5_Final(result2, &context2);
       basic_string<unsigned char> interm0;
       for (int d = 0; d < 16; d++) {
           //cout << hex <<int(result2[d]) << endl;
           interm0 = interm0 + result2[d];
           //cout << dec << int(interm0[d]) << endl;
           //cout << "------------------------" << endl;
       }
       //cout << endl;
       /*for (int z = 0; z < interm0.size(); z++) {
           cout << hex << int(interm0[z]) << endl;
           cout << "------------------------" << endl;
       }*/
       //cout << interm0 <<endl;
       MD5_CTX context3;
       basic_string<unsigned char> intermi = interm0;
       basic_string<unsigned char> intermi1;
       for (unsigned s = 0; s <= 999; s++ ) {
           intermi1.clear();
           if (s % 2 == 0) {
               intermi1 = intermi1 + intermi;
           }
            if (s % 2 == 1) {
               for (unsigned bh = 0; bh < password.size();bh++) {
               intermi1 = intermi1 + static_cast<unsigned char>(password[bh]);
               }
           }
           if (s%3 != 0) {
               for (unsigned zh = 0; zh < salt.size();zh++) {
               intermi1 = intermi1 + static_cast<unsigned char>(salt[zh]);
               }
           }
           if (s%7 != 0) {
               for (unsigned jh = 0; jh < password.size();jh++) {
               intermi1 = intermi1 + static_cast<unsigned char>(password[jh]);
               }
           }
           if (s % 2 == 0) {
               for (unsigned qh = 0; qh < password.size();qh++) {
               intermi1 = intermi1 + static_cast<unsigned char>(password[qh]);
               }
           }
            if (s % 2 == 1) {
               intermi1 = intermi1 + intermi;
           }
           MD5_Init(&context3);
           MD5_Update(&context3, intermi1.c_str(), intermi1.size());
           MD5_Final(result3, &context3);
           intermi.clear();
           for (unsigned q = 0; q < 16;q++) {
           intermi = intermi + result3[q];
           }
       }
       /*for (int ui = 0; ui < intermi.size(); ui++) {
           cout << hex << int(intermi[ui]) << ":";
       }*/
       //cout << endl;
       basic_string<unsigned char> preprefinal;
       string prefinal;
       string final;
       for (int c = 0; c < 16; c ++) {
               preprefinal = preprefinal + intermi[c];
       }
       prefinal = std::bitset<8>(preprefinal[11]).to_string() + std::bitset<8>(preprefinal[4]).to_string() + std::bitset<8>(preprefinal[10]).to_string() + std::bitset<8>(preprefinal[5]).to_string() + std::bitset<8>(preprefinal[3]).to_string() + std::bitset<8>(preprefinal[9]).to_string() + std::bitset<8>(preprefinal[15]).to_string() + std::bitset<8>(preprefinal[2]).to_string() + std::bitset<8>(preprefinal[8]).to_string() +std::bitset<8>(preprefinal[14]).to_string() + std::bitset<8>(preprefinal[1]).to_string() + std::bitset<8>(preprefinal[7]).to_string() + std::bitset<8>(preprefinal[13]).to_string() +std::bitset<8>(preprefinal[0]).to_string() +std::bitset<8>(preprefinal[6]).to_string() + std::bitset<8>(preprefinal[12]).to_string();
       //cout << intermi << endl;
       //cout << intermi1 << endl;
       //cout << atoi(prefinal.substr(122, 6).c_str()) << endl;
       //cout << cry[stoi(prefinal.substr(122, 6), NULL , 2)] << endl;
       for (int y = prefinal.size() -1; y > 1; y -=6) {
           //cout << stoi(prefinal.substr(y-5, 6), NULL , 2) << endl;
           //cout << cry[stoi(prefinal.substr(y-5, 6), NULL , 2)] << endl;
           final = final + cry[stoi(prefinal.substr(y-5, 6), NULL , 2)]; 
       }
       final = final + cry[stoi(prefinal.substr(0,2),NULL,2)];
       ofstream ofs;
       if (final == "OuCy/cfigw2ZVyQ0bkOOU.") {
            cout << password << endl;
            ofs.open("finalpassword.txt");
            ofs << password << endl;
            ofs << final << endl;
            ofs.close();
        }
        
       	auto stop = chrono::high_resolution_clock::now();
       	chrono::duration<double> elapsed = stop - start;
		mtx.lock();
		cout << elapsed.count() << endl;
		cout << password << endl;
		mtx.unlock();
}

/*int main () {
    
     cout << hasher("hfT7jp2q", "aaaaaa") << endl << "done\n";
    return 0;
}*/
#endif
