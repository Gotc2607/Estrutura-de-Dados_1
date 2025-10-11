#include <stdio.h> // Incluído por boa prática, embora não seja estritamente necessário para a lógica da função.

// Declaração antecipada da função auxiliar (helper) estática.
static int pa_helper(int *v, int primeiro, int ultimo, int soma_alvo);

/**
 * @brief Verifica se um vetor representa uma progressão aritmética conforme a definição dada.
 * Esta função atua como um invólucro para a função recursiva auxiliar.
 *
 * @param v Ponteiro para o início do vetor de inteiros.
 * @param primeiro Índice do primeiro elemento a ser considerado (inicialmente 0).
 * @param ultimo Índice do último elemento a ser considerado (inicialmente n-1).
 * @return 1 se a sequência for uma PA, 0 caso contrário.
 */
int pa_recursiva(int *v, int primeiro, int ultimo) {
    // Calcula a soma alvo usando os elementos mais externos.
    int soma_alvo = v[primeiro] + v[ultimo];

    // Inicia a verificação recursiva com o próximo par de elementos internos.
    return pa_helper(v, primeiro + 1, ultimo - 1, soma_alvo);
}

/**
 * @brief Função auxiliar recursiva que realiza a verificação da PA.
 *
 * @param v Ponteiro para o início do vetor de inteiros.
 * @param primeiro Índice do primeiro elemento do par atual.
 * @param ultimo Índice do último elemento do par atual.
 * @param soma_alvo A soma que cada par de elementos simétricos deve ter.
 * @return 1 se a subsequência for uma PA, 0 caso contrário.
 */
static int pa_helper(int *v, int primeiro, int ultimo, int soma_alvo) {
    // Caso base: Se os índices se cruzaram, todos os pares anteriores
    // corresponderam à soma alvo. A sequência é uma PA.
    if (primeiro >= ultimo) {
        return 1;
    }

    // Passo recursivo:
    // Verifica se a soma do par atual é igual à soma alvo.
    if (v[primeiro] + v[ultimo] != soma_alvo) {
        // Se não for, a sequência não é uma PA.
        return 0;
    } else {
        // Se for, continua a verificação para o próximo par interno.
        return pa_helper(v, primeiro + 1, ultimo - 1, soma_alvo);
    }
}