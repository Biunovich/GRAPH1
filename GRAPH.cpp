#include <stdio.h>
#include <stdlib.h>
class Graph
{
private:
	int **arr;
	bool *visited;
public:
	int n;
	Graph()
	{
		int N;
		FILE * f;
		f = fopen("input.txt", "r");
		fscanf(f, "%d", &N);
		this->n = N;
		visited = (bool *)calloc(sizeof(bool), N);
		arr = (int **)calloc(sizeof(int*),N);
		for (int i = 0; i < N; i++) {
			arr[i] = (int *)calloc(sizeof(int), N);
			for (int j = 0; j < N; j++)
			{
				fscanf(f, "%d", &(this->arr[i][j]));
			}
		}
		fclose(f);
	}
	void write()
	{
		for (int i = 0; i < this->n; i++)
		{
			printf("\n");
			for (int j = 0; j < this->n; j++)
				printf("%d ", this->arr[i][j]);
		}
		printf("\n");
	}
	bool Euler()
	{
		bool euler = true;
		int chet;
		for (int i = 0; i < this->n; i++) {
			chet = 0;
			for (int j = 0; j < this->n; j++)
			{
				chet += this->arr[i][j];
			}
			if ((chet % 2) == 1)
				euler = false;
		}
		return euler;
	}
	bool Smezh(int i, int j)
	{
		if (this->arr[i][j] != 0)
			return true;
		else
		{
			return false;
		}
	}
	bool Gamil(int v,int w,int d)
	{
		if (d == 1 && Smezh(w, v))
			return true;
		visited[v] = true;
		for (int t = 0; t < this->n; t++)
			if (Smezh(t, v))
				if (!visited[t])
					if (Gamil(t, w, d - 1))
						return true;
		visited[v] = false;
		return false;
	}
};
void main()
{
	Graph *graph = new Graph();
	graph->write();
	if (graph->Euler())
		printf("GRAPH IS EULER\n");
	else
	{
		printf("GRAPH ISNT EULER\n");
	}
	if (graph->Gamil(0,0,graph->n))
		printf("GRAPH IS GAMILTONIAN\n");
	else
	{
		printf("GRAPH ISNT GAMILTONIAN\n");
	}
}