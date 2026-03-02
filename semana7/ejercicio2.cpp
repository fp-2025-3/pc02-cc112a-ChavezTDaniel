#include <iostream>
#include <fstream>
struct Empleado{

int id;
char nombre[30];
double salario;

};
using namespace std;

int main(){
int id;
double nuevo_salario;
cout<<"Ingrese id de empleado: ";cin>>id;
if(id<=0){
    cout<<"Error, id invalido. "<<endl;
    return 1;
}

fstream archivoLectura("empleados.dat",ios::binary | ios::in |ios::out);

if(!archivoLectura){
    cout<<"Error al abrir el archivo. ";
    return 1;

}

Empleado original;
archivoLectura.seekg((id-1)*sizeof(Empleado),ios::beg);
archivoLectura.read((char*)&original,sizeof(Empleado));

cout<<"---DATOS DEL EMPLEADO---"<<endl;
cout<<"ID: "<<original.id<<endl;
cout<<"Nombre: "<<original.nombre<<endl;
cout<<"Salario: "<<original.salario<<endl;


cout<<"Ingrese nuevo salario: ";cin>>nuevo_salario;
if(nuevo_salario<=0){
    cout <<"Error, precio invalido."<<endl;
    return 1;
}


Empleado em;

archivoLectura.seekg((id-1)*sizeof(Empleado),ios::beg);
archivoLectura.read((char*)&em,sizeof(Empleado));

em.salario=nuevo_salario;

archivoLectura.seekp((id-1)*sizeof(Empleado),ios::beg);
archivoLectura.write((char*)&em,sizeof(Empleado));
archivoLectura.close();
cout<<"Salario actualizado correctamente. ";


    return 0;
}
