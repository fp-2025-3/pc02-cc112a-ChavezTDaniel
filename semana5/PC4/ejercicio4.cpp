#include <iostream>
#include <cstring>
using namespace std;
struct Item{
 char*descripcion;   //Memoria dinamica
 int cantidad;
 double precioUnitario;

};

struct Pedido{
int numeroPedido;                // Memoria dinamico
char*nombreCliente;              // Arreglo dinamico de items
Item*items;
int cantidadItems;

};


 //CrearItems solo copia los parametros a una variable temporal y luego lo retornamos
Item crearItem(const char*descripcion,int cantidad,double precio){
 Item nuevo_item;
 nuevo_item.descripcion=new char[strlen(descripcion)+1];   //strlen(descripcion)+1 calcula el tamaño del arreglo incluyendo a '\0'
 strcpy(nuevo_item.descripcion,descripcion);               //luego strcpy copia el contendio de descripcion en donde corresponde
nuevo_item.cantidad=cantidad;
nuevo_item.precioUnitario=precio;
 
return nuevo_item;
}



Pedido*crearPedido(int numero,const char*cliente,int cantidadItems){
    
Pedido*Unpedido=new Pedido[1];

for(int i=0;i<1;i++){

     Unpedido[i].numeroPedido=numero;
 

    Unpedido[i].nombreCliente=new char[strlen(cliente)+1];
    strcpy(Unpedido[i].nombreCliente,cliente);


    Unpedido[i].items=new Item[cantidadItems];
    Unpedido[i].cantidadItems=cantidadItems;


    for(int j=0;j<cantidadItems;j++){
        //Creamos variables temporales y las inicializamos, luego usamamos las mismas como parametros para llamar a crearItem
    char descrip[20]; 
    int cant;
    double precio_unitario;
    cin.ignore();
    
    cout<<"Ingrese nombre del producto "<<j+1<<": ";cin.get(descrip,20); //si hay problemas en la salida podemos usar cin.ignore();
    cout<<"Ingrese cantidad del producto: ";cin>>cant;
    cout<<"Ingrese precio Unitario del producto: ";cin>>precio_unitario;
    
    Unpedido[i].items[j]=crearItem(descrip,cant,precio_unitario);

    }


    }
    //Retornamos la direccion de Unpedido
 return Unpedido;
}


double calcularTotal(const Pedido*p){
    double PRECIO_TOTAL=0;
    //Es comodo usar -> debido a que p es un direccion y -> ayuda a desreferenciar el contenido
for(int i=0;i<p->cantidadItems;i++){
 PRECIO_TOTAL+=(p->items[i].cantidad)*(p->items[i].precioUnitario);

}
return PRECIO_TOTAL;
}


Item*itemMasCaro(Pedido*p){
   
 for(int i=0;i<p->cantidadItems-1;i++){
    for(int j=0;j<p->cantidadItems-i-1;j++){
     if(p->items[j].precioUnitario>p->items[j+1].precioUnitario){
        //Es mucho mas sencillo que intercambiar los variables internas como descripcion por ejemplo.
        //Des esta manera todos los elementos intercambian sus posicion de acuerdo a la condicion if
        swap(p->items[j],p->items[j+1]);
     }
    }
 }
 //Retornamos el ultimo elemento debido a que el ordenamiento burbuja los ordeno de menor a mayor
return &(p->items[p->cantidadItems-1]);
}


//Similar ala ejercicio3 liberamos la memoria de adentro hacia afuera
void liberarPedido(Pedido*p){

for(int i=0;i<p->cantidadItems;i++){
delete[] p->items[i].descripcion;
}

for(int i=0;i<1;i++){
delete [] p[i].items;
delete [] p[i].nombreCliente;
}


    delete [] p;

}

//Como p es una direccion usar -> nos facilita al momento de desreferenciar
void imprimir_pedido(Pedido*p){
cout<<"Pedido N:  "<<p->numeroPedido<<endl;
cout<<"Cliente:  "<<p->nombreCliente<<endl;

cout<<"Items:  "<<endl;
for(int i=0;i<p->cantidadItems;i++){
cout<<"-  "<<p->items[i].descripcion<<"  |  "<<"Cant:  |  "<<p->items[i].cantidad<<"  Precio:  |  "<<p->items[i].precioUnitario<<endl;
}
 cout<<endl;
 double Total=calcularTotal(p);
 cout<<"Total:  "<<Total;
 cout<<endl;
 cout<<"Item mas caro:  "<<(itemMasCaro(p))->descripcion<<"  |  Precio: "<<(itemMasCaro(p))->precioUnitario;

}

int main(){
 
Pedido*PEDIDO;

int numero_pedido;
cout<<"Ingrese numero de pedido: ";cin>>numero_pedido;
cin.ignore();
char DESCRIPCION[20];
cout<<"Ingrese nombre del usuario: ";
cin.get(DESCRIPCION,20);

int cant_items;
cout<<"Ingrese cantidad de items: ";cin>>cant_items;

PEDIDO=crearPedido(numero_pedido,DESCRIPCION,cant_items);
cout<<endl;
imprimir_pedido(PEDIDO);
liberarPedido(PEDIDO);

    return 0;
}
