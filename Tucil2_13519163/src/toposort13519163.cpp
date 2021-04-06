/*
Nama    : Alvin Wilta
NIM     : 13519163
Kelas   : K03
Tugas   : Tucil 2 STIMA
*/

#include "graph13519163.hpp"
using namespace std;

void DAGraph::topoSort() {	
	for (int i = 0; i < this->jmlsudut; i++) {
        if (vis[i] == false) {
            iterate(i);
        }			
    }
    cout << endl;
    // printHasil();
}

// void DAGraph::printHasil() {
//     cout << "jumlah node" << endl;
//     for (int i=0; i<this->jmlsudut; i++) {
//         cout << i << " ";
//         cout << inbound[i] << endl;
//     }
// }


void DAGraph::iterate(int a) {
	vis[a] = true;
	list<int>::iterator i;
	for (i = node[a].begin(); i != node[a].end(); ++i) {
        ++inbound[*i];
        if (!vis[*i]) {
            iterate(*i);
        }		
    }
}

void DAGraph::sortSemester() {
    int sem = 0;
    for (sem; sem<this->jmlsudut; sem++) {          // majuin semester
        for (int i=0; i<this->jmlsudut; i++) {      // iterasi untuk nyari yang inbound = 0
            if (inbound[i]==0) {
                hasil[sem].push_back(i);            // sudut yang inbound = 0 ke semester terkait
                checkInboundFrom(i);
                inbound[i]=-1;
            }
        }
        for (int i=0; i<temp.size(); i++) {
            --inbound[temp[i]];
        }
        temp.clear();
    }
}

void DAGraph::checkInboundFrom(int a) {
    int x;
    list<int>::iterator it;
    for (it=node[a].begin(); it!=node[a].end(); ++it) {
        x = *it;
        temp.push_back(x);
    }
}

void DAGraph::printHasilSemester(map<int, string> dict, string ket) {
    for (int i=0; i<hasil.size(); i++) {
        if (!hasil[i].empty()) {
            cout << ket << " " << i+1 << ": ";
            for (int j=0; j<hasil[i].size(); j++) {
                cout << dict.find(hasil[i][j])->second << " ";
            }
            cout << endl;
        }
    }
}