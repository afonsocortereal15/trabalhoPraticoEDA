/**
 * @file main.c
 * @author Afonso Corte-Real (a31500@alunos.ipca.pt)
 * @brief Main program implementation for matrix character processing
 * @version 0.1
 * @date 26-03-2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/input.h"
#include "include/calculate.h"
#include "include/remove.h"
#include "include/matrix.h"
#include "include/insert.h"

/**
 * @brief Print the matrix content in grid format
 * 
 * @param matrix Matrix structure to print
 */
void printGrid(Matrix matrix) {
  char** gridOutput = (char**)malloc(matrix.rows * sizeof(char*));
  for (int i = 0; i < matrix.rows; i++) {
    gridOutput[i] = (char*)malloc((matrix.cols + 1) * sizeof(char));
    for (int j = 0; j < matrix.cols; j++) {
      gridOutput[i][j] = '.';
    }
    gridOutput[i][matrix.cols] = '\0';
  }
  
  Node* temp = matrix.head;
  while (temp != NULL) {
    if (temp->row < matrix.rows && temp->col < matrix.cols) {
      gridOutput[temp->row][temp->col] = temp->data;
    }
    temp = temp->next;
  }
  
  for (int i = 0; i < matrix.rows; i++) {
    printf("%s\n", gridOutput[i]);
    free(gridOutput[i]);
  }
  free(gridOutput);
}

/**
 * @brief Process characters that appear multiple times and calculate interference points
 * 
 * @param matrix Pointer to the Matrix structure to process
 */
void processSameCharacters(Matrix* matrix) {
  // Create a 2D grid representation of the matrix for easier processing
  char** grid = (char**)malloc(matrix->rows * sizeof(char*));
  for (int i = 0; i < matrix->rows; i++) {
    grid[i] = (char*)malloc(matrix->cols * sizeof(char));
    // Initialize all cells with '.' (empty)
    for (int j = 0; j < matrix->cols; j++) {
      grid[i][j] = '.';
    }
  }

  // Copy data from linked list to grid representation
  Node* temp = matrix->head;
  while (temp != NULL) {
    if (temp->row < matrix->rows && temp->col < matrix->cols) {
      grid[temp->row][temp->col] = temp->data;
    }
    temp = temp->next;
  }
  
  // Create array to track positions of each character
  CharPositions chars[256]; // Array size covers all possible ASCII characters
  
  // Initialize the character position tracking array
  for (int i = 0; i < 256; i++) {
    chars[i].character = (char)i;
    chars[i].count = 0;
  }
  
  // Scan the grid and record all character positions
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->cols; j++) {
      char c = grid[i][j];
      // Only process meaningful characters (not empty or interference markers)
      if (c != '.' && c != '#') {
        unsigned char idx = (unsigned char)c;
        // Store position information for this character
        chars[idx].rows[chars[idx].count] = i;
        chars[idx].cols[chars[idx].count] = j;
        chars[idx].count++;
      }
    }
  }
  
  // Process each character that appears at least twice (can create interference)
  for (int i = 0; i < 256; i++) {
    if (chars[i].count >= 2) {
      char c = (char)i;
      printf("Processing character '%c' with %d occurrences\n", c, chars[i].count);
      
      // Generate all unique pairs of the same character
      for (int j = 0; j < chars[i].count - 1; j++) {
        for (int k = j + 1; k < chars[i].count; k++) {
          // Get coordinates for this pair
          int r1 = chars[i].rows[j];
          int c1 = chars[i].cols[j];
          int r2 = chars[i].rows[k];
          int c2 = chars[i].cols[k];
          
          printf("Calculating coordinates for '%c' at positions (%d,%d) and (%d,%d)\n", c, r1, c1, r2, c2);
          
          // Calculate interference points based on this pair
          Coordinates coords = calculate_coordinates(r1, c1, r2, c2);
          
          // Add interference marker '#' at the first calculated position if in bounds
          if (coords.n1R >= 0 && coords.n1R < matrix->rows && coords.n1C >= 0 && coords.n1C < matrix->cols) {
            appendNode(&matrix->head, '#', coords.n1R, coords.n1C);
          } else {
            printf("Coordinates (%d,%d) out of bounds\n", coords.n1R, coords.n1C);
          }
          
          // Add interference marker '#' at the second calculated position if in bounds
          if (coords.n2R >= 0 && coords.n2R < matrix->rows && coords.n2C >= 0 && coords.n2C < matrix->cols) {
            appendNode(&matrix->head, '#', coords.n2R, coords.n2C);
          } else {
            printf("Coordinates (%d,%d) out of bounds\n", coords.n2R, coords.n2C);
          }
        }
      }
    }
  }
  
  // Free allocated memory for the grid
  for (int i = 0; i < matrix->rows; i++) {
    free(grid[i]);
  }
  free(grid);
}

/**
 * @brief Main function that coordinates program execution
 * 
 * @return int Exit status code (0 for success)
 */
int main() {
  Matrix matrix = importFromFile("assets/input.txt");

  // Print the matrix dimensions
  printf("Matrix dimensions: %d rows x %d columns\n", matrix.rows, matrix.cols);
  
  // Print the original grid
  printf("\nOriginal Grid:\n");
  printGrid(matrix);

  printf("\n-------------------\n\n");
  
  // Process same characters and place '#' at the calculated coordinates
  processSameCharacters(&matrix);
  
  // Print the updated grid
  printf("\nUpdated Grid:\n");
  printGrid(matrix);

  printf("\n-------------------\n\n");

  removeAllChar(&matrix, '#');
  
  printf("\n-------------------\n\n");
  
  removeAllChar(&matrix, 'O');

  printf("\n-------------------\n\n");
  
  processSameCharacters(&matrix);
  
  // Print the updated grid
  printf("\nUpdated Grid (after removal):\n");
  printGrid(matrix);

  printf("\n-------------------\n\n");
  
  insertCharAtPosition(&matrix, 'X', 4, 7);
  insertCharAtPosition(&matrix, 'X', 6, 5);
  processSameCharacters(&matrix);
  printf("\nUpdated Grid (after insertion):\n");
  printGrid(matrix);

  // Free the linked list
  Node* current = matrix.head;
  while (current != NULL) {
    Node* next = current->next;
    free(current);
    current = next;
  }

  return 0;
}


