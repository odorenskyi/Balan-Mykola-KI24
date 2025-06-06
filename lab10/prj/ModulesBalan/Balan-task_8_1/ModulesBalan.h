#pragma once
#include <fstream>
#include <string>
double calculateS(double x, double y, double z);
void calculateDeposit(double amount, int months, double& dailyInterest, double& totalInterest);
void calculateAverageTemperatureForTest(const double tempsC[], int size, double& avgC, double& avgF);
int analyzeBits(int N);
void analyzeWord(std::ifstream& inFile, std::ofstream& outFile);
void appendWordInfo(std::ifstream& inFile, std::ofstream& outFile, const std::string& inputFileName);
void computeAndConvert(std::ifstream& inFile, std::ofstream& outFile);