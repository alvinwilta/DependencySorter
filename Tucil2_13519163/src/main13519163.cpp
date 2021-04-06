/*
Nama    : Alvin Wilta
NIM     : 13519163
Kelas   : K03
Tugas   : Tucil 2 STIMA
*/

#include "parser13519163.hpp"
#include "graph13519163.hpp"
#include <iostream>
using namespace std;


void print_map(map<int, string> dict)
{
    for (auto const& pair: dict) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}

int main() {
    string path = inputFilePath();
    vector<string> hasilparse = parseFile(path);
    map<int, string> dict = dictionary(hasilparse);
    DAGraph G(dict.size());
    //printHasilParse(hasilparse);
    G.parseToGraph(dict,hasilparse);
    // print_map(dict);
    G.topoSort();
    G.sortSemester();
    string ket = getKet();
    G.printHasilSemester(dict, ket);
    
    return 0;
}