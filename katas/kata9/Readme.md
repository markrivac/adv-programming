# You've built an inflight entertainment system with on-demand movie streaming

Users on longer flights like to start a second movie right when their first one ends, but they complain that the plane usually lands before they can see the ending. **So you're building a feature for choosing two movies whose total runtimes will equal the exact flight length.**

Write a function that takes an integer *flight_length* (in minutes) and a list of integers *movie_lengths* (in minutes) and returns a boolean indicating whether there are two numbers in *movie_lengths* whose sum equals *flight_length.*

When building your function:

- Assume your users will watch exactly two movies.
- Don't make your users watch the same movie twice.
- Optimize for runtime over memory.

## BreakDown

Lo primero a realizar es una función que reciba dos parámetros: un número indicando los minutos del viaje **flight_length** y un array de números indicando la duración de las películas en minutos **movies_Length**.

Después, por cada número **x** en el array, se busca uno **y** tal que **x + y** den como resultado **flight_length**. Para esto se seguirían los siguientes pasos:

1. Se toma un número **x** y se suma solamente con los que se encuentran a su derecha.
2. Si la suma resultante es igual al **flight_length**, entonces el programa termina regresando un true.

Se pensó el siguiente pseudo-código:

    findMovies(flight_lenght, movies_length):
        for (i = 0, i < movies_length - 1; i++):
            for (j = i + 1, j < movies_length; j++):
                if (movies_length[i] + movies_length[j] = flight_lenght):
                    return true;
        return false;