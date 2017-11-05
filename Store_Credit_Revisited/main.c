//
//  main.c
//  Store_Credit_Revisited
//
//  Created by Emily Zhuang on 11/3/17.
//  Copyright © 2017 Emily Zhuang. All rights reserved.
//

#include <stdio.h>

//prototypes
float calc_new_bal(float, float, float);
float calc_rem_cred(float, float);
void print_exceed(char [], char [], float);
void print_include(char name[], char num[], float max_credit, float rem_credit);

int main()
{
    //declare variables
    char account_num[20];
    char customer_name[20];
    float initial_bal;
    float debit;
    float credit;
    float max_credit;
    float new_bal;
    float rem_credit;
    
    char repeat;
    
    do
    {
        //prompt user for account number
        printf("Account number: ");
        scanf("%s", account_num);
        getchar();          //flush the input buffer
        
        //prompt user for name
        printf("Customer name: ");
        gets(customer_name);
        
        //prompt for balance, debits, credits, and maximum credit
        printf("Initial balance: ");
        scanf("%f", &initial_bal);
        getchar();
        printf("Debits: ");
        scanf("%f", &debit);
        getchar();
        printf("Credits: ");
        scanf("%f", &credit);
        getchar();
        printf("Maximum credit: ");
        scanf("%f", &max_credit);
        getchar();
        
        //calculate the new balance of the account
        new_bal = calc_new_bal(initial_bal, credit, debit);
        //calculate the remaining credit
        rem_credit = calc_rem_cred(max_credit, new_bal);
        
        //determine if user exceeded credit limit
        //if exceeded print name, account number, and balance
        if(max_credit < new_bal)
        {
            print_exceed(customer_name, account_num, new_bal);
        }
        //if not exceeded, print name, account number, maximum credit, and remaining credit
        else
        {
            print_include(customer_name, account_num, max_credit, rem_credit);
        }
        
        //does the user want to repeat the program
        printf("Do you have another customer to enter data for?\n");
        printf("Enter Y for yes and N for no: ");
        scanf("%c", &repeat);
        getchar();
        putchar('\n');
    }
    //repeat program while the user wants to
    while (repeat == 'y' || repeat == 'Y');
    
    return 0;
}

//calculates the new balance of an account when passed the initial balance, credits, and debits
float calc_new_bal(float init_bal, float cred, float deb)
{
    return (init_bal - cred + deb);
}

//calculates the remaning credit of an account when passed the maximum credit and new balance
float calc_rem_cred(float max_cred, float new_bal)
{
    return (max_cred - new_bal);
}

//prints the customer name, account number, and new balance of account when the credit exceeds the limit
void print_exceed(char name[], char num[], float new_bal)
{
    printf("%20s %20s\n", "NAME", name);
    printf("%20s %20s\n", "ACCOUNT NUMBER", num);
    printf("%20s %20.2f\n", "NEW BALANCE", new_bal);
    printf("CREDIT LIMIT EXCEEDED\n\n");
}

//prints the customer name, account number, maximum credit, and remaining credit of account
//when the credit hasn't exceeded the limit
void print_include(char name[], char num[], float max_credit, float rem_credit)
{
    printf("%20s %20s\n", "NAME", name);
    printf("%20s %20s\n", "ACCOUNT NUMBER", num);
    printf("%20s %20.2f\n", "MAXIMUM CREDIT", max_credit);
    printf("%20s %20.2f\n", "REMAINING CREDIT", rem_credit);
}

