/**
 * @file insert.h
 * @author Afonso Corte-Real (a31500@alunos.ipca.pt)
 * @brief Header file for matrix character insertion functions
 * @version 0.1
 * @date 26-03-2025
 * 
 * @details This file contains function declarations for inserting characters
 * at specific positions in the matrix data structure.
 */

#ifndef INSERT_H
#define INSERT_H

#include "input.h"

/**
 * @brief Insert a character at specified coordinates in the matrix
 * 
 * @param matrix Pointer to the Matrix structure
 * @param character Character to insert
 * @param row Row coordinate
 * @param col Column coordinate
 * @return int 1 if insertion was successful, 0 if coordinates are out of bounds
 */
int insertCharAtPosition(Matrix* matrix, char character, int row, int col);

#endif /* INSERT_H */