// Amanda Naroaka
// Gustavo Xavier
// Leonardo de Almeida Pereira
// Lucas Vinicius
// Marcelo Berger Gil
// Vinicius Lustosa

#include <iostream>
#include <thread>
#include <vector>

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

void calcular_linha(int** matriz__a, int** matriz__b, int** matriz__c, int tamanho_da_matriz, int linha) {
    std::cout << "linha: " << linha << std::endl;
    for (int j = 0; j < tamanho_da_matriz; j++) {
        matriz__c[linha][j] = 0;
        std::cout << "Estou multiplicando o elemento: " << linha << " " << j << std::endl;
        for (int k = 0; k < tamanho_da_matriz; ++k) {
            matriz__c[linha][j] += matriz__a[linha][k] * matriz__b[k][j];
        }
    }
}

int main(int argc, char *argv[]) {
    int tamanho_da_matriz = atoi(argv[1]);

    if(argc < 2) {
        std::cout << "O programa deve ter pelo menos UM argumento para funcionar" << std::endl;
        return -1;
    }

    int **matriz_a, **matriz_b, **matriz_c;

    // Vetor de threads
    std::vector<std::thread> threads;

    matriz_a = new int*[tamanho_da_matriz];
    matriz_b = new int*[tamanho_da_matriz];
    matriz_c = new int*[tamanho_da_matriz];

    for(int i = 0; i < tamanho_da_matriz; i++)
    {
        matriz_a[i] = new int[tamanho_da_matriz];
        matriz_b[i] = new int[tamanho_da_matriz];
        matriz_c[i] = new int[tamanho_da_matriz];
    }

    for(int i = 0; i < tamanho_da_matriz; i++)
    {
        for(int j = 0; j < tamanho_da_matriz; j++) 
        {
            matriz_a[i][j] = i + 1;
            matriz_b[i][j] = (i + 1) + (j + 1);
            matriz_c[i][j] = 0.0;
        }
    }

    std::cout << "imprimindo as 3 matrizes:" << std::endl;
    std::cout << "matriz 1: " << std::endl;
    imprimeMatriz(matriz_a, tamanho_da_matriz, tamanho_da_matriz);

    std::cout << "matriz 2: " << std::endl;
    imprimeMatriz(matriz_b, tamanho_da_matriz, tamanho_da_matriz);

    std::cout << std::endl;
    std::cout << "matriz 3: " << std::endl;

    imprimeMatriz(matriz_c, tamanho_da_matriz, tamanho_da_matriz);

    // Criando uma thread para cada linha
    for (int linha = 0; linha < tamanho_da_matriz; ++linha) {
        threads.push_back(std::thread(calcular_linha, matriz_a, matriz_b, matriz_c, tamanho_da_matriz, linha));
    }

    for (auto& t : threads) {
      t.join();
    }

    std::cout << std::endl;

    std::cout << "matriz resultante: " << std::endl;
    imprimeMatriz(matriz_c, tamanho_da_matriz, tamanho_da_matriz);

    return 0;
}