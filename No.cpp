/**
 *
 * Implementação dos métodos da classe Nó.
 *
 */

//Inclui o cabeçalho da classe No
#include "No.h"

/**
 * Construtor sem parâmetros.
 */
No::No() {
    No(0, (No*) NULL);
}

/**
 * Construtor com parâmetros.
 *
 * @param dado um valor do tipo inteiro.
 * @param proximo um próximo nó da lista
 */
No::No(int dado, No* proximo) {
    this->dado = dado;
    this->proximo = proximo;
}

/**
 * Recuperador de dado.
 *
 * @return Um inteiro com o dado do nó.
 */
int No::getDado() {
    return this->dado;
}

/**
 * Recuperador de próximo.
 *
 * @return Um próximo nó da lista.
 */
No* No::getProximo() {
    return proximo;
}

/**
 * Modificador de dado.
 *
 * @param dado Um valor inteiro a ser atribuído para o dado.
 */
void No::setDado(int dado) {
    this->dado = dado;
}

/**
 * Modificador de próximo.
 *
 * @param proximo Um próximo nó da lista.
 */
void No::setProximo(No* proximo) {
    this->proximo = proximo;
}

/**
 * Retorna o valor em String do dado.
 *
 * @return Uma string com o valor do dado do nó.
 */
string No::paraString() {
    stringstream endereco;
    endereco << this;
    return "OID: " + endereco.str() + " / dado: " + to_string(getDado());
}