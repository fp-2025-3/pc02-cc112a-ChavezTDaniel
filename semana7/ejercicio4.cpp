#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
struct Venta{
int idVenta;
int idVendedor;
int idProducto;
int cantidad;
double precioUnitario;
};

int main(){


ifstream LeerBinario("ventas.dat",ios::binary);
if(!LeerBinario){
    cerr << "Erro no se puedo abrir el archivo ventas.dat";
    return 1;
}

//Calculamos el tamaño total de bytes del archivo
LeerBinario.seekg(0,ios::end);                        // seekg mueve el ptr de lectura y se mueve cero unidades de bytes respecto del final
long tamanio_total=LeerBinario.tellg();               // tellg nos devuelve el tamaño en bytes hasta ese punto en donde se ecuentra

int cantidad_ventas=tamanio_total/sizeof(Venta);      // Dividimos el total de bytes entre la cantidad de bytes de Venta lo que nos dara el numero de n ventas

//Regresamo el ptr al inicio para leer desde el principio
LeerBinario.seekg(0,ios::beg);

int n=cantidad_ventas;
Venta*ventas=new Venta[n];

LeerBinario.read((char*)ventas,sizeof(Venta)*n); // Aqui ya le paso los datos a ventas
//Ahora procedemos a completar el ejercicio y a guardarlo en un archivo .txt

LeerBinario.close();



//Hallamos monto total, ID del vendedor con mayor recaudacion y el total vendido.
double monto_total_vendido=0;
double venta_mayor=0;
for(int i=0;i<n;i++){
    monto_total_vendido+=ventas[i].cantidad*ventas[i].precioUnitario;

   if(ventas[i].cantidad*ventas[i].precioUnitario>venta_mayor){
    venta_mayor=ventas[i].cantidad*ventas[i].precioUnitario;
   }

}
int idMayor_vendedor=0;
for(int i=0;i<n;i++){
    if(ventas[i].cantidad*ventas[i].precioUnitario==venta_mayor){
        idMayor_vendedor=ventas[i].idVendedor;
    }
}


// Guardamos los datos: ID producto mas vendido y cantidad de producto mas vendido
int cantidadMasVendido=0;
int idmasVendido;
for(int i=0;i<n;i++){
if(ventas[i].cantidad>cantidadMasVendido){
    cantidadMasVendido=ventas[i].cantidad;
}
}
for(int i=0;i<n;i++){
    if(ventas[i].cantidad==cantidadMasVendido){
    idmasVendido=ventas[i].idProducto;
    }
}


//Creamos el archivo reporte.txt con ofstream
ofstream archivo("reporte.txt",ios::out);

if(!archivo){
    cerr <<"Error al crear el archivo.txt";
    return 1; 
}
archivo<<fixed<<setprecision(3);
archivo<<"---REPORTE GENERAL DE VENTAS---"<<endl<<endl;
archivo<<"Total de registros: "<<n<<endl<<endl;
archivo<<"MONTO TOTAL VENDIDO: "<<endl;
archivo<<"S/."<<monto_total_vendido<<endl<<endl<<endl;
archivo<<"---------------------"<<endl;
archivo<<"VENDEDOR CON MAYOR RECAUDACION: "<<endl;
archivo<<"ID Vendedor: "<<idMayor_vendedor<<endl;
archivo<<"Total vendido: S/."<<venta_mayor<<endl<<endl<<endl;
archivo<<"---------------------"<<endl;
archivo<<"PRODUCTO MAS VENDIDO: "<<endl;
archivo<<"Id producto: "<<idmasVendido<<endl;
archivo<<"Total unidades: "<<cantidadMasVendido<<endl<<endl<<endl;
archivo<<"VENTAS SOSPECHOSAS (cantidad>100): "<<endl<<endl;
for(int i=0;i<n;i++){
    if(ventas[i].cantidad>100){
    archivo<<"ID Venta:"<<ventas[i].idVenta<<"|Vendedor:"<<
    ventas[i].idVendedor<<"|Producto:"<<ventas[i].idProducto<<"|Cantidad:"<<
    ventas[i].cantidad<<endl;
    }
}

archivo.close();
cout<<"Se registraron los datos exitosamente en reporte.txt";
delete[]ventas;

    return 0;
}
