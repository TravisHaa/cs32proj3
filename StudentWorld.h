#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "Level.h"
#include <string>
#include "Actor.h"
#include <list>
using namespace std;

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class StudentWorld : public GameWorld
{
public:
  StudentWorld(std::string assetPath);
    ~StudentWorld();
  virtual int init();
  virtual int move();
  virtual void cleanUp();
   
    
    bool isValidPos(int x, int y);
       

private:
    int playerx;
    int playery;
    player* m_player;
    list<actor*> actors;
};

#endif // STUDENTWORLD_H_
