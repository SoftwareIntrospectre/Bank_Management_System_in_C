#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bankAccount{
    char bankAccountName[20];
    double bankAccountBalance;
    int accountID;
};

struct accountCredentials{
    int accountID;

    // limiting to 20 characters so it's manageable / easy to remember.
    char username[20];
    // pointer because I want to allow dynamic memory allocation
    char *password; 
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

    int j = 0;
    for(int i = password_length - 1; i >= 0; i--) {
        encryptPassword[j++] = password[i];
    }

    // Null-terminate the encrypted password
    encryptPassword[password_length] = '\0';

    // //reverse the array and add it to the new array for a backwrads result
    // for(int i = strlen(password); i > -2; i--){
    //     //printf("\n%c", password[i]);
    //     strcat(encryptPassword, password[i]);
    // }
    
    
    // for(int i = strlen(password); i > -2; i--){
    //     //printf("\n%c", password[i]);
    //     strcat(encryptPassword, password[i]);
    // }

    printf("\n%s\n", encryptPassword);
    // return encryptPassword;
    return encryptPassword;
}

int main(){
    struct bankAccount b1 = {"TonyAccount", 12.34, 1};

    char* encrypted_password = encryptPassword("Password");
    if (encrypted_password == NULL) {
        // Handle the case where encryption failed
        printf("Password encryption failed.\n");
        return 1; //error
}

    struct accountCredentials acc1 = {1, "TonyC", encrypted_password};

    printf("My Bank Account Name is: %s.\n", b1.bankAccountName);
    printf("My Bank Account Balance is: $%.2f.\n", b1.bankAccountBalance);
    printf("My Account ID is: %d.\n", b1.accountID);

    printf("My accountCredentials are:\n Username=%s\n", acc1.username); 
    printf("Password=%s\n",acc1.password);

    free(encrypted_password);

    return 0;
}