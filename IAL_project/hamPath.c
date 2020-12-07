#include "hamPath.h"
#include "check.h"


void FindPath(Graph* aGraph, int start, int end)
{
	int* processed = malloc(4);
	*processed = 0;
	int* arr_ptr;
	int vert_count = aGraph->iVertices;
	arr_ptr = malloc(vert_count * sizeof(int));
	memset(arr_ptr, -1, sizeof arr_ptr);

	process_vertex(aGraph, start, arr_ptr, vert_count, processed, end);

	printf("Path from %d to %d:\n", start, end);
	for (int j = 0; j < vert_count; j++)
	{
		printf("%d  ", arr_ptr[j]);
	}
	printf("\n");
	
	free(arr_ptr);
	free(processed);
}

//pokud vertex už prozkoumán
bool is_done(int* arr, int i, int no_verts)
{
	for (int j = 0; j < no_verts; j++)
	{
		if (arr[j] == i)
		{
			return true;
		}
	}
	return false;
}

//prohledáváni vertexu
void process_vertex(Graph* aGraph, int vert, int* arr_ptr, int vert_count, int* processed, int end)
{
	//pro každý soused vrcholu 'vert' do:
	for (int i = 0; i < aGraph->iVertices; i++)
	{
		//pokud má hranu s jiným vrcholem
		if (aGraph->iGraph[i][vert] == 1)
		{
			//pokud se jedná o hledaný vrchol, return
			// pro nalezení všech øešení asi bude continue a navázání na ostatní vìtve
			//TBD
			if (vert == end) 
			{
				arr_ptr[*processed] = vert;
				return;
			}

			//testovaci vypis
			//printf("Processing vertex %d\n", vert);

			//pokud onen vrchol je již navštíven, skip
			if (is_done(arr_ptr, i, vert_count))
			{
				//testovaci vypis
				//printf("%d already searched\n", i);
				continue;
			}
			else
			//pøidat vrchol do pole prohledaných, inkrementovat poèet zpracovaných a spustit prohledávání dalšího vrcholu
			{
				arr_ptr[*processed] = vert;
				(*processed)++;
				//testovaci vypis
				//printf("Vertex %d processed, continuing to vertex %d. Processed: %d\n", vert, i, *processed);
				process_vertex(aGraph, i, arr_ptr, vert_count, processed, end);
			}
		}
	}
}