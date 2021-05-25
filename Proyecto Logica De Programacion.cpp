#include<iostream>
using namespace std;
int const filas=4;
int const columnas=5;
void llenarVector(int n,string vector[]);
void imprimirMatrizBooleana(bool disponibilidad[filas][columnas]);
void limpiarMatrices(bool disponibilidad[filas][columnas],int pesoContenedor [filas][columnas]);
float porcentajeOcupado(bool disponibilidad[filas][columnas]);
int calcularvalorpuertos(string puertoContenedor[filas][columnas],string nombrePuerto);
int conteoContenedores(bool disponibilidad[filas][columnas]);
void reporteEmpresa(string marcaContenedor[filas][columnas],string marcaBuscada);
int promedioPesos(int pesoContenedor[filas][columnas]);
int mayorpesofila(int pesoContenedor[filas][columnas]);
int columnamenospesada (int pesoContenedor[filas][columnas]);
int cantidadarticulo(string tipoContenedor[filas][columnas],string tiposaber);
void imprimirMatrizTexto(string tipoContenedor[filas][columnas]);
int ProbabilidadEnPuerto(string puertoContenedor[filas][columnas],int pesoContenedor[filas][columnas],string puertoPromediopeso);
string marcaConMasPeso(string marcaContenedor[filas][columnas],int pesoContenedor[filas][columnas]);
string marcaConMenosPeso(string marcaContenedor[filas][columnas],int pesoContenedor[filas][columnas]);


int main(){
	

	int puertos=0;
	string marcaconmaspeso;
	string marcamasliviana;
	string tiposaber;
	string puertoPromediopeso;
	int Promedioenpuertopreguntado=0;
	int contadortipo=0;
	int tipoA=0;
	int tipoB=0;
	int tipoC=0;
	int fila=0;
	int columnaM=0;
	int contadorcontenedores=0;
	int x=0;
	string marcaBuscada="";
	int y=0;
	int porcentaje=0;
	string nombrePuerto;
	int promediopeso=0;
	
	//matrices 
	bool disponibilidad[filas][columnas];
	string marcaContenedor[filas][columnas];
	string tipoContenedor[filas][columnas];
	string puertoContenedor[filas][columnas];
	int pesoContenedor[filas][columnas];
	
	limpiarMatrices(disponibilidad,pesoContenedor);
	int n=0;
	
	//puertos 
	cout<<"ingrese la cantidad de puertos"<<endl;
	cin>>n;
	int contadorcontenedoresenpuertos[n];
	string vector[n];
	llenarVector(n,vector);
	
	//llenado matrices
	for(int i=0;i<n;i++){
		cout<<"puerto "<<vector[i]<<endl;
		cout<<"cuantos contenedores va a almacenar en el puerto "<<endl;
		cin>>puertos;
		string nombrePuerto=vector[i];
		int total=0;
		int contador=1;
		while (contador<=puertos){
		imprimirMatrizBooleana(disponibilidad);
		cout<<"ingrese la fila deseada "<<endl;
		cin>>x;
		cout<<"ingrese la columna deseada "<<endl;
		cin>>y;
		if (disponibilidad[x][y]==1){
			disponibilidad[x][y]=0;
			puertoContenedor[x][y]=vector[i];
			cout<<"ingrese el nombre del contenedor "<<endl;
			cin>>marcaContenedor[x][y];
			cout<<"ingrese el peso en kg del contenedor "<<endl;
			cin>>pesoContenedor[x][y];
			cout<<"ingrese el tipo de contenedor Tipo A: Alimentos, Tipo B: Dispositivos electrónicos, Tipo C: Ropa y demás textiles "<<endl;
			cin>>tipoContenedor[x][y];
			cout<<"contenedor registrado "<<endl;
			contador=contador+1;
		
		}
		
	}total=calcularvalorpuertos(puertoContenedor,nombrePuerto);	
	cout<<"el total recuadado en el puerto "<<total<<endl;
	}
	porcentaje=porcentajeOcupado(disponibilidad);
	cout<<"el porcentaje de celdas ocupadas es de "<<porcentaje<<"%"<<endl;
	
	contadorcontenedores=conteoContenedores(disponibilidad);
	cout<<"hay un total de "<<contadorcontenedores<<" contenedores en el barco"<<endl;
	
    cout<<"Ingrese la marca a buscar "<<endl;
    cin>>marcaBuscada;
    cout<<"la informacion de la marca buscada es "<<endl;
    reporteEmpresa(marcaContenedor,marcaBuscada);
    
    
    promediopeso=promedioPesos(pesoContenedor);
    cout<<"el promedio de los contenedores es de "<<promediopeso<<endl;
    
    
    fila=mayorpesofila(pesoContenedor);
    cout<<"la fila con mas peso es "<<fila<<endl;
    
    columnaM=columnamenospesada (pesoContenedor);
    cout<<"la columna con menos peso es "<<columnaM<<endl;
    
    
    cout<<"que tipo de articulo quieres saber la cantidad de existencia "<<endl;
    cin>>tiposaber;
    contadortipo=cantidadarticulo(tipoContenedor,tiposaber);
    cout<<"hay "<<contadortipo<<" articulos de este tipo "<<endl;
    
    cout<<"de que puerto quiere saber el promedio del peso "<<endl;
    cin>>puertoPromediopeso;
    Promedioenpuertopreguntado=ProbabilidadEnPuerto(puertoContenedor,pesoContenedor,puertoPromediopeso);
    cout<<"el promedio del peso del puerto "<<puertoPromediopeso<<" es "<<Promedioenpuertopreguntado<<endl;
    
    
    marcaconmaspeso=marcaConMasPeso( marcaContenedor,pesoContenedor);
    cout<<"la marca con mas peso es "<<marcaconmaspeso<<endl;
    
    marcamasliviana=marcaConMenosPeso(marcaContenedor,pesoContenedor);
    cout<<"la marca mas liviana es "<<marcamasliviana<<endl;
    
    
    
	return 0;
}
//llenado vector
void llenarVector(int n,string vector[]){
	for(int i=0;i<n;i++){
		cout<<"ingrese el nombre"<<endl;
		cin>>vector[i];
	}
}
//matriz disponibilidad 
void imprimirMatrizBooleana(bool disponibilidad[filas][columnas]){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<disponibilidad[i][j]<<"\t";
		}
		cout<<endl;
	}
}
//limpieza de matriz 
void limpiarMatrices(bool disponibilidad[filas][columnas], int pesoContenedor[filas][columnas]){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			disponibilidad[i][j]=1;
			pesoContenedor[i][j]=0;
		}
	}
}
//porcentaje de ocupacion del barco
float porcentajeOcupado(bool disponibilidad[filas][columnas]){
	int ocupado=0;
	float porcentaje=0.0;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
		
		if(disponibilidad[i][j]==0){
			ocupado=ocupado+1;
		}
	}
	}porcentaje=(ocupado*100)/(filas*columnas);
	return porcentaje; 
}
//valor en los puertos 
int calcularvalorpuertos(string puertoContenedor[filas][columnas],string nombrePuerto){
	int total=0;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(puertoContenedor[i][j]==nombrePuerto){
				if (((i=0)||(i=3))&&((j=0)||(j=4))){
				total=100+total;
				}
				else{total=total+300;
				}
			}   
		}
	}return total;
}
//contador de contenedores en el barco
int conteoContenedores(bool disponibilidad[filas][columnas]){
	int contadorcontenedores=0;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(disponibilidad[i][j]==0){
				contadorcontenedores=contadorcontenedores+1;
			}
}
}return contadorcontenedores;
}
//busqueda de empresa
void reporteEmpresa(string marcaContenedor[filas][columnas],string marcaBuscada){
	int contadorE=0;
	int contadorP=0;
	int pagar=0;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(marcaContenedor[i][j]==marcaBuscada){
				if (((i=0)||(i=4))&&((j=0)||(j=4))){
					contadorE=contadorE+1;
					pagar=pagar+100;
				}else{contadorP=contadorP+1;
					pagar=pagar+300;
				}
				
			}
		}
	}cout<<"la marca tiene "<<contadorP<<" contenedores en zona Premiun y "<<contadorE<<" en zona economica, debe pagar en total "<<pagar<<endl;
}
//promedio de todos los pesos
int promedioPesos(int pesoContenedor[filas][columnas]){
	int promedio=0;
	int suma=0;
	int contador=0;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++)
		if(pesoContenedor[i][j]>0){
			contador=contador+1;
			suma=suma+pesoContenedor[i][j];
			
			
		}
	}promedio=suma/contador;
	
	return promedio;
}
//fila con el mayor peso
int mayorpesofila(int pesoContenedor[filas][columnas]){
	int fila=-1;
	int suma=0;
	int mayor=INT_MIN;
	for(int i=0;i<filas;i++){
		suma=0;
		for(int j=0;j<columnas;j++){
			suma=suma+pesoContenedor[i][j];
		}if(suma>mayor){
			fila=i;
			mayor=suma;
		}
		
	
}return fila;
}
//columna mas liviana 
int columnamenospesada (int pesoContenedor[filas][columnas]){
	int menor=INT_MAX;
	int suma=0;
	int columnamenor=-1;
	for(int j=0;j<columnas;j++){
		for(int i=1;i<filas;i++){
			suma=suma+pesoContenedor[i][j];
		}
		if(suma<menor){
			menor=suma;
			columnamenor=j;
			
		}
		suma=0;
	}
	return columnamenor;
}
//cantidad de articulo preguntado
int cantidadarticulo(string tipoContenedor[filas][columnas],string tiposaber){
	int cantidad=0;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(tipoContenedor[i][j]==tiposaber){
				cantidad=cantidad+1;
			}
		}
	}return cantidad;
}
//promedio de peso en puerto preguntado 
int ProbabilidadEnPuerto(string puertoContenedor[filas][columnas],int pesoContenedor[filas][columnas],string puertoPromediopeso){
	int contador=0;
	int suma=0;
	int Promedioenpuerto=0;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(puertoContenedor[i][j]==puertoPromediopeso){
				suma=suma+pesoContenedor[i][j];
				contador=contador+1;
			}
		}
	}Promedioenpuerto=suma/contador;
		return Promedioenpuerto;
}
//marca que tiene contenedor mas pesado
string marcaConMasPeso(string marcaContenedor[filas][columnas],int pesoContenedor[filas][columnas]){
	int mayor=INT_MIN;
	string marcamaspesada="";
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(pesoContenedor[i][j]>mayor){
				mayor=pesoContenedor[i][j];
				marcamaspesada=marcaContenedor[i][j];
			}
			
		}
	} return marcamaspesada;
		
	
}
//marca que tiene contenedor mas liviano
string marcaConMenosPeso(string marcaContenedor[filas][columnas],int pesoContenedor[filas][columnas]){
	int menor=INT_MAX;
	string marcamasliviana="";
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(pesoContenedor[i][j]<menor){
				menor=pesoContenedor[i][j];
				marcamasliviana=marcaContenedor[i][j];
			}
			
		}
	} return marcamasliviana;
		
	
}










