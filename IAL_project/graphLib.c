#include "graphLib.h"
#include "check.h"

/* -----
** Function for loading graph from text file
** aFileName - string representing name of file
** aGraph - structure 
**/
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
		fseek(file, 2, SEEK_CUR);
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

/* -----
** Function which returns number of lines in text file.
** Number of lines is equal to number of vertices in graph.
** aFile - pointer to opened file
**/
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

/* -----
** Function which allocates memory for graph
** Graph is stored as 2D array
** Dimensions of array are equal to number of vertices
** aVertices - number of vertices in graph 
**/
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

/* -----
** Function for deallocation of memory
** aGraph - structure
**/
void DeallocMemory(Graph* aGraph)
{
	if(!aGraph || !aGraph->iGraph)
		exit(1);
	for(size_t i = 0; i < aGraph->iVertices; i++)
		free(aGraph->iGraph[i]);
	free(aGraph->iGraph);
}

/* -----
** Function prints graph as adjacency matrix
** aGraph - structure
**/
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