/**
 * @file input.h
 * @author Afonso Corte-Real (a31500@alunos.ipca.pt)
 * @brief Header file for matrix data input and basic linked list operations
 * @version 0.1
 * @date 26-03-2025
 * 
 * @details This file contains declarations for data structures and functions
 * related to matrix input and linked list manipulation.
 */

#ifndef INPUT_H
#define INPUT_H

/**
 * @struct Node
 * @brief Linked list node structure for matrix elements
 */
typedef struct Node {
  char data;         /**< Character stored at this position */
  int row;           /**< Row coordinate */
  int col;           /**< Column coordinate */
  struct Node* next; /**< Pointer to next node in linked list */
} Node;

/**
 * @struct Matrix
 * @brief Structure representing a sparse matrix using linked list
 */
typedef struct {
  Node* head; /**< Head of linked list containing matrix elements */
  int rows;   /**< Number of rows in the matrix */
  int cols;   /**< Number of columns in the matrix */
} Matrix;

/**
 * @brief Create a new node with given data and coordinates
 * 
 * @param data Character to store in the node
 * @param row Row coordinate
 * @param col Column coordinate
 * @return Node* Pointer to the newly created node
 */
Node* createNode(char data, int row, int col);

/**
 * @brief Append a new node to the end of the linked list
 * 
 * @param head Pointer to head pointer of linked list
 * @param data Character to store in the new node
 * @param row Row coordinate
 * @param col Column coordinate
 */
void appendNode(Node** head, char data, int row, int col);

/**
 * @brief Import matrix data from a file
 * 
 * @param filename Path to the input file
 * @return Matrix Matrix structure populated with data from file
 */
Matrix importFromFile(const char* filename);

#endif /* INPUT_H */