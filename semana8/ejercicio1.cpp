#include <iostream>
using namespace std;



int **crearMatriz(int n, int m);     // devolera un doble puntero, que puedde ser un aarreglo de puntero
void llenarMatriz(int**M,int n,int m);
int * sumarFilas(int **M,int n,int m);
void liberarMatriz(int **M,int n);

int main(){

//1. CREAMOS MATRIZ  
int filas,columnas;
cout<<"---CREAR MATRIZ---"<<endl;
cout<<"Ingrese las dimensiones de la matriz donde n es fila y m columna."<<endl;
cout<<"n = ";cin>>filas;
cout<<"m = ";cin>>columnas;
int**nueva_matriz=crearMatriz(filas,columnas); //crearFilas devuelve un puntero doble
 //                                            //entonces debo crear un puntero doble?

//2. LLENAR VALORES DE MATRIZ

llenarMatriz(nueva_matriz,filas,columnas);

//3. SUMAR FILAS 

// Creamos el puntero que resivira los datos
int *sumafilas;  
sumafilas=sumarFilas(nueva_matriz,filas,columnas);

cout<<"Resultado de filas de la matriz orginal: "<<endl;
for(int i=0;i<filas;i++){
    cout<<sumafilas[i]<<" ";
}

//4. LIBERAMOS MEMORIA
delete [] sumafilas;
liberarMatriz(nueva_matriz,filas);

    return 0;
}
int **crearMatriz(int n, int m){
    int**matriz=new int*[n];  //Reservamos memoria dinamica para un arreglo de punteros
    //Ahora accedemos a cada puntero para asignarle memoria dinamica
    for(int j=0;j<n;j++){     
        matriz[j]=new int[m]; //Iteramos los punteros del arreglo de punteros para asignarles memoria dinamica
    }

    return matriz;            //matriz es un puntero doble? Por eso lo retornamos;
}

void llenarMatriz(int**M,int n,int m){
for(int i=0;i<n;i++){
   for(int j=0;j<m;j++){
      M[i][j]=(i+1)*(j+1);
   }
}
}

int * sumarFilas(int **M,int n,int m){
    
int *sumarFILAS=new int[n];

for(int i=0;i<n;i++){
    int sumafilas=0;
    for(int j=0;j<m;j++){
        sumafilas+=M[i][j];
    }
  sumarFILAS[i]=sumafilas;
 
}

return sumarFILAS;
}
void liberarMatriz(int **M,int n){
for(int i=0;i<n;i++){
    delete[] M[i];      //M[i] es una matriz de i filas donde cada una se tiene que liberar
}
delete[]M;              // liberamos la matriz externa

}
