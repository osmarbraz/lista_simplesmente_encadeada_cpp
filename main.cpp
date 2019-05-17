/**
 * Implementação de Lista Simplesmente Encadeada.
 *
 */

//Declaração de bibliotecas
#include <cstdlib>
#include <iostream>
#include <string>

//Inclui o cabeçalho da classe Lista
#include "Lista.h"

using namespace std;

/**
 * Realiza a leitura dos dados dos nós.
 *
 * @return O valor lido.
 */
int leitura() {
    cout << "\nDigite um valor: ";
    int valor = 0;
    cin >> valor;
    return valor;
}

int main(int argc, char** argv) {
    /**
     * Declara e instancia a lista.
     */
    Lista lista;

    // Controla o menu da lista
    int opcao = -1;

    //Laço do menu de opções
    while (opcao != 99) {
        //Monta o menu de opções        
        cout << "\n\t### Lista Simplesmente Encadeada ###\n"
                << "Selecione a opção desejada:\n"
                << " 1- Inserir Nó no início\n"
                << " 2- Inserir Nó no fim\n"
                << " 3- Inserir Nó em uma posição especifica\n"
                << " 4- Remover Nó do início\n"
                << " 5- Remover Nó de uma posição específica\n"
                << " 6- Remover Nó do fim\n"
                << " 7- Alterar o valor de um Nó\n"
                << " 8- Procurar o dado de uma posição específica\n"
                << " 9- Procurar a posição de um dado\n"
                << "10- Listar Nós\n"
                << "11- Listar Nós e Endereços\n"
                << "12- Mostrar a quantidade de Nós\n"
                << "13- Está vazia?\n"
                << "99- Sair\n"
                << " Opcao:";
        cin >> opcao;
        switch (opcao) {
            case 1:
            {
                //Preenche o valor do dado
                int dado = leitura();
                if (lista.inserirInicio(dado) == true) {
                    cout << "\nNó inserido no início com Sucesso!" << endl;
                } else {
                    cout << "\nNó não inserido no início!" << endl;
                }
                break;
            }
            case 2:
            {
                int k;
                cout << "\nDigite a posição a ser inserido:";
                cin >> k;
                //Preenche o valor do dado
                int dado = leitura();
                if (lista.inserirPosicao(dado, k) == true) {
                    cout << "\nNó inserido na posição " << k << " com Sucesso!" << endl;
                } else {
                    cout << "\nNó não inserido na posição " << k << "!" << endl;
                }
                break;
            }
            case 3:
            {
                //Preenche o valor do dado
                int dado = leitura();
                if (lista.inserirFim(dado) == true) {
                    cout << "\nNó inserido no fim com Sucesso!" << endl;
                } else {
                    cout << "\nNó não inserido no fim!" << endl;
                }
                break;
            }
            case 4:
            {
                if (lista.excluirInicio()) {
                    cout << "\nNó do início foi excluído com Sucesso!" << endl;
                } else {
                    cout << "\nNó do início não foi excluído!" << endl;
                }
                break;
            }
            case 5:
            {
                int k;
                cout << "\nDigite a posição a ser excluída:";
                cin >> k;
                if (lista.excluirPosicao(k)) {
                    cout << "\nO valor da posição " << k << " foi excluído com Sucesso!" << endl;
                } else {
                    cout << "\nValor não foi excluído!" << endl;
                }
                break;
            }

            case 6:
            {
                if (lista.excluirFim()) {
                    cout << "\nO Nó da fim foi excluído com Sucesso!" << endl;
                } else {
                    cout << "\nNó do fim não foi excluído!" << endl;
                }
                break;
            }
            case 7:
            {
                int k;
                cout << "\nDigite a posição do dado a ser alterada e o novo dado:";
                cin >> k;
                //Preenche o valor do dado
                int dado = leitura();
                if (lista.alterarPosicao(dado, k)) {
                    cout << "\nO valor da posição " << k << " foi alterado com Sucesso!" << endl;
                } else {
                    cout << "\nValor não foi alterado!" << endl;
                }
                break;
            }
            case 8:
            {
                int k;
                cout << "\nDigite a posição do dado a ser procurada:";
                cin >> k;
                int dado = lista.procurarPosicao(k);
                if (dado != -1) {
                    cout << "\nO valor da posição " << k << "  possui o dado = " << dado << endl;
                } else {
                    cout << "\nA posição " << k << " não está preenchida" << endl;
                }
                break;
            }
            case 9:
            {
                int dado;
                cout << "\nDigite o valor do dado a ser procurado:";
                cin >> dado;
                int k = lista.procurarValor(dado);
                if (k != -1) {
                    cout << "\nO valor " << dado << " foi encontrado na posição = " << k << endl;
                } else {
                    cout << "\nO valor " << dado << " não existe" << endl;
                }
                break;
            }
            case 10:
            {
                if (lista.estaVazia()) {
                    cout << "\nLista vazia!" << endl;
                } else {
                    cout << "\nListagem \n" << lista.listar();
                }
                break;
            }
            case 11:
            {
                if (lista.estaVazia()) {
                    cout << "\nLista vazia!" << endl;
                } else {
                    cout << "\nListagem Endereços\n" << lista.listarEndereco();
                }
                break;
            }
            case 12:
            {
                cout << "\nQuantidade de Nós na lista : " << lista.getQuantidade() << endl;
                break;
            }          
            case 13:
            {
                cout << "\nLista está vazia : " << lista.estaVazia() << endl;
                break;
            }
        }//Fim switch
    }//Fim while
    return 0;
}//Fim main

