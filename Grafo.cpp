#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

//variables globales
int opc;
int volver;
int valor;

//funciones


//declarar nodo que tendra el numero entero y dos punteros
struct nodo{
	int numero;//nombre del vertice o nodo
	struct nodo *sgte;
	struct arista *ady;//puntero hacia la primera arista del nodo
	
	
};
//instanciamos++
// el nodo y creamos una variable punteros
typedef struct nodo *Tnodo;
Tnodo puntero;//puntero cabeza

//declaramos arsita que tiene el nodo destino y la arista siguiente 
struct arista {
	struct nodo *destino;
	struct arista *sgte;
	
};
// insertar arista 
typedef struct arista *Tarista;

//metodo para capturar e insertar un nuevo nodo al grafo
void insertar_nodo (){
	//instancia el nodo y declara un nuveo puntero
	Tnodo t,nuevo=new struct nodo;
	cout<<"ingrese un numero para el nodo: "<<endl;
	//captura el nuevo nodo
	cin>>nuevo->numero;
	nuevo->sgte=NULL;
	nuevo->ady=NULL;
	//si el puntero esta vacio lo crea
	if(puntero==NULL){
		puntero=nuevo;
		cout<<"Nodo ingresado."<<endl;
	}else{
		//si no debe recorrer este puntero para preguntar
		//por la variable siguiente que este vacia 
		t=puntero;
		while (t->sgte!=NULL){
		    t = t->sgte;
		}
		t->sgte=nuevo;
		cout<<"Nodo ingresado."<<endl;    
	}	
}
//metodo para agregar aristas
void agregar_arista (Tnodo &aux, Tnodo &aux2, Tarista &nuevo){
	//con el puntero de la arista inicializamos otro puntero
	Tarista q;
	//preguntamos si esta vacia para ingresar la nueva arista
	if (aux->ady==NULL){
		aux->ady=nuevo;
		nuevo->destino=aux2;
	}else{
		//de lo contrario debemos recorrerlo por que ya hay arista en esa posicion
		q=aux->ady;
		//recorremos la arista 
		while (q->sgte!=NULL){
			q=q->sgte;
		}
		//cuando encontramos la libre ahi si ingresamos la arista
		nuevo->destino=aux2,
		q->sgte=nuevo;
		cout<<"Arista ingresado"<<endl;	
	}
	
}

//metodo para insertar la arista
void insertar_arista(){
	//declaramos variable para capturar el nodo final el inicial
	int ini,fin;
	//se instancia una arista 
	Tarista nuevo=new struct arista;
	// se instacia dos nodos
	Tnodo aux, aux2;
	//si el puntero esta vacio es por que no se ha definido 
	//ningun nodo
	if (puntero==NULL){
		cout<<"No hay grafo"<<endl;
		return;
	}
	//de lo contrario instancia el nodo siguiente null
	nuevo->sgte=NULL;
	//con estas dos variables captura el nodo inicial y el final
	cout<<"Ingrese el nodo del inicio: "<<endl;
	cin>>ini;
	cout<<"Ingrese el nodo del final: "<<endl;
	cin>>fin;
	//a las dos variables auxiliares le llevamos el puntero
	aux=puntero;
	aux2=puntero;
	//verificamos si el auxiliar dos tiene algo
	while (aux2!=NULL){
		//veremos si ese algo es el puntero final
		if (aux2->numero==fin){
			//si, si lo es entonces se sale
			break;
		}
		//de lo contrario le llevamos el valor de sgte
		aux2=aux2->sgte;
	}
	//aqui ingresamos la arista al primer puntero
	while (aux!=NULL){
		//si la variable auxiliar es igual a la arista del puntero 1
		if (aux->numero==ini){
			//agrefa la arista
			agregar_arista(aux,aux2,nuevo);
			return;
		}
		//de lo contrario va con el siguiente
		aux=aux->sgte;
	}	
}
//muestra la matriz 
void mostrar_grafo() {
	//se instancia el puntero del nodo y el puntero de la arista
	Tnodo ptr;
	Tarista ar;
	//al puntero del nodo lo llevamos al que tenemos inicialmente
	ptr=puntero;
	cout<<"Nodo:Arista"<<endl;
	//si esta vacia
	while (ptr!=NULL){
		//mustra el dato puntero
		cout<<"  "<<ptr->numero<<"|";
		if(ptr->ady!=NULL){
			ar=ptr->ady;
		//despues mustra todas las aristas que tiene ese puntero
			while(ar!=NULL){
				cout<<"  "<<ar->destino->numero;
				ar=ar->sgte;
			}
		}
		//despues pasa el siguiente puntero y repite el proces a ver si tiene arsitas
		ptr=ptr->sgte;
		cout<<endl;
	}	 
}

//esta funcion mustra las aristas de un nodo en especifico
void mostrar_aristas(){
	//inicializamos nodo y arista
	Tnodo aux;
	Tarista ar;
	int var;
	cout <<"Mostrar arista del nodo"<<endl;
	cout<<"Ingrese el nodo"<<endl;
	cin>>var;
	//captura el puntero y comienza el ciclo
	aux=puntero;
	while(aux!=NULL){
		//preguntamos si es un puntero ya definido
		if (aux->numero==var){
			if(aux->ady==NULL){
			cout<<"El nodo no tiene Aristas"<<endl;
			return;
		    }else{
			
		     	//si el puntero tiene arista la imprime 
			    cout<<"Nodo:Arista"<<endl;
			    cout<<"  "<<aux->numero<<"|";
		    	ar=aux->ady;
			    //posteriormente lo lleva a la siguiente posicion para mostrar todas las aristas que tiene este nodo; cuando culmine se saldra
			    while(ar!=NULL){
			 	    cout<<ar->destino->numero<<" ";
			 	    ar=ar->sgte;
			    }
			    cout<<endl;
			    return; 
		    }
	    }else{
		   aux=aux->sgte;
        }
	}
}		
	

//MENU DE OPCIONES
int crear_menu(){
	cout<<"ESTRUCTURA DE DATO NO LINEAL: GRAFO"<<endl;
	cout<<"Digite el numero de la opcion que desea realizar"<<endl;
	cout<<"1. Insertar nodo"<<endl;
	cout<<"2. Insertar Arista"<<endl;
	cout<<"3. Mostrar Grafo"<<endl;
	cout<<"4. M0star Arista de la posicion deseada"<<endl;
	cout<<"5. Salir"<<endl;
} 

int main(){
	//incialicemos el puntero primcipal en NULL
	puntero=NULL;
	
	//ciclo para ejecutar acciones del menu
	volver= 1;
	while(volver==1){
		//se inicializa el menu
		 crear_menu();
		 cin>>opc;
		
		switch(opc){
		case 1:
				//insertar nodo en el grafo
		    	insertar_nodo();
				break;
		case 2:
			    //insertar arista en el grafo
				insertar_arista();
				break;
		case 3:
			    //mostar grafo
				mostrar_grafo();
				break;
		case 4:
			    //mostrar un nodo y sus aristas adyacentes
				mostrar_aristas();
				break;
		case 5:
			    //salir del programa
			   cout<<"salir"<<endl;
			   return 0;
			   break;
				
		default:
		   cout<<"opcion invalida"<<endl;		
		}
		cout<<"para volver al menu principal, presione el numero 1\n";
		cin>>volver;
	}
return 0;
}


