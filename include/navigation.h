#ifndef _NAVIGATION_H_
#define _NAVIGATION_H_

//This Class handles the navigation on each timeslice. Two 2d-arrays are
//allocated with the corresponding size. The lookup tables are 3dimensional. 

class Nav {

  private:

    const int **iup;
    const int **idown;
    const int vol;

  protected:
    init();

  public:
    // Constructor
    Nav();
    // Destructor
    ~Nav();
    //Get index in distance. Org stands for the origin, dir for the direction
    int dist_ind(const int org, const int dir, const int dist);

};

#endif //_NAVIGATION_H_
