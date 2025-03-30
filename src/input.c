/**
 * @file input.c
 * @author Afonso Corte-Real (a31500@alunos.ipca.pt)
 * @brief Functions for matrix input and linked list manipulation
 * @version 0.1
 * @date 26-03-2025
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct Node {
  char data;
  int row;
  int col;
  struct Node* next;
} Node;

typedef struct {
  Node* head;
  int rows;
  int cols;
} Matrix;

/**
 * @brief Create a new node with given data and coordinates
 * 
 * @param data Character to store in the node
 * @param row Row coordinate
 * @param col Column coordinate
 * @return Node* Pointer to the newly created node
 */
Node* createNode(char data, int row, int col) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->row = row;
  newNode->col = col;
  newNode->next = NULL;
  return newNode;
}

/**
 * @brief Append a new node to the end of the linked list
 * 
 * @param head Pointer to head pointer of linked list
 * @param data Character to store in the new node
 * @param row Row coordinate
 * @param col Column coordinate
 */
void appendNode(Node** head, char data, int row, int col) {
  Node* newNode = createNode(data, row, col);
  if (*head == NULL) {
    *head = newNode;
  } else {
    Node* temp = *head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

/**
 * @brief Import matrix data from a file
 * 
 * @param filename Path to the input file
 * @return Matrix Matrix structure populated with data from file
 */
Matrix importFromFile(const char* filename) {
  FILE* file = fopen(filename, "r");
  Matrix matrix = {NULL, 0, 0};
  
  if (file == NULL) {
    perror("Failed to open file");
    return matrix;
  }

  Node* head = NULL;
  char line[1024]; // Increased buffer size
  int row = 0;
  int maxCol = 0;

  while (fgets(line, sizeof(line), file)) {
    int lineLen = strlen(line);
    if (lineLen > maxCol) {
      maxCol = lineLen;
    }
    
    for (int col = 0; col < lineLen; col++) {
      if (line[col] != '.' && line[col] != '\n') {
        appendNode(&head, line[col], row, col);
      }
    }
    row++;
  }

  fclose(file);
  
  matrix.head = head;
  matrix.rows = row;
  matrix.cols = (maxCol > 0 && maxCol - 1 >= 0) ? maxCol - 1 : 0; // Subtract 1 to account for newline
  
  return matrix;
}
