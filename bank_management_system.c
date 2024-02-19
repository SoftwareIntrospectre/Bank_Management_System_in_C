#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct bankUser{
    int accountID;

    // limiting to 20 characters so it's manageable / easy to remember.
    char username[20];
    // pointer because I want to allow dynamic memory allocation
    char *password; 

    //used to keep track of which accounts belong to which user
    char *accountsArray;
};


struct bankAccount{
    int bankAccountID;
    char bankAccountName[20];
    double bankAccountBalance;
    int accountTypeID;
    char bankAccountType[20];


    /* Want this to be able to include different types of accounts in it

        If a person's account has $1,000 in it, and I they want that divided between Checking and Savings, that should be possible.

        AccountBalance = 1000.00
        CheckingBalance = 200.00
        SavingsBalance = 800.00

        sub-balances' total should always equal the AccountBalance.
        Or another way, the AccountBalance itself relies on said total. It's the result.

        For this, I'll allow up to 10 accounts per user, and 1 of them must be a checking account. A user can have between 0 and 9 savings accounts.



        Problem to Solve: "How do I not duplicate tons of code for this?"



        - When a user is created, a checking account is also automatically created.
        - If another account is added to the user, it becomes a savings account. 
            - each account can be represented as either an Array, Linked List, or Hash Table


            UserID: 1
            UserName: Tony
            Password: ********
            Total Account Balance = (sum of all accounts' balances)
            Checking Account Balance = (total amount of first account balance)
            Total Savings Account Balance = (total of all accounts that is not the first one.)
                - if multiple savings, then have separate Savings Account Balances for each
    */
};




//incorrect way to declare a function that takes in/returns a string
// char[] encryptPassword(char[] password){

//     char encryptedPassword[50] = {0};

//     return encryptedPassword;
// }

char* encryptPassword(char* password){

// Will do proper encryption later, but this is just an example of changing a password for now.

    //reverse a string operation (will do actual encryption later)
    // think through how I want to do this.

        // iterate through the array from right to left
        // example

        // input array:   ['c','a','t','s']
        // output array:  ['s','t','a','c']

        // start at end of input array, insert that character from the array into the new one

        // initialized:
        // input array: ['c','a','t','s']
        // ouput array: []

        // iteration 1:
        // input array: ['c','a','t','s']
        //                            ^ 
        //                            i = last index                                              

        // ouput array: ['s']

        // iteration 2:
        // input array: ['c','a','t','s']
        //                        ^ 
        //                        i = last index - 1                                              

        // ouput array: ['s', 't']

        // iteration 3:
        // input array: ['c','a','t','s']
        //                    ^ 
        //                    i = last index - 2                                              

        // ouput array: ['s', 't', 'a']

        // iteration 4:
        // input array: ['c','a','t','s']
        //                ^ 
        //                i = last index - 3                                              

        // ouput array: ['s', 't', 'a', 'c']

        // iteration 5:
        // input array: ['c','a','t','s']
        //             ^ 
        //             i = last index - 4                                              

        // i < the array minimum size, so quit.

        // return ['s','t','a',c']


    if(password == NULL){
        printf("No password to speak of. Returning NULL.");
        return NULL;
    }

    int password_length = strlen(password);

    // Allocate enough space for the encrypted password
    char* encryptPassword = malloc((password_length + 1) * sizeof(char));


    if(encryptPassword == NULL){
        printf("Memory allocation failed");
        return NULL;
    }

    //iterate over the array backwards, and append the characters to the new array (i.e. reverse an array)
    int j = 0;
    for(int i = password_length - 1; i >= 0; i--) {
        encryptPassword[j++] = password[i];
    }

    // Null-terminate the encrypted password
    encryptPassword[password_length] = '\0';

    return encryptPassword;
}

int main(){
    struct bankAccount b1 = {1, "TonyAccount", 12.34, 1, 1};

    //handling nulls here, outside of the main functionality
    //easier to manage memory this way, because I can free(encrypted_password by itself)
    char* encrypted_password = encryptPassword("Password");
    if (encrypted_password == NULL) {
        printf("Password encryption failed.\n");
        return 1; //error
    }

    struct bankUser usr1 = {1, "TonyC", encrypted_password};

    printf("My Bank Account Name is: %s.\n", b1.bankAccountName);
    printf("My Bank Account Balance is: $%.2f.\n", b1.bankAccountBalance);
    printf("My Account ID is: %d.\n", b1.bankAccountID);

    printf("My accountCredentials are:\n Username=%s\n", usr1.username); 
    printf("Password=%s\n",usr1.password);

    free(encrypted_password);

    return 0;
}