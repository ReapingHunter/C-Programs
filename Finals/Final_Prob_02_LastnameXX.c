/************************************************************************
 * Prim's Algorithm : It grows a spanning tree, one edge at a time.     *
 * Given:                                                               *
 *   1)  Graph G = (V, E)                                               *
 *   2)  V = {0, 1, 2, 3, 4}                                            *
 *                                                                      *
 * Steps of Prim’s Algorithm:                                           *
 *   1) Initialize set U to contain { 0 }                               *
 *      //In the program, starting vertex will be inputted by the user  *
 *   2) While (U != V)                                                  *
 *       a) Find the minimum cost edge (u, v) such that                 *
 *          u is an element  U and   v is not yet in U                  *
 *       b)  Add v to U                                                 *
 ************************************************************************/
 
#include <unistd.h>    // for sleep(), to add in code if display leaves blank screen  
#include <stdio.h> 
#include <string.h>   

                 
#define MAX  6              // Number of vertices in the graph  
#define INFINITY  0XFFFF    
   
/***** Data Structure Definition *****/  
typedef int graphType[MAX][MAX];    // A[x][y] = INFINITY  if there is not edge ;  A[x][y] = weight of the edge (x,y)
typedef int set[MAX];               // Bit-vector implementation of Set

typedef struct {
	int u, v;     // (u,v) represents the edge  
	int weight;   // weight of the edge
}edgetype;

typedef struct {
    edgetype edges[MAX];
    int edgeCount;   //actual number of edges
	int minCost;	 //Cost of the MST
}primMST;

/***** Function Prototypes *****/

void populateGraph(graphType G);
void displayGraph(graphType G);
primMST primAlgo(graphType graph, int startVertex);
void displayPrimMST(primMST tree);

int main() 
{ 
     /*---------------------------------------------------------------------------------
    * 	Problem #2 ::  a) Allows user to input from keyboard the starting vertex      *
    *                  b) Calls populateGraph() to populate the given graph           *
    *                  c) Calls primAlgo() and displayPrimMST()                       *
    *                                                                                 *
    * printf("\n\n\nProblem #2:: ");                                                  *  
    * printf("\n------------");                                                       *
    *---------------------------------------------------------------------------------*/
 	printf("\n\n\nProblem #2:: "); 
    printf("\n------------"); 
    
    //Write code here
 	graphType G;
 	primMST P;
 	populateGraph(G);
 	P = primAlgo(G, 3);
 	displayPrimMST(P);
    return 0; 
} 

/************************************************************
 * Function Definitions                                     *
 ************************************************************/
void populateGraph(graphType G)
{
	graphType graph = {  INFINITY, 1, 5, 4, 6, 5, 1, INFINITY, 5, INFINITY, INFINITY, 6, 5, 5, INFINITY, 2, INFINITY, INFINITY, 4,
                             INFINITY, 2, INFINITY, 1, INFINITY, 6, INFINITY,INFINITY, 1, INFINITY, 3, 5, 6, INFINITY, INFINITY, 3, INFINITY} ;   //5

	memcpy(G, graph, sizeof(graph));

	
}

void displayGraph(graphType G){
	int x;
	int y;
	for(x = 0; x < MAX; x++){
		printf("\n");
		for(y = 0; y < MAX; y++){
			printf("%d ",G[x][y]);
		}
	}
}

primMST primAlgo(graphType graph, int startVertex)
{
	 //Write code here
	 primMST P;
	 P.edgeCount = 0;
	 P.minCost = 0;
	 set U = {0};
	 int x;
	 int y;
	 int z;
	 int i;
	 int j;
	 int min = INFINITY;
	 printf("\nStart vertex is %d", startVertex);
	 for(x = startVertex; U[x] != 1; x = j){
	 	U[x] = 1;
	 	for(y = 0; y < MAX; y++){
	 		for(z = 0; z < MAX; z++){
	 			if(graph[y][z] < min && U[y] == 1 && U[z] == 0){
			 		min = graph[y][z];
			 		i = y;
			 		j = z;
				}
			}
		}
		if(min != INFINITY){
			P.minCost += min;
			P.edges[P.edgeCount].u = i;
			P.edges[P.edgeCount].v = j;
			P.edges[P.edgeCount++].weight = graph[i][j];
			min = INFINITY;
		}
	 }
	 
	 return P;
}

void displayPrimMST(primMST T)
{
	int x;
		
	printf("\n%5s%5s", "Edge", "Cost");
 
    //Write code here
    for(x = 0; x < T.edgeCount; x++){
    	printf("\n(%d,%d)%6d",T.edges[x].u, T.edges[x].v, T.edges[x].weight);
	}
	printf("\nMinimum Cost : %d",T.minCost);
	
}





