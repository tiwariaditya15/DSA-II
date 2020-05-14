#include <iostream>

using namespace std;

int doesThing(int *a, int size){
    
    for(int i = 0;i < size; i++)
        a[i] = 10;
    return 0;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(a)/sizeof(a[0]);
    doesThing(a, size);
    for(int j = 0;j < size; j++)
    	cout << a[j];
    return 0;
}
