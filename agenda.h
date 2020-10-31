#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h>
#include <conio.h>

typedef struct agenda
{
    int id;
    char nome[100];
    int ano;
    int qtdEvento;
} Agenda[100];

Agenda agenda[101];
