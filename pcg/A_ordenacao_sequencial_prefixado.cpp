#include <bits/stdc++.h>

// Gera um único vetor grande com todos os dados
std::vector<int> gerarVetorBase(int tamanhoMaximo) {
    std::vector<int> v(tamanhoMaximo);
    std::mt19937 rng(42); // semente fixa
    std::uniform_int_distribution<int> dist(0, 1000000);
    for (int &x : v) x = dist(rng);
    return v;
}

// ------------------ MERGESORT ------------------

void merge(std::vector<int>& v, int esq, int meio, int dir) {
    std::vector<int> temp(dir - esq + 1);
    int i = esq, j = meio + 1, k = 0;
    while (i <= meio && j <= dir) {
        if (v[i] < v[j]) temp[k++] = v[i++];
        else             temp[k++] = v[j++];
    }
    while (i <= meio) temp[k++] = v[i++];
    while (j <= dir)  temp[k++] = v[j++];
    for (int l = 0; l < k; ++l) v[esq + l] = temp[l];
}

void mergesort(std::vector<int>& v, int esq, int dir) {
    if (esq < dir) {
        int meio = (esq + dir) / 2;
        mergesort(v, esq, meio);
        mergesort(v, meio + 1, dir);
        merge(v, esq, meio, dir);
    }
}

// ------------------ QUICKSORT ------------------

int particiona(std::vector<int>& v, int esq, int dir) {
    int pivo = v[dir];
    int i = esq - 1;
    for (int j = esq; j < dir; ++j) {
        if (v[j] < pivo) std::swap(v[++i], v[j]);
    }
    std::swap(v[i + 1], v[dir]);
    return i + 1;
}

void quicksort(std::vector<int>& v, int esq, int dir) {
    if (esq < dir) {
        int pi = particiona(v, esq, dir);
        quicksort(v, esq, pi - 1);
        quicksort(v, pi + 1, dir);
    }
}

// ------------------ TESTES ------------------

void medirTempo(void (*sortFunc)(std::vector<int>&, int, int), const std::vector<int>& base, int tam, const std::string& nome) {
    std::vector<int> vetor(base.begin(), base.begin() + tam); // copia o prefixo

    auto inicio = std::chrono::high_resolution_clock::now();
    sortFunc(vetor, 0, vetor.size() - 1);
    auto fim = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duracao = fim - inicio;

    std::string tamanhoAbreviado = "";
    int tamanhoVetor = vetor.size();
    if (tamanhoVetor == 10000) {
        tamanhoAbreviado = "10e4";
    } else if (tamanhoVetor == 100000) {
        tamanhoAbreviado = "10e5";
    } else if (tamanhoVetor == 1000000) {
        tamanhoAbreviado = "10e6";
    } else if (tamanhoVetor == 10000000) {
        tamanhoAbreviado = "10e7";
    }

    std::cout << nome << " - Tamanho: " << tamanhoAbreviado << " - Tempo: " << duracao.count() << "s\n";
}

int main() {
    std::vector<int> tamanhos = { 10000, 100000, 1000000, 10000000 };
    std::vector<int> base = gerarVetorBase(tamanhos.back()); // vetor base de 10^7

    for (int tam : tamanhos) {
        medirTempo(mergesort, base, tam, "Mergesort");
        medirTempo(quicksort, base, tam, "Quicksort");
        std::cout << "--------------------------------------\n";
    }

    return 0;
}
