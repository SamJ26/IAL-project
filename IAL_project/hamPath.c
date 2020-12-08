/* hamPath.c
 * Predmet: Algoritmy (IAL) - FIT VUT v Brne
 * Autor: Marek Bahník
 * Popis: Zdrojový kód pre hamPath.h (knižnica na hladanie hamiltonovej cesty)
 * Vytvoril: Marek Bahník, 7.12.2020
 * Upravil: Samuel Janek, 8.12.2020
 */

#include "hamPath.h"
#include "check.h"

/// <summary>
/// Function prepares array for storing the path and calls process_vertex function to fill this array
/// </summary>
/// <param name="graph"> - graph structure </param>
/// <param name="start"> - starting vertex </param>
/// <param name="end"> - last vertex of the path</param>
void FindPath(Graph* graph, int start, int end)
{
	int* processed = (int*)malloc(4);
	*processed = 0;
	int vert_count = graph->iVertices;
	int* path_arr = (int*)malloc(vert_count * sizeof(int));
	memset(path_arr, -1, sizeof * path_arr);

	process_vertex(graph, start, path_arr, vert_count, processed, end);

	free(path_arr);
	free(processed);
}

/// <summary>
/// Function checks if the vertex was already visited
/// </summary>
/// <param name="arr"> - array for storing the path </param>
/// <param name="neighbor"> - actually tested vertex </param>
/// <param name="no_verts"> - number of vertices in graph </param>
/// <returns> Returns true if vertex was already visited </returns>
bool is_done(int* arr, int neighbor, int no_verts)
{
	for(int j = 0; j < no_verts; j++) {
		if(arr[j] == neighbor) {
			return true;
		}
	}
	return false;
}

/// <summary>
/// Function for printing out the hamiltonian path
/// </summary>
/// <param name="arr"> - array for storing the path </param>
/// <param name="vert_count"> - number of vertices in graph </param>
void printPath(int* arr, int vert_count)
{
	printf("Found hamiltonian path:\n");
	printf("%d", arr[0]);
	for(int j = 1; j < vert_count; j++) {
		printf("->%d", arr[j]);
	}
	printf("\n\n");
}

/// <summary>
/// This function searches all adjecent vertices with backtracking algorithm
/// </summary>
/// <param name="graph"> - graph structure </param>
/// <param name="vert"> - starting vertex </param>
/// <param name="path_arr"> - array for storing of found path </param>
/// <param name="vert_count"> - number of vertices in graph </param>
/// <param name="processed"> - number of processed vertices </param>
/// <param name="end"> - last vertex of the path </param>
void process_vertex(Graph* graph, int vert, int* path_arr, int vert_count, int* processed, int end)
{
	int* loc_path_arr = (int*)malloc(vert_count * sizeof(int));
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

	for(int neighbor = 0; neighbor < graph->iVertices; neighbor++) {

		if(graph->iGraph[neighbor][vert] == 1) {

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
				process_vertex(graph, neighbor, loc_path_arr, vert_count, &loc_processed, end);
			}
		}
	}
	free(loc_path_arr);
}