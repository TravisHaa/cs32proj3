#include "StudentWorld.h"
#include "GameConstants.h"
#include "Level.h"
#include <iostream> // defines the overloads of the << operator
#include <sstream>  // defines the type std::ostringstream
#include <vector>
#include <string>
#include <list>
using namespace std;

GameWorld* createStudentWorld(string assetPath)
{
    return new StudentWorld(assetPath);
}

// Students:  Add code to this file, StudentWorld.h, Actor.h, and Actor.cpp



StudentWorld::StudentWorld(string assetPath)
: GameWorld(assetPath)
{
}



int StudentWorld::init()
{
    Level lev(assetPath());
   
    vector <string> lvlnum;
    for(int i = 0; i <=99;i++)
    {
        ostringstream lvl;
        lvl << "level" << setw(2)  << setfill('0') << i << ".txt";// Set width to 2 and fill with '0'
        lvlnum.push_back(lvl.str());
    }
    
//
    Level::LoadResult result = lev.loadLevel(lvlnum[0]);
    if (result == Level::load_fail_file_not_found)
    cerr << "Could not find" << lvlnum[0] << "data file\n";
    else if (result == Level::load_fail_bad_format)
    {
        cerr << "Your level was improperly formatted\n";
        return GWSTATUS_LEVEL_ERROR;
    }
    else if (result == Level::load_success)
    {
    cerr << "Successfully loaded level\n";
        
        for(int x = 0; x <= 15; x++)
        {
            for(int y = 0; y <= 15; y++)
            {
                Level::MazeEntry ge = lev.getContentsOf(x,y); // x=5, y=10
                switch (ge)
                {
                  case Level::player:
                        m_player = new player(this, x, y);
                      break;
                  case Level::wall:
                    {
                        actors.push_back(new wall(this, x, y));
                        break;
                    }
                  case Level::empty:
                  
                  break;
                  case Level::exit:
                  
                  break;
                  case Level::horiz_ragebot:
                  
                  break;
                  case Level::vert_ragebot:
                  
                  break;
                  case Level::thiefbot_factory:
                  
                  break;
                  case Level::mean_thiefbot_factory:
                  
                  break;
                  case Level::marble:
                  
                  break;
                  case Level::pit:
                  
                  break;
                  case Level::crystal:
                  
                  break;
                  case Level::restore_health:
                  
                  break;
                  case Level::extra_life:
                  
                  break;
                  case Level::ammo:
                  
                  break;
                  }
                                              }
        }
    
    }
    return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move()
{
    m_player->doSomething();
    list<actor*>::iterator it;
    for(it = actors.begin(); it != actors.end(); it++)
    {
        (*it)->doSomething();
    }
    
    // This code is here merely to allow the game to build, run, and terminate after you type q

    setGameStatText("Game will end when you type q");
    
    return GWSTATUS_CONTINUE_GAME;
}

bool StudentWorld::isValidPos(int x, int y)
{
    list<actor*>::iterator it;
    for(it = actors.begin(); it != actors.end(); it++)
    {
        if((*it)->getX() == x && (*it)->getY() == y && !((*it)->canStepOn()) )//y doesnt this work if i do (*it)->canStepOn(), then return true
            
        {
            return false;
        }
    }
    return true;
}

StudentWorld::~StudentWorld()
{
    cleanUp();
    delete m_player;
}

void StudentWorld::cleanUp()
{
    list<actor*>::iterator it = actors.begin();
    while(it != actors.end())
    {
        delete(*it);
        it = actors.erase(it);
    }
//    delete m_player;
}
