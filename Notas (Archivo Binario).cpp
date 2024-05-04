#include<iostream>
using namespace std;
const char *nombre_archivo="notas.date";
struct Estudiante{
	int id, res, promedio;
	char nombres[50];
	char apellidos[50];
	int nota_1,nota_2,nota_3,nota_4;
};

void leer();
void crear();
void borrar();
void actualizar();


int main(){
	leer();
	crear();
	borrar();
	actualizar();
		
		
	system("pause");
}

void leer(){
	system("cls");
	FILE* archivo=fopen(nombre_archivo,"rb");
	if(!archivo){
		archivo=fopen(nombre_archivo,"w+b");
	}
	
	Estudiante estudiante;
	int indice=0;
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	cout<<"______________________________"<<endl;
	cout<<"No."<<"|"<<"Codigo"<<"|"<<"    Nombres   "<<"|"<<"   Apellidos   "<<"|"<<"Nota 1"<<"|"<<"Nota 2"<<"|"<<"Nota 3"<<"|"<<"Nota 4"<<"|"<<"RESULTADO"<<"|"<<"PROMEDIO"<<endl;
	do{
		cout<<indice<<"  |"<<estudiante.id<<"    |"<<estudiante.nombres<<"        |"<<estudiante.apellidos<<"   |"<<estudiante.nota_1<<"    |"<<estudiante.nota_2
		<<"    |"<<estudiante.nota_3<<"    |"<<estudiante.nota_4<<"    |"<<estudiante.res<<"    |"<<estudiante.promedio<<endl;		
		indice+=1;
		if(estudiante.promedio>60){
			cout<<"APROBADO\n"<<endl;
		}
		else{
			cout<<"REPROBADO\n"<<endl;
		}
		fread(&estudiante,sizeof(Estudiante),1,archivo);
	}while(feof(archivo)==0);
	fclose(archivo);
}

void crear(){
	FILE* archivo=fopen(nombre_archivo,"a+b");
	

	Estudiante estudiante;
	int est=0;
	cout<<"Cuantos estudiantes desea ingresar: ";
	cin>>est;
	
	for(int i=0;i<est;i++){
		fflush(stdin);
		cout<<"\nIngrese el ID: ";
		cin>>estudiante.id;
		cin.ignore();
		cout<<"Ingrese nombres: ";
		cin.getline(estudiante.nombres,50);
		cout<<"Ingrese apellidos: ";
		cin.getline(estudiante.apellidos,50);
		cout<<"Ingrese nota 1: ";
		cin>>estudiante.nota_1;
		cout<<"Ingrese nota 2: ";
		cin>>estudiante.nota_2;
		cout<<"Ingrese nota 3: ";
		cin>>estudiante.nota_3;
		cout<<"Ingrese nota 4: ";
		cin>>estudiante.nota_4;
		estudiante.res=estudiante.nota_1+estudiante.nota_2+estudiante.nota_3+estudiante.nota_4;
		estudiante.promedio=(estudiante.res/4);
		
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);

	}
			
	fclose(archivo);
	leer();
	
	
}

void actualizar(){
	FILE* archivo=fopen(nombre_archivo,"r+b");
	Estudiante estudiante;
	int indice=0;
	cout<<"Ingrese el No. que desea modificar: ";
	cin>>indice;
	fseek(archivo,indice*sizeof(Estudiante),SEEK_SET);

		cout<<"\nIngrese el ID: ";
		cin>>estudiante.id;
		cin.ignore();
		cout<<"Ingrese nombres ";
		cin.getline(estudiante.nombres,50);
		cout<<"Ingrese apellidos: ";
		cin.getline(estudiante.apellidos,50);
		cout<<"Ingrese nota 1: ";
		cin>>estudiante.nota_1;
		cout<<"Ingrese nota 2: ";
		cin>>estudiante.nota_2;
		cout<<"Ingrese nota 3: ";
		cin>>estudiante.nota_3;
		cout<<"Ingrese nota 4: ";
		cin>>estudiante.nota_4;
		estudiante.res=estudiante.nota_1+estudiante.nota_2+estudiante.nota_3+estudiante.nota_4;
		estudiante.promedio=(estudiante.res/4);
		
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);

	
	fclose(archivo);
	leer();
}

void borrar(){
	const char *nombre_archivo_temp="notas_temp.date";
	FILE* archivo_temp=fopen(nombre_archivo_temp,"w+b");
	FILE* archivo=fopen(nombre_archivo,"rb");
	Estudiante estudiante;
	int indice=0, indice_n=0;
	cout<<"Ingrese el No. a eliminar: ";
	cin>>indice;
	
	while(fread(&estudiante,sizeof(Estudiante),1,archivo)){
		if(indice_n!=indice){
			fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp);
		}
		indice_n++;
		
	}
	fclose(archivo);
	fclose(archivo_temp);
	archivo_temp=fopen(nombre_archivo_temp,"rb");
	archivo=fopen(nombre_archivo,"wb");
	while(fread(&estudiante,sizeof(Estudiante),1,archivo_temp)){
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	}
	
	fclose(archivo);
	fclose(archivo_temp);
	leer();
}

