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

int Maximum(struct Node* root){
    if(root->right==NULL){
        return root->data;
    }
    
    return Maximum(root->right);
}

int main()
{
    struct Node* root=NULL;
    
    root=Insert(root,5);
    root=Insert(root,6);
    root=Insert(root,3);
    root=Insert(root,8);
    root=Insert(root,4);
    
    bool res=Search(root,9);
    
    if(res==true){
        printf("Found\n");
    }
    else{
        printf("Not Found\n");
    }
    
    
    int min=Minimum(root);
    printf("%d",min);
    
    int max=Maximum(root);
    printf("\n%d",max);
    

    return 0;
}