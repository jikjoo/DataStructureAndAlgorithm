#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct heap_struct{
    unsigned int max_heap_size;
    unsigned int size;
    int *elements;
} *Heap;
Heap Create_heap(void){
    int max_elements;
    printf("Max Size of Heap : ");
    scanf("%d",&max_elements);
    if(max_elements < 1)
        printf("ERROR : Heap size is too small\n");
    Heap H = (Heap) malloc(sizeof(struct heap_struct));
    if(H==NULL)
        printf("ERROR : Out of Space\n");
    H->elements = (int *) malloc((max_elements+1) * sizeof (int));
    if(H->elements == NULL)
        printf("ERROR : Out of Space\n");
    H->max_heap_size = max_elements;
    H->size =0;
    H->elements[0] = -INT_MAX;
    return H;
}
void Heapify(Heap H, int i){
    int left = i*2;
    int right = i*2+1;
    int tmp;
    int minimum;
    if(left<=H->size && H->elements[left] < H->elements[i])
        minimum = left;
    else
        minimum = i;
    if(right <= H->size && H->elements[right] < H->elements[minimum])
        minimum = right;
    if(minimum != i){
        tmp = H->elements[i];
        H->elements[i] = H->elements[minimum];
        H->elements[minimum] = tmp;
        Heapify(H, minimum);
    }
}
void Insert_heap(Heap H){
    int input;
    printf("Input = ");
    scanf("%d",&input);
    if(H->size == H->max_heap_size)
        printf("Heap is full\n");
    else{
        int i = ++H->size;
        H->elements[i] = input;
        for(;i>0;i = i/2)
            Heapify(H,i);
    }
}

int Extract_heap(Heap H){
    if(H->size == 0){
        printf("Heap is empty\n");
        return H->elements[0];
    }
    else{
        int min = H->elements[1];
        H->elements[1] = H->elements[H->size];
        H->size--;
        Heapify(H,1);
        printf("\n%d is extracted\n", min);
    }
}
void Print_heap(Heap H){
    if(H->size == 0)
        printf("Heap is empty\n");
    else{
        printf("[");
        for(int i=1;i<=H->size;i++)
            printf(" %d ,",H->elements[i]);
        printf("]\n");
    }
}
int main (void){
    int select;
    Heap H;
    while(1){
        printf("\nSelect\n0 : Create  1 : Insert  2 : Extract  3 : Print  4 : Exit\n");
        scanf("%d",&select);
        switch(select){
            case 0 : H = Create_heap();break;
            case 1 : Insert_heap(H);break;
            case 2 : Extract_heap(H);break;
            case 3 : Print_heap(H);break;
            case 4 : return 0;break;
            default : printf("error\n");
        }
        Print_heap(H);
    }
    return 0;
}