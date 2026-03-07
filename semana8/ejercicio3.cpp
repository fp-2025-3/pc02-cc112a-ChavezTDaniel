#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct Proyecto{
int id;
char titulo[40];
double presupuesto;
int duracionMeses;
};

int main(){
    int N;
cout<<"Numero de proyectos: ";
cin>>N;
cout<<endl;
Proyecto *PROYECTOS=new Proyecto[N];
int*ID=new int[N];

// INGRESAMOS DATOS CON EL DINERO EN FORMA DECRECIENTE
for(int i=0;i<N;i++){
cout<<"Proyecto "<<i+1<<endl;
cout<<"ID: ";cin>>PROYECTOS[i].id;
cin.ignore();
cout<<"Titulo: ";cin.getline(PROYECTOS[i].titulo,40);
cout<<"Presupuesto: ";cin>>PROYECTOS[i].presupuesto;
cout<<"Duracion (meses): ";cin>>PROYECTOS[i].duracionMeses;
cout<<endl;
ID[i]=PROYECTOS[i].id;
}

// Hacemos un burbuja en orden decreciente para ordenar los prespuestos de mayor a menor
for(int i=0;i<N-1;i++){
    for(int j=N-1;j>i;j--){
     if(PROYECTOS[j].presupuesto>PROYECTOS[j-1].presupuesto){
        swap(PROYECTOS[j-1],PROYECTOS[j]);
     }
    }
}

 // ESCRIBIMOS L0S DATOS EN EL ARCHIVO BINARIO 
ofstream archivonuevo("proyectos.dat",ios::binary);

if(!archivonuevo){
    cout<<"Error al intentar abrir el archivo. "<<endl;
    return 1;
}

archivonuevo.write((char*)PROYECTOS,sizeof(Proyecto)*N);   // Ya pasamos todos los datos al archibo binario;
archivonuevo.close();
delete[]PROYECTOS;


// INGRESAR NUEVO PROYECTO CON ACCESO ALEATORIO MEDIANTE INSERCION
// ANTES DE REGISTRAR EL PROYECTO VERIFICAR SI EXISTE DENTRO DEL ARCHIVO

fstream archivo("proyectos.dat",ios::binary|ios::out|ios::in);

if(!archivo){
    cout<<"Error al abrir archivo. ";
    return 1;
}

Proyecto NUEVO;
cout<<"Nuevo proyecto a insertar. "<<endl;
cout<<"ID: ";cin>>NUEVO.id;
cin.ignore();
cout<<"Titulo: ";cin.getline(NUEVO.titulo,40);
cout<<"Presupuesto: ";cin>>NUEVO.presupuesto;
cout<<"Duracion (meses): ";cin>>NUEVO.duracionMeses;
cout<<endl;

int posicion=0;
 
for(int i=N-1;i>=0;i--){
Proyecto temporal;
archivo.seekg((i)*sizeof(Proyecto),ios::beg);      
archivo.read((char*)&temporal,sizeof(Proyecto)); 

if(NUEVO.presupuesto>temporal.presupuesto){    //Si mayor movemos todos los datos una posicion
archivo.seekp((i+1)*sizeof(Proyecto),ios::beg); 
archivo.write((char*)&temporal,sizeof(Proyecto)); 

}else{ //En caso sea menor y nos encontramos en la posicion y este sera ubicado en la pocion 
   posicion=i+1;
   break;
}

}

//COMPROBAMOS SI HAY UN ID SIMILAR
bool encontrar=false;
for(int i=0;i<N;i++){
if(NUEVO.id!=ID[i]){
    continue;
}else{
    encontrar=true;
    cout<<"Error ingrese un Proyecto con id no repetido. ";
    delete[]ID;
    return 1;
}
}
if(!encontrar){
  archivo.seekp(posicion*sizeof(Proyecto),ios::beg);
  archivo.write((char*)&NUEVO,sizeof(Proyecto));  //Finalmente guardamos los datos
}


delete[]ID;
archivo.close();

// LECTURA DE ARCHIVO BINARIO
ifstream leerArchivo("proyectos.dat",ios::binary);
if(!leerArchivo){
    cout<<"Error al leer el archivo . ";
    return 0;
}

Proyecto*nuevo=new Proyecto[N+1];
leerArchivo.read((char*)nuevo,sizeof(Proyecto)*(N+1));

cout<<"Contenido del archivo"<<endl;
for(int i=0;i<N+1;i++){
cout<<nuevo[i].id<<" "<<nuevo[i].titulo<<" "<<nuevo[i].presupuesto<<" "<<nuevo[i].duracionMeses<<endl;
}
leerArchivo.close();
delete [] nuevo;


    return 0;
}
