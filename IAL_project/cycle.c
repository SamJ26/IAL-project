/* cycle.c
 * Predmet: Algoritmy (IAL) - FIT VUT v Brne
 * Autor: Samuel Líška
 * Popis: Zdrojový kód pre cycle.h (knižnica na hladanie hamiltonovych cyklov)
 * Vytvoril: Samuel Líška, 1.12.2020
 * Upravil: Samuel Janek, 8.12.2020
 */

#include "cycle.h"
#include "check.h"

/// <summary>
/// Function that initializes answer array 'x'
/// and after that calls function hamiltonian.
/// </summary>
/// <param name="graph"> - graph structure </param>
void hamiltonianCycle(Graph* graph)
{
	int* x = (int*)calloc(graph->iVertices, sizeof(int));
	if(x == NULL)
		exit(1);
	hamiltonian(graph, 1, graph->iVertices, x);
	free(x);
	return;
}

/// <summary>
/// This function uses backtracking algorithm to find all possible hamiltonian cycles, within given graph.
/// </summary>
/// <param name="graph"> - graph structure </param>
/// <param name="k"> - position is answer array </param>
/// <param name="n"> - number of vertices </param>
/// <param name="x"> - answer array </param>
void hamiltonian(Graph* graph, int k, int n, int* x)
{
	while(true) {
		nextVertex(graph, k, n, x);
		if(x[k] == 0)
			return;
		if(k == n - 1) {
			printf("Found Hamiltonian cycle:\n");
			for(int i = 0; i < n; i++)
				printf("%d->", x[i]);
			printf("%d", x[0]);
			printf("\n\n");
		}
		else {
			hamiltonian(graph, k + 1, n, x);
		}
	}
}

/// <summary>
/// Function that checks validity of next vertex.
/// First it checks for duplicates in array(previous positions).
/// After finding new value that doesn't appear in 'x' array it checks in adjacency for an edge.
/// Complexity: n!= O(n ^ n)
/// </summary>
/// <param name="graph"> - graph structure </param>
/// <param name="k"> - position on answer array </param>
/// <param name="n"> - number of vertices </param>
/// <param name="x"> - answer array </param>
void nextVertex(Graph* graph, int k, int n, int* x)
{
	while(true) {
		/* counting next value */
		x[k] = (x[k] + 1) % (n);
		if(x[k] == 0)
			return;
		/* check for adjacency matrix edge */
		if(graph->iGraph[x[k - 1]][x[k]] != 0) {
			int j;
			/* checking for duplicates within array */
			for(j = 0; j <= k; j++) {
				if(x[k] == x[j]) {
					break;
					}
				}
			if(j == k) {
				if(k < n - 1) {
					return;
				}
				/* last position must have edge so the cycle is complete */
				if((k == n - 1) && (graph->iGraph[x[k]][x[0]] != 0)) {
					return;
				}
			}
		}
	}
}
