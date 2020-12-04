#include <stdio.h>
#include <stdbool.h>
#include "graphLib.h"
#include "check.h"
#include "cycle.h"


int main(int argc, char** argv)
{
	Graph graph01 = { .iGraph = NULL, .iVertices = 0, };
	Graph graph02 = { .iGraph = NULL, .iVertices = 0, };

	LoadGraph("graph01.txt", &graph01);
	LoadGraph("graph02.txt", &graph02);

	PrintGraph(&graph01);
    hamiltonianCycle(&graph01);
    
    
	PrintGraph(&graph02);
    hamiltonianCycle(&graph02);

    
    
	DeallocMemory(&graph01);
	DeallocMemory(&graph02);

	return 0;
}
