#include<stdio.h>

struct Details
{
    int roll_no;
    char name[30];
    char address[200];
    int age;
    int average_marks;

}s[6];
void show (struct Details s){
    printf("Name of the student %s: \n",s.name);
    printf("Roll number of the student %d: \n",s.roll_no);
    printf("Adress of the student %s: \n",s.address);
    printf("Age of the student %d: \n",s.age);
    printf("Average marks of the student %d: \n",s.average_marks);
}
int main()
{
    int i;
    for(i=0;i<=1;i++)
    {
        
        
        printf("Enter the name of the student %d: ",i+1);
        scanf("%s",s[i].name);
        printf("Enter the rollno of the student %d: ",i+1);
        scanf("%d",&s[i].roll_no);
        printf("Enter the address of the student %d: ",i+1);
        scanf("%s",s[i].address);
        printf("Enter the age of the student %d: ",i+1);
        scanf("%d",&s[i].age);
        printf("Enter the marks of the student %d: ",i+1);
        scanf("%d",&s[i].average_marks);
        
    }
    printf("\n");

    for (int i = 0; i <=1; i++)
    {
        show(s[i]);
    }
    return 0;
}