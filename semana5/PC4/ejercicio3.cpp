#include <iostream>
#include <cstring>
using namespace std;
struct Producto{
int codigo;
char*nombre;
double precio;
int stock;
};

//Una vez copiada los parametros a Producto, retornamos ese producto.

Producto crearProducto(int codigo,const char*nombre,double precio,int stock){
 
 Producto nuevoProducto;
 
 nuevoProducto.codigo=codigo;
 //Usamos strlen para saber el tamaño de nombre, +1 para incluir el '\0' ya que el stren no lo cuenta
 nuevoProducto.nombre=new char[strlen(nombre)+1];

 strcpy(nuevoProducto.nombre,nombre); 

 nuevoProducto.precio=precio;

 nuevoProducto.stock=stock;

return nuevoProducto;

}


// Creamos variables temporales y le damos valores, para llamar a la funcion crearProducto. Esta nos pasara los productos uno por uno
// y las guardara en cada direccion de memoria del puntero new_Inventario. "Producto*new_inventario se comporta como un arreglo",
// y finalmente retornamos la direccion new_puntero

Producto*crearInventario(int n){
 Producto*new_inventario=new Producto[n];

for(int i=0;i<n;i++){
    cout<<"Ingrese datos del producto "<<i+1<<": "<<endl;
int cod;
char nom[20];
double prec;
int  s_tock;
cout<<"Ingrese codigo: ";cin>>cod;
cin.ignore();
cout<<"Ingrese nombre: ";
cin.get(nom,20);
cout<<"Ingrese precio: ";cin>>prec;
cout<<"Ingrese stock: ";cin>>s_tock;

new_inventario[i]=crearProducto(cod,nom,prec,s_tock);

}
return new_inventario;
}



Producto*buscarProducto(Producto*inventario,int n,int codigoBuscando){
    // Accedemos a los codigos de cada producto, y los comaparamos con codigoBuscando
    for(int i=0;i<n;i++){
      if(codigoBuscando==inventario[i].codigo){
      return &inventario[i];
      }
      
}
//En caso no haya coincidencias saldra del bucle for y devolvera nullptr
return nullptr;

}

//Para liberar memoria comenzamos desde la parte interna
//Liberamos cada espacio creado para los nombres accediendo a ellos mediante un bucle for
void liberarInventario(Producto*inventario,int n){
 for(int i=0;i<n;i++){
    delete[]inventario[i].nombre;
 }
 //Finalmente liberamos la parte exterior 
 delete[]inventario;
}



void imprimir_inventario(Producto*inventario,int n){
    cout<<"         INVENTARIO: "<<endl;
for(int i=0;i<n;i++){
    cout<<"Codigo:  "<<inventario[i].codigo<<" | Nombre:  "<<inventario[i].nombre<<" | Precio:  "<<inventario[i].precio<<" |  Stock:  "<<inventario[i].stock<<endl;
}
}


void imprimir_busqueda(Producto*inventario,int n){
int codigo;
cout<<"Ingrese codigo del producto: ";cin>>codigo;
Producto*copia_inventario=buscarProducto(inventario,n,codigo);
cout<<"Buscando producto con codigo "<<codigo<<"..."<<endl;

//Hacemos un if para el caso donde la funcion buscarProducto alla retornado un nullptr
if(copia_inventario==nullptr){
    cout<<"Error producto de codigo "<<codigo<<" no encontrado. "<<endl;
}else{
cout<<"Producto encontrado: "<<(*copia_inventario).nombre<<" | Precio:  "<<(*copia_inventario).precio<<endl;
}

}


int main(){
int n;
cout<<"Ingrese la cantidad de productos a registrar en el inventario: "<<endl;
cin>>n;
Producto*nuevo_inventario;

nuevo_inventario=crearInventario(n);
cout<<endl;
imprimir_inventario(nuevo_inventario,n);

cout<<endl;
imprimir_busqueda(nuevo_inventario,n);

liberarInventario(nuevo_inventario,n);

    return 0;
}
