/**
 * @file remove.h
 * @author Afonso Corte-Real (a31500@alunos.ipca.pt)
 * @brief Header file for matrix node removal functions
 * @version 0.1
 * @date 26-03-2025
 * 
 * @details This file contains function declarations for removing specific characters
 * from the matrix data structure.
 */

#ifndef REMOVE_H
#define REMOVE_H

#include "input.h"

/**
 * @brief Remove a node with the specified character at given coordinates from the matrix
 * 
 * @param matrix Pointer to the Matrix structure
 * @param character Character to remove
 * @param row Row coordinate
 * @param col Column coordinate
 * @return int 1 if removal was successful, 0 if node was not found
 */
int removeCharAtPosition(Matrix* matrix, char character, int row, int col);

/**
 * @brief Remove all nodes with the specified character from the matrix
 * 
 * @param matrix Pointer to the Matrix structure
 * @param character Character to remove
 * @return int Number of nodes removed
 */
int removeAllChar(Matrix* matrix, char character);

#endif /* REMOVE_H */