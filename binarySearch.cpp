#include<iostream>
using namespace std;

int binarySearch(int a[], int start, int end, int key){
	int mid = (start + end)/2;
	if(a[mid] == key){
		return mid;
	}else if (a[mid] > key){
		return binarySearch(a, start, mid-1, key);
	}else{
		return binarySearch(a, mid+1, end, key);
	}
	return -1;
}

int main(){
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11 , 12, 13, 14, 15, 16, 17, 18, 19};
	int end = sizeof(a)/sizeof(a[0]), key;
	cout << "Enter element to be searched  : "; cin >> key;
	int result = binarySearch(a, 0, end, key);
	cout << "Element found at position " << result << endl;
	return 0; 
}

