# Dia 4: Ceres Search  
Ejecución:

>>  g++ -o Day4 Day_4.cpp

>>./Day4
 
Hemos seleccionado el problema "Ceres Search" para implementar técnicas de búsqueda eficiente debido a la complejidad del problema. Este ejercicio combina desafíos de manipulación de matrices y búsqueda de patrones en múltiples direcciones, lo que lo hace idóneo para aplicar técnicas algorítmicas como divide y vencerás.

La decisión de implementar divide y vencerás surgió de la oportunidad de optimizar el algoritmo ms allá del enfoque básico de la fuerza bruta. A diferencia de otros ejercicios en los que las técnicas algorítmicas pueden ser mas especificas y acaban resultando menos aptas para implementar esta técnica aquí se requiere recorrer las múltiples dimensiones, su naturaleza visual y lógica lo hacen un candidato excelente para lograr una correcta resolución.
En nuestra implementación, utiliza un algoritmo de divide y vencerás para encontrar la palabra "XMAS" en una matriz, verificando sus apariciones en todas las direcciones posibles.
El proceso se divide en diversas etapas:

1. Definir la dirección de desplazamiento entre las 8 posibles opciones
2. Leer la matriz en la que estamos iterando
3. Buscar la palabra objetivo Dividir la matriz en cuatro más pequeñas

Inicialmente se consideró implementar una solución de fuerza bruta para resolver el problema, recorriendo toda la matriz y verificando cada dirección para cada posición, no obstante, la complejidad de esta estrategia es mucho mayor que la que obtenemos al usar el método de divide y vencerás

Otra alternativa evaluada fue utilizar un enfoque basado en búsquedas simultáneas desde todas las posiciones iniciales posibles, pero se descartó debido al elevado costo de almacenamiento y procesamiento.

Una gran dificultad encontrada era hallar la manera de que las búsquedas no se salieran de los límites de la matriz, para solucionarlo se integraron soluciones que verifican los limites antes de realizar cualquier desplazamiento
Resolver este problema nos ayudó a consolidar conceptos clave relacionados con algoritmos de búsqueda y optimización en matrices. Aprendimos a analizar estructuras problemáticas para aplicar soluciones eficientes. 

Además, ayudo a mejorar el entendimiento con casos límite para garantizar que los algoritmos sean robustos y precisos.


