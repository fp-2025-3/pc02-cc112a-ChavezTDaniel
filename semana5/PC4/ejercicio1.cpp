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

};

int main(){
    polinomio primer;
    polinomio segundo;
    polinomio tercero;

   primer.n=3;
   segundo.n=2;
   tercero.n=3;

   primer.guardar= new coeficientes[primer.n];
   segundo.guardar=new coeficientes[segundo.n];
   tercero.guardar=new coeficientes[tercero.n];
   
   primer.guardar[0]={1};
   primer.guardar[1]={0};
   primer.guardar[2]={3};

   segundo.guardar[0]={-4};
   segundo.guardar[1]={5};
   
   tercero.guardar[0]={3};
   tercero.guardar[1]={0};
   tercero.guardar[2]={1};
    
   cout<<"Polinomio 1: ";
   int copy=primer.n-1;
    for(int i=0;i<primer.n;i++){
        if(primer.guardar[i].coef!=0 && copy!=0){
        cout<<primer.guardar[i].coef<<"x^"<<copy<<" + ";
        }else if(i==primer.n-1 && primer.guardar[i].coef!=0 && copy==0){
      cout<<primer.guardar[i].coef;
    }
        copy--;
    }
cout<<endl;

    
   cout<<"Polinomio 2: ";
   int copy1=segundo.n-1;
   for(int i=0;i<segundo.n;i++){
    if(segundo.guardar[i].coef!=0 && copy1!=0){
        cout<<segundo.guardar[i].coef<<"x^"<<copy1<<" + ";
    }else if(i==segundo.n-1 && segundo.guardar[i].coef!=0 && copy1==0){
      cout<<segundo.guardar[i].coef;

    }

    copy1--;
   }
cout<<endl;
    int copy2=tercero.n-1;
   cout<<"Polinomio 3: ";
   for(int i=0;i<tercero.n;i++){
   if(tercero.guardar[i].coef!=0 && copy2!=0){
     cout<<tercero.guardar[i].coef<<"x^"<<copy2<<" + ";
   }else if(i==tercero.n -1 && tercero.guardar[i].coef!=0 && copy2==0){
      cout<<tercero.guardar[i].coef;

    }
   copy2--;
   }

   polinomio cuarto;
   cuarto.n=3;
   cuarto.guardar= new coeficientes[cuarto.n];

   cout<<endl;

suma(primer,segundo,tercero,cuarto);

cout<<"Suma de los tres polinomios: "<<endl;
int copy3=cuarto.n-1;
   for(int i=0;i<cuarto.n;i++){
   if(cuarto.guardar[i].coef!=0 && copy2!=0){
     cout<<cuarto.guardar[i].coef<<"x^"<<copy3<<" + ";
   }else if(i==tercero.n -1 && cuarto.guardar[i].coef!=0 && copy3==0){
      cout<<cuarto.guardar[i].coef;

    }
   copy3--;
   }


  delete[]primer.guardar;
  delete[]segundo.guardar;
  delete[]tercero.guardar;
  delete[]cuarto.guardar;

    return 0;
}
