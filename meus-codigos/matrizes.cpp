#include <iostream>

// cabeçalho das funções
void imprimeMatriz(int**, int, int);

/**
 * Nesse programa vamos:
 * • fazer multiplicação entre 2 matrizes.
 * 
 * Como rodar:
 * • é necessário colocar um argumento quando compilar o programa, para compilar:
 *   1) g++ matrizes.cpp -o matrizes
 *   2) .\matrizes.exe <um numero inteiro, para formar uma matriz quadrada>
 *  
 * Informações Importantes:
 * • argc seria a quantidade de argumentos, por isso int
 * • *argv seria os argumentos (sim voce consegue mandar mais de 1 argumento)
 * 
 */

int main(int argc, char *argv[]) {

    /**
     * Pega o primeiro argumento, que é uma cadeia de caracter, e converte para inteiro
     * por exemplo: pode entrar com o decimal 1, 22, 333, etc... que é uma cadeia de caracter...
     */
    int n = atoi(argv[1]);

    /**
     * verifica se o usuário colocou um argumento
     */
    if(argc < 2) {
        std::cout << "O programa deve ter pelo menos UM argumento para funcionar" << std::endl;
        return -1;
    }

    /**
     * Aqui estamos declarando 3 ponteiros duplos, defininindo:
     * • é um ponteiro duplo
     * • tipo de dado
     * 
     * obs: o ponteiro existe mas ainda não aponta para um bloco de memória válido.
     */
    int **matriz_a, **matriz_b, **matriz_c;
    /**
     * Geralmente instanciamos ponteiros duplos para matrizes dinâmicas, podendo ser:
     * • bidimensionais (2x2 ou 3x3 ou etc...) ou tridimensional (2x2x2 ou 3x3x3 e etc...)
     *   (matrizes dinâmicas: elas podem ser de qualquer tamanho dinamicamente)
     * 
     */

    /**
     * Aqui estamos instanciando (alocando memória)
     * • 'n' sendo a quantidade de linhas
     */
    matriz_a = new int*[n];
    matriz_b = new int*[n];
    matriz_c = new int*[n];

    /**
     * para cada linha estamos alocando um novo array, formando então as colunas
     */
    for(int i = 0; i < n; i++) 
    {
        matriz_a[i] = new int[n];
        matriz_b[i] = new int[n];
        matriz_c[i] = new int[n];
    }


    // Aqui estamos preenchendo as matrizes com os valores
    for(int i= 0; i < n; i++) 
    {
        for(int j= 0; j < n; j++) {
            matriz_a[i][j] = i + 1;
            matriz_b[i][j] = (i + 1) + (j + 1);
            matriz_c[i][j] = 0.0;
        }
    }

    std::cout << "imprimindo as 3 matrizes:" << std::endl;
    std::cout << "matriz 1: " << std::endl;
    imprimeMatriz(matriz_a, n, n);

    std::cout << "matriz 2: " << std::endl;
    imprimeMatriz(matriz_b, n, n);

    std::cout << std::endl;
    std::cout << "matriz 3: " << std::endl;

    imprimeMatriz(matriz_c, n, n);
        
    // multiplicando as matrizes:
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            for (int k = 0; k < n; k++) {
                matriz_c[i][j] += matriz_a[i][k] * matriz_b[k][j];
            }
        }
    }
        
    std::cout << "matriz resultante: " << std::endl;
    imprimeMatriz(matriz_c, n, n);

    return 0;
}

void imprimeMatriz(int** matriz, int linhas, int colunas) {
    for(int i = 0; i < linhas; i++) 
    {
        for(int j = 0; j < colunas; j++) 
        {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
