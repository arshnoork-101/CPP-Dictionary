

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
