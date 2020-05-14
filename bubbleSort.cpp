#include<iostream>
using namespace std;
int printArray(int [], int);
int bubbleSort(int a[], int size){

	for(int j = 0;j < size -1; j++){
		for(int i = 0;i < size-j-1; i++){
			if(a[i] > a[i+1]){
				a[i] += a[i+1];
				a[i+1] = a[i] - a[i+1];
				a[i] = a[i] - a[i+1];
			}
		}
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
	int a[] = {12, 52, 42, 36, 47, 76, 91, 41};
	int size = sizeof(a)/sizeof(a[0]);
	bubbleSort(a, size);
	return 0;
}