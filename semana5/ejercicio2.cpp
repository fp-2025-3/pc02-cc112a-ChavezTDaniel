#include <iostream>
using namespace std;
struct fecha{
 int dia;
 int mes;
 int año;

};
struct contactos{
    char nombre[20];
    fecha nacimiento;

};

int main(){
    int N;
    cout<<"Ingrese el numero de contactos: "<<endl;
    cin>>N;
contactos*ptr=new contactos[N];

for(int i=0;i<N;i++){
  cout<<"Contacto "<<i+1<<" : "<<endl;
  cout<<"nombre: ";cin>>(*(ptr+i)).nombre;
  cout<<"Ingrese fecha de nacimiento: "<<endl;
  cout<<"Dia: ";cin>>(*(ptr+i)).nacimiento.dia;
  cout<<"Mes: ";cin>>(*(ptr+i)).nacimiento.mes;
  cout<<"Dia: ";cin>>(*(ptr+i)).nacimiento.año;

}
int año;
cout<<"Ingrese el año: ";
cin>>año;
cout<<"Personas nacidas en el año "<<año<<": "<<endl;
for(int i=0;i<N;i++){
    if((*(ptr+i)).nacimiento.año==año){
  cout<<"nombre: "<<(*(ptr+i)).nombre<<endl;
  cout<<"Fecha de nacimiento: "<<endl;
  cout<<"Dia: "<<(*(ptr+i)).nacimiento.dia<<endl;
  cout<<"Año: "<<(*(ptr+i)).nacimiento.mes<<endl;
  cout<<"Año: "<<(*(ptr+i)).nacimiento.año<<endl;
}
}
cout<<endl;

delete[] ptr;

    return 0;
}



