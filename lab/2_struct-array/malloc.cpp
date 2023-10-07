#include <iostream>
#include <string>
using namespace std;

int main()
{
	int num, i, * ptr, sum = 0;
	cout << "Enter number of elements: ";
	cin >> num;
	ptr = (int*)malloc(num * sizeof(int));
	if (ptr == NULL)
	{
		cout << "Error! memory not allocated.";
		exit(0);
	}

	cout << "Enter elements of array: ";
	for (i = 0; i < num; ++i)
	{
		cin >> *(ptr + i);
		sum += *(ptr + i); // hasil akhir adalah akumulasi dari angka yang dimasukkan
	}
	cout << "Sum = " << sum;
	free(ptr);

	cin.get();
	return 0;
}
