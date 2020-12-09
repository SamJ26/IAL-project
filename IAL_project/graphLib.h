/* graphLib.h
 * Predmet: Algoritmy (IAL) - FIT VUT v Brne
 * Autor: Samuel Janek
 * Popis: Hlavičkový súbor pre graphLib.c (knižnica na načítvanie grafov z textových súborov)
 * Vytvoril: Samuel Janek, 1.12.2020
 */

#ifndef _GRAPHLIB_H_
#define _GRAPHLIB_H_

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct TGraph
{
	bool** iGraph;
	int iVertices;
} Graph;

void LoadGraph(char* aFileName, Graph* aGraph);
int VerticesCount(FILE* aFile);
bool** AllocMemory(int vertices);
void DeallocMemory(Graph* aGraph);
void PrintGraph(Graph* aGraph);

#endif