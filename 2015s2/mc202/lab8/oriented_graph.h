/* Interface: oriented_graph.h
 * Autor: Rodrigo Surita (RA 139095)
 *
 * Descrição:
 *
 */

/* */
struct nodeData;

/* Tipo: Vértice de grafo */
typedef struct graphVertex {

  int id;
  struct nodeData* data;

} GraphVertex;

/* Tipo: grafo armazenado com lista de adjacências */
typedef struct graph {

  int size;
  GraphVertex* nodes;
  int** edges;

} *Graph;

/* Cria um grafo de tamanho arbitrário */
Graph newGraph(int size);

/* Libera um grafo da memória */
void destroyGraph(Graph G);

/* Adiciona uma aresta no grafo */
void setEdgeGraph(Graph G, int startId, int endId, int weight);

/* Remove aresta no grafo */
void removeEdgeGraph(Graph G, int startId, int endId);

/* Verifica se há aresta entre dois nós */
int hasEdgeGraph(Graph G, int startId, int endId);

/* Verifica se há caminho entre dois vértices */
int hasPathGraph(Graph G, int startId, int endId);

/* Modifica o conteúdo de um vértice */
void setGraphVertex(Graph G, int id, struct nodeData* data);

/* Recupera o conteúdo de um vértice */
struct nodeData* getGraphVertex(Graph G, int id);
