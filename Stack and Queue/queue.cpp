#include<iostream>
using namespace std;

class Node{
public:    
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void Enqueue(int x){
    cout<<"Enqueuing: "<<endl;
    Node* temp = new Node();
    temp->data=x;
    temp->next=NULL;
    if(front==NULL && rear==NULL){
        front=rear=temp;
        return;
    }
    rear->next=temp;
    rear=temp;
}

void Dequeue(){
    cout<<"Dequeuing: "<<endl;
    Node* temp=front;
    if(front==NULL){
        cout<<"Error: Queue is empty\n";
        return;
    }
    if(front==rear){
        front=rear=NULL;
    }
    else{
        front=front->next;
        delete(temp);
    }
}

int Front(){
    if(front==NULL){
        cout<<"Queue is empty\n";
    }
    return front->data;
}

void Print(){
    Node* temp=front;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    Enqueue(2); Print(); 
    Enqueue(4); Print();
    Enqueue(6); Print();
    Dequeue();  Print();
    Enqueue(8); Print();
    return 0;
}
