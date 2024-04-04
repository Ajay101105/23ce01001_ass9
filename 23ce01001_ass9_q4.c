#include<stdio.h>
int main(){
    typedef struct address
    {
        char street[100];
        char city[100];
        char zipcode[100];
        
    } address;
    struct person{
        char Name[100];
        address a;

    }person;
    printf("Enter the name of the person : ");
    scanf("%s",person.Name);
    printf("\nEnter the street  : ");
    scanf("%s",person.a.street);
    printf("\nEnter the city : ");
    scanf("%s",person.a.city);
    printf("\nEnter the zipcode : ");
    scanf("%s",person.a.zipcode);

    printf("\n%s",person.Name);
    printf("\n%s",person.a.street);
    printf("\n%s",person.a.city);
    printf("\n%s",person.a.zipcode);


}