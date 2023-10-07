#include <iostream>
#include <string>
using namespace std;

void hitung_Arr(int total, int single) {
	cout << "Panjang array tersebut adalah " << total / single;
}

int main() {

	int arr[] = {2,6,4,7,9,5,3,6,4};

	hitung_Arr(sizeof(arr), sizeof(*arr));

	cin.get();
	return 0;
}
