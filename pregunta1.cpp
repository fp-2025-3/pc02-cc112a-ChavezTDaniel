#include <iostream>
using namespace std;

// Complete la funcion que calcula la derivada de orden k de un polinomio
// Usar EXCLUSIVAMENTE punteros (NO indices)

void derivadaK(
    const double* coef, // es un puntero al primer elemento del arreglo del int main()
    int grado, int k,   // grado puede usarse como el tamaño total total de la matriz, k es el numero de veces que se efectuara la derivacion
    double* res,        // double *res, puede usarse como una matriz para modificar los coef y guardarlos
    int &gradoRes){     // Uso grado res para saber el nuevo tamaño de la matriz
   
    // Escriba su codigo aqui
  while(k!=0){
    double*temporal=res;                        
for(const double *p=coef+1;p<coef+grado+1;p++){  
    int exponente=p-coef;
    *temporal=(*p)*exponente;                   //Obtengo los nuevos coeficientes y como temporal es un puntero se modifican los valores de res
    temporal++;
}
 coef=res;                                      //Importante para que en el siguiente recorrido se trabaje con los nuevos datos
 k--;
 grado--;                                       //Restringe el nuevo recorrido de de p
} 
gradoRes=grado;   
cout<<"La derivada de orden dos es: "<<endl;
for(double*p=res;p<res+gradoRes+1;p++){
    int exp=p-res;                            
        cout<<"+"<<*p<<"x^"<<exp<<"  ";
        
    }

    cout<<endl;
}

// Complete la función auxiliar para imprimir un polinomio
int contador=0;
void imprimirPolinomio(const double* p, int grado) {
   for(const double*filas=p;filas<p+grado+1;filas++){
    cout<<" + "<<*filas<<" "<<"x^"<<contador<<" "<<""<<" ";
    contador++;
   }
   cout<<endl;
 
}


int main() {
    // Polinomio:
    // P(x) = 2 + 3x - x^2 + 4x^3
    double coef[] = {2, 3, -1, 4};
    const double*ptr=coef;

    const int grado = 3;


    double resultado[10]; // espacio suficiente 

    int gradoResultado;

    int k = 2; // derivada de orden 2

    // Llamar a su funcion derivadaK
    derivadaK(coef, grado, k, resultado, gradoResultado);

    // Llamar la funcion imprimir para mostrar el polinomio original y  la derivada
    cout<<"El polinomio original es: "<<endl;
    imprimirPolinomio(ptr,grado);
    

    return 0;
}