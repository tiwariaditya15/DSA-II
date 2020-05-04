#include<iostream>
using namespace std;

//to print array
int printArray(int a[], int size){
	cout << "Elements : ";
	for(int i = 0;i < size; i++)
		cout << a[i] << " "; 
	cout << endl;
	return 0;
}

int linearSearch(int a[], int size, int key){
	
	for(int i = 0;i < size; i++){
		if(a[i] == key){
			return i;
		}
	}
	return -1;
}


int main(){
	int a[] = {45, 74, 58, 89, 10, 67, 12, 4, 64, 07};
	int size = sizeof(a)/sizeof(a[0]);
	printArray(a, size);
	int key; cout << "Enter key to be searched : "; cin >> key;
	int returned = linearSearch(a, size, key);
	if(returned < 0){
		cout << "Element not found.";
	}else{
		cout << "Element found at " << returned << " position." << endl;
	}
	return 0;
}