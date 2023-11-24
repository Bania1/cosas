#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

	struct Alumno{
		int dni=0;
		int edad=0;
		float nota;
	
		void print(){
			cout<<""<<endl;
			cout<<"dni: "<<dni<<" edad: "<<edad<<" nota: "<<nota<<endl;		
		}
		void add(){
			cout<<"introduce el dni"<<endl;
			cin>>dni;
			cout<<"introduce la edad"<<endl;
			cin>>edad;
			cout<<"introduce la nota"<<endl;
			cin>>nota;
		}
		void mod(){
			int op;
			cout<<"que cambio quiere realizar"<<endl;
			cout<<"1-nota		2-edad		3-ambas"<<endl;
			cin>>op;
			if(op==1){
				cout<<"introduce la nueva nota"<<endl;
				cin>>nota;
			}
			else if(op==2){
				cout<<"introduce la nueva edad"<<endl;
				cin>>edad;
			}
			else if(op==3){
				cout<<"introduce la nueva edad"<<endl;
				cin>>edad;
				cout<<"introduce la nueva nota"<<endl;
				cin>>nota;
			}
			else{
			cout<<"opcion invalida"<<endl;
			}
		}
		void eliminar(){
			dni=0;
			edad=0;
			nota=0;
		}
	};

	int find(Alumno v[],int n){
		for(int i=0;i<10;i++){
			if(v[i].dni==n){
				return i;
			}
		}
		return -1;
	}

	int menu(){
		cout<<""<<endl;
		cout<<"1-añadir alumno"<<endl;
		cout<<"2-mostrar datos del alumno"<<endl;
		cout<<"3-mostrar todos los alumnos"<<endl;
		cout<<"4-modificar alumno"<<endl;
		cout<<"5-eliminar alumno"<<endl;
		cout<<"6-salir"<<endl;
		cout<<""<<endl;
		cout<<"elija una opcion a realizar"<<endl;
		cout<<""<<endl;
		int op;cin>>op;
		return op;
	}


	int main(){
		Alumno v[10];
		int na=0;
		int op=0;
		int n,i;
		do{
			op=menu();
			switch(op){
				case 1:
					cout<<"ha elegido añadir alumno"<<endl;
					if(na!=10){
						v[na].add();
						na++;
					}
					else{
					cout<<"no es posible añadir mas alumnos"<<endl;
					}
					break;
				case 2:
					cout<<"ha elegido mostrar datos del alumno"<<endl;
					cout<<"introduce el dni del alumno que quieres mostrar"<<endl;
					cin>> n;
					i=find(v,n);
					if(i!=-1){
						cout<<"los datos del alumno son"<<endl;		
						v[i].print();
					}
					else{
						cout<<"alumno no existente"<<endl;
					}
					break;
				case 3:
					cout<<"ha elegido mostrar todos los alumnos"<<endl;
					for(int i=0;i<na;i++){
						v[i].print();
					}
					break;
				case 4:
					cout<<"ha elegido modificar alumno"<<endl;
					cout<<"introduzca el dni del alumno a modificar"<<endl;
					cin>>n;
					i=find(v,n);
					if(i!=-1){
						v[i].mod();
					}
					else{
						cout<<"alumno no existente"<<endl;
					}
					break;
				case 5:
					cout<<"ha elegido eliminar alumno"<<endl;
					cout<<"introduce el dni del alumno a eliminar"<<endl;
					cin>>n;
					int ult=na-1;
					i=find(v,n);
					if(i!=-1){
						v[i].eliminar();
						cout<<"alumno eliminado"<<endl;
						v[i]=v[ult];
						v[ult].eliminar();
						na--;
					}
					else{
						cout<<"alumno no existente"<<endl;
					}
					break;
			};
		}
		while(op!=6);

   system("pause");
	}
