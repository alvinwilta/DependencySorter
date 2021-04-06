/*
Nama    : Alvin Wilta
NIM     : 13519163
Kelas   : K03
Tugas   : Tucil 2 STIMA
*/

#include "graph13519163.hpp"
using namespace std;


DAGraph::DAGraph(int t_jmlsudut) {
	this->jmlsudut = t_jmlsudut;
	node = new list<int>[t_jmlsudut];
	vis = new bool[this->jmlsudut];
	inbound = new int[this->jmlsudut];
	for (int i = 0; i < this->jmlsudut; i++) {
        vis[i] = false;
		inbound[i] = 0;
		hasil.push_back(vector<int>());
    }
	
}

void DAGraph::addSisi(int asal, int tujuan) {
	node[asal].push_back(tujuan);
}

void DAGraph::parseToGraph(map<int, string> ndict, vector<string> hasilparse) {
    int code = 0;
    int tempasal;
    int temptuj;
    for (int i=1; i<hasilparse.size()-1; i++) {
        if (hasilparse[i]=="\n") {
            code = i+1;
            i++;
        } else {
            tempasal = dictKey(ndict,hasilparse[i]);
            temptuj = dictKey(ndict,hasilparse[code]);
            addSisi(tempasal,temptuj);
        }
    }
}