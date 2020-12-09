/* cycle.h
 * Predmet: Algoritmy (IAL) - FIT VUT v Brne
 * Autor: Samuel Líška
 * Popis: Hlavičkový súbor pre cycle.c (knižnica na hladanie hamiltonovych cyklov)
 * Vytvoril: Samuel Líška, 1.12.2020
 * Upravil: Samuel Janek, 8.12.2020
 */

#ifndef _CYCLE_H_
#define _CYCLE_H_

#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "graphLib.h"

void hamiltonian(Graph* graph,int k, int n, int* x);
void nextVertex(Graph* graph,int k, int n, int* x);
void hamiltonianCycle(Graph* graph);

#endif
