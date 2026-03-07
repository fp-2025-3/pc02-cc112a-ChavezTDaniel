#include <iostream>
#include <cmath>
using namespace std;
 int N;
struct Punto{
double x;
double y;
};

void leerPunto(Punto*p);
double distanciaOrigen(const Punto*p);
Punto* masLejano(Punto*p1,Punto*p2);

int main(){

Punto p1;
leerPunto(&p1);
Punto p2;
leerPunto(&p2);


Punto*lejano=masLejano(&p1,&p2);
cout<<"EL punto mas lejano al origen entre ("<<p1.x<<","<<p1.y<<") y ("<<p2.x<<","<<p2.y<<") "<<"es: "<<"("<<lejano->x<<","<<lejano->y<<")."<<endl;


    return 0;
}

void leerPunto(Punto*p){   // copia del puntero original
    double a,b;
    cout<<"Ingrese datos del punto."<<endl;
    cout<<"x=";cin>>a;
    cout<<"y=";cin>>b;
    p->x=a;
    p->y=b;
 }

double distanciaOrigen(const Punto*p){
double distance;
double X=(p->x)*(p->x);
double Y=(p->y)*(p->y);
distance=sqrt(X+Y);
return distance;
}
Punto* masLejano(Punto*p1,Punto*p2){
if(distanciaOrigen(p1)>distanciaOrigen(p2)){
return p1;
}else{
 return p2;
}
}
