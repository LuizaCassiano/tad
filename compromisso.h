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

typedef struct no
{
    int id, duracao, grauPrioridade;
    char data[20], hora[20], nome[100];
    bool adiavel;
    enum statusCompromisso numStatus;
    enum tipoCompromisso tipoCompromisso;
    struct no *prox;
} Compromisso;

Compromisso *listaCompromisso = NULL, *novoCompromisso = NULL;

int criarLista(int tipoCompromisso, char data[20], char hora[20], int duracao, char nome[100])
{
    Compromisso *comp = (Compromisso *)malloc(sizeof(Compromisso));

    if (comp == NULL)
    {
        printf("\nFalha ao inicializar lista\n");
        return 0;
    }

    int id = (rand() % 100) + 1;

    comp->id = id;
    comp->numStatus = A_SER_CUMPRIDO;
    strcpy(comp->data, data);
    strcpy(comp->hora, hora);
    strcpy(comp->nome, nome);
    comp->duracao = duracao;
    comp->adiavel = false;

    if (tipoCompromisso == 1) //nao pode ser adiado
    {
        comp->tipoCompromisso = AULA;
        comp->grauPrioridade = 2;
    }
    else if (tipoCompromisso == 2)
    {
        comp->tipoCompromisso = ORIENTACAO;
        comp->grauPrioridade = 1;
    }
    else if (tipoCompromisso == 3)
    {
        comp->tipoCompromisso = COMPROMISSO_PARTICULAR;
        comp->grauPrioridade = 2;
    }
    else if (tipoCompromisso == 4)
    {
        comp->tipoCompromisso = REUNIAO;
        comp->grauPrioridade = 4;
    }
    else if (tipoCompromisso == 5) //nao pode ser adiado
    {
        comp->tipoCompromisso = EVENTO;
        comp->grauPrioridade = 3;
    }
    else
    {
        return 0;
    }

    comp->prox = NULL;

    listaCompromisso = novoCompromisso = comp;
    return comp->id;
}

int inicializaCompromisso(int tipoCompromisso, char data[20], char hora[20], int duracao, char nome[100])
{
    if (listaCompromisso == NULL)
    {
        return criarLista(tipoCompromisso, data, hora, duracao, nome);
    }
    else
    {
        Compromisso *comp = (Compromisso *)malloc(sizeof(Compromisso));

        if (comp == NULL)
        {
            printf("\nFalha ao inicializar compromisso\n");
            return 0;
        }

        int id = (rand() % 100) + 1;

        comp->id = id;
        comp->numStatus = A_SER_CUMPRIDO;
        strcpy(comp->data, data);
        strcpy(comp->hora, hora);
        strcpy(comp->nome, nome);
        comp->duracao = duracao;
        comp->adiavel = false;

        if (tipoCompromisso == 1) //nao pode ser adiado
        {
            comp->tipoCompromisso = AULA;
            comp->grauPrioridade = 2;
        }
        else if (tipoCompromisso == 2)
        {
            comp->tipoCompromisso = ORIENTACAO;
            comp->grauPrioridade = 1;
        }
        else if (tipoCompromisso == 3)
        {
            comp->tipoCompromisso = COMPROMISSO_PARTICULAR;
            comp->grauPrioridade = 2;
        }
        else if (tipoCompromisso == 4)
        {
            comp->tipoCompromisso = REUNIAO;
            comp->grauPrioridade = 4;
        }
        else if (tipoCompromisso == 5) //nao pode ser adiado
        {
            comp->tipoCompromisso = EVENTO;
            comp->grauPrioridade = 3;
        }
        else
        {
            return 0;
        }

        comp->prox = NULL;

        novoCompromisso->prox = comp;
        novoCompromisso = comp;

        return comp->id;
    }
}

Compromisso *buscaElemento(int id, Compromisso **ant)
{
    if (listaCompromisso == NULL)
    {
        return NULL;
    }

    Compromisso *comp = listaCompromisso;
    Compromisso *aux_ant = NULL;
    int achou = 0;

    while (comp != NULL)
    {
        if (comp->id == id)
        {
            achou = 1;
            break;
        }

        aux_ant = comp;
        comp = comp->prox;
    }

    if (achou == 1)
    {
        if (ant != NULL)
        {
            *ant = aux_ant;
        }
        return comp;
    }

    return NULL;
}

int removerCompromisso(int index)
{
    Compromisso *ant = NULL;
    Compromisso *elem = buscaElemento(index, &ant);

    if (elem == NULL)
    {
        return 0;
    }

    if (ant != NULL)
    {
        ant->prox = elem->prox;
    }

    if (elem == novoCompromisso)
    {
        novoCompromisso = ant;
    }

    if (elem == listaCompromisso)
    {
        listaCompromisso = elem->prox;
    }

    free(elem);
    elem = NULL;

    return 1;
}

void imprimeCompromisso(int index)
{
    if (listaCompromisso == NULL)
    {
        printf("\nNao existem compromissos cadastradas\n");
    }
    else
    {
        Compromisso *comp = buscaElemento(index, NULL);

        if (comp != NULL)
        {
            char tipoCompromisso[30], adiavel[10], status[30];

            switch (comp->tipoCompromisso)
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

            switch (comp->adiavel)
            {
            case 1:
                strcpy(adiavel, "True");
                break;

            default:
                strcpy(adiavel, "False");
                break;
            }

            switch (comp->numStatus)
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

            printf("\nId: %d", comp->id);
            printf("\nTipo do compromisso: %s", tipoCompromisso);
            printf("\nData: %s", comp->data);
            printf("\nHora: %s", comp->hora);
            printf("\nDuracao: %d minutos", comp->duracao);
            printf("\nNome: %s", comp->nome);
            printf("\nAdiavel: %s", adiavel);
            printf("\nStatus: %s \n", status);
        }
        else
        {
            printf("\nCompromisso nao encontrado!\n");
        }
    }
}

void verificaConflito(int index1, int index2)
{
    if (listaCompromisso == NULL)
    {
        printf("\nNao existem compromissos cadastradas\n");
    }
    else
    {
        Compromisso *comp1 = buscaElemento(index1, NULL);
        Compromisso *comp2 = buscaElemento(index2, NULL);

        if (comp1 != NULL && comp2 != NULL)
        {
            if (strcmp(comp1->hora, comp2->hora) == 0)
            {
                printf("\nConflito entre os compromissos!\n");

                if (comp1->grauPrioridade > comp2->grauPrioridade)
                {
                    if (comp2->adiavel == true)
                    {
                        comp2->numStatus = ADIADO;
                        comp1->numStatus = A_SER_CUMPRIDO;
                        printf("\nConflito %d adiado!\n", index2);
                    }
                    else
                    {
                        comp2->numStatus = CANCELADO;
                        comp1->numStatus = A_SER_CUMPRIDO;
                        printf("\nConflito %d cancelado!\n", index2);
                    }
                }
                else if (comp2->grauPrioridade > comp1->grauPrioridade)
                {
                    if (comp1->adiavel == true)
                    {
                        comp1->numStatus = ADIADO;
                        comp2->numStatus = A_SER_CUMPRIDO;
                        printf("\nConflito %d adiado!\n", index1);
                    }
                    else
                    {
                        comp1->numStatus = CANCELADO;
                        comp2->numStatus = A_SER_CUMPRIDO;
                        printf("\nConflito %d cancelado!\n", index1);
                    }
                }
                else
                {
                    printf("\nNao foi possivel resolver conflitos!\n");
                }
            }
            else
            {
                printf("\nNao existe conflito entre os compromissos!\n");
            }
        }
        else
        {
            printf("\nCompromisso nao encontrado!\n");
        }
    }
}

void defineCompromissoAdiavel(int index, int flag)
{
    if (listaCompromisso == NULL)
    {
        printf("\nNao existem compromissos cadastradas\n");
    }
    else
    {
        Compromisso *comp = buscaElemento(index, NULL);

        if (comp != NULL)
        {
            int tipo = comp->tipoCompromisso;

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
                        comp->adiavel = true;
                        printf("\nCompromisso alterado!\n");
                    }
                    else if (flag == 2)
                    {
                        comp->adiavel = false;
                        printf("\nCompromisso alterado!\n");
                    }
                }
            }
        }
        else
        {
            printf("\nCompromisso nao encontrado!\n");
        }
    }
}

void alteraPrioridadeCompromisso(int index, int novaPrioridade)
{
    if (listaCompromisso == NULL)
    {
        printf("\nNao existem compromissos cadastradas\n");
    }
    else
    {
        Compromisso *comp = buscaElemento(index, NULL);

        if (comp != NULL)
        {
            if (novaPrioridade < 1 || novaPrioridade > 4)
            {
                printf("\nOpção inválida!");
            }
            else
            {
                comp->grauPrioridade = novaPrioridade;
            }
        }
        else
        {
            printf("\nCompromisso nao encontrado!\n");
        }
    }
}

void retornarPrioridadeCompromisso(int index)
{
    if (listaCompromisso == NULL)
    {
        printf("\nNao existem compromissos cadastradas\n");
    }
    else
    {
        Compromisso *comp = buscaElemento(index, NULL);

        if (comp != NULL)
        {
            printf("\nPrioridade: %d \n", comp->grauPrioridade);
        }
        else
        {
            printf("\nCompromisso nao encontrado!\n");
        }
    }
}

void alterarStatusCompromisso(int index, int novoStatus)
{
    if (listaCompromisso == NULL)
    {
        printf("\nNao existem compromissos cadastradas\n");
    }
    else
    {
        Compromisso *comp = buscaElemento(index, NULL);

        if (comp != NULL)
        {
            int tipo = comp->tipoCompromisso;

            if ((tipo == 2 && novoStatus == 2) || (tipo == 4 && novoStatus == 2))
            {
                printf("\nNao foi possivel alterar o status!");
            }
            else
            {
                switch (novoStatus)
                {
                case 1:
                    comp->numStatus = A_SER_CUMPRIDO;
                    printf("\nStatus alterado!");
                    break;
                case 2:
                    comp->numStatus = ADIADO;
                    printf("\nStatus alterado!");
                    break;
                case 3:
                    comp->numStatus = CANCELADO;
                    printf("\nStatus alterado!");
                    break;
                default:
                    printf("\nOpcao invalida!");
                    break;
                }
            }
        }
        else
        {
            printf("\nCompromisso nao encontrado!\n");
        }
    }
}

void retornarStatusCompromisso(int index)
{
    if (listaCompromisso == NULL)
    {
        printf("\nNao existem compromissos cadastradas\n");
    }
    else
    {
        Compromisso *comp = buscaElemento(index, NULL);

        if (comp != NULL)
        {
            char status[30];

            switch (comp->numStatus)
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
        else
        {
            printf("\nCompromisso nao encontrado!\n");
        }
    }
}