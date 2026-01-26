#include <iostream>
using namespace std;

int sumadelimitada(int(*inicio)[5],int x1,int y1,int x2,int y2){ //(int (*inicio)[5], es un puntero que apunta a las filas enteras

  int*comienzo=*(inicio+x1)+y1; //Accede al primer elemento que queremos sumar
  int*final =*(inicio+x2)+y2;   //Accede al ultimo elemento que queremos sumar
  int sumatotal=0;
for(int*p=comienzo;p<=final;p++){ 
 sumatotal+=*p;
}
return sumatotal;
}


void sumaycoordenadas(int(*inicio)[5],int(*fin)[5]){
    int actual=0;
    int sumamax=(*inicio)[0];
    int x=0;
    int y=0;
    for(int(*filas)[5]=inicio;filas<fin;filas++){
 for(int*col=*filas;col<*filas+5;col++){
  actual+=*col;
 if(actual>sumamax){
    sumamax=actual;
      x=filas-inicio; //En c++ la diferencia de dos direcciones nos da la posicion 
      y=col-(*filas);  //De igual forma col y *filas son direcciones que al restarse dan coordenadas
}
}
 }
    cout<<"Coordenadas: ("<<x<<","<<y<<")"<<endl;
    cout<<"Suma maxima: "<<sumamax<<endl;

   }

void imprimir(int(*inicio)[5],int(*fin)[5]){
for(int(*filas)[5]=inicio;filas<fin;filas++){
 for(int*col=*filas;col<*filas+4;col++){
 cout<<*col<<" ";
 }
cout<<endl;
}
}

int main(){
  
   int matriz[4][5]={{-2,1,-3,4,-1},{2,3,-2,1,-5},{-1,4,2,-3,2},{1,-2,3,4,-1}};
  int(*inicio)[5]=matriz;
  int(*final)[5]=matriz+4;

imprimir(inicio,final);
cout<<"Submatriz de suma maxima: "<<endl;
sumaycoordenadas(inicio,final);
cout<<endl;

  int i1,j1,i2,j2;
  cout<<"Ingrese las posiciones (i1,j1) y (i2,j2) dentro de l rango de la matriz: "<<endl;
  cin>>i1>>j1>>i2>>j2;
cout<<"Suma de elementos de la matriz delimitada por las posiciones es: "<<sumadelimitada(inicio,i1,j1,i2,j2)<<endl;
   return 0; 
}