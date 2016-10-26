#include "English_length.h"
#include <iostream>
#include <string>
using namespace std;

void English_length::English_length(){
	int inches=0;
	int totalInches=0;
	int feet=0;
	int totalFeet=0;
	int yard=0;

}

int English_length::inches() const 
{
	return inches;
}
int English_length::totalInches() const
{
	return totalInches;

}
int English_length::feet() const 
{
	return feet;
}
int English_length::totalFeet() const
{
	return totalFeet;
}
int English_length::yards() const
{
	return yards;
}
bool EnglishLength::isGreaterThan(const English_length & L);
{
	if (totalFeet > L)
	{
		return true;
	}
	else
		return false;
}
void add_inches(int amt_to_add)
{
	totalInches += amt_to_add;
}
