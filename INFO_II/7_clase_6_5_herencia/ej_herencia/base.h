#ifndef BASE_H
#define BASE_H

class Base
{
public:
    Base();
    Base(int xx);
    ~Base();
    void setX(int xx) { x = xx; }
    int getX(void) const { return x; }
    int getY(void) const {return y; }
    void display();
    Base& operator= (const Base&);

private:
    int x;
protected:
    int y = 8;
};

#endif // BASE_H
