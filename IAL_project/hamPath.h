/* hamPath.h
 * Predmet: Algoritmy (IAL) - FIT VUT v Brne
 * Autor: Marek Bahník
 * Popis: Hlavičkový súbor pre hamPath.c (knižnica na hladanie hamiltonovej cesty)
 * Vytvoril: Marek Bahník, 7.12.2020
 */

#ifndef _HAMPATH_H_
#define _HAMPATH_H_

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "graphLib.h"

void FindPath(Graph* aGraph, int start, int end);
bool is_done(int *arr, int i, int no_verts);
void process_vertex(Graph* aGraph, int vert, int* arr_ptr, int vert_count, int* processed, int end);

#endif
