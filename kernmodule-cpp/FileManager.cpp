
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "FileManager.h"

using std::string;
using std::to_string;

void FileManager::saveScore(int score) {

	std::cout << "Saving score..." << std::endl;

	string newScore = to_string(score);

	std::ifstream readScoreFile("Scores.txt");
	if (readScoreFile.is_open()) {

		//Read scores
		std::vector<string> fileContents;
		string currentLine;
		while (!readScoreFile.eof()) {
			std::getline(readScoreFile, currentLine);
			fileContents.push_back(currentLine);
		}
		fileContents.push_back(newScore);

		readScoreFile.close();

		//Write scores
		std::ofstream writeScoreFile("Scores.txt");
		if (writeScoreFile.is_open()) {

			for (int i = 0; i < fileContents.size(); i++) {

				if (i == fileContents.size() - 1) {
					writeScoreFile << fileContents[i];
				}
				else {
					writeScoreFile << fileContents[i] << std::endl;
				}
			}
		}
	}
}

std::vector<int> FileManager::getHighScores() {
	
	std::cout << "Reading HighScores" << std::endl;

	std::vector<string> fileContents;

	std::ifstream readScoreFile("Scores.txt");
	if (readScoreFile.is_open()) {

		//Read scores
		string currentLine;
		while (!readScoreFile.eof()) {
			std::getline(readScoreFile, currentLine);
			fileContents.push_back(currentLine);
		}
		readScoreFile.close();
	}

	std::vector<int> fileContentsInt;

	//Convert from string to int
	for (int i = 0; i < fileContents.size(); i++) {
		fileContentsInt.push_back(std::stoi(fileContents[i]));
	}

	std::sort(fileContentsInt.begin(), fileContentsInt.end());
	std::reverse(fileContentsInt.begin(), fileContentsInt.end());

	return fileContentsInt;
} 