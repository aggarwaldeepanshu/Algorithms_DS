#include<iostream>
#include<cstring>
#define max 256
using namespace std;

void printPatternRecur(char str[], char arr[], int i, int j, int n)
{
	if (i==n)
	{
		arr[j] = ')';
		arr[j+1]='\0';
		cout << arr << endl;
		return;
	}

	arr[j] = str[i];
	printPatternRecur(str, arr, i+1, j+1, n);

	arr[j] = ')';
	arr[j+1]='(';
	arr[j+2] = str[i];

	printPatternRecur(str, arr, i+1, j+3, n);
}

void printPattern(char *str)
{
	int n = strlen(str);
	char arr[2*n];
	arr[0]='(';
	arr[1] = str[0];
	printPatternRecur(str, arr, 1, 2, n);
}

int main()
{
	char str[max];
	cout<<"enter the string"<<endl;
	cin.get(str,max);

	printPattern(str);
	return 0;
}

