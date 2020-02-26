/* Include statements */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/* Constants */
#define TRAFFIC_NUM 1.7
#define CRIME_NUM 872.6
#define EXPENSE_NUM 1217.1
#define LIVABILITY_NUM 13.81

/* Prototypes */

//Gets input using fscanf
int getInput(FILE*, char[], int*, int*, int*, int*, int*, int*);
//Returns population density
double getPopulationDensity(int, int);
//Computes pollution/traffic rating and crime/expense per capita
void computeRates(double, int, int, int, int, double*, double*, double*, double*);
//Returns the livability
double getLivability(double, double, double, double);
//Updates totals and checks for new best city
void updateStats(double*, int*, double*, char*, double, char*);
//Prints out individual city summary
void printSummary(char[], double, double);
//Prints out the final summary: total cities, average livability, best city and it's livability
void printFinalSummary(int, double, char*, double);