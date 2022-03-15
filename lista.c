#include "lista.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const int ERROR = -1;
const int EXITO =  0;
const size_t PRIMER_ELEMENTO= 0;

lista_t* lista_crear(){
	lista_t* lista_prueba= malloc(sizeof(lista_t));
	if(!lista_prueba) return NULL;
	(*lista_prueba).cantidad=  0;
	(*lista_prueba).nodo_inicio= NULL;
	(*lista_prueba).nodo_fin= NULL;
	return lista_prueba;
}

int lista_insertar(lista_t* lista, void* elemento){
	if(!lista)
		return ERROR;
	nodo_t* nodo_nuevo= malloc (sizeof(nodo_t));
	if(!nodo_nuevo) return ERROR;
	(*nodo_nuevo).elemento= elemento;
    (*nodo_nuevo).siguiente= NULL;
    if(!(*lista).nodo_fin && (*lista).cantidad ==0){
		(*lista).nodo_fin= nodo_nuevo;
		(*lista).nodo_inicio =nodo_nuevo;
    }
    else{
		(*lista).nodo_fin->siguiente= nodo_nuevo;
		(*lista).nodo_fin= nodo_nuevo;
	}
	(*lista).cantidad++;
	return EXITO;
}
// devuelve el nodo  que se encuentra en la posicion buscada
void* lista_nodo_en_posicion(lista_t* lista, size_t posicion){
	if(!lista) return NULL;
	if(posicion >= (*lista).cantidad) return NULL;
	if((*lista).nodo_inicio == NULL) return NULL;
	nodo_t* nodo_actual=(*lista).nodo_inicio;
	int i=0;
	while((*nodo_actual).siguiente != NULL && i < (posicion)){
		nodo_actual= (*nodo_actual).siguiente;			
		i++;
	}
 	return nodo_actual;
}
void* lista_elemento_en_posicion(lista_t* lista, size_t posicion){
	if(!lista) return NULL;
	if((*lista).cantidad ==0) return NULL;
	nodo_t* nodo=lista_nodo_en_posicion(lista, posicion);
	if(nodo == NULL) return NULL;
	else return nodo->elemento;
}


int lista_insertar_en_posicion(lista_t* lista, void* elemento, size_t posicion){
	if(!lista) return ERROR;
	if(!(*lista).nodo_inicio && posicion !=0) return ERROR;
	if(posicion+1 > (*lista).cantidad){
	 	int fallo=lista_insertar(lista, elemento);
	 	if(fallo== EXITO) return EXITO;
		else return ERROR;
 	}
 	else{
 		nodo_t* nodo_actual=lista_nodo_en_posicion(lista, posicion-1);
 		if(!nodo_actual) return ERROR;
 		nodo_t* nodo_nuevo= malloc(sizeof(nodo_t));
 		if(!nodo_nuevo) return ERROR;
 		(*nodo_nuevo).elemento= elemento;
 		(*nodo_nuevo).siguiente= (*nodo_actual).siguiente;
 		(*nodo_actual).siguiente=nodo_nuevo;
 		(*lista).cantidad++;
 		return EXITO;
 	}
}
//Si el nodo que recibe no es nulo, guarda su siguiente, lo libera y vuelve a repetir con el nodo siguiente, hasta que alguno sea nulo.
void destruir_nodos(nodo_t* nodo){
	if(!nodo) return;
	if(nodo !=NULL){
		nodo_t* siguiente= nodo->siguiente;
		free(nodo);
		destruir_nodos(siguiente);
	}
}

void lista_destruir(lista_t* lista){
	destruir_nodos((*lista).nodo_inicio);
	if(lista) free(lista);
} 
int lista_borrar(lista_t* lista){
	if(!lista)return ERROR;
	if((*lista).cantidad ==0) return ERROR;
	if((*lista).cantidad ==1){
		destruir_nodos((*lista).nodo_inicio);
		(*lista).nodo_inicio= NULL;
		(*lista).nodo_fin =NULL;
		(*lista).cantidad=0;
		return EXITO;
	}
	nodo_t* nodo_actual=lista_nodo_en_posicion(lista, (*lista).cantidad-2);
	free((*lista).nodo_fin);
	(*lista).nodo_fin= nodo_actual;
	(*lista).nodo_fin->siguiente=NULL;
	(*lista).cantidad--;
	return EXITO;
}

int lista_borrar_de_posicion(lista_t* lista, size_t posicion){
	if(!lista) return ERROR;
	if(posicion >= (*lista).cantidad || (*lista).cantidad==1){
		int fallo=lista_borrar(lista);
		if(fallo== EXITO) return EXITO;
		else return ERROR;
	}
	if(posicion==0){
		nodo_t* primer_nodo=(*lista).nodo_inicio->siguiente;
		free((*lista).nodo_inicio);
		(*lista).nodo_inicio= primer_nodo;
		(*lista).cantidad--;
		return EXITO;
	}
	nodo_t* nodo_anterior= lista_nodo_en_posicion(lista, posicion-1);
	nodo_t* nodo_a_eliminar= lista_nodo_en_posicion(lista, posicion);
	if(!nodo_anterior || !nodo_a_eliminar) return ERROR;
	(*nodo_anterior).siguiente= (*nodo_a_eliminar).siguiente;
	free(nodo_a_eliminar);
	(*lista).cantidad--;
	return EXITO;
}

bool lista_vacia(lista_t* lista){
	if(!lista) return true;
	if((*lista).nodo_inicio == NULL) return true;
	nodo_t* nodo_actual=(*lista).nodo_inicio;
	int i=0;
	while(nodo_actual == NULL){
		nodo_actual= (*nodo_actual).siguiente;
		i++;			
	}
	if(i== (*lista).cantidad) return true;
	return false;
}
void* lista_ultimo(lista_t* lista){
	if(lista_vacia(lista)) return NULL;
	return (*lista).nodo_fin->elemento;
}

size_t lista_elementos(lista_t* lista){
	if(!lista) return 0;
	return (*lista).cantidad;
}

int lista_apilar(lista_t* lista, void* elemento){
	return lista_insertar(lista, elemento);
}

int lista_desapilar(lista_t* lista){
	return lista_borrar(lista);
}

void* lista_tope(lista_t* lista){
	return lista_ultimo(lista);
}

int lista_encolar(lista_t* lista, void* elemento){
	return lista_insertar(lista, elemento);
}
int lista_desencolar(lista_t* lista){
	return lista_borrar_de_posicion(lista, PRIMER_ELEMENTO);
}

void* lista_primero(lista_t* lista){
	return lista_elemento_en_posicion(lista, PRIMER_ELEMENTO);
}

void* lista_iterador_elemento_actual(lista_iterador_t* iterador){
	if(!iterador) return NULL;
	return (*iterador).corriente->elemento;
}

lista_iterador_t* lista_iterador_crear(lista_t* lista){
	if(!lista) return NULL;
	lista_iterador_t* iterador= malloc(sizeof(lista_iterador_t));
	if(!iterador) return NULL;
	(*iterador).lista = lista;
	(*iterador).corriente =(*lista).nodo_inicio;
	(*iterador).corriente->elemento=lista_iterador_elemento_actual(iterador);
	return iterador;
}

bool lista_iterador_tiene_siguiente(lista_iterador_t* iterador){
	if(!iterador) return false;
	if(!(*iterador).corriente) return false;
	return true;
}

bool lista_iterador_avanzar(lista_iterador_t* iterador){
	if(!iterador) return false;
	if(lista_iterador_tiene_siguiente(iterador) && (*iterador).corriente->siguiente != NULL){
		(*iterador).corriente= (*iterador).corriente->siguiente;
		return true;
	}
	return false;
}

void lista_iterador_destruir(lista_iterador_t* iterador){
	free(iterador);
}

size_t lista_con_cada_elemento(lista_t* lista, bool (*funcion)(void*, void*), void *contexto){
	if(!lista || !funcion) return 0;
	nodo_t* nodo_actual= (*lista).nodo_inicio;
	size_t contador_nodos=0;
	while(nodo_actual!= NULL && funcion( nodo_actual->elemento, contexto) && contador_nodos <= (*lista).cantidad){
		nodo_actual= nodo_actual->siguiente;
		contador_nodos++;
	}
	return contador_nodos;
}
