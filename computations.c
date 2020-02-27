//computations.c
#include "header.h"

//Performs various computations

//Calculates pollution and traffic ratings, and crime/expense per capita
void computeRates(double popDensity, int pollution, int crime, int expense, int highwayAmt, double* pollutionRating, double* trafficRating, double* crimePerCapita, double* expensePerCapita)
{
	*pollutionRating = pollution * popDensity / 1000;
	*trafficRating = popDensity * TRAFFIC_NUM / highwayAmt;
	*crimePerCapita = crime * popDensity / CRIME_NUM;
	*expensePerCapita = expense * popDensity / EXPENSE_NUM;
}

//Returns the livability
double getLivability(double pollution, double trafficRating, double crimePerCapita, double expensePerCapita)
{
	return 100 - (pollution + trafficRating + crimePerCapita + expensePerCapita) / LIVABILITY_NUM;
}

//Returns the population density
double getPopulationDensity(int population, int sqMileage)
{
	return (double)population / sqMileage;
}

//Updates totalLivability and totalCities value, checks if this city is the new best city
void updateStats(double* totalLivability, int* totalCities, double* highestLivability, char* bestCity, double livability, char* name)
{
	*totalLivability += livability;
	*totalCities = *totalCities + 1;
	if (livability > * highestLivability)
	{
		*highestLivability = livability;
		strcpy(bestCity, name);
	}
}