#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
};
struct Node* head;


void Insert(int data){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node*));
    temp->data=data;
    temp->next=head;
    head=temp;
    Print();
}

void Reverse(){
    struct Node* current;
    struct Node* next;
    struct Node* prev;
    current=head;
    prev=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
   
   
}

void Print(){
    if(head==NULL){
        return;
    }
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    head=NULL;
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(6);
    Insert(7);
    Reverse();
    Print();

    return 0;
}

