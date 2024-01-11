#include<string.h>
#include<stdio.h>

struct passenger{
    char userName[50];
    char passNo[20];
};
int registration(){
    FILE *log;
    log = fopen("keya.txt","wb");
    struct passenger p1;

    printf("Enter the passport number: ");
    scanf("%s",&p1.passNo);
    printf("Enter Username: ");
    scanf("%s",&p1.userName);

    fwrite(&p1, sizeof(p1),1,log);

    printf("\nRegistration successful....\n");
    fclose(log);

    printf("\n\nYour User Name is UserId\n");
    printf("Your passport number is password\n\n");
    printf("\n ------------- Login ------------------\n");

    if(login()){
        int option;
        do{
            showMenu();
            printf("Enter option: ");
            scanf("%d",&option);
            MenuOption(option);

        }while(option!=4);
    }
}

int login(){
    char userId[50];
    char pass[20];

    FILE *log;
    log = fopen("keya.txt","r");
    struct passenger p1;
    printf("Enter UserId: ");
    scanf("%s",&userId);
    printf("Enter Password: ");
    scanf("%s",&pass);
    while(fread(&p1, sizeof(p1),1, log)){
        if(strcmp(userId, p1.userName)==0 && strcmp(pass, p1.passNo)==0){
            printf("\nLogged in successfully.\n");
            return 1;
        }
        else{
            printf("Invalid userId and password..\n");
        }
    }
    fclose(log);

}






