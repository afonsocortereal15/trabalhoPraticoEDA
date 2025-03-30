#ifndef CALCULATE_H
#define CALCULATE_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @struct Coordinates
 * @brief Structure to store the calculated interference coordinates
 */
typedef struct {
  int n1R; /**< Row of first interference point */
  int n1C; /**< Column of first interference point */
  int n2R; /**< Row of second interference point */
  int n2C; /**< Column of second interference point */
} Coordinates;

/**
 * @brief Calculate interference coordinates based on two input positions
 * 
 * @param r1 Row of first position
 * @param c1 Column of first position
 * @param r2 Row of second position
 * @param c2 Column of second position
 * @return Coordinates Structure containing the calculated interference positions
 */
Coordinates calculate_coordinates(int r1, int c1, int r2, int c2);

#endif /* CALCULATE_H */