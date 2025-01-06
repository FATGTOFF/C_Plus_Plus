#include "Dictionary.h"

std::string Dictionary::getOriginalWord() const
{
	return originalWord;
}

std::string Dictionary::getModifiedWord() const
{
	auto random = randomNumber(index_file_format.size() - 1);
	originalWord = index_file_format.at(random).lemma;

	// Take the word and replace the -, _ and ' to spaces.
	std::string updatedWord{ index_file_format.at(random).lemma };

#ifndef DEBUG_HANGMAN

		std::replace(updatedWord.begin(), updatedWord.end(), '-', ' ');
		std::replace(updatedWord.begin(), updatedWord.end(), '_', ' ');
		std::replace(updatedWord.begin(), updatedWord.end(), '\'', ' ');

#endif

#ifdef DEBUG_HANGMAN

		std::cout << updatedWord << '\n';

#endif


	return updatedWord;
}

std::size_t Dictionary::getTotalCountOfWords() const
{
	return countLinesOfIndexData;
}

void Dictionary::findTheWord(const std::string& word_To_Search) const
{
	findTheWord(index_file_format, data_file_format, word_To_Search);
}

std::size_t Dictionary::randomNumber(std::size_t max) const
{
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<std::size_t> distrib(0, max);

	const std::size_t random = distrib(rng);

	return random;
}

void Dictionary::gotoLine(std::ifstream& file, const std::size_t num) const
{
	file.seekg(std::ios::beg);

	for (std::size_t i = 0; i < num - 1; ++i)
	{
		file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

unsigned Dictionary::findStartDataLine(std::ifstream& infile) const
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

#ifdef DEBUG_HANGMAN

		std::cout << "\nLine of Comments: " << totalCommentLines << '\n';
#endif

	return (totalCommentLines + 1); // Starting line with actual data in the file.
}

void Dictionary::findTheWord(const std::vector<Index_File_Format>& index_file_format_word, 
	const std::vector<Data_File_Format>& data_file_format_word, const std::string& word_To_Search) const
{
	std::size_t countTheFinds{ 0 };

	if (foundNoun(index_file_format_word, data_file_format_word, word_To_Search))
	{
		++countTheFinds;
	}
	if (foundVerb(index_file_format_word, data_file_format_word, word_To_Search))
	{
		++countTheFinds;
	}
	if (foundAdjective(index_file_format_word, data_file_format_word, word_To_Search))
	{
		++countTheFinds;
	}
	if (foundAdverb(index_file_format_word, data_file_format_word, word_To_Search))
	{
		++countTheFinds;
	}

	if (0 == countTheFinds)
	{
		std::cout << word_To_Search << " was not found\n";
	}
}

void Dictionary::findTheGlossary(const std::vector<Data_File_Format>& data_file_format_word, 
	const std::string& wordtosearch, const char syntacticCategory) const
{

	for (size_t count = 0; count < data_file_format_word.size(); ++count)
	{
		if (data_file_format_word.at(count).synset_offset == wordtosearch && data_file_format_word.at(count).ss_type == syntacticCategory)
		{
			std::cout << data_file_format_word.at(count).gloss << '\n';
			return;
		}
	}

}

void Dictionary::loadIndexFileFormatData(std::ifstream& inFile, 
	std::vector<Index_File_Format>& index_file_format_word, std::size_t& countLinesOfData) const
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
		index_file_format_word.emplace_back();

		inStringStream >> index_file_format_word.at(countLinesOfData).lemma >>
			index_file_format_word.at(countLinesOfData).pos >>
			index_file_format_word.at(countLinesOfData).synset_cnt >>
			index_file_format_word.at(countLinesOfData).p_cnt;

#ifdef DEBUG_HANGMAN

			std::ofstream listOfWords{};
			listOfWords.open("listOfWords_Alphabetized.txt", std::ios_base::app);
			if (listOfWords.fail())
			{
				std::cerr << "Error creating the file.\n";
				return;
			}
			else
			{
				listOfWords << index_file_format_word.at(countLinesOfData).lemma << '\n';
			}

			listOfWords.close();
#endif

		if (index_file_format_word.at(countLinesOfData).p_cnt > 0)
		{
			for (size_t count = 0; count < index_file_format_word.at(countLinesOfData).p_cnt; ++count)
			{
				std::string tempLineOfData{};
				inStringStream >> tempLineOfData;
				index_file_format_word.at(countLinesOfData).ptr_symbol.emplace_back(tempLineOfData);
			}

		}

		inStringStream >> index_file_format_word.at(countLinesOfData).sense_cnt >>
			index_file_format_word.at(countLinesOfData).tagsense_cnt;

		if (index_file_format_word.at(countLinesOfData).synset_cnt > 0)
		{
			for (size_t count = 0; count < index_file_format_word.at(countLinesOfData).synset_cnt; ++count)
			{
				std::string tempLineOfData{};
				inStringStream >> tempLineOfData;
				index_file_format_word.at(countLinesOfData).synset_offset.emplace_back(tempLineOfData);
			}

		}

		++countLinesOfData;
	}

}

void Dictionary::loadDataFileFormatData(std::ifstream& inFile, 
	std::vector<Data_File_Format>& data_file_format_word, std::size_t& countLinesOfData) const
{
	const auto startDataLine{ findStartDataLine(inFile) };
	std::string lineOfData{};
	data_file_format_word.emplace_back();

	gotoLine(inFile, startDataLine);

	inFile >> data_file_format_word.at(countLinesOfData).synset_offset;
	inFile >> data_file_format_word.at(countLinesOfData).lex_filenum;
	inFile >> data_file_format_word.at(countLinesOfData).ss_type;

	inFile.ignore(std::numeric_limits<std::streamsize>::max(), '|');

	while (std::getline(inFile, data_file_format_word.at(countLinesOfData).gloss))
	{
		if (countLinesOfData % 10000 == 0)
		{
			std::cout << ".";
		}

		++countLinesOfData;
		data_file_format_word.emplace_back();
		inFile >> data_file_format_word.at(countLinesOfData).synset_offset;
		inFile >> data_file_format_word.at(countLinesOfData).lex_filenum;
		inFile >> data_file_format_word.at(countLinesOfData).ss_type;
		inFile.ignore(std::numeric_limits<std::streamsize>::max(), '|');

	}
}

void Dictionary::loadAllData()
{

#ifdef DEBUG_HANGMAN

	std::cout << "Loading the Index File Data";

#else

	std::cout << "Loading the words";

#endif


	for (std::size_t iter = 0; iter < indexFileNames.size(); ++iter)
	{

		std::ifstream inIndexFile(indexFileNames.at(iter));

		if (inIndexFile.fail())
		{
			std::cerr << "Error opening the file.\n";
			return;
		}

#ifdef DEBUG_HANGMAN

		std::cout << "\nLoading data from " << indexFileNames.at(iter) << '\n';

#endif
		loadIndexFileFormatData(inIndexFile, index_file_format, countLinesOfIndexData);

		inIndexFile.close();
	}

#ifdef DEBUG_HANGMAN

		std::cout << "\nLoading the Data File";
#endif

	for (std::size_t iter = 0; iter < dataFileNames.size(); ++iter)
	{
		std::ifstream inDataFile(dataFileNames.at(iter));

		if (inDataFile.fail())
		{
			std::cerr << "Error opening the file.\n";
			return;
		}

#ifdef DEBUG_HANGMAN

		std::cout << "\nLoading data from " << dataFileNames.at(iter) << '\n';

#endif

		loadDataFileFormatData(inDataFile, data_file_format, countLinesOfDataFile);

		inDataFile.close();

	}

#ifdef DEBUG_HANGMAN

		std::cout << "\nIndex File Data Total Count: " << countLinesOfIndexData << std::endl;
		std::cout << "Data File Total Count: " << countLinesOfDataFile << std::endl;
#else
		std::cout << "\n" << countLinesOfIndexData << " words loaded!\n";
#endif

}

bool Dictionary::foundNoun(const std::vector<Index_File_Format>& index_file_format_word, 
	const std::vector<Data_File_Format>& data_file_format_word, const std::string& dataToSearch) const
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

bool Dictionary::foundVerb(const std::vector<Index_File_Format>& index_file_format_word, 
	const std::vector<Data_File_Format>& data_file_format_word, const std::string& dataToSearch) const
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

bool Dictionary::foundAdjective(const std::vector<Index_File_Format>& index_file_format_word, 
	const std::vector<Data_File_Format>& data_file_format_word, const std::string& dataToSearch) const
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

bool Dictionary::foundAdverb(const std::vector<Index_File_Format>& index_file_format_word, 
	const std::vector<Data_File_Format>& data_file_format_word, const std::string& dataToSearch) const
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
