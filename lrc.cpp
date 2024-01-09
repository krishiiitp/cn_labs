#include<stdio.h>
#include<conio.h>
using namespace std;
int main()
{
    int l1,bit[100],count=0,i,choice;
    printf("Enter the length of data stream: ");
    scanf("%d",&l1);
    printf("\nEnter the data stream ");
    for(i=0;i<l1;i++){
        scanf("%d",&bit[i]);
        if(bit[i]==1)
        count=count+1;
        }
    printf("Number of 1's are %d",count);
    printf("\nEnter the choice to implement parity bit");
    printf("\n1-Sender side\n2-Receiver side\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        if(count%2==0)
        bit[l1]=0;
        else
        bit[l1]=1;
        printf("\nThe data stream after adding parity bit is\n");
        for(i=0;i<=l1;i++){
            printf("%d",bit[i]);
        }
        break;
        
        case 2:
        if(count%2==0)
        printf("There is no error in the received data stream");
        else
        printf("There is error in the received data stream");
        break;
        
        default:
        printf("Invalid choice");
        break;
    }
}