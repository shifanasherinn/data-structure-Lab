#include<stdio.h>
int Q[5],i,item,front=-1,rear=-1;
void enqueue(int item)
{
    if((rear+1)%5==front)
    {
        printf("the queue is full\n");
    }
    else 
    {
        if((rear==-1)&&(front==-1))
        {
            front=(front+1)%5;
            rear=(rear+1)%5;
        }
        else
        {
            rear=(rear+1)%5;
        }
        Q[rear]=item;
    }
}
    void dequeue()
    {
    if((front==-1)&&(rear==-1))
    {
        printf("Queue is empty\n");
    }
    else{
        if(front==rear)
        {
            printf("The deleted item is %d",Q[front]);
            front=-1;
            rear=-1;
        }
        else{
            printf("the deleted item is %d",Q[front]);
            front=(front+1)%5;
        }
    }
    }
    void display()
    {
        if(front<=rear)
        {
            for(i=front;i<=rear;i++)
            printf(" %d",Q[i]);
        }
        else{
            for(i=front;i<5;i++)
            printf(" %d",Q[i]);
        }
    }
    void main()
    {
        int choice;
        do{
            printf("\nenter the choice");
            printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                {
                    printf("enter the item to be inserted\n");
                    scanf("%d",&item);
                    enqueue(item);
                    break;
                }
                case 2:
                {
                dequeue(item);
                break;
                }
                case 3:
                {
                    printf("Queue elements are: ");
                    display(item);
                    break;
                }
                case 4:
                {
                    printf("exit");
                    break;
                }
                default:printf("invalid choice");
            }
        }
        while(choice!=4);
    }
