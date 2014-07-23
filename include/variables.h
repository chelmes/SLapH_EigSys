  /*
   * variables.h
   * Holds needed lattice info : 
   * 	- L0...L3: euclidean dimensions
 * 	- V3: 3d-Volume-size
 *	- NDIR: # directions
 *	- NCOL: # colors
 *	- V_TS: # entries in ildg-timeslice
 *	- MAT_ENTRIES: # rows/cols for PETSc-Matrix
 * Created on: Aug 26, 2013
 * Author: christopher helmes
 */

#ifndef VARIABLES_H_
#define VARIABLES_H_

//Geometry (set up for equal spatial extent)
const int L0 = 48; //nt
const int L1 = 24; //nx
const int L2 = L1; //ny
const int L3 = L1; //nz
const int V3 = L1*L2*L3;
const int NDIR = 4;
const int NCOL = 3;
const int V_TS = L1*L2*L3*NDIR*NCOL*NCOL*2; //2 is for complex
const int V_4_LIME = V_TS * L0;
const int MAT_ENTRIES = NCOL*V3;
const int NEV = 120;

//Chebyshev-acceleration
const double LAM_L = 15;
const double LAM_C = 12;

//random seed
const unsigned int RND_SEED = 1227;


#endif /* VARIABLES_H_ */
