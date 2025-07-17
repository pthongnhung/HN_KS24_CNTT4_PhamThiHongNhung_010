#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Employee{
        int id;
        char name[100];
        char position[100];
        char salary[100];
}Employee;
typedef struct singleNode
{
    Employee employee;
    struct singleNode *next;
}singleNode;
typedef struct doubleNode
{
    Employee employee;
    struct doubleNode *next;
    struct doubleNode *prev;
}doubleNode;
singleNode* createSingleNode(Employee employee)
{
    singleNode* newNode=(singleNode*)malloc(sizeof(singleNode));
    newNode->employee=employee;
    newNode->next=NULL;
    return newNode;
}
doubleNode* createDoubleNode(Employee employee)
{
    doubleNode* newNode=(doubleNode*)malloc(sizeof(doubleNode));
    newNode->employee=employee;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
singleNode* insertSingleNode(singleNode* head,Employee employee)
{
    singleNode* newNode=createSingleNode(employee);
    singleNode* current=head;
    if(head==NULL)
    {
        head=newNode;
        return head;
    }
    while(current->next!=NULL )
    {
        if (strcmp(current->next->employee.name,employee.name)==0)
        {
            printf("Name already exists");
            free(newNode);
            return NULL;
        }
            current=current->next;
    }

    current->next=newNode;
    printf("Da them thanh cong nhan vien\n");
    return head;
}
void printList(singleNode* head)
{
    singleNode* current=head;
    while(current!=NULL)
    {
        printf("Employee ID:%d\n",current->employee.id);
        printf("Employee Name:%s\n",current->employee.name);
        printf("Employee Position:%s\n",current->employee.position);
        printf("Salary:%s\n",current->employee.salary);
        current=current->next;
    }
}
int generateID() {
    static int currentID = 0;
    currentID++;
    return currentID;
}
singleNode* deleteSingleNode(singleNode* head,int deleteID)
{
    singleNode* current=head;
    singleNode* prev=NULL;
    if(head==NULL)
    {
        printf("Empty list\n");
        return head;
    }
    while (current!=NULL,current->employee.id!=deleteID)
    {
        prev=current;
        current=current->next;
    }
    if(current==NULL)
    {
        printf("No find Id");
        return head;
    }
    if (head==current)
    {
        head=head->next;
        free(current);
        return head;
    }
    prev->next=current->next;
    printf("Da xoa thanh cong\n");
    free(current);
    return head;
}
void updateSinglList(singleNode* head,int updateID)
{
    singleNode* current=head;
    while(current!=NULL && current->employee.id!=updateID)
    {
      current=current->next;
    }
    if(current==NULL)
    {
        printf("No find Id\n");
        return;
    }
    printf("Employee ID:%d\n",current->employee.id);
    printf("Employee Name:%s\n",current->employee.name);
    printf("Employee Position:%s\n",current->employee.position);
    printf("Salary:%s\n",current->employee.salary);
    fflush(stdin);

    printf("Update employee name: ");
    fgets(current->employee.name,100,stdin);
    current->employee.name[strcspn(current->employee.name,"\n")]='\0';

    printf("Update employee position: ");
    fgets(current->employee.position,100,stdin);
    current->employee.position[strcspn(current->employee.position,"\n")]='\0';

    printf("Update employee salary: ");
    fgets(current->employee.salary,100,stdin);
    current->employee.salary[strcspn(current->employee.salary,"\n")]='\0';
    printf("Update success");
}
singleNode* finishNode(singleNode* head,int finishId)
{
    singleNode* current=head;
    while (current!=NULL)
    {
        if(current->employee.id==finishId)
        {
            return head;
        }
        current=current->next;
    }
    return NULL;
}
doubleNode* insertDouble(singleNode* head,Employee employee)
{
    doubleNode* newNode=createDoubleNode(employee);
    if(head==NULL)
    {
        head=newNode;
        return head;
    }
    singleNode* current=head;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=newNode;
    return head;
}
void sortBySalary(singleNode* head)
{
    singleNode* i;
    singleNode* j;
    for (i=head;i->next!=NULL;i=i->next)
    {
        for (j=i->next;j!=NULL;j=j->next)
        {
            if (i->employee.salary>j->employee.salary)
            {
                singleNode* temp=i->next;
                i->next=j->next;
                j->next=temp;
            }
        }
    }
}
singleNode* linerSearch(singleNode* head,char * name)
{
    while (head!=NULL)
    {
        if (strcmp(head->employee.name,name)==0)
        {
            return head;
        }
        head=head->next;
    }
    return NULL;
}
int main()
{
    int choice;
    singleNode* singleHead=NULL;
    singleNode* doubleHead=NULL;
    srand(time(NULL));
    do
    {
        printf("1.Them nhan vien\n");
        printf("2.Hien thi danh sach nhan vien dang lam viec\n");
        printf("3.Xoa nhan vien theo ID\n");
        printf("4.Cap nhat thong tin nhan vien\n");
        printf("5.Danh dau nhan vien da nghi viec\n");
        printf("6.Hien thi danh sach nhien vien da nghi viec\n");
        printf("7.Sap xep nhan vien theo luong\n");
        printf("8.Tim kiem nhan vien theo ten\n");
        printf("9.Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            Employee employee;
            employee.id=generateID();
            fflush(stdin);
            printf("Nhap ten nhan vien: ");
            fgets(employee.name,100,stdin);
            employee.name[strcspn(employee.name,"\n")]='\0';

            printf("Nhap vi tri cong viec: ");
            fgets(employee.position,100,stdin);
            employee.position[strcspn(employee.position,"\n")]='\0';

            printf("Nhap muc luong: ");
            fgets(employee.salary,100,stdin);
            employee.salary[strcspn(employee.salary,"\n")]='\0';

            singleHead=insertSingleNode(singleHead,employee);
            break;
        case 2:
            printList(singleHead);
            break;
        case 3:
            int deleteId;
            printf("The enter id delete: ");
            scanf("%d",&deleteId);
            singleHead=deleteSingleNode(singleHead,deleteId);
            break;
        case 4:
            int updateID;
            printf("The enter id update: ");
            scanf("%d",&updateID);
            updateSinglList(singleHead,updateID);
            break;
        case 5:
            int finishId;
            printf("The enter id finish: ");
            scanf("%d",&finishId);
            singleNode* finish=finishNode(singleHead,finishId);
            if(finish==NULL)
            {
                printf("No find Id finish");
                break;
            }
            Employee employees=finish->employee;
            doubleHead=insertDouble(doubleHead,employees);
            singleHead=deleteSingleNode(singleHead,finishId);
            printf("Da danh dau thanh cong");
            break;
        case 6:
            printList(doubleHead);
            break;
        case 7:
            sortBySalary(singleHead);
            printf("Sap xep thanh cong");
            break;
        case 8:
            char title[100];
            printf("The enter name: ");
            scanf("%s",&title);
            getchar();


            singleNode* findName=linerSearch(singleHead,title);
            if (findName==NULL)
            {
                printf("No find name");
                break;
            }
            Employee findEmployee=findName->employee;
            printf("Id: %d\t",findEmployee.id);
            printf("Name: %s\t",findEmployee.name);
            printf("Position: %s\t",findEmployee.position);
            printf("Salary: %s\n",findEmployee.salary);
            break;
        case 9:
            printf("Cam on da dung chuong trinh");
            break;
        default:
            printf("Vui long nhap lua chon hop le");
        }
    }while (choice!=9);
    return 0;
}