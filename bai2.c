#include <stdio.h>
#include<stdlib.h>
typedef struct Operation
{
    char url[100];
    char Timestamp[20];
}Operation;
typedef struct Stack
{
    Operation Data[100];
    int top;
    int capacity;
}Stack;
typedef struct Queue
{
    Operation Data[100];
    int front;
    int rear;
    int capacity;

}Queue;
Stack* createStack(int capacity)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    return stack;
}
Queue* createQueue(int capacity)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}
// Stack* push(Stack* stack, Operation data)
// {
//     if (stack->top == stack->capacity-1)
//     {
//         printf("FUll stack");
//         return stack;
//     }
//     stack->top=stack->top+1;
//     return stack->Data[top];
// }
int main()
{
    int choice;
    do
    {
        printf("----------ROWSER HISTORY----------\n");
        printf("1.VISIT\n");
        printf("2.BACK\n");
        printf("3.FORWARD\n");
        printf("4,HISTORY\n");
        printf("5.EXIT\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            Operation stack;

            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            printf("Cam on ban da dung chuong trinh");
            break;
            default:
            printf("Vui long chon hop le");
        }
    }while (choice!=5);
}