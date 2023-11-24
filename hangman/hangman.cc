#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctime>

#define WRONGTRIES 5

using namespace std;

void pintarHombre(int intentos){
    cout<<"\n\n";
    cout<<"  -----\n";
    cout<<"  |   |\n";
    cout<<"  |"; if(intentos<=4) cout<<"  o   "; cout<<"\n";
    cout<<"  |"; if(intentos<=3) cout<<" /|\\   ";cout<<"\n";
    cout<<"  |"; if(intentos<=0) cout<<" / \\    ";cout<<"\n";
    cout<<"  |\n";
    cout<<"__|__\n";
}
int main(){
    srand (time(NULL));
    string ListaDePalabras[7] = {"cuadrado", "fresa", "barco", "quevedo", "linton", "bunda", "ass"};
    string palabra;
    string adivinada;

    palabra = ListaDePalabras[rand()%7];

    int PalabraLength = palabra.length();
    string PalabraDispo(PalabraLength, '_');

    int encontrada = 0;
    char adivina = ' ';
    int intentos = 5; //Numero de intentos fallidos
    int flagFound = 0;

    while (intentos>=0)
    {
        system("clear");
        cout<<"Adivina la palabra: \n\n";

        for (int i = 0; i < PalabraLength; i++)
        {
            cout<<" "<<PalabraDispo[i]<<" ";
        }
        cout<<"\n\n\n";

        cout<<"Intentos: "<<intentos<<" / "<<WRONGTRIES<<"\n";
        cout<<"Letras usadas: "<<adivinada<<"\n";

        pintarHombre(intentos);

        if (encontrada == PalabraLength)
        {
            cout<<"\n";
            cout<<"*******************\n";
            cout<<"*    Has Ganado   *\n";
            cout<<"*******************\n";
            break;
        }
        
        if (intentos == 0) break;
        {
            cout<<"Escoje una letra:";
            adivina = getche();

            adivinada = adivinada + " " + adivina;
        }

        if (PalabraDispo.find(adivina) != string::npos)intentos++;
        {       
            flagFound = 0;
            for (int i = 0; i < PalabraLength; i++)
            {
                if(palabra[i]==adivina && PalabraDispo[i] == '_'){
                    PalabraDispo[i] = adivina;
                    encontrada++;
                    flagFound = 1;
                }
            }   
        }
        
        if(!flagFound)
        {
            intentos--;
        }
    }
    if(encontrada != PalabraLength)
    {
        cout<<"\n";
        cout<<"********************\n";
        cout<<"*    Has Perdido   *\n";
        cout<<"********************\n";
    }

    getch();
    return 0;
}