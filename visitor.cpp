#include <iostream>
#include <string>
using namespace std;

class Element1;
class Element2;
class Element3;

// 1. Create a "visitor" base class w/ a visit() method for every "element" type

class Visitor
{
  public:
    virtual void visit(Element1 *element) = 0;
    virtual void visit(Element2 *element) = 0;
    virtual void visit(Element3 *element) = 0;
};
// 2. Add an accept(Visitor) method to the "element" hierarchy
class Element
{
  public:
    virtual void accept(Visitor &visitor) = 0;
};

class Element1: public Element
{
  public:
     
    string element1()
    {
        return "Element1";
    }

	void accept(Visitor &visitor)
	{
  		visitor.visit(this);
	}

};

class Element2: public Element
{
  public:
     
    string element2()
    {
        return "Element2";
    }

    void accept(Visitor &visitor)
	{
  		visitor.visit(this);
	}

};

class Element3: public Element
{
  public:
     
    string element3()
    {
        return "Element3";
    }

    void accept(Visitor &visitor)
	{
  		visitor.visit(this);
	}

};

// 3. Create a "visitor" derived class for each "operation" to do on "elements"
class UpVisitor: public Visitor
{
     void visit(Element1 *element)
    {
        cout << "do Up on " + element->element1() << '\n';
    }
     void visit(Element2 *element)
    {
        cout << "do Up on " + element->element2() << '\n';
    }
     void visit(Element3 *element)
    {
        cout << "do Up on " + element->element3() << '\n';
    }
};

class DownVisitor: public Visitor
{
     void visit(Element1 *element)
    {
        cout << "do Down on " + element->element1() << '\n';
    }
     void visit(Element2 *element)
    {
        cout << "do Down on " + element->element2() << '\n';
    }
     void visit(Element3 *element)
    {
        cout << "do Down on " + element->element3() << '\n';
    }
};

int main()
{
  Element *list[] = 
  {
    new Element1(), new Element2(), new Element3()
  };
  UpVisitor up; // 4. Client creates
  DownVisitor down; //    "visitor" objects
  for (int i = 0; i < 3; i++)
  //    and passes each
    list[i]->accept(up);
  //    to accept() calls
  for (int i = 0; i < 3; i++)
    list[i]->accept(down);
}