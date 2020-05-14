#include<iostream>
#define MAX 5
using namespace std;

int items[MAX], front = -1, rear = -1;
int isEmpty(){
	if(front == -1 && rear == -1) return true;

	return false;
}
int isFull(){
	if(rear == MAX-1) return true;

	return false;
}

int enqueue(int data){
		
	if(isFull()){
		cout << endl << "Queue is Full";
		return 0;
	}else if(isEmpty()){
		items[++rear] = data;
		front++;
		return 1;
	}else{
		items[++rear] = data;
		return 1;
	}
}

int printQueue(){
	if(isEmpty()){
		cout << endl << "Queue is empty. So nothing to print.";
		return 0;
	}else{
		cout << endl << "Elements:";
		for(int i = front;i <= rear; i++)
			cout << items[i] << " ";
		return 0;	
	}
	
}
int dequeue(){
	if(isEmpty()){
		//cout << endl << "Queue is empty.";
		return -1;
	}else if(front == MAX-1){
		int temp = items[front];
		front = rear = -1;
		return temp;
	}else{
		return items[front++];
	}
}

int main(){
	int data, choice;
	do{
		cout << endl << "1.Enqueue\n2.Dequeue\n3.Print Queue\n4.Exit\nEnter Choice:"; cin >> choice;
		switch(choice){

			case 1: cout << "Enter Data:"; cin >> data;
					enqueue(data);
			break;

			case 2: 
			data = dequeue();
					(data < 0)? cout << endl << "Queue is Empty." : cout << endl << "Element popped out:" << data;
			break;

			case 3: printQueue();
			break;

			default: cout << endl << "Invalid Operation.";
			break;
		}
	}while(choice != 4); 
	return 0;
}