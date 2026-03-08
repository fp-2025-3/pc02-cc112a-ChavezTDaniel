#include "Sensor.h"
#include <string>
using namespace std;

int main(){
int opcion;
int N;
cout<<"Ingrese cantidad maxima de sensores: ";cin>>N;
SistemaSensores*nuevosSensores=new SistemaSensores(N);

do{
    string id="";
    double numx,numy;
    int radio;
    double ancho,alto;
    int puntox=0;int puntoy=0;
    cout<<endl;
cout<<"---SENSORES--- "<<endl;
cout<<"1. Agregar un sensor Circular"<<endl;
cout<<"2. Agregar un sensor rectangular"<<endl;
cout<<"3. Mostrar todos los sensores"<<endl;
cout<<"4. Calcular el area total de cobertura"<<endl;
cout<<"5. Cantidad de sensores que detectan un punto (x,y)"<<endl;
cout<<"6. Sensor de mayor cobertura"<<endl;
cout<<"7. Salir"<<endl;
cin>>opcion;
switch(opcion){
 
case 1:{
    cout<<"Ingrese id: ";cin>>id;
    cout<<"Ingrese coordenada x = ";cin>>numx;
    cout<<"Ingrese coordenada y = ";cin>>numy;
    cout<<"Ingrese radio: ";cin>>radio;
    Sensor*circular=new SensorCircular(id,numx,numy,radio);
    nuevosSensores->agregarSensor(circular);
break;
}
case 2:{
    cout<<"Ingrese id: ";cin>>id;
    cout<<"Ingrese coordenada x = ";cin>>numx;
    cout<<"Ingrese coordenada y = ";cin>>numy;
    cout<<"Ingrese ancho: ";cin>>ancho;
    cout<<"Ingrese alto: ";cin>>alto;
    Sensor*cuadrado=new SensorRectangular(id,numx,numy,ancho,alto);
    nuevosSensores->agregarSensor(cuadrado);
break;
}
case 3:{
nuevosSensores->mostrarSensores();
break;
}
case 4:{
    cout<<"Area total cubierta: "<<nuevosSensores->areaTotalCobertura()<<" m^2";
    cout<<endl;
break;
}
case 5:{
cout<<"Ingrese x = ";cin>>puntox;
cout<<"Ingrese y = ";cin>>puntoy;
cout<<"Cantidad de sensores que detectan ("<<puntox<<","<<puntoy<<"): "<<nuevosSensores->sensoresQueDetectan(puntox,puntoy);
cout<<endl;
break;
}
case 6:{
cout<<"Sensor de mayor cobertura: "<<endl;
nuevosSensores->SensorMayorCobertura()->imprimir();
break;
cout<<endl;
}

}
}while(opcion!=7);
delete nuevosSensores;
return 0;
}
