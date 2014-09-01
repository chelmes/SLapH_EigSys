// Class handling the calculation of eigensystems 
#ifndef _MALT_H_
#define _MALT_H_

class EigSysCalc {
  public:
    virtual ~EigSysCalc();
    virtual void visitEigensystem(Eigensystem eigsys&) = 0;
    virtual void visitGaugefield(Gaugefield config&) = 0;
    virtual void visitAnalysis(Analysis analysis&) = 0;
  protected:
    EigSysCalc();
}

class Component {
  public:
    virtual ~Component();
    virtual void accept(Visitor&) = 0;
}

#endif //_MALT_H_
