//============================================================================
// Name        : main.cpp
// Author      : Fisal Ikhmayes
// Version     :
// Copyright   : Your copyright notice
// Description : working with files cs -210
//============================================================================

#include <iostream>
#include <fstream>
#include <string>

int main() {
  // Open the input file
  std::ifstream file_in("FahrenheitTemperature.txt");

  // Check if the file was successfully opened
  if (!file_in.is_open()) {
    std::cerr << "Error opening file: " << strerror(errno) << std::endl;
    return 1;
  }


  // Read data from the input file
  std::string city;
  int tempF;
  std::cout << "Reading data from FahrenheitTemperature.txt..." << std::endl;
  while (file_in >> city >> tempF) {
   // std::cout << city << " " << tempF << std::endl;
  }

  // Close the input file
  file_in.close();

  // Open the output file
  std::ofstream file_out("CelsiusTemperature.txt");

  // Check if the file was successfully opened
  if (!file_out.is_open()) {
    std::cerr << "Error opening file: " << strerror(errno) << std::endl;
    return 1;
  }

  // Write data to the output file
  std::cout << "Writing data to CelsiusTemperature.txt..." << std::endl;
  file_out << "City Temperature (Celsius)\n";
  file_in.open("FahrenheitTemperature.txt");
  while (file_in >> city >> tempF) {
    int tempC = (tempF - 32) * 5.0 / 9.0;
    file_out << city << " " << tempC << std::endl;
    std::cout << city << " " << tempC << std::endl;
  }

  // Close the output file
  file_out.close();

  return 0;
}

