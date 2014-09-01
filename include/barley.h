#ifndef _BARLEY_H_
#define _BARLEY_H_
class Element {

  public:
    virtual ~Element();
    virtual void Accept(EigSysCalc& eigsyscalc) = 0;
  protected:
    Element();
}
#endif //_BARLEY_H_
