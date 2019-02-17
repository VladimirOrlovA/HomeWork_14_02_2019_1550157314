#include<iostream>
#include<locale.h>
#include<time.h>
#include<Windows.h>


using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void fillArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = 1 + rand() % 99;
	}
}

void printArray(int arr[], int n)
{
	int count = 1;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cout<<arr[i]<<"\t";
		sum += arr[i];

		if (count % 10 == 0)
		{
			cout << endl << "sum= " << sum << endl << endl;
			sum = 0;
		}
	
		count++;
	}
}

void minSumTen(int arr[], int n)
{

}

void fillArray2Spiral(int arr2[][30], int n, int m)
{
	int count = 1;
	int i, j, k = 0;
	
	i = k;
	j = k;
	
	while (k != m / 2)
	{
		for (i = k; i < n - k; i++)
		{
			for (j = k; j < m - k; j++) if (i == k) arr2[i][j] = count++; // ���� ������ 
			for (j = k; j < m - k; j++)	if (i != k && i < n - k && j == m - k - 1) arr2[i][j] = count++; // ���� ������ �������	
			for (j = m - k - 1; j >= k; j--) if (i == n - k - 1 && j != m - k - 1) arr2[i][j] = count++; // ���� ������
		}
		for (i = n - k - 1; i > k; i--) if (i != n - k - 1 && i != j) arr2[i][j = k] = count++; // ���� ����� �������
		k++;
	}


	//fillArray2Spiral(arr2, n-1, m-1);

	cout << endl;
}

void fillArray2Spiralcopy(int arr2[][30], int n, int m)
{
	int count = 1;
	int i, j, k = 0;

	i = k;
	j = k;

	while (k = m / 2 - 1)
	{
		for (i = k; i < n - k; i++)
		{
			for (j = k; j < m - k; j++) if (i == k) arr2[i][j] = count++; // ���� ������ 
			for (j = k; j < m - k; j++)	if (i != k && i < n - k && j == m - k - 1) arr2[i][j] = count++; // ���� ������ �������	
			for (j = m - k - 1; j >= k; j--) if (i == n - k - 1 && j != m - k - 1) arr2[i][j] = count++; // ���� ������
		}
		for (i = n - k - 1; i > k; i--) if (i != n - k - 1 && i != j) arr2[i][j = k] = count++; // ���� ����� �������



		for (i = k; i < n - k; i++)
		{
			for (j = k; j < m - k; j++) if (i == k) arr2[i][j] = count++; // ���� ������ 
			for (j = k; j < m - k; j++)	if (i != k && i < n - k && j == m - k - 1) arr2[i][j] = count++; // ���� ������ �������	
			for (j = m - k - 1; j >= k; j--) if (i == n - k - 1 && j != m - k - 1) arr2[i][j] = count++; // ���� ������
		}
		for (i = n - k - 1; i > k; i--) if (i != n - k - 1 && i != j) arr2[i][j = k] = count++; // ���� ����� �������
	}


	//fillArray2Spiral(arr2, n-1, m-1);

	cout << endl;
}

void printArray2(int arr2[][30], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr2[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

void Task1()
{
	/*1.	**�������� ����������� �������, ������� ��������� ���������� ������ �� 100 ����� ����� ����������� ��������� ������� 
		� ������� �������, � ������� ���������� ������������������ �� 10 �����, ����� ������� ����������.*/

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask1\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	const int n = 30;
	int arr[n] = { 0 };

	fillArray(arr, n);
	printArray(arr, n);
	minSumTen(arr, n);

}

void Task2()
{
	/*2.	�������� ����������� �������, ������� ��������� ������� �� �������
		������ :
		1  2  3   4
		12 13 14  5
		11 16 15  6
		10 9  8   7*/


	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask2\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	int n = 4, m = 4;
	int arr2[30][30] = { 0 };

	//printArray2(arr2, n, m);
	fillArray2Spiral(arr2, n, m);
	printArray2(arr2, n, m);
	
}




int main()
{
	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n Orlov Vladimir HomeWork_14_02_2019_1550157314 \n\n";
	SetConsoleTextAttribute(hConsole, 7);


	setlocale(LC_ALL, "");
	srand(time(NULL));

	int number;
	char flag;

	

	do
	{
		cout << endl << "Enter number of Task (1) to (2) => ";
		cin >> number;

		switch (number)
		{
		case 1: {Task1(); } break;
		case 2: {Task2(); } break;
		

		default: cout << "\nEntered number of Task does not exist...\n\n";

		}

		SetConsoleTextAttribute(hConsole, 10);
		cout << "\n--------------------------------------------------------------------------\n\n";
		SetConsoleTextAttribute(hConsole, 7);

		cout << "Do you want to continue? \n\nIf YES press (y) if NO any keys => ";
		cin >> flag;

	} while (flag == 'y');
}
