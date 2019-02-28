#include <stdio.h>
#include <stdlib.h>

typedef struct avl_node *avl_ptr;
struct avl_node{
    int element;
    avl_ptr left;
    avl_ptr right;
    int height;
};
typedef avl_ptr SEARCH_TREE;

SEARCH_TREE make_null(void){
    return NULL;
}

int max(int a, int b){
    if(a>=b) return a;
    else return b;
}
int height(avl_ptr p){
    if(p==NULL) return -1;
    else return p->height;
}

avl_ptr find(int x, SEARCH_TREE T){
    if(T==NULL)
        return NULL;
    else if(x < T->element)
        return(find(x,T->left));
    else if(x > T->element)
        return(find(x,T->right));
    else
        return T;
}
/*********rotate**********/
avl_ptr s_rotate_left(avl_ptr k2){
    avl_ptr k1;
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    
    k2->height = max(height(k2->left),height(k2->right))+1;
    k1->height = max(height(k1->left),k2->height)+1;
    return k1;
}
avl_ptr s_rotate_right(avl_ptr k2){
    avl_ptr k1;
    k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max(height(k2->right),height(k2->left))+1;
    k1->height = max(height(k1->right),k2->height)+1;
    return k1;
}
avl_ptr d_rotate_left(avl_ptr k3){
    k3->left = s_rotate_right(k3->left);
    return(s_rotate_left(k3));
}
avl_ptr d_rotate_right(avl_ptr k3){
    k3->right = s_rotate_left(k3->right);
    return(s_rotate_right(k3));
}
/*************************/
/***********insert********/
SEARCH_TREE insert1(int x, SEARCH_TREE T, avl_ptr parent){
    avl_ptr rotated_tree;
    if(T==NULL){
        T=(SEARCH_TREE) malloc (sizeof (struct avl_node));
        if(T==NULL)
            printf("ERROR : Out of space");
        else{
            T->element = x;
            T->height = 0;
            T->left = T->right = NULL;
        }
    }
    else{
        if(x < T->element){//insert into left
            T->left = insert1(x,T->left,T);
            if((height(T->left) - height(T->right))==2){
                if(x < T->left->element)
                    rotated_tree = s_rotate_left(T);
                else
                    rotated_tree = d_rotate_left(T);
                
                if(parent -> left == T)
                    parent->left = rotated_tree;
                else
                    parent->right = rotated_tree;
            }
            else
                T->height = max(height(T->left),height(T->right))+1;    
        }
        else if(x > T->element){//insert into right
            T->right = insert1(x,T->right,T);
            if((height(T->right) - height(T->left))==2){
                if(x > T->right->element)
                    rotated_tree = s_rotate_right(T);
                else
                    rotated_tree = d_rotate_right(T);
                
                if(parent -> right == T)
                    parent->right = rotated_tree;
                else
                    parent->left = rotated_tree;
            }
            else
                T->height = max(height(T->left),height(T->right))+1;    
        }
        else//x==T->element
            printf("%d is already in tree\n",x);
    }
    return T;
}
SEARCH_TREE insert(int x, SEARCH_TREE T){
    return insert1(x,T,NULL);
}

avl_ptr find_min(SEARCH_TREE T){
    if(T==NULL)
        return NULL;
    else if(T->left == NULL)
        return(T);
    else
        return(find_min(T->left)); 
}


SEARCH_TREE delete1(int x, SEARCH_TREE T, avl_ptr parent){
    avl_ptr tmp_cell, child, rotated_tree;
    if(T==NULL)
        printf("ERROR : Element not found\n");
    else if(x < T->element){
        T->left = delete1(x, T->left,T);
         if((height(T->left) - height(T->right))==2){
            if(x < T->left->element)
                rotated_tree = s_rotate_left(T);
            else
                rotated_tree = d_rotate_left(T);
            
            if(parent -> left == T)
                parent->left = rotated_tree;
            else
                parent->right = rotated_tree;
        }
        else
            T->height = max(height(T->left),height(T->right))-1; 
    }
    else if(x > T->element){
        T->right = delete1(x, T->right,T);
        if((height(T->right) - height(T->left))==2){
            if(x > T->right->element)
                rotated_tree = s_rotate_right(T);
            else
                rotated_tree = d_rotate_right(T);
            
            if(parent -> right == T)
                parent->right = rotated_tree;
            else
                parent->left = rotated_tree;
        }
        else
            T->height = max(height(T->left),height(T->right))-1;  
    }
    else if(T->left && T->right){ //Two Children
        tmp_cell = find_min(T->right);
        T->element = tmp_cell->element;
        T->right = delete1(T->element, T->right,T);
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
SEARCH_TREE delete(int x, SEARCH_TREE T){
    return delete1(x,T,NULL);
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
     //  SEARCH_TREE T = (SEARCH_TREE) malloc (sizeof(struct avl_node));
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
