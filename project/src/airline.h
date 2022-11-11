#pragma once

#include <string>
#include <vector>

class Airline
{
public:
  Airline();
  Airline(std::string name, std::vector<std::string> knownAbbreviatations, std::string country);

private:
  std::string name_; 
  std::vector<std::string> knownAbbreviatations_;
  std::string country_;
};