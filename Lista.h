/**
 * Implementação de Lista Simplesmente Encadeada.
 *
 */

//Evita a referência circular
#ifndef LISTA_H
#define LISTA_H

//Declaração de bibliotecas
#include <iostream>
#include <string>
#include <sstream>   

//Inclui a classe No
#include "No.h"

using namespace std;

/**
 * Tamanho máximo da lista.
 */
const int TAMANHO_LISTA = 100;

class Lista {
private:
    /**
     * Nó de início da lista.
     */
    No* inicio;

public:
    /**
     * Construtor sem parâmetro da lista.
     */
    Lista();

    /**
     * Recuperador de início.
     *
     * @return O nó do início da lista.
     */
    No* getInicio();

    /**
     * Modificador de início.
     *
     * @param inicio Um nó a ser atribuído ao início da lista.
     */
    void setInicio(No* inicio);

    /**
     * Retorna o valor em String da lista.
     *
     * @return Uma string com o valor do início da lista.
     */

    string paraString();

    /**
     * Insere um nó no início da lista.
     *
     * @param valor Um novo valor de um nó a ser inserido na lista.
     * @return Verdadeiro se conseguiu incluir o nó no início da lista.
     */
    bool inserirInicio(int valor);

    /**
     * Insere um nó em uma posição especifica da lista.
     *
     * @param valor Um novo valor de um nó a ser inserido na lista.
     * @param k Posição a ser inserida o valor.
     * @return Verdadeiro ou falso se conseguiu incluir o novo valor.
     */
    bool inserirPosicao(int valor, int k);

    /**
     * Insere um nó no final da lista.
     *
     * @param valor Um novo valor de um nó a ser inserido na lista.
     * @return Verdadeiro se conseguiu incluir o nó no final da lista.
     */
    bool inserirFim(int valor);

    /**
     * Excluir um nó do início da lista.
     *
     * @return Verdadeiro ou falso se excluiu o valor do início.
     */
    bool excluirInicio();

    /**
     * Excluir um Nó da lista pela posição.
     *
     * @param k Posição do nó a ser excluído da lista.
     * @return Verdadeiro ou falso se excluiu o valor da posição.
     */
    bool excluirPosicao(int k);

    /**
     * Excluir um nó do final da lista.
     *
     * @return Verdadeiro ou falso se excluiu o valor do final.
     */
    bool excluirFim();

    /**
     * Altera o valor de um Nó da lista pela posição.
     *
     * @param valor Um valor a ser atualizado na posição k da lista.
     * @param k Posição do nó a ser alterado da lista.
     * @return Verdadeiro ou falso se alterou o valor da posição.
     */
    bool alterarPosicao(int valor, int k);

    /**
     * Procura lista pela posição.
     *
     * @param k Posição do nó a ser consultada na lista.
     * @return O dado de uma posição k ou -1.
     */
    int procurarPosicao(int k);

    /**
     * Procura o nó da lista pela posição.
     *
     * @param chave Valor a a ser consultado na lista.
     * @return A posição do dado na lista ou -1.
     */
    int procurarValor(int chave);

    /**
     * Lista os dados da lista.
     *
     * @return Uma String com os dados da lista.
     */
    string listar();

    /**
     * Lista os dados da lista.
     *
     * @return Uma String com os dados da lista e seus endereços.
     */
    string listarEndereco();

    /**
     * Retorna a quantidade de nós da lista.
     *
     * @return A quantidade de nós da lista.
     */
    int getQuantidade();

    /**
     * Retorna se a lista esta vazia.
     *
     * @return Verdadeiro ou falso se a lista está vazia.
     */
    bool estaVazia();

};

#endif /* LISTA_H */

