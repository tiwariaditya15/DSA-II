#include<iostream>
#define MAX 5
using namespace std;

int a[MAX], top = -1;

bool isFull(){
	if(top == MAX-1) return true;

	return false;
}

int isEmpty(){
	if(top == -1) return true;

	return false;
}

int push(int data){
	if(isFull()){
		cout << endl << "Stack is Full.";
		return 0;
	}else{
		a[++top] = data;
	}
	return 1;
}
int pop(){
	if(isEmpty()){
		cout << endl << "Stack is Empty.";
		return 0;
	}else{
		return a[top--];
	}
}

int printStack(){
	cout << endl << "Stack Elements:" << endl;
	for(int i = top;i >= 0; i--)
		cout << a[i] << endl; 
	return 1;
}
int countElements(){
	if(isEmpty()) return 0;
	if(isFull()) return MAX;
	int el = 0;
	for(int i = top;i >= 0; i--)
		el++;
	return el;
}
int atTop(){
	return a[top];
}

int main(){
	int data, choice;
	do{
		cout << endl << "1.Push()\n2.Pop()\n3.printStack()\n4.countElements()\n5.Top element\n6. Exit\n"; cin >> choice;
		switch(choice){
			case 1: cout << endl << "Enter Data:"; cin >> data;
					push(data);
				break;
			
			case 2 : cout << endl << "Element popped:" <<  pop();
				break;

			case 3 : printStack();
				break;
				
			case 4: cout << endl << "Number of elements in stack:" << countElements();
				break;

			case 5: cout << endl << "Element at top:" << atTop();
				break;

			default : cout << endl << "Invalid Operation.";
				break;
		}
	}while(choice != 6);
	return 0;
}