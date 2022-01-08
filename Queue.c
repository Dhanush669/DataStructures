#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head;

void Enqueue(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node*));
    newNode->data=data;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
        return;
    }
    
    struct Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

void print(){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void Dequeue(){
    if(head==NULL){
        return;
    }
    struct Node* temp=head;
    
    head=temp->next;
    
    free(temp);
    
    print();
}

int main()
{
    head=NULL;
    
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);
    
    
    
    print();
    
    Dequeue();

    return 0;
}
