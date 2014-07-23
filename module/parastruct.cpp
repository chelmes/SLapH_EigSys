#include "parastruct.h"

void IO::set_values(const char* infile) {
  //one line of config file
  std::string config_line;
  //key and value to divide string to
  std::string keyword;
  std::string value;
  
  //three map class instances for int double and const char
  std::map <std::string, std::string> path;
  std::map <std::string, int> integer;
  std::map <std::string, double> floating;

  //stream for config file
  std::fstream config;
  config.open(infile, std::fstream::in);

  //get each line of configuration into config_line
  while (!std::getline(config, config_line).eof()){
    if(config_line[0] != '#') {
        //find first occurence of '=' in each line and divide strings
        unsigned pos = config_line.find_first_of("=");
        keyword = config_line.substr(0,(pos-1));
        value = config_line.substr( (pos+2), std::string::npos);

        //String valued map variables
        if (keyword == "config_path") {
          path["config_path"] = value;
        }
        if (keyword == "result_path") {
          path["result_path"] = value;
        }

        //Integer valued map variables
        if (keyword == "LT" ) {
          integer["LT"] = atoi(value.c_str());
        }
        if (keyword == "LX" ) {
          integer["LX"] = atoi(value.c_str());
        }
        if (keyword == "NEV") {
          integer["NEV"] = atoi(value.c_str());
        }
        if (keyword == "iter") {
          integer["iter"] = atoi(value.c_str());
        }

        //floating point valued map variables
        if (keyword == "alpha_1") {
          floating["alpha_1"] = atof(value.c_str());
        }
        if (keyword == "alpha_2") {
          floating["alpha_2"] = atof(value.c_str());
        }
        if (keyword == "LAM_L") {
          floating["LAM_L"] = atof(value.c_str());
        }
        if (keyword == "LAM_C") {
          floating["LAM_C"] = atof(value.c_str());
        }
    }
  }
  config.close();

  //set the values
  config_path = path["config_path"];
  result_path = path["result_path"];

  LT = integer["LT"];
  LX = integer["LX"];
  LY=LX;
  LZ=LX;
  
  NEV = integer["NEV"];
  NCOL = 3;
  NDIR = 4;
  V3 = LX*LY*LZ;
  
  V_TS = LX*LY*LZ*NDIR*NCOL*NCOL*2; //2 is for complex
  V4_LIME = V_TS * LT;
  
  iter = integer["iter"];
  alpha_1 = floating["alpha_1"];
  alpha_2 = floating["alpha_2"];

  LAM_L = floating["LAM_L"];
  LAM_C = floating["LAM_C"];

}

void IO::print_summary() {
  std::cout << "Configuration Summary for the eigensystem calculation:" << std::endl;
  std::cout << "------------------------------------------------------" << std::endl;
  std::cout << "Lattice size is:                                   " << LT << " x " << LX << "^3" << std::endl;
  std::cout << "Number of eigenvectors is:                         " << NEV << std::endl;
  std::cout << "Hyp-smearing parameters (alpha_1, alpha_2, iter):  " << alpha_1 << ", " << alpha_2 << ", " << iter << std::endl;
  std::cout << "Using Chebyshev parameters:                        Lambda_l = " << LAM_L << " Lambda_c = " << LAM_C << std::endl;
  std::cout << "Configurations are read in from:                   " << config_path << std::endl;
  std::cout << "Results are stored in:                             " << result_path << std::endl;
}

int IO::get_int(std::string spec) {
  if (spec == "LT") {
    return LT;
  }

  if (spec == "LX" || spec == "LY" || spec == "LZ") {
    return LX;
  }

  if (spec == "NEV") {
    return NEV;
  }

  if (spec == "NDIR") {
    return NDIR;
  }

  if (spec == "NCOL") {
    return NCOL;
  }

  if (spec == "V3") {
    return V3;
  }

  if (spec == "V4_LIME") {
    return V4_LIME;
  }

  if (spec == "V_TS") {
    return V_TS;
  }

  if (spec == "iter") {
    return iter;
  }
  else return -1;

}

double IO::get_float(std::string spec) {
  if (spec == "alpha_1") {
    return alpha_1;
  }

  if (spec == "alpha_2") {
    return alpha_2;
  }
  
  if (spec == "lambda_l") {
    return LAM_L;
  }

  if (spec == "lambda_c") {
    return LAM_C;
  }
  else return -1;
}

std::string IO::get_path(std::string spec) {
  if (spec == "conf") {
    return config_path;
  }

  if (spec == "res") {
    return result_path;
  }

  else return "not found";
}



