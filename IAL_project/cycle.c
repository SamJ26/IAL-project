//
//  cycle.c
//  IAL
//
//  Created by Samuel Liska on 02/12/2020.
//
#include "cycle.h"

/* * * * * * * * * * * * * * * * * * * * * * * * *
 @function hamiltonianCycle
 
 Function that initializes 'n' and answer array 'x'
 that are being passed and used throught whole algorithm,
 and after that calls @function hamiltonian.
 
 @var n size of matrix
 @var x answer array
 
 x[0] is set to fixed '0' because we don't want duplicated hamilton
 cycles, so each one starts and ends in the same vertex.
 
 
* * * * * * * * * * * * * * * * * * * * * * * * * */
void hamiltonianCycle(Graph* aGraph){
    int n = aGraph->iVertices;
    int x[n];
    //mprintf("N : : : %lu",sizeof(x));
    x[0] = 0;
    hamiltonian(aGraph, 1, n, x);
    return;
}

/* * * * * * * * * * * * * * * * * * * * * * * * *
 @function hamiltonian
 
 This function uses backtracking algorithm to find
 all possible hamiltonian cycles, within given graph.
 
 Calls for @function nextVertex to verify given vertex.
 If 'k' have reached last position print out answer.
 Else recursive call this function(k+1) until last position
 is reached.
 
 
* * * * * * * * * * * * * * * * * * * * * * * * * */

void hamiltonian(Graph* aGraph, int k, int n, int x[]){
    while(true){
        nextVertex(aGraph,k,n,x);
        if(x[k]==0) return;
        if(k==n-1){
            printf("Hamiltonovský cyklus: \n");
            for(int i=0;i<n;i++)
               printf("%d->",x[i]);
            printf("%d",x[0]);
            printf("\n");
        }else{
            hamiltonian(aGraph,k+1, n, x);
        }
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * *
 @function nextVertex
 
 Function that checks validity of next vertex. First
 it checks for duplicates in array(previous positions)
 after finding new value that doesn't appear in 'x' array
 it checks in adjacency for an edge.
 
 Algorithm logic:
 1. Do not take duplicate
 2. Whenever you take vertex, there should be an edge
 from the previous one.
 3. If you are on the last vertex there should be an edge
 to the first one. If so there is an answer.
 
 Complexity:
 for 'n' vertices graph : (n-1)!
 n! = O(n^n)
 
* * * * * * * * * * * * * * * * * * * * * * * * * */

void nextVertex(Graph* aGraph, int k, int n, int x[]){
    while(true){
        x[k]=(x[k]+1)%(n); //next value
        if(x[k]==0) return;
        /* check for adjacency matrix edge*/
        if(aGraph->iGraph[x[k-1]][x[k]]!=0){
            int j;
            /*checking for duplicates within array*/
            for(j=0;j<k;j++){
                if(x[k]==x[j]){
                    break;
                }
            }
            if(j==k){
                if(k<n-1){
                    return;
                }
                /*last position must have edge so the cycle is complete*/
                if((k==n-1)&&(aGraph->iGraph[x[k]][x[0]]!=0)){
                    return;
                }
            }
            
        }
    }
}
