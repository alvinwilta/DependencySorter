/*
Nama    : Alvin Wilta
NIM     : 13519163
Kelas   : K03
Tugas   : Tucil 2 STIMA
*/

#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include "parser13519163.hpp"

using namespace std;


class DAGraph {
    private:
    // VARIABEL KEBUTUHAN GRAPH
        // jumlah sudut dari graph
        int jmlsudut;
        // "list" dari sudut-sudut pada graph (graph dengan implementasi linked list)
        list<int>* node;

    // VARIABEL KEBUTUHAN TOPOSORT
        // keep track yang sudah dikunjungi dan belum dikunjungi
        bool* vis;
        // Menyimpan list sudut yang akan dihapus inboundnya
        vector<int> temp;
        // Menyimpan jumlah inbound
        int* inbound;
        // Menyimpan node per semesternya
        vector<vector<int>> hasil;

    // FUNGSI REKURSIF iterate
        /**
         * Fungsi untuk melakukan Depth First Search, untuk membantu toposort (rekursif)
         * @param {int} a sebagai node yang di-"visit"
         **/
        void iterate(int a);
    // FUNGSI PEMBANTU
        /**
         * Mengecek sudut mana yang memiliki inbound bersangkutan dengan a dan memasukkan ke vector temp
         * @param {int} a sebagai node incoming
         **/
        void checkInboundFrom(int a);
    public:
        /**
         * Konstruktor Directed Acyclic Graph
         * @param {int} jumlah sudut
         **/
        DAGraph(int t_jmlsudut);

        /**
         * Menambahkan sudut pada DAG
         * @param {int} id sudut asal
         * @param {int} id sudut tujuan
         **/
        void addSisi(int asal, int tujuan);
        
        /**
         * Fungsi untuk memasukkan sisi ke dalam graph sesuai dengan hasil parser/ meng-encode hasil parse,
         * kemudian memasukannya ke dalam graph
         * @param {map<int, string>} map untuk meng-encode hasil parse
         * @param {vector<string>} hasil parse yang akan di-encode
         * @param {DAGraph} Graph yang akan ditambahkan sisinya
         **/
        void parseToGraph(map<int, string> ndict, vector<string> hasilparse);

        /**
         * Melakukan toposort dan membagi hasil sorting sesuai dengan prerequsitesnya
         **/
        void topoSort();
        
        /**
         * Menyusun hasil dari penghitungan inbound dengan menguranginya
         **/
        void sortSemester();
        

        // Print
        /**
         * Print hasil dari semester
         **/
        void printHasilSemester(map<int, string> dict, string ket);
        /**
         * Print hasil dari toposort
         **/
        void printHasil();

    
};




//Sudut* vectortoArray(map<int, string> ndict, vector<string> hasilparse);
//int jmlSisi(map<int, string> ndict, vector<string> hasilparse);

//void printList(Sudut* ptr);
//void printGraph(DAGraph G, int size);
#endif