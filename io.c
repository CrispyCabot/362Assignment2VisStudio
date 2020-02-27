//io.c
#include "header.h"

//Functions handling input and output

//Gets input from file
int getInput(FILE* fp, char name[20], int* population, int* sqMileage, int* pollution, int* crime, int* expense, int* highwayAmt)
{
	return fscanf(fp, "%s %d %d %d %d %d %d", name, population, sqMileage, pollution, crime, expense, highwayAmt);
}

//Prints the individual city summary
void printSummary(char name[], double popDensity, double livability)
{
	printf("%-29s %-40.2f %.2f\n", name, popDensity, livability);
}

//Prints the final summary, runs at end of program
void printFinalSummary(int totalCities, double totalLivability, char* bestCity, double highestLivability)
{
	printf("\nOf the %d cities, the average livability was %.2f and the most liveable was %s with a score of %.2f", totalCities, (double)totalLivability / totalCities, bestCity, highestLivability);
}