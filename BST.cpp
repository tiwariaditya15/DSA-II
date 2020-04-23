#include<iostream>
using namespace std;
struct node{
	int data;
	struct node *left, *right;
};
node* root = NULL;
int insert(int key){
	node *holder = new node();
	holder -> data = key;
	holder -> left = NULL;
	holder -> right = NULL;
	//where there are no node in tree
	if( root == NULL){
		root = holder;
	}else{
		//where tree has nodes and we need to find parent node to our current node
		node *parent, *current = new node();
		current = root;
		while(current){
			parent = current;
			if(parent -> data < key){
					current = parent -> right;			
			}else{
					current = parent -> left;
			}
		}

		
		if(parent -> data < key){
			parent -> right = holder;
		}else{
			parent -> left = holder;
		}

	}

	return 1;
}

int findNode(node *rootElement, int key){

	if( rootElement == NULL){
			return 0;
	}else{

			if( key == rootElement -> data) return 1;	//root element has key
			else if(key < rootElement -> data) findNode(rootElement -> left, key); //key is less than root element key recursively go to left
			else findNode(rootElement -> right, key);	// if recursive calling to left didn't find element go root to right recursively

	}
	
}

int printTree(node *rootElement){
		if (rootElement == NULL) return 1; 
		cout << rootElement -> data << " ";
		printTree(rootElement -> left);
		printTree(rootElement -> right);

}

int main(){

	int data;
	int choice, outCome; 
	do{
		cout << endl << "1.Insert\n2.Print Tree\n3.Find Node\nEnter Choice : "; cin >> choice;
		switch(choice){
			case 1: cout << endl << "Enter Data:"; cin >> data;
			insert(data);
			break;

			case 2: printTree(root);
			break;

			case 3: cout << endl << "Enter element to be find : "; cin >> data;
					outCome = findNode(root, data);
					if(outCome) cout << endl << "Data is available in tree.";
					else cout << endl << "Key wasn't found in tree";
			break;

			default: cout << endl << "Invalid Option." << endl;
			break;
		} 
	}while(choice <= 3);
	
	
	return 0;
}