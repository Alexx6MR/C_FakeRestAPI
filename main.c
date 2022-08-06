#include <stdio.h>
#include <string.h>

//USER MODULE
enum UserRoles {ADMIN, USER};

typedef struct NewUser
{
    char username[30];
    char password[30];
    char email[60];
    enum UserRoles role;
} User;


User admin = {"admin", "adminpsw", "admin@email.com", ADMIN};
User user1 = {"user1", "user1psw", "user1@email.com", USER};
User user2 = {"user2", "user2psw", "user2@email.com", USER};
User user3 = {"user3", "user3psw", "user3@email.com", USER};


//Auth system
User SelectUser(int dblenght, User db[], char userpass[]);


//ADMIN FUNCTIONS
void getAll();
void getOne(int id);
void create(int user);


//USER FUNCTIONS
void Register();
void Login();
void update(int user, int id);
void delete(int user, int id);

//global vars
    int ON = 1;
    int UserAuth = 1;
    int userconfirm = 0;
    int passconfirm;
    int userisOn = 1;
    char username[60];
    char password[60];
    User NewUser;
    int UserIndex;
    User UpdatedUser;

int main(){
    

    //FAKE DATABASE
    User database[] = {admin, user1, user2, user3};
    int dbsize = sizeof(database)/sizeof(database[0]);  


    while(ON == 1){
        int res;
        printf("what do you want to do \n");
        printf("1. Login \n");
        printf("2. Register \n");
        printf("3. Exit \n");
        printf("answer: ");
        scanf("%d", &res);

        switch (res)
        {
            case 1:

                printf("**********\n");
                printf("Welcome to C test \n");
                printf("Please enter your info \n");
                printf("**********\n");

                printf("Username: ");
                scanf("%s", username);
            
                while (UserAuth == 1){
        
                    printf("password: ");
                    scanf("%s", password);   
                
                    for(int i = 0; i < dbsize; i++){
                        passconfirm = stricmp(password, database[i].password);
                        if(passconfirm == 0){
                            UserAuth = 0;
                            UserIndex = i;
                            NewUser = database[i];
                        }
                   
                    } 
                } 

                while (userisOn == 1)
                {
                    switch (NewUser.role)
                    {
                        case USER:
                        {
                            int userres;
                            printf("*************\n");
                            printf("WELCOME USER: %s \n", NewUser.username);
                            printf("what do you want to do \n");
                            printf("1. See my info \n");
                            printf("2. Update my info \n");
                            printf("3. Delete my account \n");
                            printf("answer: ");
                            scanf("%d", &userres);
                            switch (userres)
                            {
                                case 1:
                                {
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


                            case 2:
                                {
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
                                        perror("select one");
                                    }

                                }
                            break;
                            case 3:
                            {

                                perror("select one");
                            }
                            
                            break;
                    
                            default:
                            perror("select one");
                            break;
                        }

                    break;
                        }
                        case ADMIN:
                        {
                            int adminres;
                            printf("*************\n");
                            printf("WELCOME ADMIN: %s \n", NewUser.username);
                            printf("what do you want to do \n");
                    
                            printf("All Users\n");
                            printf("1. See all users \n");
                            printf("2. Update User \n");
                            printf("3. Delete User \n");

                            printf("*************\n");
                            printf("My Account\n");
                            printf("4. See my info \n");
                            printf("5. Update my info \n");
                            printf("6. Delete my account \n");
                            printf("answer: ");
                            scanf("%d", &adminres);
                    
                            switch (adminres)
                            {
                                case 1:
                                {
                                    int caseres;
                                    printf("Get All USERS\n");
                                    
                                    for(int i = 0; i < dbsize; i++){
                                        printf("*************\n");
                                        printf("Index: %i\n", i);
                                        printf("Username: %s\n", database[i].username);
                                        printf("Email: %s\n", database[i].email);
                                        printf("Password: %s\n", database[i].password);
                                        printf("Role: %c\n", database[i].role);
                                        printf("*************\n");
                   
                                    } 

                                    printf("1. Go back\n");
                                    printf("2. Shut down \n");
                                    printf("answer: ");
                                    scanf("%d", &caseres);

                                    if(res == 1){
                                        continue;
                                    }else if(res == 2){
                                        ON = 0;
                                    }

                        
                                }
                        break;



                            case 2:
                        
                            break;
                            case 3:
                        
                            break;

                            case 4:
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

                            break;

                            case 5:
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
                                    perror("select one");
                                }

                        
                            break;
                            case 6:
                        
                            break;
                    
                            default:
                            break;
                        }
                }
                    break;

                default:
                    break;
                }

               
            }
            
            





        break;
        
        case 2:
            printf("**choosen: %i **\n", res);
        
        break;
        
        case 3:
            printf("The Program will shut down", res);
            ON = 0;
        
        break;
        
        default:
            perror("no options chosen");
            break;
        }
        

    }
    

  
};




// FUNCTIONS
User SelectUser(int dblenght, User db[], char userpass[]){
    for(int i = 0; i < dblenght; i++){
        
        passconfirm = stricmp(userpass, db[i].password);
        if(passconfirm == 0){

            return db[i];
        }
                   
    } 
};


