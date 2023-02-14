
#pragma once
#include<string>
#include <fstream>
#include <queue>

class videoList
{
	
private:
	struct moveNode
	{
		
		int vidID;
		std::string vidTitle;
		std::string vidGenre;
		std::string vidProd;
		int vidCopy;
		std::string vidImage;
		struct moveNode* next;

	} *movPTR;
	int movieSize;
	moveNode* head;
public:
	videoList();
	void readMFile();
	void addVideo();
	void rentVideo(int myID);
	void returnVideo(int myID);
	void vidDetails(int myID);
	void vidDisplayMovies();
	void vidAvail(int myID);
	void saveMovie();
	void vidLoad(int vidID);
	
};

