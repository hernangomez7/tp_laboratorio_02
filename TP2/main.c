#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#define TAM 20

int main()
{
    char seguir='s',opcion='0',aux,nombreaux[100];
    int i,flag01=0,dniBorrar,c18=0,c19y35=0,c36=0,num,naux,maximo;
    EPersona gente[TAM]={0};
    cargarPersonas(gente,TAM);
    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");


        opcion=getch();

        switch(opcion)
        {
            case '1':
                num=obtenerEspacioLibre(gente,TAM);
                if(num!=-1)
                {
                    do
                    {
                        system("cls");
                        printf("ingrese nombre:\n");
                        fflush(stdin);
                        gets(nombreaux);
                    }while(strlen(nombreaux)>36);
                    strcpy(gente[num].nombre,nombreaux);
                    do
                    {
                        system("cls");
                        printf("ingrese edad:\n");
                        fflush(stdin);
                        scanf("%d",&naux);
                    }while(naux>125||naux<1);
                    gente[num].edad=naux;
                    do
                    {
                        system("cls");
                        printf("ingrese dni:\n");
                        fflush(stdin);
                        scanf("%d",&naux);
                    }while(naux>999999999||naux<1000000);
                    gente[num].dni=naux;
                    do
                    {
                        system("cls");
                        printf("nombre=%s\n",gente[num].nombre);
                        printf("edad=%d\n",gente[num].edad);
                        printf("DNI=%d\n",gente[num].dni);
                        printf("confirmar datos:S/N\n");
                        fflush(stdin);
                        aux=getch();
                    }while(aux!='s'&&aux!='n');
                    if(aux=='s')
                    {
                        gente[num].estado=1;
                        flag01=1;
                        system("cls");
                        printf("accion completada!\n");
                    }
                    else if(aux=='n')
                    {
                        gente[num].estado=-1;
                        flag01=1;
                        system("cls");
                        printf("accion cancelada!\n");
                    }
                }
                if(flag01==0)
                {
                    system("cls");
                    printf("sin espacio!!!\n");
                    flag01=0;
                }
                    break;
            case '2':
                system("cls");
                printf("borrar a:(ingrese DNI de persona)\n");
                scanf("%d",&dniBorrar);
                system("cls");
                printf("Usted esta seguro?S/N borrar:%d\n",dniBorrar);
                aux=getch();
                if(aux=='s')
                {
                    num=buscarPorDni(gente,dniBorrar);
                    if(num!=-1)
                    {
                        if(gente[num].dni==dniBorrar)
                        {
                            gente[num].estado=-1;
                            system("cls");
                            printf("borrado!!!\n");
                            flag01=1;
                        }
                    }
                    if(flag01==0)
                    {
                        system("cls");
                        printf("accion fallida\n");
                        break;
                    }
                }
                else
                {
                    system("cls");
                    printf("accion cancelada!\n");
                }
                break;
            case '3':
                system("cls");
                printf("께께께께께께께께께께께께께께께께께께께께께께께께께께께\n");
                printf("nombre\t\tedad\tDNI\t\testado\n");
                printf("께께께께께께께께께께께께께께께께께께께께께께께께께께께\n");
                MostpersOrde(gente,TAM,1);
                for(i=0;i<TAM;i++)
                {
                    if(gente[i].estado==1)
                    {
                        mostrarpersona(gente[i]);
                    }
                }
                printf("께께께께께께께께께께께께께께께께께께께께께께께께께께께\n");
                break;
            case '4':
                printf("께께께께께께께께께께께께께께께께께께께께께께께께께께께\n");
                printf("-18\t19a35\t+35\n");
                printf("께께께께께께께께께께께께께께께께께께께께께께께께께께께\n");
                 for(i=0;i<TAM;i++)
                 {
                     if(gente[i].edad<18)
                     {
                         if(gente[i].estado==1)
                         {
                             c18=c18+1;
                         }
                     }
                     else if(gente[i].edad>18&&gente[i].edad<36)
                     {
                         if(gente[i].estado==1)
                         {
                             c19y35=c19y35+1;
                         }
                     }
                     else
                     {
                         if(gente[i].estado==1)
                         {
                             c36=c36+1;
                         }
                     }
                 }

                 if(c18>c19y35)
                 {
                     maximo=c18;
                 }else{
                    maximo=c19y35;
                 }
                 if(maximo<c36)
                 {
                     maximo=c36;
                 }
                 for(i=0;i<maximo;i++)
                 {
                    if(c18>0)
                    {
                        printf("*\t");
                        c18=c18-1;
                    }
                    else if(c18==0)
                    {
                        printf(" \t");
                    }
                    if(c19y35>0)
                    {
                        printf("*\t");
                        c19y35=c19y35-1;
                    }
                    else if(c19y35==0)
                    {
                        printf(" \t");
                    }
                    if(c36>0)
                    {
                        printf("*\n");
                        c36=c36-1;
                    }
                    else if(c36==0)
                    {
                        printf(" \n");
                    }

                 }
                 printf("께께께께께께께께께께께께께께께께께께께께께께께께께께께\n");
                break;
            case '5':
                seguir = 'n';
                break;
        }
    }

    return 0;
}
