#include <stdio.h>

int addition(int nb1, int nb2)
{
    return nb1 + nb2;
}

int soustraction(int nb1, int nb2)
{
    return nb1 - nb2;
}
int calculer(int nombre1, int nombre2, int (*pointeurFonction)(int,int))
{
    pointeurFonction(nombre1,nombre2);
}

int main(void){

    int (*pointeurFonction)(int,int);
    int a = 14;
    int b = 28;

    int res = calculer(a,b,&addition);
    printf("%d\n",res);

    return 0;
}