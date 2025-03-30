/**
 * @file matrix.h
 * @author Afonso Corte-Real (a31500@alunos.ipca.pt)
 * @brief Header file for matrix display and processing functions
 * @version 0.1
 * @date 26-03-2025
 * 
 * @details This file contains declarations for matrix manipulation functions
 * including display and processing of characters in the matrix.
 */

#ifndef MATRIX_H
#define MATRIX_H

#include "input.h"

/**
 * @struct CharPositions
 * @brief Structure to track positions of specific characters in the matrix
 */
typedef struct {
    char character;   /**< The character being tracked */
    int count;        /**< Number of occurrences of the character */
    int rows[100];    /**< Array of row positions */
    int cols[100];    /**< Array of column positions */
} CharPositions;

/**
 * @brief Print the matrix content in grid format
 * 
 * @param matrix Matrix structure to print
 */
void printGrid(Matrix matrix);

/**
 * @brief Process characters that appear multiple times and calculate interference points
 * 
 * @param matrix Pointer to the Matrix structure to process
 */
void processSameCharacters(Matrix* matrix);

#endif