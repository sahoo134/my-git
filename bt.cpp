#include<stdio.h>
#include<stdlib.h>
#define out(a) printf("%d ",a)
#define in(a) scanf("%d",&a)
#define sout(a) printf(a)
struct node{
    int data;
    struct node* left;
    struct node* right;
};
void inOrder(struct node* temp,int *arr)
{
    static int i = 0;
    if(temp == 0)
        return;
    inOrder(temp -> left,arr);  // left -> root -> right Inorder
    arr[i++]=temp ->data;
    inOrder(temp -> right,arr);
}
struct node* insert(node* head,int data){

    //base case
    if(head == NULL){
         struct node* temp = (struct node*)malloc(sizeof(struct node));
         temp -> data = data;
         temp -> left = NULL;
         temp -> right = NULL;
         return temp;
    }



    //if data
    if(head -> data > data){
       head -> left = insert(head->left,data);
    }
    else{
      head -> right =insert(head->right,data);
    }

    return head;
}
int pairsum(node *head, int size,int target){
    int *arr = (int*)malloc(sizeof(int));
    inOrder(head,arr);
    for(int i = 0; i<size; i++){
        out(arr[i]);
    }
    return 1;
}
int main(){
     struct node* root = NULL;
    for(int i = 0; i < 11; i++)
    {
        sout("Enter data:");
        int data;
        in(data);
        root = insert(root,data);
    }
    int target = 11;
    pairsum(root,11,target);
}
