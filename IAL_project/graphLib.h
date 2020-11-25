#ifndef _GRAPHLIB_H_
#define _GRAPHLIB_H_

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool** LoadGraph(char* aFileName);
size_t VerticesCount(FILE* aFile);
bool** AllocMemory(size_t vertices);
void DeallocMemory(bool** aGraph, size_t aVertices);
void PrintGraph(bool** aGraph, size_t aVertices);

#endif