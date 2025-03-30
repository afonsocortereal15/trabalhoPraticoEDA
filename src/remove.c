/**
 * @file remove.c
 * @author Afonso Corte-Real (a31500@alunos.ipca.pt)
 * @brief Functions for removing nodes from a matrix
 * @version 0.1
 * @date 26-03-2025
 * 
 * @details This file contains functions to replace specific characters in the matrix
 * with '.' which effectively removes them from being processed.
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/input.h"
#include "../include/remove.h"
#include "../include/matrix.h"

/**
 * @brief Replace a node with the specified character at given coordinates with a '.' in the matrix
 * 
 * @param matrix Pointer to the Matrix structure
 * @param character Character to replace
 * @param row Row coordinate
 * @param col Column coordinate
 * @return int 1 if replacement was successful, 0 if node was not found
 */
int removeCharAtPosition(Matrix* matrix, char character, int row, int col) {
    // Validate input parameters
    if (matrix == NULL || matrix->head == NULL) {
        return 0;
    }
    
    Node* current = matrix->head;
    
    // Iterate through the linked list to find the matching node
    while (current != NULL) {
      // Check if current node matches criteria (character and position)
      if (current->data == character && current->row == row && current->col == col) {
        // Replace character with '.' to mark as removed
        current->data = '.';
        printf("Character '%c' at position (%d,%d) has been replaced with '.'\n", 
              character, row, col);
        printGrid(*matrix); // Show the updated matrix
        return 1;
      }
        current = current->next;
    }
    
    // If we reach here, the node wasn't found
    printf("Character '%c' not found at position (%d,%d)\n", character, row, col);
    return 0;
}

/**
 * @brief Replace all nodes with the specified character with '.' in the matrix
 * 
 * @param matrix Pointer to the Matrix structure
 * @param character Character to replace
 * @return int Number of nodes replaced
 */
int removeAllChar(Matrix* matrix, char character) {
    // Validate input parameters
    if (matrix == NULL || matrix->head == NULL) {
        return 0;
    }
    
    int count = 0;
    Node* current = matrix->head;
    
    // Iterate through all nodes in the linked list
    while (current != NULL) {
        if (current->data == character) {
            // Replace matching characters with '.'
            current->data = '.';
            count++;
        }
        current = current->next;
    }
    
    // Report results and display updated matrix
    if (count > 0) {
      printf("Replaced %d occurrences of character '%c' with '.'\n", count, character);
      printGrid(*matrix); // Show the updated matrix
    } else {
        printf("Character '%c' not found in the matrix\n", character);
    }
    
    return count;
}
