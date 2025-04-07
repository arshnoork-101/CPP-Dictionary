/*/////////////////////////////////////////////////////////////////////////
						  Workshop - 1
Full Name  : Arshnoor Kaur
Student ID#: 138345236
Email      : arshnoor-kaur@myseneca.ca
Section    : NJJ

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_DICTIONARY_H
#define SENECA_DICTIONARY_H

#include <string>

namespace seneca
{
	enum class PartOfSpeech
	{
		Unknown,
		Noun,
		Pronoun,
		Adjective,
		Adverb,
		Verb,
		Preposition,
		Conjunction,
		Interjection,
	};

	struct Word
	{
		std::string word{};
		std::string definition{};
		PartOfSpeech pos = PartOfSpeech::Unknown;
	};

	class Dictionary
	{
		Word* m_words{ nullptr };  // Initialize to nullptr to prevent undefined behavior
		size_t m_size{ 0 };

	public:
		// Constructors
		Dictionary();
		Dictionary(const char* filename);

		// Copy constructor and assignment operator
		Dictionary(const Dictionary& src);
		Dictionary& operator=(const Dictionary& src);

		// Move constructor and assignment operator
		Dictionary(Dictionary&& src) noexcept;
		Dictionary& operator=(Dictionary&& src) noexcept;

		// Destructor
		~Dictionary();

		// Search for a word in the dictionary
		void searchWord(const char* word);

		// Parse part of speech from a string
		PartOfSpeech parsePos(const std::string& strPos);
	};
}

#endif
