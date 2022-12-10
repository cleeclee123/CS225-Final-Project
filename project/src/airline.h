#pragma once

#include <string>
#include <vector>

class Airline
{
public:
  /**
   * @brief Default Constructor of new Airline object
   *
   */
  Airline();

  /**
   * @brief Parameterized Constructor of new Airline object
   * 
   * @param airlineID 
   * @param name 
   * @param alias 
   * @param IATA 
   * @param ICAO 
   * @param callsign 
   * @param country 
   * @param isActive 
   */
  Airline(std::string airlineID, std::string name, std::string alias, std::string IATA, std::string ICAO, std::string callsign, std::string country, bool isActive);

  /**
   * helper function to print airline data
   * @return void like my soul
   */
  void printAirline();

  /**
   * comparison operator== for airline
   * @param rhs 
   * @return bool if airline is equal to each other 
   */
  bool operator==(const Airline& rhs) const;

  /**
   * @brief Get the Airline ID object
   * 
   * @return std::string 
   */
  std::string getAirlineID() const;

  /**
   * @brief Get the Name object
   * 
   * @return std::string 
   */
  std::string getName() const;

  /**
   * @brief Get the Alias object
   * 
   * @return std::string 
   */
  std::string getAlias() const;

  /**
   * @brief Get the IATA object
   * 
   * @return std::string 
   */
  std::string getIATA() const;

  /**
   * @brief Get the ICAO object
   * 
   * @return std::string 
   */
  std::string getICAO() const;

  /**
   * @brief Get the Callsign object
   * 
   * @return std::string 
   */
  std::string getCallsign() const;

  /**
   * @brief Get the Country object
   * 
   * @return std::string 
   */
  std::string getCountry() const;

  /**
   * @brief Get the Is Active object
   * 
   * @return true 
   * @return false 
   */
  bool getIsActive() const;


private:
  // airline data members
  std::string airlineID_;
  std::string name_;
  std::string alias_;
  std::string IATA_;
  std::string ICAO_;
  std::string callsign_;
  std::string country_;
  bool isActive_;

};