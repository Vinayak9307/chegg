#include <stdio.h>
#include <string.h>
struct employee
{
    char name[50];
    int id, salary, workingHour;
};
void printTotalSalary(struct employee e)
{
    if (e.workingHour > 40)
    {
        printf("Enter the weekly working day of the employee(1-WEEKDAY 2 WEEKEND): ");
        int x;
        scanf("%d", &x);
        int diff = e.workingHour - 40;
        if (x == 1)
        {
            if (diff < 5)
            {
                e.salary += diff * 35;
            }
            else
            {
                e.salary += diff * 50;
            }
        }
        else
        {
            if (diff < 5)
            {
                e.salary += diff * 50;
            }
            else
            {
                e.salary += diff * 80;
            }
        }
    }
    printf("Salary of the %s is %d\n", e.name, e.salary);
    printf("**************\n");
}

int main()
{

    FILE *fp = NULL;
    fp = fopen("salaries.txt","rb");
    if(fp == NULL)
    {
        printf("\n\t\t\tFile is not opened\n");
        return 0;
    }
    struct employee employee_data;
    while(fscanf(fp , "%s %d %d %d" , employee_data.name,&employee_data.id , &employee_data.salary , &employee_data.workingHour)){
        printf("Name of the employee: %s\n",employee_data.name);
        printf("ID of the employee: %d\n",employee_data.id);
        printf("Salary of the employee: %d\n",employee_data.salary);
        printf("Weekly working hour of the employee: %d\n",employee_data.workingHour);
        printTotalSalary(employee_data);
        if(feof(fp)){
            break;
        }
    }
    return 0;
}
