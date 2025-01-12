# Dia 1 Parte 2: Historian Hysteria  
## Tablas Hash  
Ejecución: 

>>g++ -o Day1 Day_1.cpp

>>./Day1

Hemos escogido este problema de calcular la similitud entre dos listas de IDs (Day 1: Historian Hysteria-Part 2) para implementar tablas hash debido a que podemos optimizar el cálculo de frecuencias y búsquedas de elementos. Esta estructura de datos permite una implementación eficiente para listas grandes con datos repetidos.

Esto se debe a que las tablas hash nos permiten almacenar y acceder rápidamente a las frecuencias de los números de la lista derecha, lo cual es esencial para calcular el puntaje de similitud. Si utilizáramos bucles anidados para resolver el ejercicio, la complejidad cuadrática sería de O(n × m), esto sería una complejidad demasiado grande cuando trabajamos con listas de tamaño muy elevado. Sin embargo, al emplear tablas hash, reducimos la complejidad a O(n + m),haciendo esto optimizamos considerablemente el rendimiento y logramos que el algoritmo sea escalable.

En cuanto al método empleado, hemos utilizado una tabla hash para guardar la frecuencia de cada número en la lista derecha. Posteriormente, recorrimos la lista izquierda y, para cada número, consultamos su frecuencia en la tabla hash. Luego multiplicamos el número por dicha frecuencia y acumulamos el resultado para obtener el puntaje total de similitud. Esta manera de actuar nos garantiza que las búsquedas sean muy veloces

La principal alternativa que se considero fue utilizar bucles anidados para resolver el problema directamente comparando cada elemento de cada lista entre sí. A pesar de que esta solución es la más sencilla, también implica un método ineficiente, con una complejidad significativamente mayor, y se descartó en favor de las tablas hash. Otra de las alternativas evaluada fue ordenar ambas listas y aplicar un algoritmo de doble puntero. Sin embargo, aunque esta opción también mejora respecto a la solución básica, las tablas hash son una solución más sencilla y directa

Entre las dificultades que encontramos, podemos destacar el comprender cómo manejar eficientemente los datos y calcular las frecuencias sin incrementar la complejidad del algoritmo de forma innecesaria. Además, es necesario tener especial cuidado en la parte de implementación para evitar problemas relacionados con colisiones en las tablas hash y garantizar un uso óptimo de la memoria.

Gracias a resolver este problema, hemos profundizado en la importancia de elegir las estructuras de datos que más se adecuan a los problemas presentes para resolverlos de la forma más eficiente. También aprendimos la importancia de analizar cada problema para descubrir cual es la estructura de datos de la que mas valor podemos obtener, elegir la correcta nos puede garantizar obtener el menor tiempo posible de ejecución

Además, trabajar con tablas hash nos permitió comprender su aplicación práctica en situaciones del mundo real, como el manejo de grandes volúmenes de datos y la optimización de búsquedas. Este aprendizaje será valioso para abordar futuros problemas donde la eficiencia y la escalabilidad sean fundamentales.	
