#include<iostream>
using namespace std;
int printArray(int [], int);
int insertionSort(int a[], int size){
			for(int i = 0;i < size; i++){
				int min = a[i];
				int j = i - 1;
				while(j >= 0 && a[j] > min){
					a[j+1] = a[j];
					j--;
				}
				a[j+1] = min;
			}
			printArray(a, size);
		return 0;
}

int printArray(int a[], int size){
	cout << endl << "Elements:";
	for(int i = 0;i < size; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
int main(){
	int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	int size = sizeof(array)/sizeof(array[0]);
	insertionSort(array, size);
	return 0;
}