#include <stdio.h>
#include <stdlib.h>

struct bankAccount{
    char bankAccountName[20];
    double bankAccountBalance;
    int accountID;
};

struct accountCredentials{
    int accountID;
    char username[50];
    char password[50];
};


//incorrect way to declare a function that takes in/returns a string
// char[] encryptPassword(char[] password){

//     char encryptedPassword[50] = {0};

//     return encryptedPassword;
// }

char* encryptPassword(const char* password){
    char* encryptPassword = malloc(50 * sizeof(char));

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


    if(encryptPassword == NULL){
        printf("No password to speak of. Returning NULL.");
        free(encryptPassword);
        return NULL;
    }

    return encryptPassword;
}

int main(){
    struct bankAccount b1 = {"TonyAccount", 12.34, 1};

    struct accountCredentials acc1 = {1, "TonyC", "asdfasdf"};

    printf("My Bank Account Name is: %s.\n", b1.bankAccountName);
    printf("My Bank Account Balance is: $%.2f.\n", b1.bankAccountBalance);
    printf("My Account ID is: %d.\n", b1.accountID);

    printf("My accountCredentials are: Username=%s\n", acc1.username); 
    printf("Password=%s\n",acc1.password);
}