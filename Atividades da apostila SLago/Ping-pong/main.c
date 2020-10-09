#include <stdio.h>
#include <conio.h>

#include "console.h"

int main(){
    int x=1, y=1;
    int dx=-1, dy=-1;


    do{
        gotoxy(x, y);
        printf("%c", 218);
        Sleep(25);
        gotoxy(x, y);
        printf("%c", 219);

        if(x==1 || x==80){
            // printf("\a");
            Sleep(25); 

            dx = -dx;
        }

        if(y==1 || y==24){
            // printf("\a");
            Sleep(25);

            dy = -dy;
        }

        x += dx;
        y += dy;

    }while(!kbhit());

    return 0;
}