#include<iostream>
using namespace std;
int main(){
	int estudiantes=0, id=0, suma=0, promedio=0;
	string nom, ape;
	int notas[3];
	cout<<"Cuantos estudiantes desea ingresar: "<<endl;
	cin>>estudiantes;
	
	for(int i=0;i<estudiantes;i++){
		cout<<"\nIngrese numero de ID: ";
		cin>>id;
		cout<<"Ingrese nombres: ";
		cin>>nom;
		cout<<"Ingrese apellidos: ";
		cin>>ape;
		cout<<"Ingrese la nota 1: ";
		cin>>notas[0];
		cout<<"Ingrese la nota 2: ";
		cin>>notas[1];
		cout<<"Ingrese la nota 3: ";
		cin>>notas[2];
		cout<<"Ingrese la nota 4: ";
		cin>>notas[3];
		suma=notas[0]+notas[1]+notas[2]+notas[3];
		promedio=(suma/4);
		if(promedio>60){
			cout<<"El promedio es de "<<promedio<<" el estudiante aprobo"<<endl;
		}
		else{
			cout<<"El promedio es de "<<promedio<<" el estudiante reprobo"<<endl;
		}
	}
	
	system("pause");
}
