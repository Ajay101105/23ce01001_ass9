#include<stdio.h>

int main(){
    struct company
    {
        char name[30];
        char address[100];
        long long int phone;
        int noofemployee;
    };
    struct company details;
    
    printf("Enter name\n");
    gets(details.name);

    printf("Enter Adress\n");
    gets(details.address);
    
    printf("Enter phone number\n");
    scanf("%lld",&details.phone);

    printf("Enter number of employes\n");
    scanf("%d",&details.noofemployee);

    printf("Company details: \n");

    printf("Name: %s\n",details.name);
    printf("Adress: %s\n",details.address);
    printf("Phone number: %d\n",details.phone);
    printf("Number of employee: %d\n",details.noofemployee);

    return 0;

   
}   
