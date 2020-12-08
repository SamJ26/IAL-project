#include "hamPath.h"
#include "check.h"

void FindPath(Graph* aGraph, int start, int end)
{
	int* processed = malloc(4);
	*processed = 0;
	int* path_arr;
	int vert_count = aGraph->iVertices;
	path_arr = malloc(vert_count * sizeof(int));
	memset(path_arr, -1, sizeof * path_arr);

	process_vertex(aGraph, start, path_arr, vert_count, processed, end);

	free(path_arr);
	free(processed);
}

//kontroluje jestli je vrchol jiz navstiveny
bool is_done(int* arr, int neighbor, int no_verts)
{
	for(int j = 0; j < no_verts; j++) {
		if(arr[j] == neighbor) {
			return true;
		}
	}

	return false;
}

//tiskne stav pruchodu grafu
void printPath(int* arr, int vert_count)
{
	printf("Current path\n");
	for(int j = 0; j < vert_count; j++)
	{
		printf("%d  ", arr[j]);
	}
	printf("\n");
}

//prohledava vsechny sousedy vrcholu
void process_vertex(Graph* aGraph, int vert, int* path_arr, int vert_count, int* processed, int end)
{
	int* loc_path_arr = malloc(vert_count * sizeof(int));
	memcpy(loc_path_arr, path_arr, vert_count * sizeof(*path_arr));
	int loc_processed = *processed;

	loc_path_arr[loc_processed] = vert;
	loc_processed++;

	if(vert == end) {
		if(loc_processed == vert_count) {
			free(loc_path_arr);
			return;
		}
	}

	for(int neighbor = 0; neighbor < aGraph->iVertices; neighbor++) {

		if(aGraph->iGraph[neighbor][vert] == 1) {

			if(neighbor == end) {

				if(loc_processed == vert_count - 1) {
					loc_path_arr[loc_processed] = neighbor;
					memcpy(path_arr, loc_path_arr, vert_count * sizeof(*path_arr));
					printPath(path_arr, vert_count);
					free(loc_path_arr);
					return;
				}
				else {
					loc_path_arr[loc_processed] = -1;
					continue;
				}
			}

			if(is_done(loc_path_arr, neighbor, vert_count)) {
				continue;
			}
			else {
				process_vertex(aGraph, neighbor, loc_path_arr, vert_count, &loc_processed, end);
			}
		}
	}
	free(loc_path_arr);
}