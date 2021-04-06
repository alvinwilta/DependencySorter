/*
Nama    : Alvin Wilta
NIM     : 13519163
Kelas   : K03
Tugas   : Tucil 2 STIMA
*/

#include "parser13519163.hpp"

using namespace std;
extern string ket;

vector<string> parseFile(string &filepath) {
    // Membaca file input
    vector<string> calongraph;
    ifstream in(filepath);
    // define comma dan period sebagai delimiter
    string comma = ", ";
    string period = ".";
    // Membuka file
    if (in.is_open()) {
        string temp;
        while (getline(in, temp)) {
            size_t position = 0;
            string token;
            while ((position = temp.find(comma)) != string::npos || (position = temp.find(period)) != string::npos ) {
                // Token diambil dari file dan dimasukkan ke dalam calongraph
                token = temp.substr(0, position);
                calongraph.push_back(token);

                // Membuang delimiter comma dan period dengan menghapus sebanyak delimiter
                if (temp.find(comma)) {
                    temp.erase(0, position + 2);
                } else if (temp.find(period)) {
                    temp.erase(0, position + 1);
                }
            }
            calongraph.push_back("\n");
        }
    } else {
        cout << "file gagal dibuka, mungkin penamaan file anda salah?" << endl;
    }
    // Handling error jika gagal DAN belum mencapai EOF pada file
    if(in.fail() && !in.eof())
        cout << "File error saat dibuka" << endl;

    // File ditutup kembali
    in.close();

    return calongraph;
}



map<int, string> dictionary(vector<string> hasilparse) {
    // Referensi dari dictionary python
    map<int, string> dict;
    dict.insert(make_pair(0,hasilparse[0]));
    int idx = 1;
    for (int i=0; i<hasilparse.size()-1; i++) {
        if (hasilparse[i]=="\n") {
            dict.insert(make_pair(idx,hasilparse[i+1]));
            idx++;
        }
    }
    return dict;
}


int dictKey(map<int, string> ndict, string key) {
    map<int, string>::iterator itr; 
    for (itr = ndict.begin(); itr != ndict.end(); ++itr) { 
        if (itr->second==key) {
            return itr->first;
        }
    }
    return 0; // sebagai pengaman
}


string inputFilePath() {
    string input;
    cout << "\n";
    cout << "Selamat datang di Postulationem!\n";
    cout << "Program untuk mengetahui urutan kebutuhan anda!\n";
    cout << "\n";
    cout << "mohon masukkan nama file yang ingin anda parse beserta extensionnya (misal test1.txt)\n";
    cout << "*** tolong pastikan file anda sudah ada di folder test ***\n";
    cout << "input nama file anda: ";
    getline(cin,input);
    cout << endl;
    return "../test/" + input;
}

string getKet() {
    string ket;
    cout << "Proses selesai!\n\n";
    cout << "Masukkan format nama yang anda inginkan!\n";
    cout << "Misalnya 'Semester' atau 'Modul' tanpa tanda petik\n";
    cout << "jika anda kosongkan (press enter) maka defaultnya adalah Semester" << endl;
    getline(cin,ket);
    if (ket.length()==0) {
        ket = "Semester";
    }
    return ket;
}