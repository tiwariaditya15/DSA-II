#include<iostream>
#define MAX 5
using namespace std;

class Queue{
	int items[MAX], front, rear;
	public:
		Queue(){
			front = rear = -1;
		}

		int enQueue(int data);
		int deQueue();
		bool isFull();
		bool isEmpty();
		int printQueue();
};

bool Queue::isFull(){
	if(rear == front-1 || (rear == MAX-1 && front == 0)) return true;

	return false;
}
bool Queue::isEmpty(){
	if(front < 0) return true;

	return false;
}

int Queue::enQueue(int data){
	if(isFull()){
		return -1;
	}else if(isEmpty()){
		front = 0;
		items[++rear] = data;
		return 1;
	}else if(rear == MAX-1){
		rear = 0;
		items[rear] = data;
		return 1;
	}else{
		items[++rear] = data;
		return 1;
	}
}
int Queue::deQueue(){
	if(isEmpty()){
		return -1;
	}else if(front == rear){
		int el = items[front];
		rear = front = -1;
		return el;
	
	}else if(front == MAX -1 && rear > -1){
		int el = items[front];
		front = 0;
		return el;
	}else{
		return items[front++];
	}
}

int Queue::printQueue(){
	if(isEmpty()){
		return -1;
	}else if(rear >= front){
		cout << endl << "Elements:";
		for(int i = front;i <= rear; i++)
			cout << items[i] << " ";
		return 1;
	}else{
		cout << "Elements:";

		for(int i = front;i < MAX; i++)
			cout << items[i] << " ";
		for(int j = 0;j < rear; j++) 
			cout << items[j] << " ";
		return 1;
	}	
		
}
int main(){
	Queue q;
	int data, choice;
	do{
		cout << endl << "1.Enqueue\n2.Dequeue\n3.Print Queue\nEnter Choice:"; cin >> choice;
		switch(choice){
			case 1: cout << endl << "Enter Data:"; cin >> data;
					data = q.enQueue(data);
					(data < 0) ? cout << endl << "Queue is Full." : cout << endl << "Enqueued element.";
			break;

			case 2: data = q.deQueue();
					(data < 0) ? cout << endl << "Queue is empty." : cout << endl << "Dequeued element:" << data;
			break;

			case 3: data = q.printQueue();
					if(data < 0) cout << endl << "Queue is empty.";
			break;

			default: cout << endl << "Invalid Operation.";
			break;
		}
	}while(choice <= 3);
	return 0;
}