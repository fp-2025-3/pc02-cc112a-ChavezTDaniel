#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int n;
    cout<<"Ingrese numero de corredores: ";
    cin>>n;

    char nombres[30][20];
    int  tiempo[30];


    for(int k=0;k<n;k++){
        cout<<"Nombre del corredor "<<k+1<<": ";
        cin>>*(nombres+k);
        cout<<"Tiempo (en segundos): ";
        cin>>*(tiempo+k);
        }
    

 //Usamos burbuja para ordenar de menor a mayor, si son iguales no se cambian
 //Tambien intercambiamos simulteneamente los nombres con strcpy
   for(int k=0;k<n-1;k++){
       for(int l=0;l<n-k-1;l++){
           if(*(tiempo+l)>*(tiempo+l+1)){
               int temp=*(tiempo+l+1);
               *(tiempo+l+1)=*(tiempo+l);
               *(tiempo+l)=temp;
               char TEMP[20];
               strcpy(TEMP,*(nombres+l+1));
               strcpy(*(nombres+l+1),*(nombres+l));
               strcpy(*(nombres+l),TEMP);
           }
       }
   }

cout<<endl;
cout<<"RANKING FINAL"<<endl;
for(int k=0;k<n;k++){
    cout<<k+1<<". "<<*(nombres+k)<<" - "<<*(tiempo+k)<<" segundos"<<endl;
}

//Usamos strcmp para comparar el nombre ingresado con nombres
char nombre[20];
cout<<endl;
cout<<"Ingrese nombre a buscar: ";
cin>>nombre;
int cont=-1;
for(char(*k)[20]=nombres;k<nombres+n;k++){
    cont++;
    if(strcmp(nombre,*k)==0){;
        cout<<"Corredor encontrado"<<endl;
        cout<<"Posicion: "<<(k-nombres)+1<<endl;
        cout<<"Tiempo: "<<*(tiempo+cont)<<" segundos";
    }
}


// Desreferenciamos t y lo comparamos con min y max
cout<<endl;
int min,max;
cout<<endl;
cout<<"Ingrese tiempo minimo y maximo: ";
cin>>min>>max;
cout<<"Corredores en el rango: ["<<min<<","<<max<<"]: "<<endl;
for(int k=0;k<n;k++){
    if(*(tiempo+k)>=min && *(tiempo+k)<=max){
        cout<<*(nombres+k)<<" - "<<*(tiempo+k)<<" segundos"<<endl;
    }
}

return 0;
}