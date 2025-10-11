#include <stdio.h>

int pa_recursiva(int *v, int primeiro, int ultimo) {
    // Caso base: todos os pares já foram verificados
    if (primeiro >= ultimo)
        return 1;

    // Verifica se a soma do par atual é igual à soma do próximo par
    if ((v[primeiro] + v[ultimo]) != (v[primeiro + 1] + v[ultimo - 1]))
        return 0;

    // Chamada recursiva para os próximos pares
    return pa_recursiva(v, primeiro + 1, ultimo - 1);
}
