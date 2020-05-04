#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
};

node *head = NULL;
int countLength();
int insert(int data){

	if( head == NULL){
	
		node *holder = new node();
		holder -> data = data;
		holder -> next = NULL;
		head  = holder;
		
	
	}else{

		node *iterator = new node();
		iterator = head;
		while(iterator -> next != NULL){
			iterator = iterator -> next;
		}

		node *holder = new node();
		holder -> data = data;
		holder -> next = NULL;
		iterator -> next = holder;

	}

	return 1;
}

int insertAt(int pos){
	node *iterator = new node();
	iterator = head;
	int i = 0;
	while(iterator -> next != NULL){
		if(i == (pos - 1)){
			break;
		}
		i++;
		iterator = iterator -> next;
	}

	int data; cout << "Enter Data : " << endl; cin >> data;
	node *holder = new node();
	holder -> data = data;
	holder -> next = iterator -> next;
	iterator -> next = holder; 
	return 1;
}

int insertAtHead(int data){
		node *holder = new node();

		if( head == NULL){
			insert(data);
		}else{
			holder -> data = data;
			holder -> next = head;
			head  = holder;
		}

		return 0;
}

int deleteNode(int nodeNumber){
	
	if(nodeNumber <= countLength()){
		node *iterator = new node();

	iterator = head;
	int i = 0;
	while( iterator -> next != NULL){
		i++;
		if( (nodeNumber - 1) == i){
			break;
		}
		iterator  = iterator -> next; 
	}
	iterator -> next = iterator -> next -> next;
	return 1;

	} else{
		cout << endl << "Node Number " << nodeNumber << " doesn't exist.";
		return -1;
	}

	
}

int printList(){
	if(head == NULL){
		cout << endl << "List is empty.";
		return 0;
	}else{
		node *iterator = new node();
		iterator = head;
		cout << "Elements : ";
		while(iterator -> next != NULL){
			cout << iterator -> data << " ";
			iterator = iterator -> next;
		}

		cout << iterator -> data << endl;

		return 1;
	}
}

int countLength(){
	if(head == NULL){
		cout << endl << "List is empty.";
		return 0;
	}else{
		int length = 0;
		node *current = head;
		while(current -> next != NULL){
			length++;
			current = current -> next;
		}

		return ++length;
	}
}

int reverseList(){
	if(head == NULL){
		return -1;
	}else{
		node *current, *prev = NULL, *next = NULL;
		current = head;
		while(current != NULL){
			next = current -> next;
			current -> next = prev;
			prev = current;
			current = next;
		}

		head = prev;
		return 1;
	}
}
int main(){
	int data;
	int choice;

	do{

		cout << endl << "1.Insert\n2.Print\n3.Insert after\n4.Insert at head\n5.Delete\n6.Count\n7.Reverse\nEnter operation : "; cin >> choice;
		switch(choice){
		
		case 1: cout << "Enter Data : "; cin >> data;
			insert(data);
		break;

		case 2: printList();
		break;

		case 3: int pos; cout << "Enter after position : "; cin >> pos;
				insertAt(pos);
		break;

		case 4:	cout << "Enter Data : "; cin >> data;
				insertAtHead(data);
		break;

		case 5: cout << "Enter node number : "; cin >> data;
				deleteNode(data);
		break;

		case 6: cout << endl << "Length of List:" << countLength();
		break;

		case 7: data = reverseList();
				(data > 0) ? cout << endl << "List reversed." : cout << endl << "List is empty.";
		break;


		default: cout << "Invalid" << endl;
		break;
		}

	}while(choice <= 7);
	
	return 0;
}