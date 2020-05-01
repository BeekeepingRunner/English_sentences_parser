// EnglishGrammar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <exception>

/*  This program checks if entered sentence is valid according to the English grammar.
    However there is a very limited set of words that can be entered, that is:
    nouns: birds, fish, c++,
    verbs: rules, fly, swim,
    conjunctions: and, or, but
    article: the
*/

/*  Formal grammar for this parser looks like this:

    Sentence:
        Noun Verb
        Noun Verb
        *********   TODO --> Sentence Conjunction Verb
        Sentence Conjunction Sentence

    Conjunction:
        "and"
        "or"
        "but"

    Noun:
        "birds"
        "fish"
        "C++"
        "the" Noun

    Verb:
        "rules"
        "fly"
        "swim"
*/

void error(std::string err)
{
    throw std::runtime_error("err");
}

bool sentence();
bool noun();
bool conjunction();
bool verb();

bool sentence()
{
    bool isCorrect = noun();
    if (!isCorrect)
        return false;
    
    isCorrect = verb();
    if (!isCorrect)
        return false;

    isCorrect = conjunction();
    if (!isCorrect)
        return false;
    else
        return true;
}

bool noun()
{
    std::string word{};
    std::cin >> word;

    if (word == "the" || word == "The")
        std::cin >> word;

    if (word == "birds" || word == "fish" || word == "C++")
        return true;
    else
        return false;
}

bool verb()
{
    std::string word{};
    std::cin >> word;

    if (word == "rules" || word == "fly" || word == "swim")
        return true;
    else
        return false;
}

bool conjunction()
{
    std::string word{};
    std::cin >> word;

    if (word == "and" || word == "or" || word == "but")
    {
        bool isCorrect = sentence();
        if (!isCorrect)
            return false;
        else return true;
    }
    else if (word == ".")
        return true;
    else
        return false;
}

int main()
{
    std::cout << "\tEnglish grammar parser\n\n"

            << "Accepted words are\n"
            << "nouns: birds, fish, c++\n"
            << "verbs : rules, fly, swim,\n"
            << "conjunctions : and, or , but\n"
            << "article : the\n\n";

    std::cout << "Please enter a sentence. If you want to mark the end of the sentence\n"
        << "you have to terminate it with \" .\" (a dot preceded by a space)\n\n";

    std::string word{};
    std::string text{};

    while (true) {

        std::cout << ">";
        bool isCorrect = sentence();

        // after checking a sentence
        if (isCorrect)
                std::cout << "\nOK!\n";
        else
        {
            std::cout << "\nnot ok...\n";
            
            // deleting garbage from an input stream
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();
        }
    }
}