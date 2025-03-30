/**
 * @file calculate.c
 * @author Afonso Corte-Real (a31500@alunos.ipca.pt)
 * @brief Implementation of coordinate calculation functions
 * @version 0.1
 * @date 26-03-2025
 */

#include "../include/calculate.h"

/**
 * @brief Calculate interference coordinates based on two input positions
 * 
 * @param r1 Row of first position
 * @param c1 Column of first position
 * @param r2 Row of second position
 * @param c2 Column of second position
 * @return Coordinates Structure containing the calculated interference positions
 */
Coordinates calculate_coordinates(int r1, int c1, int r2, int c2) {
  // Calculate the absolute differences between rows and columns
  int difR = abs(r1 - r2);
  int difC = abs(c1 - c2);
  
  Coordinates coords;

  if (c1 == c2) {
    if (r1 > r2) {
      coords.n1R = r1 + difR;
      coords.n1C = c1 + difR;
      coords.n2R = r2 - difR;
      coords.n2C = c2 - difR;
    } else {
      coords.n1R = r1 - difR;
      coords.n1C = c1 - difR;
      coords.n2R = r2 + difR;
      coords.n2C = c2 + difR;
    }
  } else {
    if (r1 > r2 && c1 < c2) {
      // printf("A\n");
      coords.n1R = r1 + difR;
      coords.n1C = c1 - difC;
      coords.n2R = r2 - difR;
      coords.n2C = c2 + difC;
    } else if (r1 > r2 && c1 > c2) {
      // printf("B\n");
      coords.n1R = r1 + difR;
      coords.n1C = c1 + difC;
      coords.n2R = r2 - difR;
      coords.n2C = c2 - difC;
    } else if (r1 < r2 && c1 < c2) {
      // printf("C\n");
      coords.n1R = r1 - difR;
      coords.n1C = c1 - difC;
      coords.n2R = r2 + difR;
      coords.n2C = c2 + difC;
    } else if (r1 < r2 && c1 > c2) {
      // printf("D\n");
      coords.n1R = r1 - difR;
      coords.n1C = c1 + difC;
      coords.n2R = r2 + difR;
      coords.n2C = c2 - difC;
    }
  }

  // Print the calculated interference coordinates
  printf("Interference at: (%d,%d) and (%d,%d)\n", coords.n1R, coords.n1C, coords.n2R, coords.n2C);
  
  return coords;
}