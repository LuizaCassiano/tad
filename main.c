#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>

#include "compromisso.h"
#include "agenda.h"

int main()
{
    menuPrincipal();
    return 0;
}

void menuImprimeCompromissosACumprir()
{
    int id;

    printf("\nA. DIGITE O ID DA AGENDA: ");
    scanf("%d", &id);

    imprimeCompromissosACumprir(id);
}

void menuImprimeCompromissosCancelados()
{
    int id;

    printf("\nA. DIGITE O ID DA AGENDA: ");
    scanf("%d", &id);

    imprimeCompromissosCancelados(id);
}

void menuImprimeCompromissosAdiados()
{
    int id;

    printf("\nA. DIGITE O ID DA AGENDA: ");
    scanf("%d", &id);

    imprimeCompromissosAdiados(id);
}

void menuRetornaNumeroTotal()
{
    int id;

    printf("\nA. DIGITE O ID DA AGENDA: ");
    scanf("%d", &id);

    retornaNumeroTotal(id);
}

void menuRetornaNumeroCancelados()
{
    int id;

    printf("\nA. DIGITE O ID DA AGENDA: ");
    scanf("%d", &id);

    retornaAdiantamentos(id);
}

void menuRetornaNumeroAdiantamentos()
{
    int id;

    printf("\nA. DIGITE O ID DA AGENDA: ");
    scanf("%d", &id);

    retornaAdiantamentos(id);
}

void menuResolverConflitoNaAgenda()
{
    int id;

    printf("\nA. DIGITE O ID DA AGENDA: ");
    scanf("%d", &id);

    resolveConflitoAgenda(id);
}

void menuImprimirAgenda()
{
    int id;

    printf("\nA. DIGITE O ID DA AGENDA: ");
    scanf("%d", &id);

    imprimeAgenda(id);
}

void menuRemoverCompromisso()
{
    int id, idComp;

    printf("\nA. DIGITE O ID DA AGENDA: ");
    scanf("%d", &id);

    printf("B. DIGITE O ID DO COMPROMISSO: ");
    scanf("%d", &idComp);

    removerCompromissoDaAgenda(id, idComp);
}

void menuInserirCompromissoNaAgenda()
{
    int id, tipoCompromisso, duracao;
    char data[20], hora[20], nome[100];

    printf("\nA. Digite o id da agenda: ");
    scanf("%d", &id);

    printf("B. Escolha abaixo o tipo de compromisso\n");

    printf("\nOPCOES: ");
    printf("\n1. Aula");
    printf("\n2. Orientacao");
    printf("\n3. Compromisso Particular");
    printf("\n4. Reuniao");
    printf("\n5. Evento");
    printf("\n6. Para sair");
    printf("\nDIGITE O COMPROMISSO DESEJADO: ");
    scanf("%d", &tipoCompromisso);

    if (tipoCompromisso >= 1 && tipoCompromisso <= 5)
    {
        printf("\nA. Informe a data no formato (dd/MM/yyyy):");
        scanf("%s", &data);

        printf("B. Informe a hora no formato (xx:xx):");
        scanf("%s", &hora);

        printf("C. Informe a duracao do compromisso em minutos:");
        scanf("%d", &duracao);

        printf("D. Informe o nome do compromisso:");
        scanf("%s", &nome);

        inserirCompromissoNaAgenda(id, tipoCompromisso, data, hora, duracao, nome);
    }
}

void menuRecuperaAgenda()
{
    int id;
    char data[20];

    printf("\nA. DIGITE O ID DA AGENDA: ");
    scanf("%d", &id);

    printf("B. DIGITE UMA DATA NO FORMATO (dd/MM/yyyy): ");
    scanf("%s", &data);

    recuperarAgenda(id, data);
}

void menuCriaAgenda()
{
    int idProf, ano;
    char nome[100];

    printf("\nA. DIGITE O ID DO PROFESSOR: ");
    scanf("%d", &idProf);

    printf("B. DIGITE O NOME DO PROFESSOR: ");
    scanf("%s", &nome);

    printf("C. DIGITE O ANO DA AGENDA NO FORMATO (yyyy): ");
    scanf("%d", &ano);

    int id = criarAgenda(idProf, nome, ano);

    if (id != 0)
    {
        printf("\nAgenda criada!\n");
        printf("Id: %d \n", id);
    }
    else
    {
        printf("Falha ao criar agenda!\n");
    }
}

void menuAgenda()
{
    int opcao;

    do
    {
        printf("\nOPCOES: ");
        printf("\n1. Criar agenda");
        printf("\n2. Recuperar agenda");
        printf("\n3. Inserir compromisso");
        printf("\n4. Remover compromisso");
        printf("\n5. Imprimir agenda");
        printf("\n6. Resolver conflito");
        printf("\n7. Retornar numero de adiantamentos");
        printf("\n8. Retornar numero de cancelamentos");
        printf("\n9. Retornar numero de compromissos");
        printf("\n10. Imprime compromissos adiados");
        printf("\n11. Imprime compromissos cancelados");
        printf("\n12. Imprime compromissos a cumprir");
        printf("\n13. Para sair");
        printf("\nDIGITE A OPCAO DESEJADA: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            menuCriaAgenda();
            break;
        case 2:
            menuRecuperaAgenda();
            break;
        case 3:
            menuInserirCompromissoNaAgenda();
            break;
        case 4:
            menuRemoverCompromisso();
            break;
        case 5:
            menuImprimirAgenda();
            break;
        case 6:
            menuResolverConflitoNaAgenda();
            break;
        case 7:
            menuRetornaNumeroAdiantamentos();
            break;
        case 8:
            menuRetornaNumeroCancelados();
            break;
        case 9:
            menuRetornaNumeroTotal();
            break;
        case 10:
            menuImprimeCompromissosAdiados();
            break;
        case 11:
            menuImprimeCompromissosCancelados();
            break;
        case 12:
            menuImprimeCompromissosACumprir();
            break;
        default:
            break;
        }
    } while (opcao != 13 || (opcao >= 1 && opcao <= 12));
}

void menuImprimeDadosCompromisso()
{
    int id;

    printf("DIGITE O ID DO COMPROMISSO DESEJADO: ");
    scanf("%d", &id);

    imprimeCompromisso(id);
}

void menuRetornarStatusCompromisso()
{
    int id;

    printf("DIGITE O ID DO COMPROMISSO DESEJADO: ");
    scanf("%d", &id);

    retornarStatusCompromisso(id);
}

void menuDefinirStatusCompromisso()
{
    int id, status;

    printf("DIGITE O ID DO COMPROMISSO DESEJADO: ");
    scanf("%d", &id);

    printf("DIGITE O NOVO STATUS DO COMPROMISSO (1. A_SER_CUMPRIDO, 2. ADIADO, 3. CANCELADO): ");
    scanf("%d", &status);

    alterarStatusCompromisso(id, status);
}

void menuConflitoNaAgenda()
{
    int id1, id2;

    printf("DIGITE O ID DO PRIMEIRO COMPROMISSO DESEJADO: ");
    scanf("%d", &id1);

    printf("DIGITE O ID DO SEGUNDO COMPROMISSO DESEJADO: ");
    scanf("%d", &id2);

    verificaConflito(id1, id2);
}

void menuDefineCompromissoAdiavel()
{
    int id, flag;

    printf("DIGITE O ID DO COMPROMISSO DESEJADO: ");
    scanf("%d", &id);
    printf("DIGITE 1 PARA TRUE E 2 PARA FALSE: ");
    scanf("%d", &flag);

    defineCompromissoAdiavel(id, flag);
}

void menuRetornaPrioridade()
{
    int id;

    printf("DIGITE O ID DO COMPROMISSO DESEJADO: ");
    scanf("%d", &id);

    retornarPrioridadeCompromisso(id);
}

void menuAlteraPrioridade()
{
    int id, novaPrioridade;

    printf("DIGITE O ID DO COMPROMISSO DESEJADO: ");
    scanf("%d", &id);
    printf("DIGITE A NOVA PRIORIDADE (1, 2, 3 ou 4): ");
    scanf("%d", &novaPrioridade);

    alteraPrioridadeCompromisso(id, novaPrioridade);
}

void menuIniciaCompromisso()
{
    int compromisso, duracao;
    char data[20], hora[20], nome[100];

    do
    {
        printf("\nOPCOES: ");
        printf("\n1. Aula");
        printf("\n2. Orientacao");
        printf("\n3. Compromisso Particular");
        printf("\n4. Reuniao");
        printf("\n5. Evento");
        printf("\n6. Para sair");
        printf("\nDIGITE O COMPROMISSO DESEJADO: ");
        scanf("%d", &compromisso);

        if (compromisso >= 1 && compromisso <= 5)
        {
            printf("\nA. Informe a data no formato (dd/MM/yyyy):");
            scanf("%s", &data);

            printf("B. Informe a hora no formato (xx:xx):");
            scanf("%s", &hora);

            printf("C. Informe a duracao do compromisso em minutos:");
            scanf("%d", &duracao);

            printf("D. Informe o nome do compromisso:");
            scanf("%s", &nome);

            int id = inicializaCompromisso(compromisso, data, hora, duracao, nome);

            printf("Id: %d \n", id);
        }

    } while (compromisso != 6 || (compromisso >= 1 && compromisso <= 5));
}

void menuCompromisso()
{
    int opcao;

    do
    {
        printf("\nOPCOES: ");
        printf("\n1. Inicializar um compromisso");
        printf("\n2. Alterar prioridade de um compromisso");
        printf("\n3. Retornar prioridade de um compromisso");
        printf("\n4. Definir se um compromisso e adiavel");
        printf("\n5. Verificar se existe conflitos na agenda");
        printf("\n6. Definir status de um compromisso");
        printf("\n7. Retornar status de um compromisso");
        printf("\n8. Imprimir dados de um compromisso");
        printf("\n9. Para sair");
        printf("\nDIGITE A OPCAO DESEJADA: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            menuIniciaCompromisso();
            break;
        case 2:
            menuAlteraPrioridade();
            break;
        case 3:
            menuRetornaPrioridade();
            break;
        case 4:
            menuDefineCompromissoAdiavel();
            break;
        case 5:
            menuConflitoNaAgenda();
            break;
        case 6:
            menuDefinirStatusCompromisso();
            break;
        case 7:
            menuRetornarStatusCompromisso();
            break;
        case 8:
            menuImprimeDadosCompromisso();
            break;
        default:
            break;
        }
    } while (opcao != 9 || (opcao >= 1 && opcao <= 8));
}

void menuPrincipal()
{
    int opcao;

    do
    {
        printf("\nOPCOES: ");
        printf("\n1. Inicializar e manipular compromissos");
        printf("\n2. Inicializar e manipular agendas");
        printf("\n3. Para sair");
        printf("\nDIGITE A OPCAO DESEJADA: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            menuCompromisso();
            break;
        case 2:
            menuAgenda();
            break;
        default:
            break;
        }
    } while (opcao != 3 || (opcao >= 1 && opcao <= 2));
}