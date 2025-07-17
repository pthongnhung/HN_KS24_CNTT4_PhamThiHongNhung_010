#include <stdio.h>
#include<stdlib.h>
int main()
{
    int choice;
    do
    {
        printf("----------ROWSER HISTORY----------");
        printf("1.VISIT");
        printf("2.BACK");
        printf("3.FORWARD");
        printf("4,HISTORY");
        printf("5.EXIT");
        printf("Nhap lua chon cua ban: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
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