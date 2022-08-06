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
User SelectUser(int, User);

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
    char username[60];
    char password[60] = "adminpsw";

int main(){
    

    //FAKE DATABASE
    User database[] = {admin, user1, user2, user3};
    int dbsize = sizeof(database)/sizeof(database[0]);
    
    User NewUser = SelectUser(dbsize, database);
    
    printf("usuario nuevo: %s", NewUser.username);

/*
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
                
                for(int i; i > dbsize; i++){
                    passconfirm = stricmp(password, database[i].password);
                    if(passconfirm){
                        printf("welcome %s", database[i].username );
                    }else{
                        perror("user dont found");
                    }
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
            perror("non optios choosed");
            break;
        }
        

    }
    

    */
};




// FUNCTIONS
User SelectUser(int dblenght, User db[]){
    for(int i = 0; i < dblenght; i++){
        
            passconfirm = stricmp(password, db[i].password);
            if(passconfirm == 0){
                printf("welcome %s \n", db[i].username );
                return db[i];
            }else{
                printf("no es %s \n", db[i].username );
                printf("contraseña: %s \n", password );
                printf("passconfirm:  %i \n", passconfirm );
            }
            
                   
        } 
};

