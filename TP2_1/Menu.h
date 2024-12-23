#ifndef MENU_H
#define MENU_H

#include "AEROFLOT.h"
#include <vector>
#include <string>

void printMenu();
void addFlight(std::vector<AEROFLOT>& flights);
void removeFlight(std::vector<AEROFLOT>& flights);
void editFlight(std::vector<AEROFLOT>& flights);
void showFlightsByDestination(std::vector<AEROFLOT>& flights);  // Объявление

#endif
