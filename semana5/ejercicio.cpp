#include <iostream>
using namespace std;
struct estudiantes{
  int codigo;
  float promedio;
};


int main(){
int N;
cout<<"Ingrese la cantidad de estudiantes: ";
cin>>N;
 estudiantes*ptr=new estudiantes[N];
 
for(int i=0;i<N;i++){
   cout<<"Alumno: "<<i+1<<endl;
   cout<<"Codigo: ";cin>>(*(ptr+i)).codigo;
   cout<<"Promedio : ";cin>>(*(ptr+i)).promedio;
}
 
for(int i=0;i<N;i++){
 if((*(ptr+i)).promedio>=10){
   cout<<"Alumnos aprobados: "<<endl;
   cout<<"Codigo: ";cout<<(*(ptr+i)).codigo<<endl;
   cout<<"Promedio: ";cout<<(*(ptr+i)).promedio;
}
}

 cout<<endl;

delete [] ptr;

    return 0;
}


