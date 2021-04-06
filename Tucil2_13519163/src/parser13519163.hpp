/*
Nama    : Alvin Wilta
NIM     : 13519163
Kelas   : K03
Tugas   : Tucil 2 STIMA
*/

#ifndef _PARSER_HPP_
#define _PARSER_HPP_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
using namespace std;

/**
 * Fungsi untuk parsing file dan memasukkan semua nilai didalam file ke dalam vector<string>
 * @param {string} filepath dari file test
 * @return {vector<string>} hasil dari parsing file
 **/
vector<string> parseFile(string &filepath);

/**
 * Fungsi untuk membuat mapping/dictionary dari hasil parsefile
 * @param {vector<string>} vector of string dari hasil parsing file
 * @return {map<int, string>} map dari hasil parse file dengan int sebagai key
 **/
map<int, string> dictionary(vector<string> hasilparse);

/**
 * Fungsi untuk mengembalikan key dari map berdasarkan isinya
 * @param {map<int, string>} mapping sudut dan key nya
 * @param {string} nilai yang mau dicari key nya dari map
 * @return {int} nilai dari key yang sudah dicari
 **/
int dictKey(map<int, string> ndict, string key);

/**
 * Fungsi untuk meminta filepath dan memparse file
 * @param {string} nama file beserta extensionnya (filetype)
 * @return {string} path lengkap dari file tersebut (di dalam test)
 **/
string inputFilePath();

/**
 * Fungsi untuk meminta keterangan
 * @return {string} keterangan
 **/
string getKet();

#endif