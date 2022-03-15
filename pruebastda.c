// pruebas tda
#include "lista.h"
#include "pa2mm.h"
#include <stdio.h>

#define EXITO 0
#define ERROR -1

void pruebas_crear_lista(){
	lista_t* lista_prueba = NULL;
	pa2m_afirmar((lista_prueba=lista_crear()) != NULL, "Puedo crear una lista");
    pa2m_afirmar((*lista_prueba).cantidad == 0, "Se crea una lista vacia");
    pa2m_afirmar((*lista_prueba).nodo_inicio == NULL, "Puntero a inicio apunta a null");
    pa2m_afirmar((*lista_prueba).nodo_fin == NULL, "Puntero a fin apunta a null");
    lista_destruir(lista_prueba);
}
void pruebas_insertar_lista(){
	lista_t* prueba = NULL;
	int numero_prueba = 7;
	int numero_prueba_2= 2;
	pa2m_afirmar((lista_insertar(prueba, &numero_prueba)) == ERROR, "Error al insertar en lista nula");
	lista_t* lista_no_nula= lista_crear();
	if(lista_no_nula != NULL){
    	pa2m_afirmar(lista_insertar(lista_no_nula, &numero_prueba)== EXITO, "Pudo insertar numero valido al final de la lista");
    	pa2m_afirmar((*lista_no_nula).cantidad ==1, "aumento la cantidad correcta ->1");
    	pa2m_afirmar((*lista_no_nula).nodo_fin->elemento == &numero_prueba, "el numero insertado es valido");
	    pa2m_afirmar(lista_insertar(lista_no_nula, &numero_prueba_2)== EXITO, "Pudo insertar 2 numeros validos al final de la lista");
	    pa2m_afirmar((*lista_no_nula).cantidad ==2,"aumento la cantidad correcta ->2");
	    pa2m_afirmar((*lista_no_nula).nodo_fin->elemento == &numero_prueba_2, "el numero insertado es correcto");
	}
    lista_destruir(lista_no_nula);
}
void pruebas_lista_insertar_posicion(){
	size_t posicion_dos=2;
	size_t primera_posicion =0;
	size_t tercera_posicion= 3;
	int numero_prueba= 7;
	int numero_prueba_2 = 70;
	lista_t* lista_nula = NULL;
	pa2m_afirmar(lista_insertar_en_posicion(lista_nula,&numero_prueba, primera_posicion) == ERROR, "Debe fallar con lista nula");
    lista_t* lista_no_nula= lista_crear();
	if(lista_no_nula != NULL){
    	pa2m_afirmar(lista_insertar_en_posicion(lista_no_nula,&numero_prueba, posicion_dos) == ERROR, "Debe fallar si la posicion es mayor que la cantidad");
    	pa2m_afirmar(lista_insertar_en_posicion(lista_no_nula,&numero_prueba_2, primera_posicion) == EXITO, "Debe insertar el primer elemento si la lista tiene 0 y la posicion es 0");
    	pa2m_afirmar((*lista_no_nula).nodo_inicio->elemento == &numero_prueba_2, "el numero insertado el inicio es correcto");
    	pa2m_afirmar((*lista_no_nula).cantidad ==1 ,"aumento la cantidad correcta ->1");
    	pa2m_afirmar(lista_insertar_en_posicion(lista_no_nula,&numero_prueba, tercera_posicion) == EXITO, "Debe insertar el ultimo elemento si la posicion es mayor que la cantidad");
    	pa2m_afirmar((*lista_no_nula).nodo_fin->elemento == &numero_prueba, "el numero insertado al final es correcto");
    	pa2m_afirmar((*lista_no_nula).cantidad ==2 ,"aumento la cantidad correcta ->2");
    }
    lista_destruir(lista_no_nula);
}
void pruebas_lista_elemento_en_posicion(){
	lista_t* lista_nula= NULL;
	size_t posicion_dos=2;
	size_t posicion_uno=1;
	size_t primera_posicion =0;
	int numero_prueba= 7;
	int numero_prueba_2 = 70;
	pa2m_afirmar(lista_elemento_en_posicion(lista_nula, posicion_dos)== NULL, "Da error si la lista esta vacia");
	lista_t* lista_no_nula= lista_crear();
	if(lista_no_nula != NULL){
		pa2m_afirmar(lista_elemento_en_posicion(lista_no_nula, posicion_dos)== NULL, "No hay elemento en la segunda posicion si la lista esta vacia");
		if(lista_insertar(lista_no_nula, &numero_prueba)== EXITO && lista_insertar(lista_no_nula, &numero_prueba_2) == EXITO){
			pa2m_afirmar( lista_elemento_en_posicion(lista_no_nula, primera_posicion)==&numero_prueba, "El primer elemento buscado es correcto");
			pa2m_afirmar( lista_elemento_en_posicion(lista_no_nula, posicion_uno)==&numero_prueba_2 , "El segundo elemento buscado es correcto");
			lista_borrar(lista_no_nula);
			lista_borrar(lista_no_nula);
			pa2m_afirmar( lista_elemento_en_posicion(lista_no_nula, posicion_uno)== NULL, "Si la cantidad es 0 devuelve null");
		}
	}
	lista_destruir(lista_no_nula);
}
void pruebas_lista_borrar(){
	lista_t* lista_nula= NULL;
	pa2m_afirmar(lista_borrar(lista_nula)==ERROR, "Debe fallar con una lista nula");
	lista_t* lista_no_nula= lista_crear();
	if(lista_no_nula != NULL){
		int numero_prueba= 7;
		int numero_prueba_2 = 70;
		if(lista_insertar(lista_no_nula, &numero_prueba)== EXITO && lista_insertar(lista_no_nula, &numero_prueba_2) == EXITO){
			pa2m_afirmar(lista_borrar(lista_no_nula)==EXITO, "Debe borrar el ultimo elemento");
			pa2m_afirmar((*lista_no_nula).nodo_fin->elemento== &numero_prueba, "El elemento anterior es correcto");
			pa2m_afirmar((*lista_no_nula).cantidad== 1, "La cantidad es correcta");
			pa2m_afirmar(lista_borrar(lista_no_nula)==EXITO, "Debe borrar el elemento  final de la lista");
			pa2m_afirmar((*lista_no_nula).nodo_fin==NULL && (*lista_no_nula).nodo_inicio== NULL, "Fin e inicio quedan apuntando a null cuando no hay mas elementos");
			pa2m_afirmar((*lista_no_nula).cantidad==0, "Quedan 0 elementos en la lista");
			
		}
	}
	lista_destruir(lista_no_nula);
}
void pruebas_lista_borrar_posicion(){
	lista_t* lista_no_nula= lista_crear();
	lista_t* lista_nula= NULL;
	size_t posicion_uno=1;
	size_t posicion_cero=0;
	pa2m_afirmar(lista_borrar_de_posicion(lista_nula, posicion_uno)==ERROR, "Debe fallar con una lista nula");
	if(lista_no_nula != NULL){
		int numero_prueba= 7;
		int numero_prueba_2 = 70;
		int numero_prueba_3= 8;
		if(lista_insertar(lista_no_nula, &numero_prueba)== EXITO && lista_insertar(lista_no_nula, &numero_prueba_2) == EXITO){
			pa2m_afirmar(lista_borrar_de_posicion(lista_no_nula, posicion_cero)==EXITO, "Elimina el primer elemento");
			pa2m_afirmar((*lista_no_nula).nodo_inicio->elemento== &numero_prueba_2, "El nuevo primer elemento es correcto");
			pa2m_afirmar((*lista_no_nula).cantidad==1, "La cantidad restante de nodos es correcta-->1");
			pa2m_afirmar(lista_borrar_de_posicion(lista_no_nula, posicion_cero)==EXITO, "Elimina el ultimo");
			pa2m_afirmar((*lista_no_nula).nodo_fin==NULL && (*lista_no_nula).nodo_inicio== NULL, "Fin e inicio quedan apuntando a null cuando no hay mas elementos");
			pa2m_afirmar((*lista_no_nula).cantidad==0, "Quedan 0 elementos en la lista");
			lista_insertar(lista_no_nula, &numero_prueba);
			lista_insertar(lista_no_nula, &numero_prueba_2);
			lista_insertar(lista_no_nula, &numero_prueba_3);
			pa2m_afirmar(lista_borrar_de_posicion(lista_no_nula, posicion_uno)==EXITO, "Elimina el segundo elemento de una lista de 3");
			pa2m_afirmar((*lista_no_nula).cantidad==2, "La cantidad restante de nodos es correcta-->2");
			pa2m_afirmar((*lista_no_nula).nodo_fin->elemento == &numero_prueba_3 && (*lista_no_nula).nodo_inicio->elemento== &numero_prueba, "Los  nodos restantes son correctos");
		}
	}
	lista_destruir(lista_no_nula);
}
void pruebas_lista_vacia(){
	lista_t* lista_no_nula= lista_crear();
	lista_t* lista_nula= NULL;
	int numero_prueba= 7;
	int numero_prueba_2 = 70;
	pa2m_afirmar(lista_vacia(lista_nula)== true,"Es vacia una lista nula");
	if(lista_insertar(lista_no_nula, &numero_prueba)== EXITO && lista_insertar(lista_no_nula, &numero_prueba_2) == EXITO){
		pa2m_afirmar(lista_vacia(lista_no_nula)== false,"Falso para lista no nula");
	}
	lista_destruir(lista_no_nula);
}
void pruebas_lista_ultimo(){
	lista_t* lista_no_nula= lista_crear();
	lista_t* lista_nula= NULL;
	int numero_prueba= 7;
	int numero_prueba_2 = 70;
	pa2m_afirmar(lista_ultimo(lista_nula)== NULL,"Falla con una lista nula");
	if(lista_insertar(lista_no_nula, &numero_prueba)== EXITO && lista_insertar(lista_no_nula, &numero_prueba_2) == EXITO){
		pa2m_afirmar(lista_ultimo(lista_no_nula)== &numero_prueba_2,"El ultimo elemento es correcto");
		lista_borrar(lista_no_nula);
		pa2m_afirmar(lista_ultimo(lista_no_nula)== &numero_prueba,"El ultimo elemento es correcto en una lista de 1");
		lista_borrar(lista_no_nula);
		pa2m_afirmar(lista_ultimo(lista_no_nula)== NULL,"No hay ultimo elemento en una lista vacia");

	}
	lista_destruir(lista_no_nula);
}

void pruebas_lista_elementos(){
	lista_t* lista_no_nula= lista_crear();
	lista_t* lista_nula= NULL;
	int numero_prueba= 7;
	int numero_prueba_2 = 70;
	pa2m_afirmar(lista_elementos(lista_nula)== 0,"Hay 0 elementos en una lista nula");
	if(lista_insertar(lista_no_nula, &numero_prueba)== EXITO && lista_insertar(lista_no_nula, &numero_prueba_2) == EXITO){
		pa2m_afirmar(lista_elementos(lista_no_nula)== 2,"La cantidad leida es correcta -->3");
		lista_borrar(lista_no_nula);
		lista_borrar(lista_no_nula);
		pa2m_afirmar(lista_elementos(lista_no_nula)== 0,"La cantidad leida es correcta -->0");
		lista_destruir(lista_no_nula);
	}
}
void pruebas_lista_iterador_crear(){
	lista_t* lista_no_nula= lista_crear();
	lista_t* lista_nula= NULL;
	int numero_prueba= 7;
	int numero_prueba_2 = 70;
	lista_iterador_t* iterador=NULL;
	pa2m_afirmar(lista_iterador_crear(lista_nula)== NULL,"Falla con una lista nula");
	if (lista_insertar(lista_no_nula, &numero_prueba)== EXITO && lista_insertar(lista_no_nula, &numero_prueba_2) == EXITO){
		pa2m_afirmar((iterador=lista_iterador_crear(lista_no_nula)) != NULL,"Se crea un iterador no nulo");
		pa2m_afirmar((*iterador).corriente == (*lista_no_nula).nodo_inicio,"El nodo corriente es igual al nodo inicio");
		pa2m_afirmar((*iterador).lista == lista_no_nula,"Apunta a la lista correcta");
	}
	lista_iterador_destruir(iterador);
	lista_destruir(lista_no_nula);
}
 
void pruebas_iterador_elemento_actual(){
	lista_t* lista_no_nula= lista_crear();
	lista_iterador_t* iterador_nulo= NULL;
	int numero_prueba= 7;
	int numero_prueba_2 = 70;
	pa2m_afirmar(lista_iterador_elemento_actual(iterador_nulo)== NULL,"Falla con un iterador nulo");
	if (lista_insertar(lista_no_nula, &numero_prueba)== EXITO && lista_insertar(lista_no_nula, &numero_prueba_2) == EXITO){
		lista_iterador_t* iterador =lista_iterador_crear(lista_no_nula);
		pa2m_afirmar(lista_iterador_elemento_actual(iterador)== &numero_prueba,"El elemento es correcto");
		lista_iterador_destruir(iterador);
	}
	lista_destruir(lista_no_nula);
}

void pruebas_iterador_tiene_siguiente(){
	lista_iterador_t* iterador_nulo= NULL;
	pa2m_afirmar(lista_iterador_tiene_siguiente(iterador_nulo)== false,"Falla con un iterador nulo");
	lista_t* lista_no_nula= lista_crear();
	int numero_prueba= 7;
	int numero_prueba_2 = 70;
	lista_iterador_t* iterador =lista_iterador_crear(lista_no_nula);
	pa2m_afirmar(lista_iterador_tiene_siguiente(iterador)== false,"No hay ningun elemento, no tiene siguiente");
	lista_insertar(lista_no_nula, &numero_prueba);
	lista_insertar(lista_no_nula, &numero_prueba_2);
	pa2m_afirmar(lista_iterador_tiene_siguiente(iterador)== true,"Hay dos elementos, tiene siguiente");
	lista_iterador_destruir(iterador);
	lista_destruir(lista_no_nula);
}

void pruebas_iterador_avanzar(){
	lista_iterador_t* iterador_nulo= NULL;
	pa2m_afirmar(lista_iterador_avanzar(iterador_nulo)== false,"Falla con un iterador nulo");
	lista_t* lista_no_nula= lista_crear();
	int numero_prueba= 7;
	int numero_prueba_2 = 70;
	if (lista_insertar(lista_no_nula, &numero_prueba)== EXITO){
		lista_iterador_t* iterador =lista_iterador_crear(lista_no_nula);
		pa2m_afirmar(lista_iterador_avanzar(iterador)== false,"No avanza con un solo elemento en la lista");
		lista_insertar(lista_no_nula, &numero_prueba_2);
		pa2m_afirmar(lista_iterador_avanzar(iterador)== true,"Avanza con dos elementos en la lista");
		pa2m_afirmar((*iterador).corriente->elemento == &numero_prueba_2,"El elemento actual es correcto");
		lista_iterador_destruir(iterador);
	}
	lista_destruir(lista_no_nula);
}
void pruebas_apilar_lista(){
	lista_t* prueba = NULL;
	int numero_prueba = 7;
	int numero_prueba_2= 2;
	pa2m_afirmar((lista_apilar(prueba, &numero_prueba)) == ERROR, "Error al insertar en lista nula");
	lista_t* lista_no_nula= lista_crear();
	if(lista_no_nula != NULL){
    	pa2m_afirmar(lista_apilar(lista_no_nula, &numero_prueba)== EXITO, "Pudo apilar numero valido");
    	pa2m_afirmar((*lista_no_nula).cantidad ==1, "aumenta la cantidad a 1");
    	pa2m_afirmar((*lista_no_nula).nodo_fin->elemento == &numero_prueba, "apila el numero correcto");
	    pa2m_afirmar(lista_apilar(lista_no_nula, &numero_prueba_2)== EXITO, "Pudo apilar 2 numeros validos");
	    pa2m_afirmar((*lista_no_nula).cantidad ==2,"aumenta la cantidad a 2");
	    pa2m_afirmar((*lista_no_nula).nodo_fin->elemento == &numero_prueba_2, "apila el numero correcto");
	}
    lista_destruir(lista_no_nula);
}
void pruebas_lista_desapilar(){
	lista_t* lista_nula= NULL;
	pa2m_afirmar(lista_desapilar(lista_nula)==ERROR, "Debe fallar con una lista nula");
	lista_t* lista_no_nula= lista_crear();
	if(lista_no_nula != NULL){
		int numero_prueba= 7;
		int numero_prueba_2 = 70;
		if(lista_insertar(lista_no_nula, &numero_prueba)== EXITO && lista_insertar(lista_no_nula, &numero_prueba_2) == EXITO){
			pa2m_afirmar(lista_desapilar(lista_no_nula)==EXITO, "Desapila");
			pa2m_afirmar((*lista_no_nula).nodo_fin->elemento== &numero_prueba, "el nuevo tope es correcto");
			pa2m_afirmar((*lista_no_nula).cantidad== 1, "La cantidad es correcta");
			pa2m_afirmar(lista_desapilar(lista_no_nula)==EXITO, "Debe desapilar el ultimo elemento");
			pa2m_afirmar((*lista_no_nula).nodo_fin==NULL && (*lista_no_nula).nodo_inicio== NULL, "Fin e inicio quedan apuntando a null cuando no hay mas elementos");
			pa2m_afirmar((*lista_no_nula).cantidad==0, "Quedan 0 elementos en la pila");
			
		}
	}
	lista_destruir(lista_no_nula);
}
void pruebas_lista_tope(){
	lista_t* lista_no_nula= lista_crear();
	lista_t* lista_nula= NULL;
	int numero_prueba= 7;
	int numero_prueba_2 = 70;
	pa2m_afirmar(lista_tope(lista_nula)== NULL,"Falla con una lista nula");
	if(lista_insertar(lista_no_nula, &numero_prueba)== EXITO && lista_insertar(lista_no_nula, &numero_prueba_2) == EXITO){
		pa2m_afirmar(lista_tope(lista_no_nula)== &numero_prueba_2,"El ultimo tope es correcto");
		lista_borrar(lista_no_nula);
		pa2m_afirmar(lista_tope(lista_no_nula)== &numero_prueba,"EL tope en una lista de un elemento es correcto");
		lista_borrar(lista_no_nula);
		pa2m_afirmar(lista_tope(lista_no_nula)== NULL,"No hay tope en pila vacia");

	}
	lista_destruir(lista_no_nula);
}
void pruebas_insertar_cola(){
	lista_t* prueba = NULL;
	int numero_prueba = 7;
	int numero_prueba_2= 2;
	pa2m_afirmar((lista_encolar(prueba, &numero_prueba)) == ERROR, "Debe fallar al insertar en lista nula");
	lista_t* lista_no_nula= lista_crear();
	if(lista_no_nula != NULL){
    	pa2m_afirmar(lista_encolar(lista_no_nula, &numero_prueba)== EXITO, "Pudo insertar numero valido en la cola");
    	pa2m_afirmar((*lista_no_nula).cantidad ==1, "aumento la cantidad  en uno");
    	pa2m_afirmar((*lista_no_nula).nodo_fin->elemento == &numero_prueba, "encola el numero correcto");
	    pa2m_afirmar(lista_encolar(lista_no_nula, &numero_prueba_2)== EXITO, "Pudo encolar 2 numeros validos");
	    pa2m_afirmar((*lista_no_nula).cantidad ==2,"aumento la cantidad a 2");
	    pa2m_afirmar((*lista_no_nula).nodo_fin->elemento == &numero_prueba_2, "el numero encolado es correcto");
	}
    lista_destruir(lista_no_nula);
}
void pruebas_lista_desencolar(){
	lista_t* lista_no_nula= lista_crear();
	lista_t* lista_nula= NULL;
	size_t posicion_uno=1;
	size_t posicion_cero=0;
	pa2m_afirmar(lista_borrar_de_posicion(lista_nula, posicion_uno)==ERROR, "Debe fallar con una lista nula");
	if(lista_no_nula != NULL){
		int numero_prueba= 7;
		int numero_prueba_2 = 70;
		if(lista_insertar(lista_no_nula, &numero_prueba)== EXITO && lista_insertar(lista_no_nula, &numero_prueba_2) == EXITO){
			pa2m_afirmar(lista_borrar_de_posicion(lista_no_nula, posicion_cero)==EXITO, "Desencola correctamente");
			pa2m_afirmar((*lista_no_nula).nodo_inicio->elemento== &numero_prueba_2, "El elemento restante es correcto");
			pa2m_afirmar((*lista_no_nula).cantidad==1, "La cantidad baja en 1");
			pa2m_afirmar(lista_borrar_de_posicion(lista_no_nula, posicion_cero)==EXITO, "Elimina el ultimo nodo restante");
			pa2m_afirmar((*lista_no_nula).nodo_fin==NULL && (*lista_no_nula).nodo_inicio== NULL, "Fin e inicio quedan apuntando a null cuando no hay mas elementos");
			pa2m_afirmar((*lista_no_nula).cantidad==0, "No hay mas elementos en la cola");
		}
	}
	lista_destruir(lista_no_nula);
}
void pruebas_lista_primer_elemento(){
	lista_t* lista_nula= NULL;
	int numero_prueba= 7;
	int numero_prueba_2 = 70;
	pa2m_afirmar(lista_primero(lista_nula)== NULL, "Da error si la lista esta vacia");
	lista_t* lista_no_nula= lista_crear();
	if(lista_no_nula != NULL){
		pa2m_afirmar(lista_primero(lista_no_nula)== NULL, "No hay primer elemento si la lista esta vacia");
		if(lista_insertar(lista_no_nula, &numero_prueba)== EXITO && lista_insertar(lista_no_nula, &numero_prueba_2) == EXITO){
			pa2m_afirmar( lista_primero(lista_no_nula)==&numero_prueba, "El elemento buscado es correcto");
			lista_borrar(lista_no_nula);
			lista_borrar(lista_no_nula);
			pa2m_afirmar( lista_primero(lista_no_nula)== NULL, "Si la cantidad es 0 devuelve null");
		}
	}
	lista_destruir(lista_no_nula);
}

int main(){
	pa2m_nuevo_grupo("\n PRUEBAS CREAR LISTA\n");
	pruebas_crear_lista();
	pa2m_nuevo_grupo("\n PRUEBAS INSERTAR LISTA\n");
	pruebas_insertar_lista();
	pa2m_nuevo_grupo("\n PRUEBAS INSERTAR EN POSICION LISTA\n");
	pruebas_lista_insertar_posicion();
	pa2m_nuevo_grupo("\n PRUEBAS ELEMENTO EN POSICION\n");
	pruebas_lista_elemento_en_posicion();
	pa2m_nuevo_grupo("\n PRUEBAS BORRAR LISTA\n");
	pruebas_lista_borrar();
	pa2m_nuevo_grupo("\n PRUEBAS BORRAR ELEMENTO POSICION\n");
	pruebas_lista_borrar_posicion();
	pa2m_nuevo_grupo("\n PRUEBAS LISTA VACIA\n");
	pruebas_lista_vacia();
	pa2m_nuevo_grupo("\n PRUEBAS ULTIMO LISTA\n");
	pruebas_lista_ultimo();
	pa2m_nuevo_grupo("\n PRUEBAS CANTIDAD ELEMENTOS\n");
	pruebas_lista_elementos();
	pa2m_nuevo_grupo("\n PRUEBAS CREAR ITERADOR\n");
	pruebas_lista_iterador_crear();
	pa2m_nuevo_grupo("\n PRUEBAS ITERADOR ELEMENTO ACTUAL \n");
	pruebas_iterador_elemento_actual();
	pa2m_nuevo_grupo("\n PRUEBAS ITERADOR TIENE SIGUIENTE \n");
	pruebas_iterador_tiene_siguiente();
	pa2m_nuevo_grupo("\n PRUEBAS ITERADOR AVANZAR \n");
	pruebas_iterador_avanzar();
	pa2m_nuevo_grupo("\n PRUEBAS APILAR LISTA \n");
	pruebas_apilar_lista();
	pa2m_nuevo_grupo("\n PRUEBAS DESAPILAR LISTA \n");
	pruebas_lista_desapilar();
	pa2m_nuevo_grupo("\n PRUEBAS TOPE LISTA \n");
	pruebas_lista_tope();
	pa2m_nuevo_grupo("\n PRUEBAS ENCOLAR \n");
	pruebas_insertar_cola();
	pa2m_nuevo_grupo("\n PRUEBAS DESENCOLAR \n");
	pruebas_lista_desencolar();
	pa2m_nuevo_grupo("\n PRUEBAS PRIMER ELEMENTO COLA \n");
	pruebas_lista_primer_elemento();
	pa2m_mostrar_reporte();
	printf("\n");
	return 0;
}