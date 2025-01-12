# Dia 7: Árboles  
>> g++ -o Day_7 Day_7.cpp
>> ./Day_7
***  
Hemos escogido el problema de reparar el puente (Bridge Repair) para implementar esta técnica de programación ya que, vimos una buena oportunidad para implementarla de modo que resulte relativamente útil y resulte lógica su implementación.  
Esto se debe al hecho de que, al implementarlo mediante un árbol binario, podemos realizar todas las combinaciones necesarias para encontrar el resultado, y buscarlo de forma eficiente. Además, a pesar de haber implementado esto para la parte 1, también se podría hacer la parte 2 haciendo que el árbol binario fuera un árbol general con 3 nodos hijos por cada padre.  

En cuanto al método empleado, hemos optado por, como hemos mencionado previamente, un árbol binario en el cual los nodos de la izquierda representan la suma del valor actual y el siguiente, y los nodos de la derecha la multiplicación de los mismos.  
Para ello, primero definimos la clase de nodo, con un valor y punteros a los nodos hijos de la izquierda y la derecha. Posteriormente, tras haber pasado el input a 2 vectores, uno con los resultados y otro con los números con los que se debe operar, los pasamos a la función result(). Esta función se encarga de que, para cada índice de los vectores (los cuales son del mismo tamaño), pasa el valor objetivo y los valores a operar a la función buildTree() y posteriormente suma la cantidad de resultados posibles.  
Finalmente, la función recursiva buildTree() tiene como caso base el haber alcanzado un nodo con un valor igual al objetivo, en cuyo caso devuelve true.  
En casos que no son el base, observa tanto si el índice es superior o si el valor se ha pasado, y devuelve falso en esos casos. En caso contrario, genera los hijos del modo comentado previamente y llama a la función para cada nodo hijo.  
Además, puesto que estos árboles crecen de manera dinámica, en caso de que un camino resulte incorrecto, se eliminan los nodos para liberar memoria, del mismo modo que, tras cada iteración de valores, se elimina el árbol correspondiente.

Entre las alternativas posibles para resolver este problema, estaba la fuerza bruta, como en la mayoría de problemas. Sin embargo, entre las alternativas dentro del método usado, se podría haber generado el árbol entero y a continuación haber realizado algún recorrido sobre el mismo para buscar si el resultado está presente entre los nodos.  
Por otro lado, la principal dificultad que encontramos a la hora de hacer este código fue ver que ciertos caminos en los que abundan las multiplicaciones sobrepasan el límite de los enteros, y por ello empleamos variables numéricas de tipo long long.  

Finalmente, en cuanto a lo que se ha aprendido en la resolución de este problema, podemos destacar que, en vez de usar el método de construir el árbol completamente, nos dimos cuenta que en árboles que se puede buscar mientras se crea, esto resulta innecesario, haciendo así un árbol de búsqueda binaria, pero sin necesidad de recorrer el mismo, así como el uso de árboles de modo eficiente en cuanto a memoria ocupada al ir eliminando directamente caminos que resultan imposibles.

