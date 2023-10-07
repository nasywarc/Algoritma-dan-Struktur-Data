// Nasywa Azizah Zharifah
// 225150307111060

#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
	string nama;
	int nim;
	int nilaiASD;
	int nilaiAOK;
	int nilaiBDT;
};

int main() {

	Mahasiswa mhs[10] = { {"Cici", 859305837, 79, 89, 88}, {"Budi", 462895077, 73, 70, 89},
	{"Alif", 852976028, 98, 83, 92},{"Rere", 465789343, 96, 78, 82},{"Farrel", 859305358, 85, 83, 91},
	{"Hana", 859305000, 90, 86, 80},{"Dodi", 859305126, 70, 95, 85},{"Vano", 859305749, 79, 90, 78},
	{"Lala", 859305888, 81, 93, 82},{"Monik", 859305322, 88, 85, 97} };
	
	int total[10];

	for (int i = 0; i < 10; i++) {
		total[i] = 0;
	}

	for (int i = 0; i < 10; i++) {
		total[i] += mhs[i].nilaiASD;
		total[i] += mhs[i].nilaiAOK;
		total[i] += mhs[i].nilaiBDT;
	}

	for (int i = 0; i < 10; i++) {
		cout << "Mahasiswa ke-" << i + 1 << ":" << endl;
		cout << "\tNama : " << mhs[i].nama << endl;
		cout << "\tNIM : " << mhs[i].nim << endl;
		cout << "\tNilai ASD : " << mhs[i].nilaiASD << endl;
		cout << "\tNilai AOK : " << mhs[i].nilaiAOK << endl;
		cout << "\tNilai BDT : " << mhs[i].nilaiBDT << endl;
		cout << "\tTotal Nilai : " << total[i] << endl << endl;
	}

	cout << "Mahasiswa yang memiliki total nilai tertinggi adalah " << mhs[2].nama << " dengan total nilai sebanyak " << total[2];

	cout << endl << endl;

	float rataASD, rataAOK, rataBDT;

	rataASD = 0;
	rataAOK = 0;
	rataBDT = 0;

	for (int i = 0; i < 10; i++) {
		rataASD += mhs[i].nilaiASD;
	}

	for (int i = 0; i < 10; i++) {
		rataAOK += mhs[i].nilaiAOK;
	}

	for (int i = 0; i < 10; i++) {
		rataBDT += mhs[i].nilaiBDT;
	}

	cout << "Rata-rata nilai mata kuliah ASD : " << rataASD / 10 << endl;
	cout << "Rata-rata nilai mata kuliah AOK : " << rataAOK / 10 << endl;
	cout << "Rata-rata nilai mata kuliah BDT : " << rataBDT / 10 << endl;

	cin.get();
	return 0;
}
