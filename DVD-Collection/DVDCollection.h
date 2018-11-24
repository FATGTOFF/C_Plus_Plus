#ifndef DVDCOLLECTION_H
#define DVDCOLLECTION_H
#include <string>
#include <vector>

class DVDCollection
{
private:
	std::string titleOfTheMovie;
	std::string lengthOfTheMovie; // Change it from std::string to int.
	std::string yearOfTheMovie;// Change it from std::string to int.
	std::vector <std::string> actors_actress_Name;
	std::vector <std::string> characters;
	std::size_t numElements;

public:
	// Constructor
	DVDCollection();
	DVDCollection(std::string, std::string, std::string,std::vector<std::string>,std::vector<std::string>);

	//Setters
	void setMovieTitle(std::string);
	void setMovieLength(std::string);
	void setMovieYear(std::string);
	void setActorsActressName(std::string);
	void setCharacters(std::string);

	//Getters.
	std::string getMovieTitle() const;
	std::string getMovieLength() const;
	std::string getMovieYear() const;
	std::string getActorsActressName(std::size_t) const;
	std::string getCharacters(std::size_t) const;

};
#endif
