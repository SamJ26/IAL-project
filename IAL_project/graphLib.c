/* graphLib.c
 * Predmet: Algoritmy (IAL) - FIT VUT v Brne
 * Autor: Samuel Janek
 * Popis: Zdrojový kód pre graphLib.h (knižnica na načítvanie grafov z textových súborov)
 * Vytvoril: Samuel Janek, 1.12.2020
 * Upravil: Marek Bahník, 5.12.2020
 */

#include "graphLib.h"
#include "check.h"

/// <summary>
/// Function for loading graph from text file
/// </summary>
/// <param name="aFileName"> - string representing name of file </param>
/// <param name="aGraph"> - graph structure </param>
void LoadGraph(char* aFileName, Graph* aGraph)
{
	if(!aFileName || !aGraph)
		exit(1);
	FILE* file = fopen(aFileName, "r");
	if(!file)
		exit(1);
	aGraph->iVertices = VerticesCount(file);
	aGraph->iGraph = AllocMemory(aGraph->iVertices);
	char ch = 0;
	rewind(file);
	for(size_t i = 0; i < aGraph->iVertices; i++)
	{
		ch = fgetc(file);
		ch = fgetc(file);
		ch = fgetc(file);
		while(ch != '\n')
		{
			if(ch != ',')
			{
				size_t num = ch - 48;
				aGraph->iGraph[i][num] = 1;
			}
			ch = fgetc(file);
		}
	}
	fclose(file);
}

/// <summary>
/// Function which returns number of lines in text file.
/// Number of lines is equal to number of vertices in graph.
/// </summary>
/// <param name="aFile"> - pointer to opened file </param>
/// <returns> Returns number of vertices of graph loaded from text file </returns>
size_t VerticesCount(FILE* aFile)
{
	if(!aFile)
		exit(1);
	char ch = 0;
	size_t vertices = 0;
	while(!feof(aFile))
	{
		ch = fgetc(aFile);
		if(ch == '\n')
			vertices++;
	}
	return vertices;
}

/// <summary>
/// Function which allocates memory for graph
/// Graph is stored as 2D array and dimensions of array are equal to number of vertices
/// </summary>
/// <param name="aVertices"> - number of vertices in graph </param>
/// <returns> Returns pointer to allocated memory (2D array) </returns>
bool** AllocMemory(size_t aVertices)
{
	bool** graph = (bool**)calloc(aVertices, sizeof(bool*));
	if(!graph)
		exit(1);
	for(size_t i = 0; i < aVertices; i++)
	{
		graph[i] = (bool*)calloc(aVertices, sizeof(bool));
		if(!graph[i])
			exit(1);
	}
	return graph;
}

/// <summary>
/// Function for deallocation of memory
/// </summary>
/// <param name="aGraph"> - graph structure </param>
void DeallocMemory(Graph* aGraph)
{
	if(!aGraph || !aGraph->iGraph)
		exit(1);
	for(size_t i = 0; i < aGraph->iVertices; i++)
		free(aGraph->iGraph[i]);
	free(aGraph->iGraph);
}

/// <summary>
/// Function prints graph as adjacency matrix
/// </summary>
/// <param name="aGraph"> - graph structure </param>
void PrintGraph(Graph* aGraph)
{
	if(!aGraph || !aGraph->iGraph)
		exit(1);
	for(size_t i = 0; i < aGraph->iVertices; i++)
	{
		for(size_t j = 0; j < aGraph->iVertices; j++)
			printf("%d ", aGraph->iGraph[i][j]);
		printf("\n");
	}
	printf("\n");
}