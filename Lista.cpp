/**
 *
 * Implementação dos métodos da classe Lista.
 *
 */

//Inclui o cabeçalho da classe Lista
#include "Lista.h"

/**
 * Construtor sem parâmetro da lista.
 */
Lista::Lista() {
    this->inicio = (No*) NULL; //Inicializa o início da lista com null
}

/**
 * Recuperador de início.
 *
 * @return O nó do início da lista.
 */
No* Lista::getInicio() {
    return inicio;
}

/**
 * Modificador de início.
 *
 * @param inicio Um nó a ser atribuído ao início da lista.
 */

void Lista::setInicio(No* inicio) {
    this->inicio = inicio;
}

/**
 * Retorna o valor em String da lista.
 *
 * @return Uma string com o valor do início da lista.
 */

string Lista::paraString() {
    stringstream endereco;
    endereco << this;
    stringstream enderecoinicio;
    enderecoinicio << getInicio();
    return "OID: " + endereco.str() + " / início: " + enderecoinicio.str();
}

/**
 * Insere um nó no início da lista.
 *
 * @param valor Um novo valor de um nó a ser inserido na lista.
 * @return Verdadeiro se conseguiu incluir o nó no início da lista.
 */
bool Lista::inserirInicio(int valor) {
    //Instancia o novo nó
    No* novo = new No;
    //Atribui o dado ao nó
    novo->setDado(valor);
    //Coloca o primeiro no proximo do novo
    novo->setProximo(getInicio());
    //Coloca o novo nó em início
    setInicio(novo);
    return true;
}

/**
 * Insere um nó em uma posição especifica da lista.
 *
 * @param valor Um novo valor de um nó a ser inserido na lista.
 * @param k Posição a ser inserida o valor.
 * @return Verdadeiro ou falso se conseguiu incluir o novo valor.
 */
bool Lista::inserirPosicao(int valor, int k) {
    if (k > 0) {
        if (k > 1) {
            int cont = 1;
            //Recupera o início da lista
            No* atual = getInicio();
            No* anterior = NULL;
            while ((atual != NULL) && (cont != k)) {
                anterior = atual;
                atual = atual->getProximo();
                cont = cont + 1;
            }
            if (anterior != NULL) {
                //Instancia o novo nó
                No* novo = new No;
                //Atribui o dado ao nó
                novo->setDado(valor);
                novo->setProximo(anterior->getProximo());
                anterior->setProximo(novo);
                return true;
            } else {
                return false;
            }
        } else {
            //Instancia o novo nó
            No* novo = new No;
            novo->setDado(valor);
            novo->setProximo(getInicio()); // Coloca o primeiro no proximo do novo
            setInicio(novo); // Coloca o novo no inicio
            return true;
        }
    } else {
        return false;
    }
}

/**
 * Insere um nó no final da lista.
 *
 * @param valor Um novo valor de um nó a ser inserido na lista.
 * @return Verdadeiro se conseguiu incluir o nó no final da lista.
 */
bool Lista::inserirFim(int valor) {
    //Verifica se a lista não está vazia
    if (getInicio() == NULL) {
        //Instancia o novo nó
        No* novo = new No;
        //Atribui o dado ao nó
        novo->setDado(valor);
        setInicio(novo);
        return true;
    } else {
        //Recupera o início da lista
        No* atual = getInicio();
        //Para no último nó da lista
        while (atual->getProximo() != NULL) {
            atual = atual->getProximo();
        }
        //Instancia o novo nó
        No* novo = new No;
        //Atribui o dado ao nó
        novo->setDado(valor);
        atual->setProximo(novo);
        return true;
    }
}

/**
 * Excluir um nó do início da lista.
 *
 * @return Verdadeiro ou falso se excluiu o valor do início.
 */
bool Lista::excluirInicio() {
    if (getInicio() != NULL) {//Verifica se a lista nao esta vazia
        No* temp = getInicio(); //Guarda o elemento a ser removido
        setInicio(getInicio()->getProximo()); // pula o elemento a ser removido
        delete temp; //Desaloca o elemento        
        return true;
    } else {
        cout << "\nExcluir início - Lista vazia." << endl;
        return false;
    }
}

/**
 * Excluir um Nó da lista pela posição.
 *
 * @param k Posição do nó a ser excluído da lista.
 * @return Verdadeiro ou falso se excluiu o valor da posição.
 */
bool Lista::excluirPosicao(int k) {
    if (getInicio() != NULL) { //Verifica se a lista nao esta vazia
        No* temp = NULL;
        if ((getInicio()->getProximo() != NULL) && (k > 1)) {
            //Recupera o início da lista
            No* atual = getInicio();
            No* anterior = NULL;
            int cont = 1;
            while ((atual->getProximo() != NULL) && (cont != k)) {
                anterior = atual;
                atual = atual->getProximo();
                cont = cont + 1;
            }
            temp = atual; //Guarda o elemento a ser removido
            anterior->setProximo(atual->getProximo()); // pula o elemento a ser removido
        } else {
            if (k == 1) {
                temp = getInicio(); //Guarda o elemento a ser removido
                setInicio(getInicio()->getProximo()); // pula o elemento a ser removido
            }
        }
        delete temp; //Desaloca o elemento
        return true;
    } else {
        cout << "\nExcluir posição - Lista vazia." << endl;
        return false;
    }
}

/**
 * Excluir um nó do final da lista.
 *
 * @return Verdadeiro ou falso se excluiu o valor do final.
 */
bool Lista::excluirFim() {
    if (getInicio() != NULL) { //Verifica se a lista não esta vázia
        No* temp = NULL;
        if (getInicio()->getProximo() != NULL) { //Com mais de um nó
            //Recupera o início da lista
            No* atual = getInicio();
            No* anterior = NULL;
            while (atual->getProximo() != NULL) {
                anterior = atual;
                atual = atual->getProximo();
            }
            temp = atual; //Guarda o elemento a ser removido
            anterior->setProximo(atual->getProximo()); // pula o elemento a ser removido
        } else {
            temp = getInicio(); //Guarda o elemento a ser removido
            setInicio(getInicio()->getProximo()); // pula o elemento a ser removido
        }
        delete temp; //Desaloca o elemento
        return true;
    } else {
        cout << "\nExcluir fim - Lista vazia." << endl;
        return false;
    }
}

/**
 * Altera o valor de um Nó da lista pela posição.
 *
 * @param valor Um valor a ser atualizado na posição k da lista.
 * @param k Posição do nó a ser alterado da lista.
 * @return Verdadeiro ou falso se alterou o valor da posição.
 */
bool Lista::alterarPosicao(int valor, int k) {
    if (getInicio() != NULL) {
        //Recupera o início da lista
        No* atual = getInicio();
        int cont = 1;
        while ((atual->getProximo() != NULL) && (cont != k)) {
            atual = atual->getProximo();
            cont = cont + 1;
        }
        if (cont == k) {
            atual->setDado(valor);
            return true;
        } else {
            return false;
        }
    } else {
        cout << "\nAlterar posição - Lista vazia." << endl;
        return false;
    }
}

/**
 * Procura lista pela posição.
 *
 * @param k Posição do nó a ser consultada na lista.
 * @return O dado de uma posição k ou -1.
 */
int Lista::procurarPosicao(int k) {
    if (getInicio() != NULL) {
        //Recupera o início da lista
        No* atual = getInicio();
        int cont = 1;
        while ((atual->getProximo() != NULL) && (cont != k)) {
            atual = atual->getProximo();
            cont = cont + 1;
        }
        if (cont == k) {
            return atual->getDado();
        } else {
            return -1;
        }
    } else {
        cout << "\nProcurar posição - Lista vazia." << endl;
        return -1;
    }
}

/**
 * Procura o nó da lista pela posição.
 *
 * @param chave Valor a a ser consultado na lista.
 * @return A posição do dado na lista ou -1.
 */
int Lista::procurarValor(int chave) {
    if (getInicio() != NULL) {
        //Recupera o início da lista
        No* atual = getInicio();
        int contador = 1;
        while ((atual != NULL) && (atual->getDado() != chave)) {
            atual = atual->getProximo();
            contador = contador + 1;
        }
        if (atual != NULL) {
            return contador;
        } else {
            return -1;
        }
    } else {
        cout << "\nProcurar valor - Dado não existe." << endl;
        return -1;
    }
}

/**
 * Lista os dados da lista.
 *
 * @return Uma String com os dados da lista.
 */
string Lista::listar() {
    //Recupera o início da lista
    No* atual = getInicio();
    int cont = 0;
    //String de retorno
    string temp = "";
    while (atual != NULL) {
        cont = cont + 1;
        temp = temp + to_string(cont) + "-" + to_string(atual->getDado()) + "\n";
        atual = atual->getProximo();
    }
    return temp;
}

/**
 * Lista os dados da lista.
 *
 * @return Uma String com os dados da lista e seus endereços.
 */
string Lista::listarEndereco() {
    //Recupera o início da lista
    No* atual = getInicio();
    int cont = 0;
    //String de retorno
    string temp = "";
    stringstream enderecoatual;
    enderecoatual << atual;
    temp = temp + "Início = " + enderecoatual.str() + "\n";
    while (atual != NULL) {
        cont = cont + 1;
        stringstream enderecoatual;
        enderecoatual << atual;
        stringstream enderecoproximo;
        enderecoproximo << atual->getProximo();
        temp = temp + to_string(cont) + "- Dado = " + to_string(atual->getDado()) + " / Endereço = " + enderecoatual.str() + " / Próximo = " + enderecoproximo.str() + "\n";
        atual = atual->getProximo();
    }
    return temp;
}

/**
 * Retorna a quantidade de nós da lista.
 *
 * @return A quantidade de nós da lista.
 */
int Lista::getQuantidade() {
    int cont = 0;
    //Verifica se a lista não esta vazia
    if (getInicio() != NULL) {
        //Recupera o início da lista
        No* atual = getInicio();
        while (atual != NULL) {
            cont = cont + 1;
            atual = atual->getProximo();
        }
    }
    return cont;
}

/**
 * Retorna se a lista esta vazia.
 *
 * @return Verdadeiro ou falso se a lista está vazia.
 */
bool Lista::estaVazia() {
    return getInicio() == NULL;
}