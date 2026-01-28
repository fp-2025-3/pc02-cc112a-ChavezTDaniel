#include <iostream>
using namespace std;
int comparar_palabras(const char* a, const char* b);
//swap(v[j], v[j+1]); // EJERCICIO, implementar su propia funcion intercambio

void my_swap(char *v[],int n){
for(int i=0;i<n-1;i++){
  for(int j=0;j<n-i-1;j++){
    if(comparar_palabras(v[j],v[j+1])>0){
     char*temp=v[j];
     v[j]=v[j+1];
     v[j+1]=temp;
     }
    }  
   }
}

int separar_palabras(char* texto, char* palabras[]){
int i=0; //contador de palabras
    char *p=texto;// almacena la direccion del primer caracter en texto
while(*p!='\0'){
    if((p==texto && *p!=' ') || ((*(p-1)==' ') && *p!= ' ')){
         palabras[i]=p;
    i++;
    }
    p++;
}


return i;
}
int longitud_palabra(const char* p){
int longitud=0;

while(*p!=('\0') && *p !=' '){
        p++;
        longitud++;
}
return longitud;
}

void clasificar(char* palabras[], int n ,char* cortas[], int& nc,  char* largas[], int& nl){
//recorrer el arreglo el arreglo de punteros palabras
//clasificar segun su longitud
int indlargas=0, indcortas=0;
for(int i=0;i<n;i++){
 int longitud= longitud_palabra(palabras[i]);
    if(longitud <=3){
        cortas[indcortas]=palabras[i];
        indcortas++;
        nc++;
}else{
largas[indlargas]=palabras[i];
indlargas++;
nl++;
}
}
}

int comparar_palabras(const char* a, const char* b){
int i=0;
while(a[i]!=' ' && a[i]!='\0' && b[i]!=' ' && b[i]!='\0'){
if(a[i]!=b[i]){
    return a[i]-b[i];//
}
i++;
}
 if((a[i]== ' ' || a[i]== '\0')&& (b[i]== ' ' || b[i]== '\0')){
    return 0;
 }
 
 if(b[i]== ' ' || b[i]== '\0'){
 return 1;
 }
return -1;
}

void ordenar(char* v[], int n){ //Texto original no tiene que modifiacarse solo trabajar con punteros
for(int i=0;i<n-1;i++){
  for(int j=0;j<n-i-1;j++){
    if(comparar_palabras(v[j],v[j+1])>0){
     my_swap(v,n);
  }

}

}
}
void imprimir_grupo(const char* titulo, char* v[], int n){
    cout<<"Palabras " <<titulo<<endl;
    for(int i=0;i<n;i++){
        char*p=v[i];
        while(*p!='\0' && *p!= ' '){
            cout<<*p;
            p++;
        }
        cout<<endl;
    }
}

int main(){
char texto[300] ="Programar en C++ requiere logica C++ exige disciplina";
char* palabras[60];
char* cortas[60];
char* largas[60];

int n=separar_palabras(texto,palabras);
imprimir_grupo("Original",palabras,n);
cout<<"cadena original texto\n ";
cout<<texto<<endl;

    return 0;
}