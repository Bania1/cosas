#include <iostream>

using namespace std;

int main()
{
    int n;

    cout<<"introduce un numero para hacerle el fatorial"<<endl;
    cin>>n;

    int aux = n;

    for(int contador = 1; contador < aux; contador++)
    {
        n*=contador;  //-------> n=n*contador;
    }

    cout<<n<<endl;
    
} //5*1=5*2=10*3=30*4=120