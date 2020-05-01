#include<iostream>
using namespace std;

struct node{
    int element;
    struct node *next;
    struct node *prev;
};
node *top = NULL;

bool isEmpty(){
    if(top == NULL) 
    return true;

    return false;
}

int push(int data){
    if(top == NULL){
        node *block = new node();
        block -> element = data;
        block -> next = NULL;
        block -> prev = NULL;
        top = block;
    }else{
        node *block = new node();
        block -> element = data;
        block -> prev = top;
        block -> next = NULL;
        top = block;
    }
}

node* pop(){
        if(isEmpty()){
            cout << endl << "Stack has no elements.";
        }else{
            node *block = top;
            top = top -> prev;
            cout << endl << "Element popped.";
            return block;
        }
}


int show(){
    if(isEmpty()){
        cout << endl << "Stack is empty.";
    }else{
        node *current = top;
        cout << "Elements inside list:" << endl;
        while(current -> prev != NULL){
            cout << current -> element << endl;
            current = current -> prev;
        }
        cout << current -> element;        
    }
    return 0;
}

int count(){
    if(isEmpty())
        return 0;
    int elements = 0;
    node *current = top;
    while(current -> prev != NULL){
        elements++;
        current = current -> prev;
    }

    return ++elements;
}

int atTop(){
    return top -> element;
}

int main(){
    int data, choice;
    do{
        cout << endl << "1.Push()\n2.Pop()\n3.Show()\n4.Count()\n5.top()\n6. exit\nEnter your choice:"; cin >> choice;
        switch(choice){
            case 1: cout << "Enter Data : "; cin >> data;
                    push(data);
            break;

            case 2: pop();
            break;
            
            case 3: show();
            break;
            
            case 4: cout << endl << "Number of Elements inside stack : " << count() << " elements.";
            break;
            
            case 5: cout << endl << "Element at top : " << atTop();
            break
            ;

            default : cout << endl << "Inavalid Operation.";
            break;
        }
    }while(0 < choice && choice <= 5);
    return 0;
}