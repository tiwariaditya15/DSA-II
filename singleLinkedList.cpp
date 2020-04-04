#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
};

node *head = NULL;

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

int printList(){
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

int main(){
	int data;
	int choice;

	do{

		cout << "1.Insert\n2.Print\n3.Insert after\n4.Insert at head\nEnter operation : "; cin >> choice;
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
		default: cout << "Invalid" << endl;
		break;
		}

	}while(choice <= 4);
	
	return 0;
}