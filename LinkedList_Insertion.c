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

void InsertPosi(int data,int position){
    struct Node* temp=(struct Node*) malloc(sizeof(struct Node*));
    temp->data=data;
    struct Node* temp1=head;
    if(head==NULL){
        temp->next=NULL;
        head=temp;
        return;
    }
   
    if(position==1){
        temp->next=head;
        head=temp;
    }
    else{
        for(int i=0;i<position-2;i++){
            temp1=temp1->next;
        }
        temp->next=temp1->next;
        temp1->next=temp;
    }
    Print();
}

void InsertEnd(int data){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node*));
    temp->data=data;
    temp->next=NULL;
    struct Node* temp1=head;
    while(temp1->next!=NULL){
        temp1=temp1->next;
    }
    temp->next=temp1->next;
    temp1->next=temp;
    Print();
   
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
    InsertEnd(2);
    InsertEnd(7);
    InsertPosi(4,1);
    InsertPosi(5,3);
    Print();

    return 0;
}