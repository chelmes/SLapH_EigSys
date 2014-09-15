// Class handling the calculation of eigensystems 
#ifndef _MALT_H_
#define _MALT_H_

class EigSysCalc {
  public:
    virtual ~EigSysCalc();
    virtual void visitEigensystem(Eigensystem eigsys&) = 0;
    virtual void visitGaugefield(Gaugefield config&) = 0;
    virtual void visitAnalysis(Analysis analysis&) = 0;

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

  protected:
    EigSysCalc();
}

class Component {
  public:
    virtual ~Component();
    virtual void accept(Visitor&) = 0;
}

#endif //_MALT_H_
