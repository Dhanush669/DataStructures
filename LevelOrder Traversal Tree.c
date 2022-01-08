#include <stdio.h>
#include <stdlib.h>

struct Tree{
    int data;
    struct Tree* left;
    struct Tree* right;
};


struct Node{
    struct Tree* data;
    struct Node* next;
};

struct Node* head;

struct Tree* Insert(struct Tree* root,int data){
    
    if(root==NULL){
        struct Tree* newNode=(struct Tree*)malloc(sizeof(struct Tree*));
        newNode->data=data;
        root=newNode;
        newNode->left=NULL;
        newNode->right=NULL;
    }
    
    else if(data>root->data){
        root->right=Insert(root->right,data);
    }
    
    else{
        root->left=Insert(root->left,data);
    }
    
    return root;
}

void Enqueue(struct Tree* data){
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

struct Tree* Dequeue(){
    if(head==NULL){
        return;
    }
    struct Node* temp=head;
    
    head=temp->next;
    
    return temp->data;
    
    
    print();
}

void LeverOrderTraversal(struct Tree* root){
     Enqueue(root);
    while(head!=NULL){
    struct Tree* d=Dequeue();
    printf("%d ",d->data);
    if(d->left!=NULL){
    Enqueue(d->left);
    }
    if(d->right!=NULL){
    Enqueue(d->right);
    }
    }
}

int main()
{
    head=NULL;
    
    struct Tree* root=NULL;
    
    root=Insert(root,5);
    root=Insert(root,6);
    root=Insert(root,3);
    root=Insert(root,8);
    root=Insert(root,4);
    
    LeverOrderTraversal(root);
    
    print();

    return 0;
}
