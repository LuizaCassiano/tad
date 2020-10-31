#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h>
#include <conio.h>

enum statusCompromisso
{
    A_SER_CUMPRIDO = 1,
    ADIADO = 2,
    CANCELADO = 3
};

enum tipoCompromisso
{
    ORIENTACAO = 1,
    AULA = 2,
    COMPROMISSO_PARTICULAR = 3,
    EVENTO = 4,
    REUNIAO = 5
};

typedef struct compromisso
{
    int id;
    char data[30];
    char hora[30];
    int duracao;
    char nome[100];
    int grauPrioridade;
    bool adiavel;
    enum statusCompromisso numStatus;
    enum tipoCompromisso tipoCompromisso;
} Compromisso[100];

Compromisso compromisso[101];

void verificaConflito(int index1, int index2)
{
    char hora1[30];
    char hora2[30];
    int prioridade1 = compromisso[index1]->grauPrioridade;
    int prioridade2 = compromisso[index2]->grauPrioridade;
    bool adiavel1 = compromisso[index1]->adiavel;
    bool adiavel2 = compromisso[index2]->adiavel;

    strcpy(hora1, compromisso[index1]->hora);
    strcpy(hora2, compromisso[index2]->hora);

    if (strcmp(hora1, hora2) == 0)
    {
        printf("\nConflito entre os compromissos!\n");

        if (prioridade1 > prioridade2)
        {
            if (adiavel2 == true)
            {
                compromisso[index2]->numStatus = ADIADO;
                compromisso[index1]->numStatus = A_SER_CUMPRIDO;
                printf("\nConflito %d adiado!\n", index2);
            }
            else
            {
                compromisso[index2]->numStatus = CANCELADO;
                compromisso[index1]->numStatus = A_SER_CUMPRIDO;
                printf("\nConflito %d cancelado!\n", index2);
            }
        }
        else if (prioridade2 > prioridade1)
        {
            if (adiavel1 == true)
            {
                compromisso[index1]->numStatus = ADIADO;
                compromisso[index2]->numStatus = A_SER_CUMPRIDO;
                printf("\nConflito %d adiado!\n", index1);
            }
            else
            {
                compromisso[index1]->numStatus = CANCELADO;
                compromisso[index2]->numStatus = A_SER_CUMPRIDO;
                printf("\nConflito %d cancelado!\n", index1);
            }
        }
    }
    else
    {
        printf("\nNao existe conflito entre os compromissos!\n");
    }
}

void defineCompromissoAdiavel(int index, int flag)
{
    int tipo = compromisso[index]->tipoCompromisso;

    if (tipo == 2 || tipo == 4)
    {
        printf("\nNao e possivel adiar este compromisso!\n");
    }
    else
    {
        if (flag > 2 || flag < 1)
        {
            printf("\nOpcao invalida!\n");
        }
        else
        {
            if (flag == 1)
            {
                compromisso[index]->adiavel = true;
                printf("\nCompromisso alterado!");
            }
            else if (flag == 2)
            {
                compromisso[index]->adiavel = false;
                printf("\nCompromisso alterado!");
            }
        }
    }
}

void alteraPrioridadeCompromisso(int index, int novaPrioridade)
{
    if (novaPrioridade < 1 || novaPrioridade > 4)
    {
        printf("\nOpção inválida!");
    }
    else
    {
        compromisso[index]->grauPrioridade = novaPrioridade;
    }
}

void retornarPrioridadeCompromisso(int index)
{
    int prioridade = compromisso[index]->grauPrioridade;

    printf("\nPrioridade: %d \n", prioridade);
}

void alterarStatusCompromisso(int index, int novoStatus)
{
    int tipo = compromisso[index]->tipoCompromisso;

    if ((tipo == 2 && novoStatus == 2) || (tipo == 4 && novoStatus == 2))
    {
        printf("\nNao foi possivel alterar o status!");
    }
    else
    {
        switch (novoStatus)
        {
        case 1:
            compromisso[index]->numStatus = A_SER_CUMPRIDO;
            printf("\nStatus alterado!");
            break;
        case 2:
            compromisso[index]->numStatus = ADIADO;
            printf("\nStatus alterado!");
            break;
        case 3:
            compromisso[index]->numStatus = CANCELADO;
            printf("\nStatus alterado!");
            break;
        default:
            printf("\nOpcao invalida!");
            break;
        }
    }
}

void retornarStatusCompromisso(int index)
{
    char status[30];

    switch (compromisso[index]->numStatus)
    {
    case 1:
        strcpy(status, "A ser cumprido");
        break;
    case 2:
        strcpy(status, "Adiado");
        break;
    default:
        strcpy(status, "Cancelado");
        break;
    }

    printf("\nStatus: %s \n", status);
}

int inicializaCompromisso(int tipoCompromisso, char data[20], char hora[20], int duracao, char nome[100])
{
    int id = (rand() % 100) + 1;

    compromisso[id]->numStatus = A_SER_CUMPRIDO;
    strcpy(compromisso[id]->data, data);
    strcpy(compromisso[id]->hora, hora);
    strcpy(compromisso[id]->nome, nome);
    compromisso[id]->duracao = duracao;
    compromisso[id]->adiavel = false;
    compromisso[id]->id = id;

    if (tipoCompromisso == 1) //nao pode ser adiado
    {
        compromisso[id]->tipoCompromisso = AULA;
        compromisso[id]->grauPrioridade = 2;
    }
    else if (tipoCompromisso == 2)
    {
        compromisso[id]->tipoCompromisso = ORIENTACAO;
        compromisso[id]->grauPrioridade = 1;
    }
    else if (tipoCompromisso == 3)
    {
        compromisso[id]->tipoCompromisso = COMPROMISSO_PARTICULAR;
        compromisso[id]->grauPrioridade = 2;
    }
    else if (tipoCompromisso == 4)
    {
        compromisso[id]->tipoCompromisso = REUNIAO;
        compromisso[id]->grauPrioridade = 4;
    }
    else if (tipoCompromisso == 5) //nao pode ser adiado
    {
        compromisso[id]->tipoCompromisso = EVENTO;
        compromisso[id]->grauPrioridade = 3;
    }
    else
    {
        return 0;
    }

    return compromisso[id]->id;
}

void imprimeCompromisso(int index)
{
    char tipoCompromisso[30];
    char adiavel[10];
    char status[30];

    switch (compromisso[index]->tipoCompromisso)
    {
    case 1:
        strcpy(tipoCompromisso, "Orientacao");
        break;
    case 2:
        strcpy(tipoCompromisso, "Aula");
        break;
    case 3:
        strcpy(tipoCompromisso, "Compromisso Particular");
        break;
    case 4:
        strcpy(tipoCompromisso, "Evento");
        break;
    default:
        strcpy(tipoCompromisso, "Reuniao");
        break;
    }

    switch (compromisso[index]->adiavel)
    {
    case 1:
        strcpy(adiavel, "True");
        break;

    default:
        strcpy(adiavel, "False");
        break;
    }

    switch (compromisso[index]->numStatus)
    {
    case 1:
        strcpy(status, "A ser cumprido");
        break;
    case 2:
        strcpy(status, "Adiado");
        break;
    default:
        strcpy(status, "Cancelado");
        break;
    }

    printf("\nId: %d", compromisso[index]->id);
    printf("\nTipo do compromisso: %s", tipoCompromisso);
    printf("\nData: %s", compromisso[index]->data);
    printf("\nHora: %s", compromisso[index]->hora);
    printf("\nDuracao: %d minutos", compromisso[index]->duracao);
    printf("\nNome: %s", compromisso[index]->nome);
    printf("\nAdiavel: %s", adiavel);
    printf("\nStatus: %s \n", status);
}