#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip> 
using namespace std;
struct partidos{
int GF; 
int GC;
int DG;
int resultado;
//La suma de resultado nos da los puntos totales
//(resultado/300)*100 nos da el rendimiento
};

struct estadisticas{
 double rend;
 int Pts;
 int GFtotal;
 int GCtotal;
 int DGtotal;
};

struct equipo{
 partidos*PARTIDOS;       //Uso punteros si le voy asignar memoria dinamica
 char*nombres_equipos;
 estadisticas generales;
 int PG,PE,PP;
};

//Para reservar memoria dinamica
equipo* M_dinamica(equipo*EQUIPOS){

//El numero de equipos es 5;
EQUIPOS=new equipo[5];           //Memoria dinamica para almacenar datos de 5 equipos
for(int i=0;i<5;i++){
    EQUIPOS[i].PARTIDOS=new partidos[100];    //Memoria dinamica para almacenar las simulaciones de los 100 partidos que juega cada equipo
}

for(int i=0;i<5;i++){
EQUIPOS[i].nombres_equipos=new char[25];  //Memoria de dinamica para almacenar lso nombres de los equipos
}
return EQUIPOS;
}

equipo* simulaciones(equipo* EQUIPOS) {
srand(time(0));
 for (int i=0;i<5;i++){
        int k=0; 
  for (int j=0;j<5;j++){
       if (i!=j){
               //Un equipo juega 25 partidos con cada equipo diferente a el
   for (int partido=0;partido<25;partido++){
            int goles_a=rand()%6;
            int goles_b=rand()%6;

               EQUIPOS[i].PARTIDOS[k].GF=goles_a;
               EQUIPOS[i].PARTIDOS[k].GC=goles_b;
               EQUIPOS[i].PARTIDOS[k].DG=goles_a-goles_b;
                   
               //Condicionamos los goles para saber si gano empato o perdio
               if (goles_a>goles_b){
               EQUIPOS[i].PARTIDOS[k].resultado=3;
               }else if(goles_a==goles_b){
               EQUIPOS[i].PARTIDOS[k].resultado=1;
               }else{
               EQUIPOS[i].PARTIDOS[k].resultado=0;
              }
              //Nos movemos en todos los partidos de 0-100;
                 k++; 
            }
         }
        }
   }
    return EQUIPOS;
}

equipo*estadisticaSS(equipo*EQUIPOS){
  
 for(int i=0;i<5;i++){
    double Puntaje_total=0;
    int GFtotal=0;int GCtotal=0;int DGtotal=0;
  for(int j=0;j<100;j++){
    Puntaje_total+=EQUIPOS[i].PARTIDOS[j].resultado;
    GFtotal+=EQUIPOS[i].PARTIDOS[j].GF;
    GCtotal+=EQUIPOS[i].PARTIDOS[j].GC;
    DGtotal+=EQUIPOS[i].PARTIDOS[j].DG;
  }
  
   EQUIPOS[i].generales.rend=(Puntaje_total/300)*100;
   EQUIPOS[i].generales.Pts=Puntaje_total;

   EQUIPOS[i].generales.GFtotal=GFtotal;
   EQUIPOS[i].generales.GCtotal=GCtotal;
   EQUIPOS[i].generales.DGtotal=DGtotal;
}
return EQUIPOS;
}

equipo*PG_PE_PP(equipo*EQUIPOS){
//Creamos variables PG, PE, PP y las inicializamos para acumular los partidos ganados 
//perdidos y empatados mediante if 
for(int i=0;i<5;i++){
    int PG=0;int PE=0;int PP=0;
 for(int k=0;k<100;k++){
    if(EQUIPOS[i].PARTIDOS[k].resultado==3){
     PG++;
    }else if(EQUIPOS[i].PARTIDOS[k].resultado==1){
     PE++;
    }else{
     PP++;
    }
 }
    EQUIPOS[i].PG=PG;
    EQUIPOS[i].PE=PE;
    EQUIPOS[i].PP=PP;
}

return EQUIPOS;
}

equipo*NOMBRES_EQUIPOS(equipo*EQUIPOS) {
    cout<<endl;
    cout<<"Ingrese el nombre de los 5 equipos: "<<endl;

    for (int i=0;i<5;i++){
     cout<<"Equipo "<<i+1<<": ";
     cin.getline(EQUIPOS[i].nombres_equipos,25);
    }
    return EQUIPOS;
}

//Para liberar EQUIPOS desde una funcion void le pasamos la direccion, para acceder a la memoria original
void liberar_memoria(equipo*&EQUIPOS){
  for(int i=0;i<5;i++){
   delete[] EQUIPOS[i].PARTIDOS;
   delete [] EQUIPOS[i].nombres_equipos;

  }
 delete[]EQUIPOS;

}
//Pasamos una copia del puntero ordenamos con un bucle burbuja y devolvemos la copia
void ordenar(equipo*EQUIPOS){
for(int i=0;i<5-1;i++){
    for(int j=0;j<5-i-1;j++){
    if(EQUIPOS[j].generales.Pts<EQUIPOS[j+1].generales.Pts){
        swap(EQUIPOS[j],EQUIPOS[j+1]);
    }
    }
}
}
//Usamos setprecision y \t para hacer la salida de manera mas ordenada
void imprimir(equipo*EQUIPOS){
    cout<<endl;
    cout<<"SELECCION\tPG\tPE\tPP\tGF\tGC\tDG\tPts\tRend(%)"<<endl;
    cout<<"--------------------------------------------------------------------------"<<endl;
    for (int i=0;i<5;i++) {
        cout<<EQUIPOS[i].nombres_equipos<<"\t-\t" 
       <<EQUIPOS[i].PG<<"\t" 
       <<EQUIPOS[i].PE<<"\t" 
       <<EQUIPOS[i].PP<<"\t" 
       <<EQUIPOS[i].generales.GFtotal<<"\t" 
       <<EQUIPOS[i].generales.GCtotal<<"\t" 
       <<EQUIPOS[i].generales.DGtotal<<"\t" 
       <<EQUIPOS[i].generales.Pts <<"\t" 
       <<setprecision(3)<<EQUIPOS[i].generales.rend<<"%"<<endl;
  }
  cout<<endl;
  cout<<"CAMPEON: "<<EQUIPOS[0].nombres_equipos<<" | Puntaje: "<<EQUIPOS[0].generales.Pts<<" | DG: "
  <<EQUIPOS[0].generales.DGtotal<<" | Rendmiento: "<<EQUIPOS[0].generales.rend;
}

int main(){

//Las funciones tipo puntero solo recibe una copia del puntero por eso tenemos que igualar las equipos a cada funcion
equipo*equipos=nullptr;
equipos=M_dinamica(equipos);
equipos=simulaciones(equipos);
equipos=estadisticaSS(equipos);
equipos=PG_PE_PP(equipos);
equipos=NOMBRES_EQUIPOS(equipos);
cout<<endl;
ordenar(equipos);
imprimir(equipos);
liberar_memoria(equipos);
return 0;
}
