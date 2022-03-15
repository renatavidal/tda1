
--------------------- TDA NUMERO UNO ----------------------------

En el correspondiente ZIP se adjuntaran la consigna, el trabajo y sus pruebas para verificar su correcto funcionamiento. 
Para compilarlo usamos la siguiente linea:
    gcc *.c -o lista_se -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0
Para ejecutarlo usamos las siguiente: la primera si solo queremos correr las pruebas; la segunda si deseamos corroborar que no este perdiendo memoria:
    ./lista_se 
    valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./lista_se
A continuacion explicare el funcionamiento del trabajo. Principalmente es una implementacion de los tipos de datos abstractos pila, lista, cola,e
 iteradores interno y externo en donde realizamos sus funciones basicas como crear, insertar (apilar o encolar), borrar el elemento al final (o inicio en caso de cola)
y destruir por completo liberando la memoria en caso de ser necesario. En adicion a esto realice pruebas para someter a las funciones a diversas situaciones conflictivas 
y de funcionamiento corriente, y asi asegurarme de que pueden cumplir con su trabajo.


--------- TEORIA ----------
1) ¿Qué es lo que entendés por una lista? ¿Cuáles son las diferencias entre ser simple o doblemente enlazada?
    Por lista entiendo un tipo de dato abstracto en donde se almacenan nodos, es decir una estructura o dato que apunta a otro (que esta en stack o heap),
    que apunta a su estructura en el heap lo cual permite que sea dinamica. Ademas esos nodos no necesitan memoria consecutiva por lo que facilita
    encontrar un lugar donde almacenarlos para el programa. Puede ser simplemente enlazada, lo que significa que la unica conexion entre nodos es
    con su siguiente y no hay camino para atras, a diferencia de las listas doblemente enlazadas en donde cada nodo tiene un puntero a su siguiente 
    y a su anterior.

2) ¿Cuáles son las características fundamentales de las Pilas? ¿Y de las Colas?
    Las caracteristicas fundamentales de las pilas son:
        solo se puede agregar nodos desde el ultimo y sacar desde el ultimo, llamado tope.
        Su conjunto minimo de operaciones son crear, poner, sacar, tope, esta_vacia y destruir.
    Las carateristicas fundamentales de la cola son:
        Los nodos se agregan desde el final y se sacan desde el principio, es decir, tiene dos extremos en vez de uno solo como la pila.
        Sus operaciones basicas son crear, encolar, desencolar, primero, esta_vacia y destruir.
        
3) ¿Qué es un iterador? ¿Cuál es su función?
    Un iterador es una estructura o tipo de dato abstracto cuya funcionalidad es facilitar el recorrido de una lista, pila, cola o datos abstractos en general.
    Con este iterador se pueden recorrer secuencialmente sin saber la estructura de lo que estamos recorriendo.

4) ¿En qué se diferencia un iterador interno de uno externo?
    La diferencia de un iterador interno de uno externo es que el externo tiene sus propias funciones y es un tda en si mismo para ir recorriendo el tda, en cambio el interno 
    va recorriendo el tda dentro de las estructuras del mismo, y no tiene primitivas.
