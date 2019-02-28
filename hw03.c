#include <stdio.h>
#define length 3
int head=-1, tail=-1;
int queue[length];

void Enqueue(void){
    int enqueue;
    printf("Input : ");
    scanf("%d",&enqueue);
    if((head==0&&tail==length-1)||head==tail+1)
        printf("Full Queue\n");
    else{
        if(head==-1)//empty
            head=0;
        else if(tail==length-1&&head!=0)//[null,head,tail]
            tail = -1;
        tail++;
        queue[tail]=enqueue;
    }
}
void Dequeue(void){
    if(head==-1&&tail==-1)//empty
        printf("Empty\n");
    else{
        head++;
        if(head==length)
            head=0;
        if(head==tail+1)
            head=tail=-1;
    }

}
void Print(void){
    int j=head;
    if(j == -1)
        printf("Empty\n");
    else{
        printf("[");
        if(head<=tail){
            for(;j<=tail;j++)
                printf("%d ,",queue[j]);
        }
        else{
            for(;j<length;j++)
                printf("%d ,",queue[j]);
            for(j=0;j<=tail;j++)
                printf("%d ,",queue[j]);
        }
        printf("]\n");
    }
}
int main (void){
    int inp;
    while(1){
        printf(" Enqueue : 1\n Dequeue : 2\n Exit : 0\n Select : ");
        scanf("%d",&inp);
        switch(inp){
            case 1 : //Enqueue
                Enqueue();
                break;
            case 2 : //Dequeue
                Dequeue();
                break;
            case 0 : //Exit
                Print();
                return 0;
                break;
            default : printf("error");
        }
        Print();
    }
}
