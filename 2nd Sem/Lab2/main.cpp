#include "main.h"
#include <algorithm>



void QuickSort(int a, int b, int* arr)
{
	if(a>=b)
		return;
	int m = arr[(a+b)/2];
	int l = a-1;
	int r = b+1;
	while(1)
	{
		do
		{
			l++;
			//std::cout << "l = " << l << "m = " << r << std::endl;
		} 
		while (arr[l] < m);
		do r--; while (arr[r] > m);
		if (l >= r)
			break;
		std::swap(arr[l], arr[r]);
	}
	l = r;
	r++;
	QuickSort(a, l, arr);
	QuickSort(r, b, arr);

}


int main()
{
	const int n = 10;
	int arr[n] = {1, 5, 3, 7, 2, 4, 6, 8, 9, 0};
	QuickSort(0, n-1, arr);

	for(int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
	return 0;
}