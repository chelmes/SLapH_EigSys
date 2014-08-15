class Element {

  public:
    virtual ~Element();
    virtual void Accept(EigSysCalc& eigsyscalc) = 0;
  protected:
    Element();
}
