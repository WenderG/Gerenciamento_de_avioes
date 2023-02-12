#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct Noh{
    int dado;
    char cor[50];
    float tamanho;
    int totalPassag;
    struct Noh *proximo;
}Noh;

typedef struct Lista{
    Noh* inicio;
    Noh* final;
}Lista;

Lista li;

void insereFinal(int elemento, int tamanho, int totalPassag, char cor[50]){
    Noh *p = (Noh*)malloc(sizeof(Noh));
    strcpy(p->cor, cor);
    p->dado = elemento;
    p->tamanho = tamanho;
    p->totalPassag = totalPassag;
    

    p->proximo = NULL;

    if(li.inicio == NULL){
        li.inicio = p;
    }else{
        li.final->proximo = p;
    }
    li.final = p;
}

void imprimir(){
    int aux = 0;
    Noh* p = li.inicio;
    printf(" ----------- Fila de espera para decolagem -----------\n");
    while(p != NULL){
        aux++;
        p = p->proximo;
    }
    p = li.inicio;
    printf("Total de avioes em espera: %d\n\n", aux);
    printf("Inicio->  ");
    while(p != NULL){
        printf("#%d    ", p->dado);
        p = p->proximo;
    }
}

void imprimeDados(){
    Noh* p = li.inicio;
    if(p != NULL){
        printf("Dados pre-decolagem do aviao #%d\n\n", p->dado);
        printf("Tamanho do aviao: %.2f m\n", p->tamanho);
        printf("Cor: %s\n", p->cor);
        printf("Total de passageiros: %d\n", p->totalPassag);
    }else{
        printf("Nenhum dado cadastrado!");
    }
}

int removeInicio(){
    Noh* p = li.inicio;
    int elemento;
    if(p == NULL){
        printf("Lista Vazia!\n\n");
        return -1;
    }else{
        li.inicio = li.inicio->proximo;
        p->proximo = NULL;
        elemento = p->dado;
        free(p);
        return elemento;
    }
}

int main(void){
    // 7. Escreva  um  programa  que  simule  o  controle  de  uma  pista  de  decolagem de  aviões  em  um aeroporto. Neste programa, o usuário deve ser capaz derealizar as seguintes tarefas:
    // •Listar o número de aviões aguardando na fila de decolagem;
    // •Autorizar a decolagem do primeiro avião da fila;
    // •Adicionar um avião à fila de espera;
    // •Listar todos os aviões na fila de espera;
    // •Listar as características do primeiro avião da fila.

    int opc, dado, totalPassag;
    float tamanho;
    char cor[50];

    li.inicio = NULL;
    li.final = NULL;

    do{
        system("cls");
        printf("---------- Controle de Aeronaves ----------\n");
        printf("0-Sair\n1-Inserir aviao na fila de espera\n2-Imprimir lista de espera\n3-Dados pre-decolagem\n4-Liberar o primeiro aviao para decolar\n");
        printf("Opcao: ");
        scanf("%d", &opc);

        switch(opc){
            case 0:
                system("cls");
                printf("Encerrando...");
                Sleep(1500);
                break;
            case 1:
                system("cls");
                printf("Numero do aviao: ");
                scanf("%d", &dado);
                fflush(stdin);
                printf("Tamanho (m): ");
                scanf("%f", &tamanho);
                fflush(stdin);
                printf("Cor do aviao: ");
                scanf("%s", &cor);
                fflush(stdin);
                printf("Total de passageiros: ");
                scanf("%d", &totalPassag);
                fflush(stdin);
                insereFinal(dado, tamanho, totalPassag, cor);
                printf("\n\n");
                system("pause");
                break;
            case 2:
                system("cls");
                imprimir();
                printf("\n\n");
                system("pause");
                break;
            case 3:
                system("cls");
                imprimeDados();
                printf("\n\n");
                system("pause");
                break;
            case 4:
                system("cls");
                dado = removeInicio();
                if(dado == -1){
                    system("pause");
                    break;
                }else{
                    printf("Autorizando o aviao #%d para partir!", dado);
                }
                printf("\n\n");
                system("pause");
                break;

            default:
                system("cls");
                printf("Opcao invalida!\n\n");
                system("pause");
                break;
        }

    }while(opc != 0);

    return 0;
}