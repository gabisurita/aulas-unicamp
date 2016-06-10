/* Define o tipo matriz de caracteres */

typedef struct char_matrix {
  char** el;
  int lines;
  int cols;
} CharMat;


/* Cria uma nova matriz de caracteres na memória */
void NewCharMat(CharMat** Mat, int lines, int cols);

/* Libera uma matriz de caracteres da memória */
void DestroyCharMat(CharMat** Mat);

/* Imprime uma matriz de caracteres */
void PrintCharMat(CharMat** Mat);

/* Cria uma cópia de matriz de caracteres */
void CopyCharMat(CharMat** Ref, CharMat** Copy);
