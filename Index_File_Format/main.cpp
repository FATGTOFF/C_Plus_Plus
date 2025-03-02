#include <algorithm>
#include <array>
#include <cctype>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>


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
};

void gotoLine(std::ifstream& file, const std::size_t num);
unsigned findStartDataLine(std::ifstream& infile);
void findTheWord(const std::vector<Index_File_Format>& word,
	const std::vector<Data_File_Format>&word2,
	const std::string& wordToSearch);
void findTheGlossary(const std::vector<Data_File_Format>& word,
	const std::string& wordToSearch, const char syntacticCategory);
void loadIndexFileFormatData(std::ifstream& inFile, 
	std::vector<Index_File_Format>& index_file_format, unsigned &countLinesOfData);
void loadDataFileFormatData(std::ifstream& inFile, 
	std::vector<Data_File_Format>& data_file_format, unsigned &countLinesOfData);
bool foundNoun(const std::vector<Index_File_Format>& index_file_format_word,
	const std::vector<Data_File_Format>& data_file_format_word, const std::string& dataToSearch);
bool foundVerb(const std::vector<Index_File_Format>& index_file_format_word,
	const std::vector<Data_File_Format>& data_file_format_word, const std::string& dataToSearch);
bool foundAdjective(const std::vector<Index_File_Format>& index_file_format_word,
	const std::vector<Data_File_Format>& data_file_format_word, const std::string& dataToSearch);
bool foundAdverb(const std::vector<Index_File_Format>& index_file_format_word,
	const std::vector<Data_File_Format>& data_file_format_word, const std::string& dataToSearch);


int main()
{
	std::array<const char*, 4> indexFileNames{ "index.adj", "index.adv", "index.noun", "index.verb" };
	std::array<const char*, 4> dataFileNames{ "data.adj", "data.adv", "data.noun", "data.verb" };

	unsigned countLinesOfIndexData{ 0 };
	std::vector<Index_File_Format> index_file_format{};
	index_file_format.emplace_back();

	std::cout << "Loading the Index File Data";

	for (std::size_t iter = 0; iter < indexFileNames.size(); ++iter)
	{

		std::ifstream inIndexFile(indexFileNames.at(iter));

		if (inIndexFile.fail())
		{
			std::cerr << "Error opening the file.\n";
			return -1;
		}

		loadIndexFileFormatData(inIndexFile, index_file_format, countLinesOfIndexData);

		inIndexFile.close();
	}

	unsigned countLinesOfDataFile{ 0 };
	std::vector<Data_File_Format> data_file_format{};

	std::cout << "\nLoading the Data File";

	for (std::size_t iter = 0; iter < dataFileNames.size(); ++iter)
	{
		std::ifstream inDataFile(dataFileNames.at(iter));

		if (inDataFile.fail())
		{
			std::cerr << "Error opening the file.\n";
			return -1;
		}

		loadDataFileFormatData(inDataFile, data_file_format, countLinesOfDataFile);

		inDataFile.close();

	}

	std::cout << "\nIndex File Data Total Count: " << countLinesOfIndexData << std::endl;
	std::cout << "Data File Total Count: " << countLinesOfDataFile << std::endl;

	std::string wordToSearch{};
	bool keepLooping{ true };

	while (keepLooping)
	{
		std::cout << "\nEnter a word to search in the file: ";
		std::cin >> std::ws;
		getline(std::cin, wordToSearch);

		// Convert to lowercase.
		std::transform(wordToSearch.begin(), wordToSearch.end(), wordToSearch.begin(),
			[](unsigned char singleCharacter) { return std::tolower(singleCharacter); });

		findTheWord(index_file_format, data_file_format, wordToSearch);
	}

}

void gotoLine(std::ifstream& file, const std::size_t num)
{
	file.seekg(std::ios::beg);

	for (std::size_t i = 0; i < num - 1; ++i)
	{
		file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

unsigned findStartDataLine(std::ifstream& infile)
{
	unsigned totalCommentLines{ 0 };

	License_Agreement_Format license_agreement_format{};

	while (infile.get(license_agreement_format.firstChar)
		&& infile.get(license_agreement_format.secondChar)
		&& infile.get(license_agreement_format.thirdChar))
	{
		if (isspace(license_agreement_format.firstChar)
			&& isspace(license_agreement_format.secondChar)
			&& isdigit(license_agreement_format.thirdChar))
		{
			infile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			++totalCommentLines;
		}
		else
		{
			break;
		}
	}

	//cout << "Line of Comments: " << totalCommentLines << endl;

	return (totalCommentLines + 1); // Starting line with actual data in the file.
}

void findTheWord(const std::vector<Index_File_Format>& index_file_format_word, const std::vector<Data_File_Format>& data_file_format_word , const std::string& wordToSearch)
{
	std::size_t countTheFinds{ 0 };

	if (foundNoun(index_file_format_word, data_file_format_word, wordToSearch))
	{
		++countTheFinds;
	}
	if (foundVerb(index_file_format_word, data_file_format_word, wordToSearch))
	{
		++countTheFinds;
	}
	if (foundAdjective(index_file_format_word, data_file_format_word, wordToSearch))
	{
		++countTheFinds;
	}
	if (foundAdverb(index_file_format_word, data_file_format_word, wordToSearch))
	{
		++countTheFinds;
	}

	if (0 == countTheFinds)
	{
		std::cout << wordToSearch << " was not found\n";
	}

}

void findTheGlossary(const std::vector<Data_File_Format>& word, const std::string& wordToSearch, const char syntacticCategory)
{

	for (size_t count = 0; count < word.size(); ++count)
	{
		if (word.at(count).synset_offset == wordToSearch && word.at(count).ss_type == syntacticCategory)
		{
			std::cout << word.at(count).gloss << std::endl;
			return;
		}
	}

	//std::cout << wordToSearch << " not found!\n";
}

void loadIndexFileFormatData(std::ifstream& inFile, std::vector<Index_File_Format>& index_file_format, unsigned &countLinesOfData)
{
	const auto startDataLine{ findStartDataLine(inFile) };
	std::string lineOfData{};

	gotoLine(inFile, startDataLine);

	while (std::getline(inFile, lineOfData))
	{
		if (countLinesOfData % 10000 == 0)
		{
			std::cout << ".";
		}

		std::istringstream inStringStream(lineOfData);
		index_file_format.emplace_back();

		inStringStream >> index_file_format.at(countLinesOfData).lemma >>
			index_file_format.at(countLinesOfData).pos >>
			index_file_format.at(countLinesOfData).synset_cnt >>
			index_file_format.at(countLinesOfData).p_cnt;

		if (index_file_format.at(countLinesOfData).p_cnt > 0)
		{
			for (size_t count = 0; count < index_file_format.at(countLinesOfData).p_cnt; ++count)
			{
				std::string tempLineOfData{};
				inStringStream >> tempLineOfData;
				index_file_format.at(countLinesOfData).ptr_symbol.emplace_back(tempLineOfData);
			}

		}

		inStringStream >> index_file_format.at(countLinesOfData).sense_cnt >>
			index_file_format.at(countLinesOfData).tagsense_cnt;

		if (index_file_format.at(countLinesOfData).synset_cnt > 0)
		{
			for (size_t count = 0; count < index_file_format.at(countLinesOfData).synset_cnt; ++count)
			{
				std::string tempLineOfData{};
				inStringStream >> tempLineOfData;
				index_file_format.at(countLinesOfData).synset_offset.emplace_back(tempLineOfData);
			}

		}

		++countLinesOfData;
	}

}

void loadDataFileFormatData(std::ifstream& inFile, std::vector<Data_File_Format>& data_file_format, unsigned &countLinesOfData)
{
	const auto startDataLine2{ findStartDataLine(inFile) };
	std::string lineOfData{};
	data_file_format.emplace_back();

	gotoLine(inFile, startDataLine2);

	inFile >> data_file_format.at(countLinesOfData).synset_offset;
	inFile >> data_file_format.at(countLinesOfData).lex_filenum;
	inFile >> data_file_format.at(countLinesOfData).ss_type;

	inFile.ignore(std::numeric_limits<std::streamsize>::max(), '|');

	while (std::getline(inFile, data_file_format.at(countLinesOfData).gloss))
	{
		if (countLinesOfData % 10000 == 0)
		{
			std::cout << ".";
		}

		++countLinesOfData;
		data_file_format.emplace_back();
		inFile >> data_file_format.at(countLinesOfData).synset_offset;
		inFile >> data_file_format.at(countLinesOfData).lex_filenum;
		inFile >> data_file_format.at(countLinesOfData).ss_type;
		inFile.ignore(std::numeric_limits<std::streamsize>::max(), '|');

	}

}

bool foundNoun(const std::vector<Index_File_Format>& index_file_format_word, const std::vector<Data_File_Format>& data_file_format_word, const std::string& dataToSearch)
{
	std::size_t countFoundNouns{ 0 };

	for (size_t elementPos = 0; elementPos < index_file_format_word.size(); ++elementPos)
	{
		if (index_file_format_word.at(elementPos).lemma == dataToSearch && index_file_format_word.at(elementPos).pos == 'n')
		{
			if (index_file_format_word.at(elementPos).synset_offset.size() == 1)
			{
				std::cout << "The noun " << index_file_format_word.at(elementPos).lemma << " has " << index_file_format_word.at(elementPos).synset_offset.size() << " sense\n";
			}
			else
			{
				std::cout << "The noun " << index_file_format_word.at(elementPos).lemma << " has " << index_file_format_word.at(elementPos).synset_offset.size() << " senses\n";
			}

			for (std::size_t iter = 0; iter < index_file_format_word.at(elementPos).synset_offset.size(); ++iter)
			{
				std::cout << "Noun Glossary [" << iter + 1 << "]: ";
				findTheGlossary(data_file_format_word, index_file_format_word.at(elementPos).synset_offset.at(iter), index_file_format_word.at(elementPos).pos);
			}

			std::cout << "===================================================================\n";

			++countFoundNouns;
			return true;
		}
	}

	if (countFoundNouns > 0)
	{
		return true;
	}
	return false;
}

bool foundVerb(const std::vector<Index_File_Format>& index_file_format_word, const std::vector<Data_File_Format>& data_file_format_word, const std::string& dataToSearch)
{
	std::size_t countFoundVerbs{ 0 };
	for (size_t elementPos = 0; elementPos < index_file_format_word.size(); ++elementPos)
	{
		if (index_file_format_word.at(elementPos).lemma == dataToSearch && index_file_format_word.at(elementPos).pos == 'v')
		{
			if (index_file_format_word.at(elementPos).synset_offset.size() == 1)
			{
				std::cout << "The verb " << index_file_format_word.at(elementPos).lemma << " has " << index_file_format_word.at(elementPos).synset_offset.size() << " sense\n";
			}
			else
			{
				std::cout << "The verb " << index_file_format_word.at(elementPos).lemma << " has " << index_file_format_word.at(elementPos).synset_offset.size() << " senses\n";
			}

			for (std::size_t iter = 0; iter < index_file_format_word.at(elementPos).synset_offset.size(); ++iter)
			{
				std::cout << "Verb Glossary [" << iter + 1 << "]: ";
				findTheGlossary(data_file_format_word, index_file_format_word.at(elementPos).synset_offset.at(iter), index_file_format_word.at(elementPos).pos);
			}

			std::cout << "===================================================================\n";

			++countFoundVerbs;
			return true;
		}
	}

	if (countFoundVerbs > 0)
	{
		return true;
	}
	return false;
}

bool foundAdjective(const std::vector<Index_File_Format>& index_file_format_word, const std::vector<Data_File_Format>& data_file_format_word, const std::string& dataToSearch)
{
	std::size_t countFoundAdjectives{ 0 };
	for (size_t elementPos = 0; elementPos < index_file_format_word.size(); ++elementPos)
	{
		if (index_file_format_word.at(elementPos).lemma == dataToSearch && (index_file_format_word.at(elementPos).pos == 'a' 
			|| index_file_format_word.at(elementPos).pos == 's'))
		{
			if (index_file_format_word.at(elementPos).synset_offset.size() == 1)
			{
				std::cout << "The adjective " << index_file_format_word.at(elementPos).lemma << " has " << index_file_format_word.at(elementPos).synset_offset.size() << " sense\n";
			}
			else
			{
				std::cout << "The adjective " << index_file_format_word.at(elementPos).lemma << " has " << index_file_format_word.at(elementPos).synset_offset.size() << " senses\n";
			}

			for (std::size_t iter = 0; iter < index_file_format_word.at(elementPos).synset_offset.size(); ++iter)
			{
				std::cout << "Adjective Glossary [" << iter + 1 << "]: ";
				findTheGlossary(data_file_format_word, index_file_format_word.at(elementPos).synset_offset.at(iter), 'a');
				findTheGlossary(data_file_format_word, index_file_format_word.at(elementPos).synset_offset.at(iter), 's');
			}

			std::cout << "===================================================================\n";

			++countFoundAdjectives;
			return true;
		}
	}

	if (countFoundAdjectives > 0)
	{
		return true;
	}
	return false;
}

bool foundAdverb(const std::vector<Index_File_Format>& index_file_format_word, const std::vector<Data_File_Format>& data_file_format_word, const std::string& dataToSearch)
{
	std::size_t countFoundAdverbs{ 0 };
	for (size_t elementPos = 0; elementPos < index_file_format_word.size(); ++elementPos)
	{
		if (index_file_format_word.at(elementPos).lemma == dataToSearch && index_file_format_word.at(elementPos).pos == 'r')
		{
			if (index_file_format_word.at(elementPos).synset_offset.size() == 1)
			{
				std::cout << "The adverb " << index_file_format_word.at(elementPos).lemma << " has " << index_file_format_word.at(elementPos).synset_offset.size() << " sense\n";
			}
			else
			{
				std::cout << "The adverb " << index_file_format_word.at(elementPos).lemma << " has " << index_file_format_word.at(elementPos).synset_offset.size() << " senses\n";
			}

			for (std::size_t iter = 0; iter < index_file_format_word.at(elementPos).synset_offset.size(); ++iter)
			{
				std::cout << "Adverb Glossary [" << iter + 1 << "]: ";
				findTheGlossary(data_file_format_word, index_file_format_word.at(elementPos).synset_offset.at(iter), index_file_format_word.at(elementPos).pos);
			}

			std::cout << "===================================================================\n";

			++countFoundAdverbs;
			return true;
		}
	}

	if (countFoundAdverbs > 0)
	{
		return true;
	}
	return false;
}
