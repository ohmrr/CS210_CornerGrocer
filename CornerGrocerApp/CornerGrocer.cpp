/*
 * Name: Esteban Garcia
 * Project: CS 210 Project Three - Corner Grocer
 * Description: This file implements the CornerGrocer class used to track
 * grocery item frequencies from the daily input file.
 */

#include "CornerGrocer.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>

using namespace std;

CornerGrocer::CornerGrocer(const string& t_inputFileName)
    : m_inputFileName(t_inputFileName) {}

void CornerGrocer::loadItems() {
  ifstream inputFile(m_inputFileName);
  string itemName;

  if (!inputFile.is_open()) {
    throw runtime_error("Unable to open input file: " + m_inputFileName);
  }

  // Each item is one word, so reading with >> works cleanly for this file.
  while (inputFile >> itemName) {
    ++m_itemFrequencies[normalizeItemName(itemName)];
  }

  inputFile.close();
}

void CornerGrocer::createBackupFile(const string& t_outputFileName) const {
  ofstream outputFile(t_outputFileName);

  if (!outputFile.is_open()) {
    throw runtime_error("Unable to create backup file: " + t_outputFileName);
  }

  // The backup file is created automatically before the user starts using the menu.
  for (const auto& item : m_itemFrequencies) {
    outputFile << item.first << " " << item.second << endl;
  }

  outputFile.close();
}

int CornerGrocer::getItemFrequency(const string& t_itemName) const {
  const string normalizedItemName = normalizeItemName(t_itemName);
  const auto itemIterator = m_itemFrequencies.find(normalizedItemName);

  if (itemIterator == m_itemFrequencies.end()) {
    return 0;
  }

  return itemIterator->second;
}

void CornerGrocer::printFrequencyList() const {
  cout << endl;
  cout << "Item Frequency List" << endl;
  cout << "-------------------" << endl;

  for (const auto& item : m_itemFrequencies) {
    cout << left << setw(15) << item.first << item.second << endl;
  }
}

void CornerGrocer::printHistogram() const {
  cout << endl;
  cout << "Item Frequency Histogram" << endl;
  cout << "------------------------" << endl;

  for (const auto& item : m_itemFrequencies) {
    cout << left << setw(15) << item.first << string(item.second, '*') << endl;
  }
}

string CornerGrocer::normalizeItemName(const string& t_itemName) {
  string normalizedName = t_itemName;

  if (!normalizedName.empty()) {
    normalizedName[0] = static_cast<char>(toupper(normalizedName[0]));

    for (size_t i = 1; i < normalizedName.length(); ++i) {
      normalizedName[i] = static_cast<char>(tolower(normalizedName[i]));
    }
  }

  return normalizedName;
}
