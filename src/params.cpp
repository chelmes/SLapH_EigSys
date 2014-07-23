/*****************************************
 * Testing IO of parameters with struct and infile
 * Compile with: g++ -Wall -pedantic -I../include/ -L../module  -o params params.cpp
 * Author: Christopher Helmes
 * **************************************/

#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <string>

#include "parastruct.h"

int main () {
  
  IO test;
  test.set_values("parameters.txt");
  test.print_summary();
  std::string name;
  name = test.get_path("res");
  int zahl=123;
  char datei[200];
  sprintf(datei, "%s.%04d", name.c_str(), zahl);
  std::cout << datei  << std::endl;
  return 0;
}
