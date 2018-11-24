#include "DVDCollection.h"
#include <string>
#include <vector>

DVDCollection::DVDCollection()
{
	titleOfTheMovie = "";
	lengthOfTheMovie = "";
	yearOfTheMovie = "";
	actors_actress_Name.push_back("");
	characters.push_back("");
}

DVDCollection::DVDCollection(std::string title, std::string length, std::string year, 
	std::vector<std::string> actor, std::vector<std::string> charac)
{
	titleOfTheMovie = title;
	lengthOfTheMovie = length;
	yearOfTheMovie = year;
	actors_actress_Name = actor;
	characters = charac;
}

void DVDCollection::setMovieTitle(std::string title)
{
	titleOfTheMovie = title;
}

void DVDCollection::setMovieLength(std::string length)
{
	lengthOfTheMovie = length;
}

void DVDCollection::setMovieYear(std::string year)
{
	yearOfTheMovie = year;
}

void DVDCollection::setActorsActressName(std::string actorsName)
{
	actors_actress_Name.push_back(actorsName);
}

void DVDCollection::setCharacters(std::string charac)
{
	characters.push_back(charac);
}

std::string DVDCollection::getMovieTitle() const
{
		return titleOfTheMovie;
}

std::string DVDCollection::getMovieLength() const
{
	return lengthOfTheMovie;
}

std::string DVDCollection::getMovieYear() const
{
	return yearOfTheMovie;
}

std::string DVDCollection::getActorsActressName(std::size_t element) const
{
	return actors_actress_Name[element];
}

std::string DVDCollection::getCharacters(std::size_t element) const
{
	return characters[element];
}

