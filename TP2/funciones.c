#include "funciones.h"

void mostrarpersona(EPersona x)
{
    printf("%s\t\t",x.nombre);
    printf("%d\t",x.edad);
    printf("%d\t",x.dni);
    printf("%d\n",x.estado);
}
void cargarPersonas(EPersona gente[],int cant)
{
   char nombre[20][21]={"carlos","agustin","marlon","estela","marta","vera","ana","cristo","elisa","paola","agusto","joaquin","mina","carla","sofia","elena","erica","mauro","paul","jose"};
    int edad[20]={16,17,25,35,42,22,41,19,39,27,23,22,16,12,50,53,47,27,15,30};
     int dni[20]={12345678,45612897,41568132,64238488,38453453,22872733,78634127,72483215,33554681,35461223,33345678,45344556,45241589,78455158,15345453,37546132,17445138,85456125,17545645,34534345};
    int estado[20]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

    int i;
     for(i=0; i<cant;i++)
    {
        strcpy(gente[i].nombre, nombre[i]);
        gente[i].edad = edad[i];
        gente[i].dni = dni[i];
        gente[i].estado = estado[i];
    }

}
int obtenerEspacioLibre(EPersona gente[],int cant)
{
    int i,flag1=0;
    int indice;
    for(i=0;i<cant;i++)
    {
        if(gente[i].estado!=1)
        {
            indice=i;
            flag1=1;
            break;
        }

    }
     if(flag1==0)
     {
         indice=-1;
     }
    return indice;
}
int buscarPorDni(EPersona gente[], int numDNI)
{
    int indic,flag0=0,i;
    for(i=0;i<5;i++)
    {
        if(gente[i].dni==numDNI)
        {
            indic=i;
            flag0=1;
            break;
        }
    }
    if(flag0==0)
    {
        indic=-1;
    }
    return indic;
}
void MostpersOrde(EPersona gente[],int cant,int modo)
{
    int i,j;
    EPersona auxPersona;
    if(modo==1)
        {
            for(i=0;i<cant-1;i++)
            {
                for(j=i+1;j<cant;j++)
                {
                    if(strcmp(gente[i].nombre,gente[j].nombre)>0)
                    {
                        auxPersona=gente[i];
                        gente[i]=gente[j];
                        gente[j]=auxPersona;

                    }
                }
            }
        }
    if(modo==2)
    {
        for(i=0;i<cant-1;i++)
        {
            for(j=i+1;j<cant;j++)
            {
                if(strcmp(gente[i].nombre,gente[j].nombre)<0)
                {
                    auxPersona=gente[i];
                    gente[i]=gente[j];
                    gente[j]=auxPersona;

                }
            }
        }
    }
}
