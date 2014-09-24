// Visiting methods for all components taking part in the calculation
#ifndef _MALT_H_
#define _MALT_H_

class VisitCalc {
  public:
    virtual ~VisitCalc();
    virtual void visitEigensystem(Eigensystem eigsys&) = 0;
    virtual void visitGaugefield(Gaugefield config&) = 0;
    virtual void visitAnalysis(Analysis analysis&) = 0;

  protected:
    VisitCalc();
};

class Element {
  public:
    virtual ~Element();
    virtual void accept(VisitCalc&) = 0;
};


    //initializes the calculation object, makes sure memory is allocated in the
    //right way
    void init();
    //read in everything necessary, gauge fields, evtl. phases, eigensystems,
    //etc.
    void setup();
    //actual calculation of the eigensystem, all the PETSc stuff should happen
    //here mainly relying on Analysis object
    void calc();
    //save everything 
    void save();

#endif //_MALT_H_
