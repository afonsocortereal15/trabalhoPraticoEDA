/**
 * @file insert.c
 * @author Afonso Corte-Real (a31500@alunos.ipca.pt)
 * @brief Functions for inserting nodes into a matrix
 * @version 0.1
 * @date 26-03-2025
 * 
 * @details This file provides functionality to insert characters at specific positions
 * in the matrix, either by creating new nodes or replacing existing ones.
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/input.h"
#include "../include/matrix.h"
 
/**
 * @brief Insert a character at specified coordinates in the matrix
 * 
 * @param matrix Pointer to the Matrix structure
 * @param character Character to insert
 * @param row Row coordinate
 * @param col Column coordinate
 * @return int 1 if insertion was successful, 0 if coordinates are out of bounds
 * 
 * @details If a character already exists at the specified position, it will be replaced.
 * Otherwise, a new node will be created and added to the matrix.
 */
int insertCharAtPosition(Matrix* matrix, char character, int row, int col) {
    // Validate matrix pointer
    if (matrix == NULL) {
        return 0;
    }
    
    // Validate that coordinates are within the matrix bounds
    if (row < 0 || row >= matrix->rows || col < 0 || col >= matrix->cols) {
        printf("Error: Coordinates (%d,%d) are out of bounds (matrix size: %d x %d)\n", 
               row, col, matrix->rows, matrix->cols);
        return 0;
    }
    
    // First check if there's already a character at this position
    Node* current = matrix->head;
    while (current != NULL) {
        if (current->row == row && current->col == col) {
            // Found existing node at this position - update its value
            current->data = character;
            printf("Replaced character at position (%d,%d) with '%c'\n", row, col, character);
            return 1;
        }
        current = current->next;
    }
    
    // No existing character at this position, so create a new node
    appendNode(&(matrix->head), character, row, col);
    printf("Character '%c' inserted at position (%d,%d)\n", character, row, col);
    
    return 1;
}