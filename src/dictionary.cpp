

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "settings.h"
#include "dictionary.h"
#include <cstring>

using namespace std;

namespace seneca
{
    Dictionary::Dictionary() : m_words(nullptr), m_size(0) {}

    Dictionary::Dictionary(const char* filename)
    {
        ifstream file(filename);

        if (file.is_open())
        {
            string temp;
            size_t count{ 0 };

            // Count the number of lines (words) in the file
            while (getline(file, temp))
            {
                count++;
            }

            // Reset file stream to the beginning
            file.clear();
            file.seekg(0);

            // Allocate memory for the words
            m_words = new Word[count];
            m_size = 0;

            // Load words and definitions from the file
            while (getline(file, temp))
            {
                stringstream ss(temp);
                string strWord, strDef, strPos;

                getline(ss, strWord, ',');
                getline(ss, strPos, ',');
                getline(ss, strDef);

                m_words[m_size].word = strWord;
                m_words[m_size].definition = strDef;
                m_words[m_size].pos = parsePos(strPos);
                m_size++;
            }
        }
        else {
            cerr << "Error: Could not open file: " << filename << endl;
        }
    }

    Dictionary::Dictionary(const Dictionary& src)
    {
        m_words = nullptr;
        *this = src;
    }

    Dictionary& Dictionary::operator=(const Dictionary& src)
    {
        if (this != &src)
        {
            delete[] m_words;
            m_size = src.m_size;
            m_words = new Word[m_size];
            for (size_t i = 0; i < m_size; i++)
            {
                m_words[i] = src.m_words[i];
            }
        }
        return *this;
    }

    Dictionary::Dictionary(Dictionary&& src) noexcept : m_words{ src.m_words }, m_size{ src.m_size }
    {
        src.m_words = nullptr;
        src.m_size = 0;
    }

    Dictionary& Dictionary::operator=(Dictionary&& src) noexcept
    {
        if (this != &src)
        {
            delete[] m_words;
            m_words = src.m_words;
            m_size = src.m_size;

            src.m_words = nullptr;
            src.m_size = 0;
        }
        return *this;
    }

    Dictionary::~Dictionary() {
        delete[] m_words;
        m_words = nullptr;
    }

    void Dictionary::searchWord(const char* word)
    {
        bool found = false;
        size_t len = strlen(word);
        bool stopSearch = false;

        for (size_t i = 0; i < m_size && !stopSearch; i++)
        {
            if (m_words[i].word == word)
            {
                if (!found)
                {
                    // Print the word on the first occurrence
                    cout << m_words[i].word;
                }
                else
                {
                    // Ensure alignment for subsequent definitions
                    cout << setw(len) << " ";  // Aligns the subsequent lines correctly
                }

                cout << " - ";

                // Print part of speech if required
                if (g_settings.m_verbose && m_words[i].pos != PartOfSpeech::Unknown)
                {
                    cout << "(";
                    if (m_words[i].pos == PartOfSpeech::Noun)
                    {
                        cout << "noun";
                    }
                    else if (m_words[i].pos == PartOfSpeech::Verb)
                    {
                        cout << "verb";
                    }
                    else if (m_words[i].pos == PartOfSpeech::Adjective)
                    {
                        cout << "adjective";
                    }
                    // Add more part of speech types if needed
                    cout << ") ";
                }

                cout << m_words[i].definition << endl;
                found = true;

                // If m_show_all is false, stop after the first match
                if (!g_settings.m_show_all)
                {
                    stopSearch = true;
                }
            }
        }

        // If word is not found, print a message
        if (!found)
        {
            cout << "Word '" << word << "' was not found in the dictionary." << endl;
        }
    }


    PartOfSpeech Dictionary::parsePos(const string& strPos)
    {
        if (strPos == "n." || strPos == "n.pl.")
        {
            return PartOfSpeech::Noun;
        }
        else if (strPos == "adv.")
        {
            return PartOfSpeech::Adverb;
        }
        else if (strPos == "a.")
        {
            return PartOfSpeech::Adjective;
        }
        else if (strPos == "v." || strPos == "v. i." || strPos == "v. t." || strPos == "v. t. & i.")
        {
            return PartOfSpeech::Verb;
        }
        else if (strPos == "prep.")
        {
            return PartOfSpeech::Preposition;
        }
        else if (strPos == "pron.")
        {
            return PartOfSpeech::Pronoun;
        }
        else if (strPos == "conj.")
        {
            return PartOfSpeech::Conjunction;
        }
        else if (strPos == "interj.")
        {
            return PartOfSpeech::Interjection;
        }
        return PartOfSpeech::Unknown;
    }

}