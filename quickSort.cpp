#include<iostream>
using namespace std;

int partition(int *a, int s, int e){
	int i = s-1;
	int j = s;
	int pivot = a[e];
	for(;j < e; j++){
		if(a[j] <= pivot){
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i+1], a[e]);
	return i+1;
}

int quickSort(int *a, int s, int e){
	if(s>=e){
		return 0;
	}

	int pivot = partition(a, s, e);
	quickSort(a, s, pivot-1);
	quickSort(a, pivot+1, e);
}
int main(){
	int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	int end = sizeof(a)/sizeof(a[0]);
	quickSort(a, 0, end-1);
	for(int j = 0;j < end; j++)
		cout << a[j] << " ";
	cout << endl;
	return 0;
}