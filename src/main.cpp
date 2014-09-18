/****************************************
 * Programm for the eigensystem calculation needed for SLapH method
 * copyright: still under development
 * Author: Christopher Helmes
 * **************************************/

#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <string>

#include "malt.h"
#include "navigation.h"
#include "par_io.h"

int main () {
  //Parameter Input for what has to be calculated
  IO* parameters = IO::getInstance();
  parameters -> set_values("parameters.txt");
  parameters -> print_summary();

  //have to know where is what
  Nav* nav3d = Nav::getInstance();
  //initialize data structures like gauge field, timeslice and storage for eigenvalues and phases
  EigSysCalc calculation;
  calculation.init();
  //read the gauge field from file to object gauge field
  //set up the analysis (Map timeslice from gauge field, smear timeslice, setup SLEPC EPS, )
  calculation.setup();
  //Calculate Eigensystems specified like in parameters.txt, with phase fixing and so on...
  calculation.calc();
  //write out everything that is interesting
  calculation.save();
  std::string name;
  name = parameters -> get_path("res");
  std::cout << nav3d -> get_up(2,0) << std::endl;
  int zahl=123;
  char datei[200];
  sprintf(datei, "%s.%04d", name.c_str(), zahl);
  std::cout << datei  << std::endl;
  return 0;
}
