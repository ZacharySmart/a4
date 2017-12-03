/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   */
/*  Program:  MyTunes Music Player                   */
/*   Contributors:  Zachary Smart 1009974444         */
/*                   Louis Nel                       */
/*  Date:     Nov 2017                               */
/*                                                   */
/*  (c) Nov 2017                                     */
/*  All rights reserved.  Distribution and           */
/*  reposting, in part or in whole, requires         */
/*  written consent of the author.                   */
/*                                                   */
/*  COMP 2404 students may reuse this content for    */
/*  their course assignments without seeking consent */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

//mytunes_collection.h

#include <ostream>
#include <vector>
#include <string>
using namespace std;
#include "UI.h"


template <typename T>

class MyTunesCollection {
    /*
     could represent any of the previous collection classes
     */
public:
    MyTunesCollection(){
    }
    ~MyTunesCollection(void){
        for(int i=0; i<collection.size(); i++)
            delete collection[i]; //delete songs in this container
    }
    vector<T*> getCollection(){
        return collection; //return copy of collection
    }
    typename vector<T*>::iterator findPosition(T & aT){
        for (typename vector<T*>::iterator it = collection.begin() ; it != collection.end(); ++it)
            if(*it == &aT) return it;
        return collection.end();
    }
    T * findByID(int anID){
        for (typename vector<T*>::iterator it = collection.begin() ; it != collection.end(); ++it)
            if((*it)->getID() == anID) return *it;
        return NULL;
    }
    void add(T & aT){
        collection.push_back(&aT);
    }
    void remove(T & aT){
        typename vector<T*>::iterator index = findPosition(aT);
        if(index != collection.end()) {
            T * theT = *index;
            collection.erase(index);
            delete theT; //free the memory of the T
        }
    }
    void showOn(UI & view) {
        view.printOutput("MyTunesCollection:");
        for(int i=0; i<collection.size(); i++)
            view.printOutput((*collection[i]).toString());
    }
    void showOn(UI & view, int memberID)  {
        view.printOutput("MyTunesCollection:");
        T * t = findByID(memberID);
        if( t != NULL)
            view.printOutput(t->toString());
    }
    void showOn(UI & view, const string & memberID) {
        view.printOutput("MyTunesCollection:");
        T * t = findByUserID(memberID);
        if( t != NULL)
            view.printOutput(t->toString());
    }
    T * findByUserID(const string & aUserID) {
        for (typename vector<T*>::iterator itr = collection.begin() ; itr != collection.end(); ++itr)
            if(((*itr)->getUserID()).compare(aUserID) == 0) return *itr;
        return NULL;
    }

    
private:
    vector<T*> collection;
    //typename vector<T*>::iterator findPosition(T & aT);


friend ostream & operator<<(ostream & out, const MyTunesCollection & aCol){
    for (typename vector<T*>::iterator it = aCol->collection.begin() ; it != aCol->collection.end(); ++it)
        out<<aCol->collecion[it];
}
};
