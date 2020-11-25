#include <stdio.h>
#include <stdbool.h>
#include "graphLib.h"
#include "check.h"


int main(int argc, char** argv)
{
	bool** graph01 = NULL;
	graph01 = LoadGraph("graph01.txt");
	PrintGraph(graph01, 5);
	DeallocMemory(graph01, 5);
	return 0;
}