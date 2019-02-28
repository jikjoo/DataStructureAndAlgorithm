#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node *tree_ptr;
struct tree_node{
    int element;
    tree_ptr left;
    tree_ptr right;
};
typedef tree_ptr SEARCH_TREE;

SEARCH_TREE make_null(void){
    return NULL;
}

tree_ptr find(int x, SEARCH_TREE T){
    if(T==NULL)
        return NULL;
    else if(x < T->element)
        return(find(x,T->left));
    else if(x > T->element)
        return(find(x,T->right));
    else
        return T;
}

tree_ptr insert(int x, SEARCH_TREE T){
    if(T==NULL){
        T=(SEARCH_TREE) malloc (sizeof(struct tree_node));
        if(T==NULL)
            printf("ERROR : Out of space\n");
        else{
            T->element = x;
            T->left = NULL;
            T->right = NULL;
        }
    }
    else if(x < T->element)
        T->left = insert(x, T->left);
    else if(x > T->element)
        T->right = insert(x, T->right);
    else
        printf("ERROR : x == T->element\n");
    return T;

}

tree_ptr find_min(SEARCH_TREE T){
    if(T==NULL)
        return NULL;
    else if(T->left == NULL)
        return(T);
    else
        return(find_min(T->left)); 
}

tree_ptr delete(int x, SEARCH_TREE T){
    tree_ptr tmp_cell, child;
    if(T==NULL)
        printf("ERROR : Element not found\n");
    else if(x < T->element)
        T->left = delete(x, T->left);
    else if(x > T->element)
        T->right = delete(x, T->right);
    else if(T->left && T->right){ //Two Children
        tmp_cell = find_min(T->right);
        T->element = tmp_cell->element;
        T->right = delete(T->element, T->right);
    }
    else{   //One or No Child
        tmp_cell = T;
        if(T->left == NULL)
            child = T->right;
        if(T->right == NULL)
            child = T->left;
        free(tmp_cell);
        return child;
    }
    return T;
}
int input(){
    int x;
    printf("Input : ");
    scanf("%d",&x);
    return x;
}
void print(SEARCH_TREE T){
    if(T==NULL)
        return;
    printf("%d ,", T->element);
    print(T->left);
    print(T->right);
    
}

int main(void){
    int select;
     //  SEARCH_TREE T = (SEARCH_TREE) malloc (sizeof(struct tree_node));
    SEARCH_TREE T = make_null();
     while(1){
        printf("\nSelect\n1 : Insert  2 : Delete  3 : Find  4 : Exit\n");
        scanf("%d",&select);
        int x;
        switch(select){
            case 1 : x=input(); T = insert(x,T);break;
            case 2 : x=input(); T = delete(x,T);break;
            case 3 : 
                x=input();
                SEARCH_TREE temp = find(x,T);
                print(temp);
                printf("\n");
                break;
            case 4 : return 0;break;
            default : printf("error\n");
        }
        print(T);
    }
    return 0;
}
