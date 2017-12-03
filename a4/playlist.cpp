/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   */
/*  Program:  MyTunes Music Player                   */
/*  Author:   Louis Nel                              */
/*  Date:     21-SEP-2017                            */
/*                                                   */
/*  (c) 2017 Louis Nel                               */
/*  All rights reserved.  Distribution and           */
/*  reposting, in part or in whole, requires         */
/*  written consent of the author.                   */
/*                                                   */
/*  COMP 2404 students may reuse this content for    */
/*  their course assignments without seeking consent */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <string>
#include "playlist.h"
using namespace std;
	
Playlist::Playlist(const string & aPlaylistName): name(aPlaylistName){//note base member initialisation
	cout << "Playlist(string&)" << endl;
}
Playlist::Playlist(const Playlist & aPlaylist){
	cout << "Playlist(const Playlist & aPlaylist)" << endl;
	cout << "ERROR: Playlist(const Playlist & aPlaylist) --should never run" << endl;
}

Playlist::~Playlist(){
	cout << "~Playlist(void)" << endl;
    ArrayList<Observer> observers_copy = getObservers();
    for(ArrayList<Observer>::iterator itr = observers_copy.begin(); itr != observers_copy.end(); itr++) {
        this->dettach(*itr);
    }
}
int Playlist::getID(){return -1;}
string Playlist::getName(){return name;}

vector<Track*> & Playlist::getTracks(){return tracks;}

vector<Track*>::iterator Playlist::findPosition(Track & aTrack){
	for (vector<Track*>::iterator itr = tracks.begin() ; itr != tracks.end(); ++itr)
		if(*itr == &aTrack) return itr;
	return tracks.end();
}

void Playlist::addTrack(Track & aTrack){
	//add track if it does not already exist
	vector<Track*>::iterator itr = findPosition(aTrack);
	if(itr == tracks.end()) {
		tracks.push_back(&aTrack);
	}
    notify();
}

void Playlist::removeTrack(Track & aTrack){
	vector<Track*>::iterator itr = findPosition(aTrack);
	if(itr != tracks.end()) {
		tracks.erase(itr);
	}
    notify();
}

string Playlist::toString()const {
	string indent = "     ";
	string s;
	s.append(name);
	s.append("\n");
	s.append(indent + indent + "Playlist Tracks:\n");
	for (vector<Track*>::size_type i = 0 ; i < tracks.size(); i++){
		   s.append(indent + indent + to_string(i) + " " + (tracks[i])->toString() + "\n");
	}
	
	return s;
}
    
void Playlist::update(Subject * subject){
    *this=((Playlist&)*subject);
    return;
}

Playlist & Playlist:: operator =(Playlist & p1){
    //delete name;
    
    name=p1.getName();
    vector<Track*> tracksCopy=p1.getTracks();
    for (vector<Track*>::iterator it = tracks.begin() ; it != tracks.end();0){
        tracks.erase(it);
    }//delete old tracks;
    for (vector<Track*>::iterator it = tracksCopy.begin() ; it != tracksCopy.end();++it){
        (this->tracks).push_back(*it);
    }
    return *this;
}
 


ostream & operator<<(ostream & out, const Playlist & aPlaylist){
	out << aPlaylist.toString() << endl;
	return out;
}
