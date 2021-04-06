/*
Nama    : Alvin Wilta
NIM     : 13519163
Kelas   : K03
Tugas   : Tucil 2 STIMA
*/
#include "graph13519163.hpp"
using namespace std;

int main() {
    DAGraph g(5);
    g.addSisi(2, 1);
    g.addSisi(2, 3);
    g.addSisi(1, 3);
    g.addSisi(1, 0);
    g.addSisi(3, 0);
    g.addSisi(3, 4);
    g.addSisi(0, 4);
 
    cout << "Following is a Topological Sort of the given graph \n";
 
    // Function Call
    g.topoSort();
    g.sortSemester();
    g.printHasilSemester();
    
    return 0;
}