#include <iostream>
#include <string>
using namespace std;

int main()
{
	int i = 5, j = 10;
	int* ptr;
	int** pptr;

	ptr = &i; // ptr menyimpan alamat dari var i yang menjadikan ptr pointer dari i
	pptr = &ptr; // pptr merupakan pointer dari pointer ptr
	*ptr = 3; // ptr mengubah nilai yang ditunjuk olehnya, i
	cout << i << endl;
	**pptr = 7; // pptr mengubah nilai yang ditunjuk oleh variable yang ditunjuk olehnya
	cout << i << endl;
	ptr = &j; // ptr merupakan pointer dari j
	**pptr = 9; // pptr mengubah nilai j menjadi 9
	cout << j << endl;

	cin.get();
	return 0;
}
