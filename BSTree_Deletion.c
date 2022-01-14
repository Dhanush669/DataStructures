#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
  int data;
  struct Node* left;
  struct Node* right;
};



struct Node* Insert(struct Node* root,int data){
    
    if(root==NULL){
        struct Node* newNode=(struct Node*)malloc(sizeof(struct Node*));
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

void Insert_Without_Recur(struct Node* root,int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node*));
    newNode->data=data;
    if(root==NULL){
        newNode->left=NULL;
        newNode->right=NULL;
        root=newNode;
    }
    struct Node* temp=root;
    struct Node* temp2;
    while(temp!=NULL){
        temp2=temp;
        if(temp->data<data){
            temp=temp->right;
        }
        else{
            temp=temp->left;
        }
        
    }
    
    if(temp2->data>=data){
        temp2->left=newNode;
        newNode->left=NULL;
        newNode->right=NULL;
    }
    else{
        temp2->right=newNode;
        newNode->left=NULL;
        newNode->right=NULL;
    }
    
}

bool Search(struct Node* root,int data){
    if(root==NULL){
        return false;
    }
    
    if(root->data==data){
        return true;
    }
    else if(data>root->data){
        return Search(root->right,data);
    }
    else{
        return Search(root->left,data);
    }
    
}

int Minimum(struct Node* root){
    if(root->left==NULL){
        return root->data;
    }
    
    return Minimum(root->left);
}

struct Node* Delete(struct Node* root,int data){
    if(root==NULL){
        return NULL;
    }
    if(root->data<data){
        root->right=Delete(root->right,data);
    }
    else if(root->data>data){
        root->left=Delete(root->left,data);
    }
    else{
        if(root->left==NULL && root->right==NULL){
            free(root);
            root=NULL;
        }
        else if(root->left!=NULL && root->right==NULL){
            root->data=root->left->data;
            root->left=Delete(root->left,root->left->data);
        }
        else if(root->right!=NULL && root->left==NULL){
            root->data=root->right->data;
            root->right=Delete(root->right,root->right->data);
        }
        else{
        int min;
        min=Minimum(root->right);
        root->data=min;
        root->right=Delete(root->right,min);
        }
    }
    return root;
}



int Maximum(struct Node* root){
    if(root->right==NULL){
        return root->data;
    }
    
    return Maximum(root->right);
}

void Print(struct Node* root){
    if(root==NULL){
        return;
    }
    Print(root->left);
    printf("%d ",root->data);
    Print(root->right);
}

int main()
{
    struct Node* root=NULL;
    
    root=Insert(root,5);
    root=Insert(root,7);
    root=Insert(root,3);
    root=Insert(root,8);
    root=Insert(root,4);
    root=Insert(root,6);
    
    root=Delete(root,5);
    
    Print(root);
    return 0;
}