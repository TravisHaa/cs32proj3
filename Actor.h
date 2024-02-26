#ifndef ACTOR_H_
#define ACTOR_H_
#include <map>
#include "GraphObject.h"
class StudentWorld;
using namespace std;
// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

class actor: public GraphObject
{
public:
    actor(StudentWorld* sw, int image, int x, int y, int dir, bool step, int starthp);
    virtual void doSomething() = 0;
    StudentWorld* getWorld()
    {
        return m_sw;
    }
    bool canStepOn()
    {
        return step;
    }
    bool isAlive()
    {
        return hp >= 0;
    }
private:
    StudentWorld* m_sw;
    map<int, int> walls;
    bool step;
    int hp;
    
};
//player
class player: public actor
{
public:
    player(StudentWorld* sw, int x, int y);
    virtual void doSomething();
//    void moveIfPossible(int destX, int destY, int dir);
    
private:
    int peas;
};
//wall
class wall: public actor
{
public:
    wall(StudentWorld* sw, int x,int y);
    virtual void doSomething();
    
    
};

//pea
class pea: public actor
{
public:
    pea(StudentWorld* sw, int x, int y, int dir);
private:
    
};



#endif // ACTOR_H_
