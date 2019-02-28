//2014170935 Lee JikJoo
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node * next;
}node;

typedef struct list{
    struct node * header;
}list;

int main (void){

    int option;
    list *LIST = (list *) malloc(sizeof(list));
    LIST -> header = NULL;
    while(1){
        printf("option\n0:create   1:insert   2:delete   3:find   4:display  5:exit\n");
        scanf("%d",&option);
        switch(option){
            case 0 : Create(LIST);break;
            case 1 : Insert(LIST);break;
            case 2 : Delete(LIST);break;
            case 3 : Find(LIST);break;
            case 4 : Display(LIST);break;
            case 5 : return 0;break;
            default : printf("error\n");
        }
    }
    
    return 0;
}

void Create(list * LIST){
    int inp_data;
    printf("Input data\n");
    scanf("%d",&inp_data);
    
    node * new_node = (node*) malloc(sizeof(node));
    new_node->value = inp_data;
    new_node->next = LIST->header;
    LIST->header = new_node;
}

void Insert(list * LIST){
    int k, inp_data;
    printf("Insert K-th node : ");
    scanf("%d",&k);
    printf("Input Data : ");
    scanf("%d",&inp_data);
    node * ptr = LIST->header;
    node * new_node = (node *) malloc(sizeof(node));
    for(int i=0;i<k-1;i++){
        ptr = ptr->next;
    }
    new_node -> value = inp_data;
    new_node -> next = ptr->next;
    ptr->next = new_node;

}

void Delete(list * LIST){
    int k;
    printf("Delete K-th node : ");
    scanf("%d",&k);
    node * ptr = LIST -> header;
    for(int i=0;i<k-1;i++){
        ptr=ptr->next;
    }
    ptr->next = ptr->next->next;

}

void Find(list * LIST){
    int k;
    printf("Find k-th node : ");
    scanf("%d",&k);
    node * ptr = LIST -> header;
    for(int i=0;i<k;i++){
        ptr = ptr->next;
    }
    printf("%d\n",ptr->value);
    

}
void Display(list * LIST){
    node *ptr = LIST->header;
    printf("[");
    while(ptr != NULL) {
       printf("(%d, %d)",ptr->value,ptr->next);
       ptr = ptr->next;
    }
    printf("]\n");
 }

 