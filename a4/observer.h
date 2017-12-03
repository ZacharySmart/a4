#include <string.h> 

class Subject; 
class Observer { 
  public:
    virtual void update(Subject * subject){
        return;
    }

  int operator==(const Observer & obs) const { 
    return this == & obs; 
  } 

};
