#include "laba6.h"
#include <algorithm>
using namespace std;

bool is19(int inp)
{
	int c = 0;
	while (inp > 0) {
		c += inp % 10;
		inp /= 10;
	}
	return c==19;
}

bool StEnd(int inp)
{
	int first=10;
	int last;
	while (inp >= 10) {
		if (first == 10) {
			first = inp % 10;
		}
		inp /= 10;
	}
	last = inp;
	return (last == first);
}
int fisrtNum(int inp)
{
	while (inp >= 10)
	{
		inp /= 10;
	}
	return inp;
}
bool NumEnd(int inp){
	while (inp >= 10) {
		inp /= 10;
	}
	return inp == 3;
}

int SumNums(int inp)
{
	int sum = 0;
	while (inp > 0) {
		sum += inp % 10;
		inp /= 10;
	}
	return sum;
}

int No1()
{
	int n;
	cin >> n;
	int arr[10000];
	bool DoSort = false;
	for (int i = 0; i < n; i++) {
		int inp;
		cin >> inp;
		if (is19(inp)) {
			DoSort = true;
		}	
		arr[i] = inp;
	}
	if (!DoSort) {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (arr[i] < arr[j]) {
					int tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}

int No2()
{
	int n;
	cin >> n;
	int arr[10000];
	int inp;
	for (int i = 0; i < n; i++) {
		cin >> inp;
		arr[i] = inp;
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (SumNums(arr[i]) > SumNums(arr[j])) {
				swap(arr[i], arr[j]);
			}
			else if (fisrtNum(arr[i]) > fisrtNum(arr[j])) {
				swap(arr[i], arr[j]);
			}
			else if (arr[i] > arr[j]) {
				swap(arr[i], arr[j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}

int No3()
{
	int n, m;
	cin >> n >> m;
	int arr[100][100];
	int inp;
	int max = numeric_limits<int>::min();
	short numst;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) {
			cin >> inp;
			sum += inp;
			arr[i][j] = inp;
		}
		if (abs(sum) > max) {
			max = abs(sum);
			numst = i;
		}
	}
	for (int i = 0; i < m; i++) {
		arr[numst][i] = 9999;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

int No4()
{
	
	int n;
	cin >> n;
	int arr[6];
	int inp;
	int i = 0;
	bool f = false;
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> inp;
		arr[i] = inp;
	}


	for (int i = 0; i < n; i++)
	{

		if (StEnd(arr[i]))
		{
			for (int j = i; j < (n - 1); j++)
			{
				arr[j] = arr[j + 1];
			}
			n--;
			i--;
		}
		//for (int i = 0; i < n; i++)
		//{
		//	cout << arr[i] << " ";
		//}
		//cout << endl << n << endl;
	}

	for (int i = 0; i < n; i++)
	{
		if (NumEnd(arr[i]))
		{
			for (int j = (n - 1); j >= i; j--)
			{
				arr[j + 1] = arr[j];
			}
			n++;
			i++;
		}
	}

	for (int i = 0; i < n; i++) 
	{
		cout << arr[i] << " ";
	}

	return 0;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	//No1();
	//No2();
	//No3();
	No4();
	return 0;
}