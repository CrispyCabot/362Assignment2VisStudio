//Chris Bridewell
//CSC 362, Section 2, 10 am
//Programming Assignment #2 2/28/20

//cities.c

/*
A program that gets input from a text file where the text file is arranged like:
City_Name population square_milage pollution crime expense #_of_highways
Then computes:
	population density (population/square_milage)
	pollution rating (pollution*popDensity)
	traffic rating (popDensity * 1.7 / highwayAmt)
	crime per capita (crime * popDensity / 872.6)
	expense per capita (expense * popDensity / 1217.1)
	livability (100 - (pollutionRating + trafficRating + crimePerCapita + expensePerCapita) / 13.81)

Outputs the population density and livability of all cities, then lists the total cities,
average livability, and best city and it's livability
*/

#include "header.h" //contains prototypes

void main()
{
	FILE* inputFile;
	//Values to be inputted
	char cityName[50];
	int population, sqMileage, pollution, crime, expense, highwayAmt;

	//Values to be calculated
	double popDensity, pollutionRating, trafficRating, crimePerCapita, expensePerCapita, livability;

	//Totals
	int totalCities = 0;
	double highestLivability = 0, totalLivability = 0;
	char bestCity[50];

	inputFile = fopen("C:\\Users\\cjbas\\Desktop\\Programming Assignments\\362Assignment2\\cities2.txt", "r"); //Opens input file
	printf("City \t\t\t Population Density \t\t\t Livability Score\n");
	while (getInput(inputFile, cityName, &population, &sqMileage, &pollution, &crime, &expense, &highwayAmt) == 7) //getInput returns fscanf which returns amount of elements assigned. Once it's not 7, program is done
	{
		popDensity = getPopulationDensity(population, sqMileage); //Calculates population density
		computeRates(popDensity, pollution, crime, expense, highwayAmt, &pollutionRating, &trafficRating, &crimePerCapita, &expensePerCapita); //Computes various rates
		livability = getLivability(pollutionRating, trafficRating, crimePerCapita, expensePerCapita); //Calculates livability
		updateStats(&totalLivability, &totalCities, &highestLivability, bestCity, livability, cityName); //Updates totals and the best city so far
		printSummary(cityName, popDensity, livability); //Outputs the summary of the city it just went through
	}
	printFinalSummary(totalCities, totalLivability, bestCity, highestLivability); //Prints the final summary
	fclose(inputFile); //Close file
}

/*
cities2.txt output:

City                     Population Density                      Livability Score
Atlanta                       443.12                                   55.02
Boston                        519.65                                   34.87
Cincinnati                    276.13                                   75.90
Dallas                        273.46                                   76.58
Las_Vegas                     154.44                                   84.91
Los_Angeles                   566.09                                   17.72
Minneapolis                   323.74                                   69.47
New_York_City                 829.75                                   1.01
Seattle                       373.01                                   56.78
Washington_DC                 493.87                                   41.80

Of the 10 cities, the average livability was 51.40 and the most liveable was Las_Vegas with a score of 84.91
*/