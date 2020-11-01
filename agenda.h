#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h>
#include <conio.h>
#include <string.h>

typedef struct agenda
{
    int id, idProf, ano, eventos;
    char nome[100];
    Compromisso *compromisso;
    struct agenda *prox;
} Agenda;

Agenda *listaAgenda = NULL, *novoAgenda = NULL;

int criarListaAgenda(int idProf, char nome[100], int ano)
{
    Agenda *age = (Agenda *)malloc(sizeof(Agenda));

    if (age == NULL)
    {
        printf("\nFalha ao inicializar agenda\n");
        return 0;
    }

    int id = (rand() % 100) + 1;

    age->id = id;
    age->idProf = idProf;
    age->ano = ano;
    age->eventos = 0;
    age->compromisso = NULL;
    strcpy(age->nome, nome);

    age->prox = NULL;

    listaAgenda = novoAgenda = age;
    return age->id;
}

int criarAgenda(int idProf, char nome[100], int ano)
{
    if (listaAgenda == NULL)
    {
        return criarListaAgenda(idProf, nome, ano);
    }

    Agenda *age = (Agenda *)malloc(sizeof(Agenda));

    if (age == NULL)
    {
        printf("\nFalha ao inicializar agenda\n");
        return 0;
    }

    int id = (rand() % 100) + 1;

    age->id = id;
    age->idProf = idProf;
    age->ano = ano;
    age->eventos = 0;
    age->compromisso = NULL;
    strcpy(age->nome, nome);

    age->prox = NULL;

    novoAgenda->prox = age;
    novoAgenda = age;

    return age->id;
}

Agenda *buscaElementoAgenda(int id, Agenda **ante)
{
    if (listaAgenda == NULL)
    {
        return NULL;
    }

    Agenda *age = listaAgenda;
    Agenda *aux_ante = NULL;
    int achou = 0;

    while (age != NULL)
    {
        if (age->id == id)
        {
            achou = 1;
            break;
        }

        aux_ante = age;
        age = age->prox;
    }

    if (achou == 1)
    {
        if (ante != NULL)
        {
            *ante = aux_ante;
        }
        return age;
    }

    return NULL;
}

void recuperarAgenda(int index, char data[20])
{
    if (listaAgenda == NULL)
    {
        printf("\nNao existem agendas cadastradas\n");
    }
    else
    {
        Agenda *age = buscaElementoAgenda(index, NULL);

        if (age != NULL)
        {
            printf("\nNome do professor: %s", listaAgenda->nome);
            printf("\nAno da agenda: %d", listaAgenda->ano);
            printf("\nNumero de compromissos no ano a partir de %s: %d\n", data, listaAgenda->eventos);
        }
        else
        {
            printf("\nAgenda nao encontrada!\n");
        }
    }
}

void inserirCompromissoNaAgenda(int index, int tipoCompromisso, char data[20], char hora[20], int duracao, char nome[100])
{
    if (listaAgenda == NULL)
    {
        printf("\nNao existem agendas cadastradas\n");
    }
    else
    {
        Agenda *age = buscaElementoAgenda(index, NULL);

        if (age != NULL)
        {
            int idCompromisso = inicializaCompromisso(tipoCompromisso, data, hora, duracao, nome);
            age->eventos++;

            printf("Compromisso inserido na agenda!\n");
            printf("Id do compromisso: %d \n", idCompromisso);
        }
        else
        {
            printf("\nAgenda nao encontrada!\n");
        }
    }
}

void removerCompromissoDaAgenda(int index, int idCompromisso)
{
    if (listaAgenda == NULL)
    {
        printf("\nNao existem agendas cadastradas\n");
    }
    else
    {
        Agenda *age = buscaElementoAgenda(index, NULL);

        if (age != NULL)
        {
            int retorno = removerCompromisso(idCompromisso);

            if (retorno == 0)
            {
                printf("\nCompromisso nao encontrado!\n");
            }
            else
            {
                printf("\nCompromisso excluido!\n");
            }
        }
        else
        {
            printf("\nAgenda nao encontrada!\n");
        }
    }
}

void imprimeCompromissosDaAgenda()
{
    if (listaAgenda == NULL)
    {
        printf("\nNao existem agendas cadastradas\n");
    }
    else
    {
        Compromisso *auxiliar = listaCompromisso;

        while (auxiliar != NULL)
        {
            printf("\nNome do compromisso: %s", auxiliar->nome);
            printf("\nPrioridade do compromisso: %d", auxiliar->grauPrioridade);

            char status[20];

            switch (auxiliar->numStatus)
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

            printf("\nStatus do compromisso: %s\n", status);

            auxiliar = auxiliar->prox;
        }
    }
}

void imprimeAgenda(int index)
{
    if (listaAgenda == NULL)
    {
        printf("\nNao existem agendas cadastradas\n");
    }
    else
    {
        Agenda *age = buscaElementoAgenda(index, NULL);

        if (age != NULL)
        {
            imprimeCompromissosDaAgenda();

            printf("\nAgenda encontrada!\n");
        }
        else
        {
            printf("\nAgenda nao encontrada!\n");
        }
    }
}

void resolveConflitoAgenda(int index)
{
    if (listaAgenda == NULL)
    {
        printf("\nNao existem agendas cadastradas\n");
    }
    else
    {
        Agenda *age = buscaElementoAgenda(index, NULL);

        if (age != NULL)
        {
            Compromisso *aux = listaCompromisso;

            while (aux != NULL)
            {
                if (aux->prox != NULL)
                {
                    if (strcmp(aux->hora, aux->prox->hora) == 0)
                    {
                        if (aux->grauPrioridade > aux->prox->grauPrioridade)
                        {
                            aux->numStatus = ADIADO;
                            aux->prox->numStatus = CANCELADO;

                            printf("\nConflito resolvido!\n");
                        }
                        else if (aux->grauPrioridade < aux->prox->grauPrioridade)
                        {
                            aux->numStatus = CANCELADO;
                            aux->prox->numStatus = ADIADO;

                            printf("\nConflito resolvido!\n");
                        }
                    }
                    else
                    {
                        printf("\nProximo conflito!\n");
                    }
                }
                else
                {
                    printf("\nTodos os conflitos foram resolvidos!\n");
                }

                aux = aux->prox;
            }
        }
        else
        {
            printf("\nAgenda nao encontrada!\n");
        }
    }
}

void retornaAdiantamentos(int index)
{
    if (listaAgenda == NULL)
    {
        printf("\nNao existem agendas cadastradas\n");
    }
    else
    {
        Agenda *age = buscaElementoAgenda(index, NULL);

        if (age != NULL)
        {
            Compromisso *aux = listaCompromisso;
            int count = 0;

            while (aux != NULL)
            {
                if (aux->numStatus == 2)
                {
                    count++;
                }
                aux = aux->prox;
            }
            printf("\nNumero: %d\n", count);
        }
        else
        {
            printf("\nAgenda nao encontrada!\n");
        }
    }
}

void retornaCancelados(int index)
{
    if (listaAgenda == NULL)
    {
        printf("\nNao existem agendas cadastradas\n");
    }
    else
    {
        Agenda *age = buscaElementoAgenda(index, NULL);

        if (age != NULL)
        {
            Compromisso *aux = listaCompromisso;
            int count = 0;

            while (aux != NULL)
            {
                if (aux->numStatus == 3)
                {
                    count++;
                }
                aux = aux->prox;
            }
            printf("\nNumero: %d\n", count);
        }
        else
        {
            printf("\nAgenda nao encontrada!\n");
        }
    }
}

void retornaNumeroTotal(int index)
{
    if (listaAgenda == NULL)
    {
        printf("\nNao existem agendas cadastradas\n");
    }
    else
    {
        Agenda *age = buscaElementoAgenda(index, NULL);

        if (age != NULL)
        {
            Compromisso *aux = listaCompromisso;
            int count = 0;

            while (aux != NULL)
            {
                count++;
                aux = aux->prox;
            }
            printf("\nNumero: %d\n", count);
        }
        else
        {
            printf("\nAgenda nao encontrada!\n");
        }
    }
}

void imprimeCompromissosAdiados(int index)
{
    if (listaAgenda == NULL)
    {
        printf("\nNao existem agendas cadastradas\n");
    }
    else
    {
        Agenda *age = buscaElementoAgenda(index, NULL);

        if (age != NULL)
        {
            Compromisso *aux = listaCompromisso;

            while (aux != NULL)
            {
                if (aux->numStatus == 2)
                {
                    printf("\nCompromisso: %s\n", aux->nome);
                }
                aux = aux->prox;
            }
        }
        else
        {
            printf("\nAgenda nao encontrada!\n");
        }
    }
}

void imprimeCompromissosCancelados(int index)
{
    if (listaAgenda == NULL)
    {
        printf("\nNao existem agendas cadastradas\n");
    }
    else
    {
        Agenda *age = buscaElementoAgenda(index, NULL);

        if (age != NULL)
        {
            Compromisso *aux = listaCompromisso;

            while (aux != NULL)
            {
                if (aux->numStatus == 3)
                {
                    printf("\nCompromisso: %s\n", aux->nome);
                }
                aux = aux->prox;
            }
        }
        else
        {
            printf("\nAgenda nao encontrada!\n");
        }
    }
}

void imprimeCompromissosACumprir(int index)
{
    if (listaAgenda == NULL)
    {
        printf("\nNao existem agendas cadastradas\n");
    }
    else
    {
        Agenda *age = buscaElementoAgenda(index, NULL);

        if (age != NULL)
        {
            Compromisso *aux = listaCompromisso;

            while (aux != NULL)
            {
                if (aux->numStatus == 1)
                {
                    printf("\nCompromisso: %s\n", aux->nome);
                }
                aux = aux->prox;
            }
        }
        else
        {
            printf("\nAgenda nao encontrada!\n");
        }
    }
}