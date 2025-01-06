#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "Debug.h"
#include <algorithm> // For the use of the replace function.
#include <array>
#include <cctype>
#include <fstream>
#include <iostream>
#include <limits>
#include <random>
#include <sstream>
#include <string>
#include <vector>

class Dictionary
{
private:
	/*
	  Each index file begins with several lines containing a
		copyright notice, version number and license agreement.
		These lines all begin with two spaces and the line number.
	*/
	struct License_Agreement_Format
	{
		char firstChar{};
		char secondChar{};
		char thirdChar{};
	};


	struct Index_File_Format
	{
		// lower case ASCII text of word or collocation. 
		// Collocations are formed by joining individual 
		// words with an underscore (_ ) character.
		std::string lemma{};

		// Syntactic category: 
		// n for noun files, 
		// v for verb files, 
		// a for adjective files, 
		// r for adverb files.
		char pos{};

		// Number of synsets that lemma is in. 
		// This is the number of senses of the word in WordNet. 
		unsigned synset_cnt{};

		// Number of different pointers that lemma has in 
		// all synsets containing it.
		unsigned p_cnt{};

		// A space separated list of p_cnt different types 
		// of pointers that lemma has in all synsets containing it.
		std::vector<std::string> ptr_symbol{};

		// Same as synset_cnt above. 
		// This is redundant, but the field was 
		// preserved for compatibility reasons.
		unsigned sense_cnt{};

		// Number of senses of lemma that are 
		// ranked according to their frequency 
		// of occurrence in semantic concordance texts.
		unsigned tagsense_cnt{};

		// Byte offset in data.pos file of a synset 
		// containing lemma . Each synset_offset in the list 
		// corresponds to a different sense of lemma in WordNet. 
		// synset_offset is an 8 digit, zero-filled decimal integer
		std::vector<std::string> synset_offset{};

		Index_File_Format() = default;
	};

	struct Data_File_Format
	{
		// Current byte offset in the file represented 
		// as an 8 digit decimal integer.
		std::string synset_offset{};

		// Two digit decimal integer corresponding to 
		// the lexicographer file name containing the synset.
		unsigned lex_filenum{};

		// One character code indicating the synset type:
		// n    NOUN
		// v    VERB
		// a    ADJECTIVE
		// s    ADJECTIVE SATELLITE
		// r    ADVERB
		char ss_type{};


		// Each synset contains a gloss. A gloss is represented 
		// as a vertical bar (| ), followed by a text string 
		// that continues until the end of the line. The gloss 
		// may contain a definition, one or more example 
		// sentences, or both.
		std::string gloss{};

		Data_File_Format() = default;
	};

	const std::array<const char*, 4> indexFileNames{ ".\\Text_Files\\index.adj", ".\\Text_Files\\index.adv", 
		".\\Text_Files\\index.noun", ".\\Text_Files\\index.verb" };
	const std::array<const char*, 4> dataFileNames{ ".\\Text_Files\\data.adj", ".\\Text_Files\\data.adv", 
		".\\Text_Files\\data.noun", ".\\Text_Files\\data.verb" };
	std::string wordToSearch{};
	mutable std::string originalWord{};
	std::vector<Index_File_Format> index_file_format{};
	std::vector<Data_File_Format> data_file_format{};
	std::size_t countLinesOfIndexData{ 0 };
	std::size_t countLinesOfDataFile{ 0 };


	void gotoLine(std::ifstream& file, const std::size_t num) const;
	unsigned findStartDataLine(std::ifstream& infile) const;
	void findTheWord(const std::vector<Index_File_Format>& index_file_format_word,
		const std::vector<Data_File_Format>& data_file_format_word,
		const std::string& wordToSearch) const;
	void findTheGlossary(const std::vector<Data_File_Format>& data_file_format_word,
		const std::string& wordToSearch, const char syntacticCategory) const;
	void loadIndexFileFormatData(std::ifstream& inFile,
		std::vector<Index_File_Format>& index_file_format, std::size_t& countLinesOfData) const;
	void loadDataFileFormatData(std::ifstream& inFile,
		std::vector<Data_File_Format>& data_file_format_word, std::size_t& countLinesOfData) const;

	bool foundNoun(const std::vector<Index_File_Format>& index_file_format_word,
		const std::vector<Data_File_Format>& data_file_format_word, const std::string& dataToSearch) const;
	bool foundVerb(const std::vector<Index_File_Format>& index_file_format_word,
		const std::vector<Data_File_Format>& data_file_format_word, const std::string& dataToSearch) const;
	bool foundAdjective(const std::vector<Index_File_Format>& index_file_format_word,
		const std::vector<Data_File_Format>& data_file_format_word, const std::string& dataToSearch) const;
	bool foundAdverb(const std::vector<Index_File_Format>& index_file_format_word,
		const std::vector<Data_File_Format>& data_file_format_word, const std::string& dataToSearch) const;

	std::size_t randomNumber(std::size_t) const;

public:
	Dictionary() = default;
	~Dictionary() = default;

	std::string getOriginalWord() const;
	std::string getModifiedWord() const;
	std::size_t getTotalCountOfWords() const;

	void findTheWord(const std::string& wordToSearch) const;
	void loadAllData();

};

#endif