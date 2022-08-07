#include <stdio.h>




void UserComponent(){   
    int userres;

    printf("*************\n");
    printf("WELCOME USER: %s \n", NewUser.username);
    printf("what do you want to do \n");
    printf("1. See my info \n");
    printf("2. Update my info \n");
    printf("3. Delete my account \n");
    printf("answer: ");
    scanf("%d", &userres);
    
    switch (userres){
        case 1:{
            printf("Here are your info \n");
            printf("*************** \n");
            printf("Username : %s \n", NewUser.username);
            printf("Email : %s \n", NewUser.email);
            printf("Password : %s \n", NewUser.password);
            printf("*************** \n");

            int res;
            printf("1. Go back\n");
            printf("2. Shut down \n");
            printf("answer: ");
            scanf("%d", &res);

            if(res == 1){
                continue;
            }else if(res == 2){
                ON = 0;
            }


        }
        break;

        case 2:{
            printf("Here you can update your info\n");
            printf("What do you want to update\n");

            int Countres;
            printf("1. Update Username\n");
            printf("2. Update Email \n");
            printf("3. Update Password \n");
            printf("4. Go Back \n");
            printf("answer: ");
            scanf("%d", &Countres);

            if(Countres == 1){
                char newUsername[100];
                printf("old Username: %s\n", NewUser.username);
                printf("new Username: "); 
                scanf("%s", newUsername);
                strcpy(database[UserIndex].username, newUsername);
                printf("Username: %s\n", database[UserIndex].username);
                                        
            }else if(Countres == 2){
                char newEmail[100];
                printf("old Email: %s\n", NewUser.email);
                printf("new Email :"); 
                scanf("%s", newEmail);
                strcpy(database[UserIndex].email, newEmail);
            }else if(Countres == 3){

            }else if(Countres == 4){

            }else{
                perror("non select");
            }

        }
        break;
        
        case 3:{

            perror("select one");
        }
                            
        break;
                    
        default:{
            perror("select one");
        }
                            
        break;
    }

    break;
}
