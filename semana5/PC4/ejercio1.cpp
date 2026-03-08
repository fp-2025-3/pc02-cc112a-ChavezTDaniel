#include <iostream>
using namespace std;
struct coeficientes{
   int coef;
   
};
struct polinomio{
 coeficientes*guardar;
 int n;
};


void suma(polinomio primer,polinomio segundo,polinomio tercero,polinomio&cuarto){

for(int i=0;i<cuarto.n;i++){
cuarto.guardar[i].coef=primer.guardar[i].coef+segundo.guardar[i].coef+tercero.guardar[i].coef;
}

}

polinomio multiplicacion(polinomio primer, polinomio segundo,polinomio tercero){
 
  int tamaño_max=0;
  int copia1=primer.n-1; int copia2=segundo.n-1;int copia3=tercero.n-1;
 //Hallamos el tamaño maximo del arreglo que depende del exponente maximo que se obtendra a la hora de la multplicaion
  for(int i=0;i<3;i++){
   if(primer.guardar[i].coef==0){
    copia1--;
   }else{
    break;
   }
  }
  for(int i=0;i<3;i++){
   if(segundo.guardar[i].coef==0){
    copia2--;
   }else{
    break;
   }
  }
  for(int i=0;i<3;i++){
   if(tercero.guardar[i].coef==0){
    copia3--;
   }else{
    break;
   }
  }

 tamaño_max=copia1+copia2+copia3;

 //Sumamos uno a tamaño maximo para almacenar sin problemas x^0
polinomio quinto;
quinto.n=tamaño_max+1;
quinto.guardar=new coeficientes[quinto.n]();


for(int i=0;i<3;i++){
  for(int j=0;j<3;j++){
     for(int z=0;z<3;z++){
            //Calculamos todas las multiplicaciones posibles de los polinomios
           int coeficiente=(primer.guardar[i].coef)*(segundo.guardar[j].coef)*(tercero.guardar[z].coef);
            //Nos da el expoente de cada coeficiente, teniendo cuenta que van de mayor a menor
            int exponente_final=(2-i)+(2-j)+(2-z);

            int posicion_actual=tamaño_max-exponente_final;
               //exponente_final podria ser incluso mayor que tamaño_max
               //En ese caso condicionamos que posicion_actual debe estar dentro del arreglo
            if(posicion_actual>=0 && posicion_actual<quinto.n){
                //Entonces los valores se sumaran en su respectiva posicion
                quinto.guardar[posicion_actual].coef+=coeficiente;
          }
       }

     }
}

   return quinto;

  }

void imprimir_polinomio(polinomio p){
   int exp=p.n-1;

  //Utilizamos condicionales para imprimir de forma ordenada los polinomios
   for(int i=0;i<p.n;i++){
   if(p.guardar[i].coef==0){
    continue;
   }else if(i==0){
    cout<<p.guardar[i].coef<<"x^"<<exp;
   }else if(i>0 && i<p.n-1 && p.guardar[i].coef<0){
    cout<<" "<<p.guardar[i].coef<<"x^"<<exp;
   }else if(i>0 && i<p.n-1 && p.guardar[i].coef>0){
    cout<<" +"<<p.guardar[i].coef<<"x^"<<exp;
   }else if(i==p.n-1 && p.guardar[i].coef>0){
   cout<<" +"<<p.guardar[i].coef;
   }else if(i==p.n-1 && p.guardar[i].coef<0 ){
    cout<<" "<<p.guardar[i].coef;
   }
   exp--;
   }
cout<<endl;
}

int main(){
    polinomio primer;
    polinomio segundo;
    polinomio tercero;

   primer.n=3;
   segundo.n=3;
   tercero.n=3;

   //Inicializamos los arreglos dinamicos en una sola linea
   primer.guardar= new coeficientes[primer.n]{1,0,3};
   segundo.guardar=new coeficientes[segundo.n]{0,-4,5};
   tercero.guardar=new coeficientes[tercero.n]{3,0,1};
   
  
   cout<<"Polinomio 1: ";
   imprimir_polinomio(primer);

   cout<<"Polinomio 2: ";
   imprimir_polinomio(segundo);

   cout<<"Polinomio 3: ";
   imprimir_polinomio(tercero);

   polinomio cuarto;
   cuarto.n=3;
   cuarto.guardar= new coeficientes[cuarto.n];
  //La funcion void suma modifica a "cuarto" debido a que le pasamos su direccion
  suma(primer,segundo,tercero,cuarto); 

  cout<<"Suma de los tres polinomios: ";
  imprimir_polinomio(cuarto);

  polinomio final;
  final=multiplicacion(primer,segundo,tercero);

  cout<<"Producto de los tres polinomios: ";
  imprimir_polinomio(final);
   
  //Liberamos todas las memorias dinamicas creadas
  delete[]primer.guardar;
  delete[]segundo.guardar;
  delete[]tercero.guardar;
  delete[]cuarto.guardar;
  delete[]final.guardar;

    return 0;
}
