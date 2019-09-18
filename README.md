# TECFLIX

TecFlix es una aplicación para visualizar metadata y trailers de películas o series de televisión. Es una aplicación de escritorio que consume un dataset de películas. Dicho dataset es provisto como un archivo csv similar a https://drive.google.com/open?id=1nfyBO8_-ZYRS8gqmmFfQ6JZ8eGLc6W7K) y la aplicación muestra todas las
películas listadas en el dataset junto con información sobre estas. La aplicación se conecta a IMDB (sigue un URL provisto en el dataset, descarga la página y extrae las partes relevantes) y muestra el poster y el trailer.

Dado que el dataset puede crecer considerablemente, TecFlix es escalable y para mantener una experiencia de
usuario óptima y evitar sobrecargar la memoria del cliente, los resultados se paginan de forma que solo 3 páginas se mantengan en memoria (y en la interfaz gráfica) en cualquier momento: la página anterior, la página actual y la página siguiente.La aplicación tiene dos modos en el que muestra el listado de películas: paginación tradicional y scroll infinito. Para ambos modos, las siguientes reglas aplican:

1. Cada tarjeta para cada película tiene un tamaño fijo dependiendo del nivel de zoom (se puede hacer zoom
en la interfaz gráfica).

2. Considerando el tamaño de la ventana, se calcula dinámicamente la cantidad de tarjetas que puede ver el
usuario sin hacer scroll, es decir el tamaño de cada página dependen del tamaño de la ventana y del
tamaño de las tarjetas.

En el modo de scroll infinito, se monitorea el evento de scroll. Cuando el usuario hace scroll hacia arriba o hacia abajo, se cargan nuevas páginas y se descargan las páginas no visibles.

En el modo de paginación tradicional, se muestra un paginador con números que permite al usuario avanzar entre
páginas haciendo click en los números de página. Al saltar por ejemplo a la página 20, se trae a memoria la 19 y la 21.
La aplicación tiene un modo de no paginación, en el que se carga todo el dataset. Debe mostrarse, el uso de memoria (dentro de la aplicación) y que se muestre claramente cómo se reduce al usar paginación. Se debe calcular y mostrar cuanta memoria usa cada página (incluyendo los elementos de UI que se utilicen).
