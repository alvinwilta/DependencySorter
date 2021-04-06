/*
Nama    : Alvin Wilta
NIM     : 13519163
Kelas   : K03
Tugas   : Tucil 2 STIMA
*/

#include "parser13519163.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string filepath = "../test/test.txt";
    vector<string> test = parseFile(filepath);
    for(int i=0; i < test.size(); i++) {
        std::cout << test.at(i) << ' ';
    }
    getchar();
    return 0;
}