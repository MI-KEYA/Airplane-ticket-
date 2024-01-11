#include<stdio.h>
#include "splash.h"
#include "userlogin.h"
#include "booking.h"
int main(){
    for(int i=0;i<8;i++){

    showSplashScreen();
    delay(250);
    system("cls");
    delay(250);
    }
    welcome();
    printf("Please do Registration first...\n\n");
    registration();

    return 0;
}
