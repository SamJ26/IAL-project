/* main.c
 * Predmet: Algoritmy (IAL) - FIT VUT v Brne
 * Popis: Vstupný bod programu (tu sú testované vytvorené knižnice)
 */

#include <stdio.h>
#include <stdbool.h>
#include "graphLib.h"
#include "hamPath.h"
#include "cycle.h"
#include "check.h"


int main(int argc, char** argv)
{
	Graph graph01 = { .iGraph = NULL, .iVertices = 0, };
	Graph graph02 = { .iGraph = NULL, .iVertices = 0, };
	Graph graph03 = { .iGraph = NULL, .iVertices = 0, };
	Graph graph04 = { .iGraph = NULL, .iVertices = 0, };

	LoadGraph("graph01.txt", &graph01);
	LoadGraph("graph02.txt", &graph02);
	LoadGraph("graph03.txt", &graph03);
	LoadGraph("graph04.txt", &graph04);

	printf("----- graph01 -----\n\n");
	PrintGraph(&graph01);
    hamiltonianCycle(&graph01);
	FindPath(&graph01, 0, 4);
      
	printf("----- graph02 -----\n\n");
	PrintGraph(&graph02);
    hamiltonianCycle(&graph02);
	FindPath(&graph02, 1, 2);

	printf("----- graph03 -----\n\n");
	PrintGraph(&graph03);
	hamiltonianCycle(&graph03);
	FindPath(&graph03, 3, 0);

	printf("----- graph04 -----\n\n");
	PrintGraph(&graph04);
	hamiltonianCycle(&graph04);
	FindPath(&graph04, 0, 2);
     
	DeallocMemory(&graph01);
	DeallocMemory(&graph02);
	DeallocMemory(&graph03);
	DeallocMemory(&graph04);

	return 0;
}
