#include "Actor.h"
#include "StudentWorld.h"
#include <map>

// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.cpp
//default dir is none, step is false, etc
actor::actor(StudentWorld* sw, int image, int x, int y, int dir = none, bool step = false, int hp = 0)
:GraphObject(image, x, y, dir), m_sw(sw) {setVisible(false);}





player::player(StudentWorld* sw, int x, int y)
:actor(sw, IID_PLAYER, x, y, right, 3)
{
    setVisible(true);
}

void player::doSomething() {
    int ch;
    
    
    if (getWorld()->getKey(ch)) {
        switch (ch) {
            case KEY_PRESS_LEFT:
            {
                if(getWorld()->isValidPos(getX() - 1, getY())){
                    moveTo(getX() - 1, getY());
                    setDirection(left);
                }
                
                
                break;
            }
            case KEY_PRESS_RIGHT:
            {
                if(getWorld()->isValidPos(getX() + 1, getY())){
                    moveTo(getX() + 1, getY());
                    setDirection(right);
                }
                
                break;
            }
            case KEY_PRESS_UP:
            {
                if(getWorld()->isValidPos(getX(), getY()+1)){
                    moveTo(getX(), getY()+1);
                    setDirection(up);
                }
                
                
                break;
            }
            case KEY_PRESS_DOWN:
            {
                if(getWorld()->isValidPos(getX(), getY()-1)){
                    moveTo(getX(), getY()-1);
                    setDirection(down);
                }
            case KEY_PRESS_SPACE:
                {
                    
                    break;
                }
            }
        }
    }
}

pea::pea(StudentWorld* sw, int x, int y, int dir)
:actor(sw, IID_PEA, x, y, dir)
{
    setVisible(true);
}

wall::wall(StudentWorld* sw, int x,int y)
:actor(sw, IID_WALL, x, y){
    setVisible(true);
}

 void wall::doSomething()
{}
