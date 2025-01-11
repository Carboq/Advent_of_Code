# Dia 11: Programación Dinámica  
***  
Hemos escogido el problema de las piedras plutónicas (Plutonian Pebbles) para implementar esta técnica de programación ya que, creemos que es el ejemplo perfecto para demostrar cuándo esta técnica resulta eficiente a la hora de resolver un problema.  
Esto se debe al hecho de que este problema resuelto por fuerza bruta conllevaría demasiado tiempo y/o recursos, es por ello que hemos elegido este problema entre las diversas opciones.  

En cuanto al método empleado, hemos optado por una aproximación que, en vez de gestionar un array con las diversas piedras que hay en cada momento, consiste en una función predictiva, la cual se encarga predecir ese crecimiento por cada blink.  
Para ello, optamos por una variable de memoria, en este caso un mapa, para poder generar nuevas entradas de manera dinámica según sean necesarias con una key asignada a cada entrada, similar a una tabla hash, y así evitar tener un array con n entradas, de las cuales se acabarían empleando solo unas pocas.  
El caso base para esta función será cuando ya no queden más blinks por hacer, que entonces devolverá un 1, basándonos en que, en ese punto, cada piedra se habrá "creado" mediante las llamadas recursivas a la función.
Por otro lado, para la asignación de la memoria, nos hemos enfocado en 3 casos:  
1. El valor actual es 0, para lo cual se vuelve a llamar a la función pero con valor 1, y un blink menos.
2. El valor actual tiene cifras pares, para lo cual el resultado es la suma de las llamadas de la primera mitad y la segunda mitad, con un blink menos.
3. El valor actual es 1, que vuelve a llamar a la función con el valor multiplicado por 2024.

Entre las alternativas posibles para resolver este problema, como ya hemos comentado, la fuerza bruta resulta inservible, de modo que en la mayoría de soluciones consideradas había recursividad sí o sí para poder realizar el cómputo de una manera más eficiente. En cuanto alternativas dentro del método usado, como ya hemos comentado, en vez de un mapa se podría haber usado un array, de manera menos eficiente, o una tabla hash, pero que como ya la habíamos implementado en un problema anterior, hemos optado por el mapa para agilizar el proceso.  

Finalmente, en cuanto a lo que se ha aprendido en la resolución de este problema, claramente podemos destacar la necesidad de buscar métodos lo más eficientes para resolver un problema ya que, este problema en concreto te fuerza a ello. Además, dentro de lo que son los contenidos de la asignatura, a parte de evidentemente haber reforzado los conocimientos de estos métodos, hemos podido ver de manera clara como las distintas técnicas y algoritmos se pueden ir implementando juntos para resolver un mismo problema ya que, para un mismo problema se podían usar tablas hash, programación dinámica, e incluso divide y vencerás si se hubiera optado por realizar las llamadas recursivas iniciales por mitades hasta haberse quedado con una sola piedra.
