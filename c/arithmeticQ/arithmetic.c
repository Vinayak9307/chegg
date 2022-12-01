#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// The fun1 function is responsible for handling option B
float fun1()
{
    float num1, num2, answer;
    char ch;
    printf("Enter first number: ");
    while (scanf("%f", &num1) == 0)
    {
        printf("Invalid input. Please enter flaoting point number: ");
        scanf("%*s");
    }
    printf("Enter second number: ");
    while (scanf("%f", &num2) == 0)
    {
        printf("Invalid input. Please enter flaoting point number: ");
        scanf("%*s");
    }
    runAgain:
    printf("\nEnter operator, '+' for addition, '-' for subtraction, '/' for division, '*' for multiplication, '%%' for remainder, 'X' for greatest number, 'I' for smallest number: ");
    getchar();
    scanf("%c", &ch);
    switch (ch)
    {
    case '+':
        printf("The answer is: ");
        answer = num1 + num2;
        return (answer);
        break;
    case '-':
        printf("The answer is: ");
        answer = num1 - num2;
        return (answer);
        break;
    case '*':
        printf("The answer is: ");
        answer = num1 * num2;
        return (answer);
        break;
    case '/':
        while (num2 == 0)
        {
            printf("Please enter a non-zero number: ");
            while (scanf("%f", &num2) == 0)
            {
                printf("Invalid input. Please enter a number: ");
                scanf("%*s");
            }
        }
        printf("The answer is: ");
        answer = num1 / num2;
        return (answer);
        break;
    case '%':
        while (num2 == 0)
            {
                printf("Please enter a non-zero number: ");
                while (scanf("%f", &num2) == 0)
                {
                    printf("Invalid input. Please enter a number: ");
                    scanf("%*s");
                }
            }
        printf("The answer is: ");
        answer = remainder(num1, num2);
        return (answer);
        break;
    case 'X':
        printf("The answer is: ");
        if (num1 < num2)
            return (num2);
        break;
    case 'I':
        printf("The answer is: ");
        if (num1 > num2)
            return (num2);
        break;
    default:
        printf("Entered option is invalid.");
        goto runAgain;
        break;
    }
}
// The fun2 function is responsible for handling option U
float fun2()
{
    float num1, answer;
    char ch;
    printf("Please enter a positive number: ");
    while (scanf("%f", &num1) == 0)
    {
        printf("Invalid input. Please enter a flaoting point number: ");
        scanf("%*s");
    }

    {
        runAgain2:
        printf("Enter operator, 'S' for square root, 'L' for logarithm, 'E' for exponentiation, 'C' for ceiling, 'F' for flooring: ");
        getchar();
        scanf("%c", &ch);

        switch (ch)
        {
        case 's':
        case 'S':
            while(num1 < 0){
                printf("Please enter a positive number: ");
                scanf("%f",&num1);
            }
            printf("The answer is: ");
            answer = sqrt(num1);
            return (answer);
        case 'l':
        case 'L':
            while(num1 < 0){
                printf("Please enter a positive number: ");
                scanf("%f",&num1);
            }
            printf("The answer is: ");
            answer = log(num1);
            return (answer);
        case 'e':
        case 'E':
            printf("The answer is: ");
            answer = exp(num1);
            return (answer);
        case 'c':
        case 'C':
            printf("The answer is: ");
            answer = ceil(num1);
            return (answer);
        case 'f':
        case 'F':
            printf("The answer is: ");
            answer = floor(num1);
            return (answer);
        default:
            printf("That is not a valid operation.\n");
            goto runAgain2;
            break;
        }
    }
}
float fun4()
{
    char choice;
    float answer;
    printf("Enter B, U, or E: ");
    getchar();
    scanf("%c", &choice);
    if (choice == 'B')
    {
        answer = fun1();
        printf("%f", answer);
    }

    if (choice == 'U')
    {
        answer = fun2();
        printf("%f", answer);
    }
    if (choice == 'E')
    {
        printf("Program Terminated\n");
        exit(0);
    }
}
// The choice_show function is responsible for checking all valid and invalid inputs
char choice_show()
{
    printf("Select one of the following items: \n");
    printf("B) - Binary Mathematical Operations, such as addition and subtraction.\n");
    printf("U) - Unary Mathematical operations, such as square root, and log.\n");
    printf("A) - Advanced Mathematical Operations, using variables, arrays.\n");
    printf("V) - Define variables and assign them values.\n");
    printf("E) - Exit\n");

    char user_choice1;

    printf("\nEnter any one option: ");
    scanf("%c", &user_choice1);
    if (user_choice1 != 'B' && user_choice1 != 'U' && user_choice1 != 'A' && user_choice1 != 'V' && user_choice1 != 'E')
    {
        printf("Wrong option, please try again\n");
        //here I stored the value of the inner choice function in the user_choice variable.
        //thats how recursion works
        user_choice1 = choice_show();
    }
    return user_choice1;
}

int main()
{
    float res;
    printf("Welcome to my Command-Line Calculator (CLC)\n");
    printf("Developer:\n");
    printf("Version: 3\n");
    printf("Date: November 27, 2022\n");
    printf("----------------------------------------------------------\n\n");
    char user_choice = choice_show(); // separate function for options
    if (user_choice == 'B')
    {
        res = (fun1());
        printf("%f", res);
    }

    else if (user_choice == 'U')
    {
        res = (fun2());
        printf("%f", res);
    }
    else if (user_choice == 'V')
    {
        char var_name;
        float init_val;
        printf("Enter variable character between 'a' and 'e': ");
        getchar();
        scanf("%c",&var_name);
        while(var_name < 'a'|| var_name > 'e'){
            printf("Enter variable character between 'a' and 'e': ");
            getchar();
            scanf("%c",&var_name);
        }
        printf("Enter float value: ");
        scanf("%f", &init_val);
        printf("%c = %f", var_name, init_val);
    }
    else if (user_choice == 'A')
    {
        res = fun4();
    }
    else if (user_choice == 'E')
    {
        printf("Program Terminated");
        exit(0);
    }
    return 0;
}
