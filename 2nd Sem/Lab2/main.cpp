#include "main.h"
#define _DEBUG
//#define _Sort
//#define _PathFinder

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

void SwapSort(int n, int* arr)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n-1; j++)
		{
			if(arr[j] > arr[j+1])
				std::swap(arr[j], arr[j+1]);
		}
	}
}

int StringLenght(std::string inp, int index = 0)
{
	if(inp[index])
		return 1 + StringLenght(inp, index+1);
	else
		return 0;
}

void PathFinder(int i, int j, int step, int n, int m, char field[100][100], int table[100][100])
{
	if(step > table[i][j])
	{	
		return;
	}
	table[i][j] = step;
	if(field[i][j] == 'E')
	{
		return;
	}

	if(i+1 < n && field[i+1][j] != '#')
	{
		PathFinder(i+1, j, step+1, n, m, field, table);
	}
	if(j+1 < m && field[i][j+1] != '#')
	{
		PathFinder(i, j+1, step+1, n, m, field, table);
	}
	if(i-1 >= 0 && field[i-1][j] != '#')
	{
		PathFinder(i-1, j, step+1, n, m, field, table);
	}
	if(j-1 >= 0 && field[i][j-1] != '#')
	{
		PathFinder(i, j-1, step+1, n, m, field, table);
	}


}

int main()
{
#ifdef _PathFinder
	char field[100][100];
	int table[100][100];
	std::ifstream in("input.txt");
	int n, m;
	int is, js, ie, je;
	in >> m >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			table[i][j] = INT_MAX;
			in >> field[i][j];
			if(field[i][j]=='S')
			{
				is = i;
				js = j;
			}
			if(field[i][j]=='E')
			{
				ie = i;
				je = j;
			}
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			std::cout << field[i][j] << " ";
		}
		std::cout << std::endl;
	}

	table[is][js] = 0;
	PathFinder(is, js, 0, n, m, field, table);
	std::cout << table[ie][je] << std::endl;
#endif

	std::string s;
	std::cin >> s;
	std::cout << StringLenght(s) << std::endl;

	
#ifdef _Sort
	//const int n = 11;
	const int n = 11000;
	int arr[n] = {3, 6, 8, 10, 1, 2, 1, 5, 7, 9, 3};
	int arr2[n] = {3, 6, 8, 10, 1, 2, 1, 5, 7, 9, 3};
#ifdef _DEBUG
	auto begin = std::chrono::high_resolution_clock::now();
	getchar();
#endif
	QuickSort(0, n-1, arr);
#ifdef _DEBUG
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
  	std::cout << "QuickSort time: " << elapsed_ms.count() << " ms\n";
#endif

#ifdef _DEBUG
	begin = std::chrono::high_resolution_clock::now();
#endif
	SwapSort(n, arr2);
#ifdef _DEBUG
	end = std::chrono::high_resolution_clock::now();
    elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
  	std::cout << "SwapSort time: " << elapsed_ms.count() << " ms\n";
#endif
	for(int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
	return 0;

#endif
}