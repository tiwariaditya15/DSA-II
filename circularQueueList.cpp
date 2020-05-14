#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *next;
};

class Queue{
	node *front, *rear;
	

	public:
		Queue(){
			front = rear = NULL;
		}
		int enQueue(int data);
		int deQueue();
		bool isEmpty();
		int printQueue();
		int printFront();
		int printRear();
};

int Queue::printFront(){
	if(isEmpty()) return -1;
	return front -> data;
}
int Queue::printRear(){
	if(isEmpty()) return -1;
	return rear -> data;
}
bool Queue::isEmpty(){
	if(front == NULL && rear == NULL) return true;

	return false;
}
int Queue::enQueue(int data){
	if(isEmpty()){
		node *block = new node();
		block -> data = data;
		block -> next = NULL;
		front = rear = block;
		return 1;
	}else{
		node *block = new node();
		block -> data = data;
		block -> next = front;
		rear -> next = block;
		rear = block;
		return 1;
	}
}

int Queue::deQueue(){
	node *temp;
	if(isEmpty()){
		return -1;
	}else if ( front == rear){
		temp = front;
		cout << endl << temp -> data << " was dequeued.";
		front = rear = 0;
		return 1;
	}else{
		temp = front;
		front = front -> next;
		cout << endl << temp -> data << " dequeued.";
		free(temp);
		return 1;
	}
}
int Queue::printQueue(){
	if(isEmpty()){
		return -1;
	}else{
		node *current = front;
		while(current -> next != rear){
			cout << current -> data << " ";
			current = current -> next;
		}

		cout << current -> data << " " << current -> next -> data;
		return 1;
	}
}
int main(){
	Queue q;
	int data, choice, returned;
	bool ret;
	do{
		cout  << endl << endl << "1.Enqueue\n2.Dequeue\n3.Print Queue\n4.isEmpty()\n5.Print Front\n6.Print Rear\nEnter Choice:";
		cin >> choice;
		switch(choice){
			case 1: cout << endl << "Enter Data:"; cin >> data;
					returned = q.enQueue(data);
					(returned == 1) ? cout << endl << data << " inserted." : cout << "NOne";
			break;

			case 2: returned = q.deQueue();
					(returned < 0) ? cout << "Queue is empty." : cout << ""; 
			break;

			case 3: q.printQueue();
			break;

			case 4: ret = q.isEmpty();
					(ret == true) ? cout << endl << "Yes, queue is empty." : cout << endl << "Queue isn't empty.";
			break;

			case 5: returned = q.printFront();
					cout << endl << "Element " << returned << " is at front.";
			break;

			case 6: returned = q.printRear();
					cout << endl << "Element " << returned << " is at rear.";
			break;

			default: cout << endl << "Invalid Choice.";
			break;
		}
	}while(choice <= 6);
	return 0;
}