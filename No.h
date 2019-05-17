/**
 *
 * Nó a ser armazenado na lista.
 *
 */

//Evita a referência circular
#ifndef NO_H
#define NO_H

//Declaração de bibliotecas
#include <iostream>
#include <string>
#include <sstream>   

using namespace std;

class No {
private:
    int dado;
    /**
     * Aponta para o próximo nó.
     */
    No* proximo;
public:
    /**
     * Construtor sem parâmetros.
     */
    No();
    
    /**
     * Construtor com parâmetros.
     *
     * @param dado um valor do tipo inteiro.
     * @param proximo um próximo nó da lista    
     */
    No(int dado, No* proximo);

    /**
     * Recuperador de dado.
     *
     * @return Um inteiro com o dado do nó.
     */
    int getDado();
    
    /**
     * Recuperador de próximo.
     *
     * @return Um próximo nó da lista.
     */
    No* getProximo();
     
     /**
     * Modificador de dado.
     *
     * @param dado Um valor inteiro a ser atribuído para o dado.
     */
    void setDado(int dado);

    /**
     * Modificador de próximo.
     *
     * @param proximo Um próximo nó da lista.
     */
    void setProximo(No* proximo);
    
      /**
     * Retorna o valor em String do dado.
     *
     * @return Uma string com o valor do dado do nó.
     */
    string paraString();
};

#endif /* NO_H */

