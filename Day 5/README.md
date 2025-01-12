# Dia 5: Print Queue
## Grafos  
Ejecución:  
>> g++ -o Day5 Day_5.cpp

>> ./Day5

El problema Day5(Print Queue) fue seleccionado porque trata sobre un caso de ordenaciones topológicas y validaciones, estos casos al ser un conjunto estructurado y reglado son los candidatos ideales para resolverse por grafos.

El problema se puede dividir en tres etapas principales, la primera consistiría en el procesamiento de la entrada, aquí se separarían las reglas de ordenación y las actualizaciones, acto seguido se convierten los datos de entrada en estructuras manipulables, como listas de pares para las reglas y listas de vectores para las actualizaciones.

Después de esto debemos de validar el orden de las actualizaciones, para cada conjunto de páginas de una actualización, se comprueba si respeta las reglas de orden usando un grafo dirigido y un ordenamiento topológico, aquellas reglas que resulten irrelevantes para la actualización actual se ignoran.

Al final si la validación es exitosa, se extrae la página central del conjunto y se suma a un acumulador total.

A la hora de construir el grafo se utiliza una lista de adyacencias para representar las dependencias entre las páginas.

Mientras realizábamos este ejercicio hemos encontrado algunas dificultades, inicialmente las reglas se procesaban sin verificar la presencia de las páginas en la actualización, lo que generaba errores de acceso fuera de rango.

En un principio, no se consideró la posibilidad de que existiesen ciclos en las dependencias.

Al empezar se contempló usar un enfoque basado en recorrido en profundidad para validar las dependencias, no obstante, el manejar la validación con múltiples conjuntos de páginas habría sido más complicado.

El problema fue un reto que sirvió de mucha ayuda para aprender más sobre la teoría de grafos y desarrollar habilidades necesarias para podes implementar estas soluciones en futuros problemas. Adaptar los algoritmos al contexto especifico es de suma importancia si lo que se pretende es maximizar la eficiencia.
