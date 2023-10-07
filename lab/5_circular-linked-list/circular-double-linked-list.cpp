#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

struct NodeCDLL {
	int data;
	NodeCDLL* sebelum;
	NodeCDLL* setelah;
};
struct CircularDoubleLinkedList {
	NodeCDLL* pAwal, * pAkhir;
	int jumlah;
	CircularDoubleLinkedList() {
		pAwal = NULL;
		pAkhir = NULL;
		jumlah = -1;
	}
	void sisipDataDiAwal(int data) {
		NodeCDLL* pBaru = new NodeCDLL();
		pBaru->data = data;
		pBaru->sebelum = pBaru;
		pBaru->setelah = pBaru;
		if (pAwal == NULL) {
			pAwal = pBaru;
			pAkhir = pBaru;
			jumlah = 0;
		}
		else {
			pBaru->sebelum = pAkhir;
			pBaru->setelah = pAwal;
			pAwal->sebelum = pBaru;
			pAkhir->setelah = pBaru;
			pAwal = pBaru;
			jumlah++;
		}
	}
	void sisipDataDiAkhir(int data) {
		NodeCDLL* pBaru = new NodeCDLL();
		pBaru->data = data;
		pBaru->sebelum = pBaru;
		pBaru->setelah = pBaru;
		if (pAwal == NULL) {
			pAwal = pBaru;
			pAkhir = pBaru;
		}
		else {
			pBaru->setelah = pAwal;
			pBaru->sebelum = pAkhir;
			pAwal->sebelum = pBaru;
			pAkhir->setelah = pBaru;
			pAkhir = pBaru;
			jumlah++;
		}

	}
	void hapusData(int dtHapus) {
		if (pAwal == nullptr) {
			cout << "List kosong" << endl;
			return;
		}

		if (dtHapus == 0) {
			if (pAwal == pAkhir) {
				delete pAwal;
				pAwal = nullptr;
				pAkhir = nullptr;
			}
			else {
				NodeCDLL* temp = pAwal;
				pAwal = pAwal->setelah;
				pAwal->sebelum = pAkhir;
				pAkhir->setelah = pAwal;
				delete temp;
			}
			return;
		}

		NodeCDLL* temp = pAwal;
		for (int i = 0; i < dtHapus - 1; i++) {
			temp = temp->setelah;
			if (temp == pAkhir) {
				cout << "Index tidak mencukupi" << endl;
				return;
			}
		}

		if (temp->setelah == pAkhir) {
			delete pAkhir;
			pAkhir = temp;
			pAkhir->setelah = pAwal;
			pAwal->sebelum = pAkhir;
		}
		else {
			NodeCDLL* delNode = temp->setelah;
			temp->setelah = delNode->setelah;
			delNode->setelah->sebelum = temp;
			delete delNode;
			jumlah--;
		}
	}
	void cetak(string komentar) {
		cout << komentar << endl;
		NodeCDLL* pCetak;

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
		CircularDoubleLinkedList* cdll = new CircularDoubleLinkedList();
		cdll->sisipDataDiAwal(70);
		cdll->sisipDataDiAwal(60);
		cdll->sisipDataDiAwal(50);
		cdll->sisipDataDiAwal(8);
		cdll->sisipDataDiAwal(9);
		cdll->sisipDataDiAwal(19);
		cdll->sisipDataDiAwal(90);
		cdll->cetak("cdll Asal");
		cout << endl;

		cdll->sisipDataDiAkhir(2000);
		cdll->cetak("cdll stl tambah akhir 2000");
		cout << endl;
		cdll->sisipDataDiAkhir(2703);
		cdll->cetak("cdll stl tambah akhir 2703");
		cout << endl;
		cdll->hapusData(4);
		cdll->cetak("cdll stl index ke-4 sebelumnya dihapus");
	}
