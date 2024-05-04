#include<iostream>
using namespace std;
struct Estudiante{
	int id;
	string nom, ape;
};
int main(){
	int est=0, suma=0, promedio=0;
	int nota_1=0, *pnota_1;
	int nota_2=0, *pnota_2;
	int nota_3=0, *pnota_3;
	int nota_4=0, *pnota_4;
	pnota_1=&nota_1;
	pnota_2=&nota_2;
	pnota_3=&nota_3;
	pnota_4=&nota_4;
	
	Estudiante estudiante;

	cout<<"Cuantos estudiantes desea ingresar: "<<endl;
	cin>>est;
	
	for(int i=0;i<est;i++){
		cout<<"\nIngrese numero de ID: ";
		cin>>estudiante.id;
		cin.ignore();
		cout<<"Ingrese nombres: ";
		getline(cin,estudiante.nom);
		cout<<"Ingrese apellidos: ";
		getline(cin,estudiante.ape);
		cout<<"Ingrese nota 1: ";
		cin>>nota_1;
		cout<<"Ingrese nota 2: ";
		cin>>nota_2;
		cout<<"Ingrese nota 3: ";
		cin>>nota_3;
		cout<<"Ingrese nota 4: ";
		cin>>nota_4;
		suma=*pnota_1+*pnota_2+*pnota_3+*pnota_4;
		promedio=(suma/4);
		if(promedio>60){
			cout<<"El promedio es de "<<promedio<<" el estudiante a aprobado"<<endl;
		}
		else
			cout<<"El promedio es de "<<promedio<<" el estudiante a reprobado"<<endl;	
		}
	system("pause");
}
