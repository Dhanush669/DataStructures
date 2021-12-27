#include <stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};

struct Node* head;

void InsertFirst(int value){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node*));
    temp->data=value;
    temp->prev=NULL;
    if(head==NULL){
        head=temp;
        temp->next=NULL;
        return;
    }
    temp->next=head;
    head->prev=temp;
    head=temp;
    
    Print();
}

void Reverse(){
    struct Node* temp=head;
    struct Node* p;
    struct Node* n;
   
    while(temp!=NULL){
        p=temp->prev;
        n=temp->next;
        temp->next=p;
        temp->prev=n;
        temp=n;
    }
    head=p->prev;
    Print();
}


void Print(){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    head=NULL;
    InsertFirst(1);
    InsertFirst(2);
    InsertFirst(3);
    Reverse();
    Print();

    return 0;
}