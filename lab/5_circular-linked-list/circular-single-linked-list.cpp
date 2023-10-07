#include <iostream>
#include <string>
using namespace std;

struct NodeCSLL {
	int data;
	NodeCSLL* setelah;
};
struct CircularSingleLinkedList {
	NodeCSLL* pAwal, * pAkhir;
	int jumlah;
	CircularSingleLinkedList() {
		pAwal = NULL;
		pAkhir = NULL;
		jumlah = -1;
	}
	void sisipDataDiAwal(int data) {
		NodeCSLL* pBaru = new NodeCSLL();
		pBaru->data = data;
		pBaru->setelah = pBaru;
		if (pAwal == NULL) {
			pAwal = pBaru;
			pAkhir = pBaru;
			jumlah = 0;
		}
		else {
			pBaru->setelah = pAwal;
			pAkhir->setelah = pBaru;
			pAwal = pBaru;
			jumlah++;
		}
	}
	void sisipDataDiAkhir(int data) {
		// lengkapi bagian ini
		NodeCSLL* pBaru = new NodeCSLL();
		pBaru->data = data;
		pBaru->setelah = pBaru;
		if (pAwal == NULL) {
			pAwal = pBaru;
			pAkhir = pBaru;
		}
		else {
			pBaru->setelah = pAwal;
			pAkhir->setelah = pBaru;
			pAkhir = pBaru;
		}
		jumlah++;
	}
	void hapusData(int dtHapus) {
		if (pAwal != NULL) {
			NodeCSLL* pSbl, * pHapus;
			pSbl = NULL; pHapus = pAwal;
			bool ketemu = false;
			int i = 0;
			while (!ketemu && (i <= jumlah)) {
				if (pHapus->data == dtHapus) {
					ketemu = true;
				}
				else {
					pSbl = pHapus;
					pHapus = pHapus->setelah;
				}
				i++;
			}
			if (ketemu) {
				if (pSbl == NULL) {
					pAwal = pHapus->setelah;
					pAkhir->setelah = pAwal;
					delete pHapus;
				}
				else {
					if (pAkhir == pHapus) {
						pAkhir = pSbl;
					}
					pSbl->setelah = pHapus->setelah;
					delete pHapus;
				}
				jumlah--;
			}
		}
	}
	void hapusSatuDataDiAwal() {
		// lengkapi bagian ini
		if (pAwal == nullptr) {
			cout << "List kosong" << endl;
		}
		else if (pAwal == pAkhir) {
			delete pAwal;
			pAwal = nullptr;
			pAkhir = nullptr;
			jumlah--;
		}
		else {
			NodeCSLL* temp = pAwal;
			pAwal = pAwal->setelah;
			pAkhir->setelah = pAwal;
			delete temp;
			jumlah--;
		}
	}
	void hapusSatuDataDiAkhir() {
		// lengkapi bagian ini
		if (pAwal == nullptr) {
			cout << "List kosong" << endl;
		}
		else if (pAkhir->setelah == pAkhir) {
			delete pAkhir;
			pAkhir = nullptr;
			jumlah--;
		}
		else {
			NodeCSLL* temp = pAwal;
			while (temp->setelah->setelah != pAwal) {
				temp = temp->setelah;
			}
			NodeCSLL* hapus = temp->setelah;
			temp->setelah = pAwal;
			delete hapus;
		}
			jumlah--;
	}
	void cetak(string komentar) {
		cout << komentar << endl;
		NodeCSLL* pCetak;
		pCetak = pAwal;
		int i = -1;
		while ((i < jumlah)) {
			cout << pCetak->data << "->";
			pCetak = pCetak->setelah;
			i++;
		}
		cout << endl;
	}
};
	int main() {
		CircularSingleLinkedList *csll =
				new CircularSingleLinkedList();
		csll->sisipDataDiAwal(50);
		csll->sisipDataDiAwal(60);
		csll->sisipDataDiAwal(70);
		csll->sisipDataDiAwal(8);
		csll->sisipDataDiAwal(9);
		csll->sisipDataDiAwal(90);
		csll->sisipDataDiAwal(19);
		csll->cetak("csll Asal");
		cout << endl;
		csll->hapusData(8);
		csll->cetak("csll stl 8 dihapus");
		cout << endl;
		csll->hapusData(90);
		csll->cetak("csll stl 90 dihapus");
		cout << endl;

		csll->sisipDataDiAkhir(1000);
		csll->cetak("csll stl 1000 tambah akhir");
		cout << endl;
		csll->hapusSatuDataDiAwal();
		csll->cetak("csll stl hapus data awal");
		cout << endl;
		csll->sisipDataDiAkhir(2703);
		csll->cetak("csll stl 2703 tambah akhir");
		cout << endl;
		csll->hapusSatuDataDiAkhir();
		csll->cetak("csll stl hapus data akhir");

	}
