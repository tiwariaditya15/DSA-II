#include<iostream>
using namespace std;
int printArray(int a[], int size){
	cout << endl << "Elements:";
	for(int i = 0;i < size; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}

int selectionSort(int a[], int size){	
	for(int i = 0;i < size; i++){
		int min = i;
		for(int j = i+1;j < size; j++){
			if(a[min] > a[j]){
				a[min] += a[j];
				a[j] = a[min] - a[j];
				a[min] = a[min] - a[j];
			}
		}
	}
	printArray(a, size);
	return 0;
}
int main(){
	int a[] = {21, 54, 69, 75, 98, 87, 73, 45};
	int size = sizeof(a)/sizeof(a[0]);
	selectionSort(a, size);
	return 0;
}