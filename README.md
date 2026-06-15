# Push Swap

## Descripción

Push Swap es un proyecto de algoritmia cuyo objetivo es ordenar una pila de números utilizando el menor número posible de operaciones.

El programa recibe una lista de enteros como argumentos y debe generar una secuencia de instrucciones que ordene los números en orden ascendente usando únicamente dos pilas (`a` y `b`) y un conjunto limitado de operaciones.

## Operaciones permitidas

### Swap

- `sa` : intercambia los dos primeros elementos de la pila A.
- `sb` : intercambia los dos primeros elementos de la pila B.
- `ss` : ejecuta `sa` y `sb` al mismo tiempo.

### Push

- `pa` : mueve el primer elemento de B a A.
- `pb` : mueve el primer elemento de A a B.

### Rotate

- `ra` : desplaza todos los elementos de A una posición hacia arriba.
- `rb` : desplaza todos los elementos de B una posición hacia arriba.
- `rr` : ejecuta `ra` y `rb` simultáneamente.

### Reverse Rotate

- `rra` : desplaza todos los elementos de A una posición hacia abajo.
- `rrb` : desplaza todos los elementos de B una posición hacia abajo.
- `rrr` : ejecuta `rra` y `rrb` simultáneamente.

## Conceptos trabajados

- Algoritmos de ordenación
- Estructuras de datos
- Listas enlazadas
- Optimización
- Complejidad temporal
- Gestión de memoria
- Parsing y validación de datos

## Compilación

Para compilar el proyecto:

```bash
make
```

Esto generará el ejecutable:

```bash
push_swap
```

### Reglas disponibles

```bash
make
make clean
make fclean
make re
```

## Uso

```bash
./push_swap [números]
```

### Ejemplo

```bash
./push_swap 4 67 3 87 23
```

El programa mostrará por pantalla la secuencia de operaciones necesaria para ordenar los números.

## Gestión de errores

El programa muestra:

```bash
Error
```

cuando:

- Existen argumentos no numéricos.
- Hay números duplicados.
- Se produce un overflow o underflow de enteros.
- El formato de entrada es inválido.

## Objetivo

Además de ordenar correctamente los datos, el objetivo principal es minimizar el número de operaciones realizadas para obtener la mejor puntuación posible.

## Autor

Proyecto realizado como parte del programa de formación de 42.
