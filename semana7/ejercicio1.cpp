#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip> //Para setprecision & fixed
using namespace std;
//Creamos una estructura Estudiantes con los datos necesarios para guardar los datos del archivo notas.txt
struct Estudiante{
  char nombre[50];
  int codigo;
  int nota1,nota2,nota3;
  double promedio;
  char condicion[40];
};


int main(){

//Recolectamos los datos de los estudiantes del archivo .txt
ifstream archivoLectura("notas.txt",ios::in);

if(!archivoLectura){
    cout<<"Error al intentar abrir el archivo. ";
    return 1;
}
Estudiante*estudiantes=new Estudiante[30];
int i=0;
while(archivoLectura>>estudiantes[i].codigo>>estudiantes[i].nombre>>estudiantes[i].nota1>>estudiantes[i].nota2>>estudiantes[i].nota3){
i++;
}
archivoLectura.close();
cout<<"Se leyeron los datos exitosamente. "<<endl;

int total_estudiantes=0;
double promedio_general;
double mayor_promedio=0;
double menor_promedio;
char estudiante_mayor[50];
char estudiante_menor[50];

//De acuerdo a las notas guardamos el promedio y condicion del estudiante en el estruct estudiantes
for(int i=0;i<30;i++){
estudiantes[i].promedio=(estudiantes[i].nota1+estudiantes[i].nota2+estudiantes[i].nota3)/3.0;
if(estudiantes[i].nota1<5 || estudiantes[i].nota2<5 || estudiantes[i].nota3<5){
strcpy(estudiantes[i].condicion,"DESAPROBADO POR REGLA ACADEMICA");
}else if(estudiantes[i].promedio<10){
    strcpy(estudiantes[i].condicion,"DESAPROBADO");
}else if(estudiantes[i].promedio>=10){
    strcpy(estudiantes[i].condicion,"APROBADO");
}
total_estudiantes++;
}

//Hallamos el promedio general de la clase
double suma_total_notas=0; //promedio con decimales
for(int i=0;i<30;i++){
suma_total_notas+=estudiantes[i].promedio;
}
promedio_general=suma_total_notas/total_estudiantes;

//Hallamos el mayor promedio;
for(int i=0;i<30;i++){
    if(estudiantes[i].promedio>mayor_promedio){
        mayor_promedio=estudiantes[i].promedio;
    }
}

//Hallamos el menor promedio
menor_promedio=mayor_promedio;
for(int i=0;i<30;i++){
    if(estudiantes[i].promedio<menor_promedio){
     menor_promedio=estudiantes[i].promedio;
    }
}


//Hallamos el nombre de los estudiantes con mayor y menor promedio
for(int i=0;i<30;i++){
    if(estudiantes[i].promedio==mayor_promedio){
        strcpy(estudiante_mayor,estudiantes[i].nombre);
    }
    if(estudiantes[i].promedio==menor_promedio){
        strcpy(estudiante_menor,estudiantes[i].nombre);
    }
}


//Guardamos los datos en reporteAlumnos.txt
ofstream guardarArchivo("reporteAlumnos.txt");
if(!guardarArchivo){
    cout <<"Error al crear archivo reporteAlumnos.txt ";
    return 1;
}

// No se usa en archivos .txt guardarArchivo.write((char*)estudiantes,sizeof(Estudiante)*29);
//fixed nos ayuda a que el numero a que el numero no se escriba en notacion cientifica
guardarArchivo<<fixed<<setprecision(1);  //Para que los los numeros solo tengan un decimal
for(int i=0;i<30;i++){
    guardarArchivo<<estudiantes[i].codigo<<" "<<estudiantes[i].nombre <<" "<<
    estudiantes[i].nota1<<" "<<estudiantes[i].nota2 <<" "<<estudiantes[i].nota3<<"\t| "<<estudiantes[i].promedio<<"\t"<<
    estudiantes[i].condicion<<endl;
}
//Guardamos los datos finales
guardarArchivo<<"Total de estudiantes: "<<total_estudiantes<<endl;
guardarArchivo<<"Promedio general del curso: "<<promedio_general<<endl;
guardarArchivo<<"Estudiante con mayor promedio: "<<estudiante_mayor<<" | "<<mayor_promedio<<endl;
guardarArchivo<<"Estudiante con menor promedio: "<<estudiante_menor<<" | "<<menor_promedio<<endl;


guardarArchivo.close();
cout<<"Se genero el reporte de los alumnos exitosamente. ";
//liberamos memoria
delete[]estudiantes;
return 0;
}
