#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********************************************************************
 * Data Structure Definition                                        *
 ********************************************************************/
#define MAX_VERTEX    6                  // Maximum number of vertices  
#define SENTINEL      0XFFFF             // A value bigger than any weight  

typedef char  vertexType;               // 'A', 'B', 'C', 'D', 'E', 'F'               

typedef struct {
	vertexType tail;         // vertex at the tail of the arc or edge  
	vertexType head;         // vertex at the head of the arc or edge  
	int weight;
}edgeType;                  // data type of the list of edges in the file and edge list  

typedef struct {
	vertexType adjVertex;
	int weight;
}adjType;

typedef struct adjNode {
	adjType  info;
	struct adjNode *link;
}*AdjList;

/* Labeled Adjacency list */
typedef struct {
   AdjList head[MAX_VERTEX];       /* Vertices adjacent to Vertex A are stored at index 0, Vertex B at index 1, etc.. */          
   int edgeCount;                  /* Total number of edges in the graph */             
}directedAdjList;


/**************************************************
 * Function Prototypes                            *
 **************************************************/
/* PROBLEM 1 */
void initDirectedAdjList(directedAdjList * L);
directedAdjList populateDirectedAdjList();
void displayAdjList(directedAdjList L);


 int main( ) 
 {	
 
 /*------------------------------------------------------------------------------------
 * 	Problem #1 ::  a) Creates a Labeled Adjacency List via populateDirectedAdjList()  *
 *                 b) Calls displayAdjList().                                         *
 *------------------------------------------------------------------------------------*/
   printf("\n\n\nProblem #1:: "); 
   printf("\n------------"); 
   
   //Write the code for main here
  directedAdjList DL = populateDirectedAdjList();
 displayAdjList(DL);
 return 0;
}


 
/************************************************************
 *  Problem 1 Function Definitions                          *
 ************************************************************/ 
void initDirectedAdjList(directedAdjList *DL)
{
	 //Write the code 
	 int x;
	 for(x = 0; x < MAX_VERTEX; x++){
	 	DL->head[x] = NULL;
	 }
	 DL->edgeCount = 0;
	 
}

directedAdjList populateDirectedAdjList()
{
	directedAdjList graph;
	initDirectedAdjList(&graph);
	AdjList node;
	AdjList *trav;
	int x;
	int y;
	
	const int COUNT = 14;
    edgeType data[] =     {  {'A', 'E', 6}, {'C', 'A', 4}, { 'E', 'C' , 6 },
                             {'A', 'F', 3}, {'C', 'D', 6}, { 'E', 'F' , 6 },
                             {'B', 'A', 4}, {'D', 'A', 8}, { 'F', 'B' , 3 },
                             {'B', 'C', 3}, {'D', 'B', 6}, {'D', 'E', 3}, 
							 {'B', 'E', 6}, {'F', 'D' ,3 }, { 'B', 'F' , 10 }, 
						};
	for(x = 0; x < MAX_VERTEX; x++){
		for(y = 0; y <= COUNT; y++){
			if(data[y].tail == 'A' + x){
				for(trav = &graph.head[x]; *trav != NULL && (*trav)->info.adjVertex < data[y].head; trav = &(*trav)->link){}
				if(*trav != NULL && (*trav)->info.adjVertex == data[y].head){
					if((*trav)->info.weight > data[y].weight){
						(*trav)->info.weight = data[y].weight;
					}
				} else {
					node = (AdjList)malloc(sizeof(struct adjNode));
					node->info.adjVertex = data[y].head;
					node->info.weight = data[y].weight;
					node->link = *trav;
					*trav = node;
					graph.edgeCount++;
				}
				
			}
		}
		
	}
	 return graph;
}

void displayAdjList(directedAdjList L)
{
 	int x;
	AdjList temp;
		
	printf("\n\nThe Adjacency List ::");
	printf("\n%-8s", "VERTEX");
	printf("%-20s", "Adjacent vertices");
	printf("\n%-8s", "------");
	printf("%-20s", "-----------------");
 
	//Write your code here 
	for(x = 0; x < MAX_VERTEX; x++){
		printf("\n%3C ::",'A' + x);
		for(temp = L.head[x]; temp != NULL; temp = temp->link){
			printf("%6C(%d)",temp->info.adjVertex, temp->info.weight);
		}
	}
	printf("\n\nPress any key to continue ... ");

 }
 

