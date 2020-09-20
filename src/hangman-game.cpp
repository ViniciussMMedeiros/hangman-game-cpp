#include <iostream>
#include <time.h>
#include <string>

using namespace std;

int exitProgram()
{
  return 1;
}

string aleatoryWord()
{

  int aleatoryIndex, count, difficulty;

  srand((unsigned)time(NULL));

  aleatoryIndex = rand() % 33;

  string normalWordList[32] = {"house", "pencil", "ball", "orange", "television", "paper", "mouse", "banana", "guitar", "note", "lion", "object", "picture", "water", "bedroom", "movie", "game", "computer", "music", "potato", "book", "document", "football", "video", "letter", "rubber", "enter", "door", "flower", "time", "navigation", "concert"};

  string hardWordList[32] = {"abruptly", "absurd", "awkward", "dwarves", "lengths", "microwave", "mystify", "nightclub", "nowadays", "oxygen", "rhythm", "strength", "subway", "syndrome", "transcript", "transgress", "transplant", "twelfth", "unknown", "unworthy", "uptown", "vodka", "voodoo", "voyeurism", "wave", "whiskey", "witchcraft", "wizard", "zipper", "zodiac", "zombie", "jazz"};

  do
  {
    cout << "\n[Choose the difficulty of the game]";
    cout << "\n[1] Normal \n[2] Hard";
    cout << "\n\nOption: ";
    cin >> difficulty;
  } while (difficulty < 1 || difficulty > 2);

  if (difficulty == 1)
  {
    return normalWordList[aleatoryIndex];
  }
  else
  {
    return hardWordList[aleatoryIndex];
  }
}

string wordMask(string word, int wordSize)
{
  int count;
  string wordMask;
  for (count = 0; count < wordSize; count++)
  {
    wordMask += "_";
  }

  return wordMask;
}

int home();

int returnOption()
{

  int returnToMenu;

  do
  {
    cout << "\n\n[1] to return to the menu.";
    cout << "\n[2] to exit the game.";
    cout << "\n\nOption: ";
    cin >> returnToMenu;
    system("CLS");
  } while (returnToMenu < 1 || returnToMenu > 2);

  if (returnToMenu == 1)
  {
    home();
    system("CLS");
  }

  if (returnToMenu == 2)
  {
    system("CLS");
    exit(1);
    exitProgram();
  }

  return 0;
}

int play(int option)
{
  int returnToMenu;

  string word;

  int count;

  if (option == 1)
  {
    word = aleatoryWord();
  }

  if (option == 2)
  {
    cout << "Enter the word to be guessed: ";
    cin >> word;
  }

  system("CLS");

  int wordSize = word.size();

  // converting all the letters of the word to lowercase
  for (count = 0; count < wordSize; count++)
  {
    char newLetter = tolower(word[count]);
    word[count] = newLetter;
  }

  string mask = wordMask(word, wordSize);

  string testedChars, letterTesting, wordTest;

  char letter;

  int maximumAttempts = 6, attempts = 0;

  bool rightOrWrongChar = false;

  bool letterTestingCheck = false;

  testedChars += "*Letters tried: ";

  while (mask != word && maximumAttempts - attempts > 0)
  {

    cout << "\nWord: " << mask;
    cout << "\t\tSize: " << wordSize;
    cout << "\n\nRemaining attempts: " << maximumAttempts - attempts;

    cout << "\n"
         << testedChars;

    cout << "\nEnter a letter [enter '1' to try to guess the whole word]: ";
    cin >> letter;

    if (letter == '1')
    {
      cout << "\nGood Luck, take a guess: ";
      cin >> wordTest;

      if (wordTest == word)
      {
        mask = wordTest;
      }
      else
      {
        attempts = 10;
      }
    }

    system("CLS");

    for (count = 0; count < attempts; count++)
    {
      if (tolower(letter) == letterTesting[count])
      {
        system("CLS");
        cout << "\n[Letter already tested, choose another.]";
        letterTestingCheck = true;
      }
    }

    if (letterTestingCheck == false)
    {
      letterTesting += tolower(letter);
      testedChars += tolower(letter);
      testedChars += ", ";

      for (count = 0; count < wordSize; count++)
      {
        if (tolower(letter) == word[count])
        {
          system("CLS");
          mask[count] = word[count];
          rightOrWrongChar = true;
        }
      }

      if (rightOrWrongChar == false)
      {
        system("CLS");
        cout << "\n[You missed!]";
      attempts++;
      }

    }

    rightOrWrongChar = false;
    letterTestingCheck = false;
  }

  if (mask == word)
  {
    system("CLS");
    cout << "\n\t***You Won!***";
    cout << "\nThe word was: " << mask;
    cout << "\n";
    returnOption();
  }

  else
  {
    system("CLS");
    cout << "\n~~You lost!";
    cout << "\nThe word was: " << word;
    cout << "\n";
    returnOption();
  }

  return 0;
}

int home()
{

  int option, wordSize, returnToMenu;

  string word, mask;

  do
  {
    cout << "\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
    cout << "\n\t\t\t    HANGMAN GAME";
    cout << "\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
    cout << "\n\n1 - Single Player";
    cout << "\n2 - Two Players";
    cout << "\n3 - Instructions";
    cout << "\n4 - About";
    cout << "\n5 - Exit";
    cout << "\n\nEnter an option: ";
    cin >> option;

    system("CLS");

  } while (option < 1 && option > 4);

  switch (option)
  {

  case 1:
    if (play(1) == 1)
    {
      home();
    }
    break;

  case 2:
    if (play(2) == 2)
    {
      home();
    }
    break;

  case 3:
    if (option == 3)
    {
      cout << "\nSingle player - Select a letter of the alphabet, if the hidden word contains it then you got it right and the occurances of that letter will appear in the masked word.";
      cout << "\nIf you type '1' to try to guess the whole word, you either guess it right or lose the game.";
      cout << "\n\nMultiplayer - The only difference to single player is that one of the players have to enter the word to be guessed.";
      cout << "\n\nPay attention! You have 10 attempts until you get hanged.";
      returnOption();
    }
    break;

  case 4:
    cout << "\nThere are 32 words in normal mode and 32 words in hard mode, totaling 64 words!";
    cout << "\n\nGame created by Vinicius Medeiros.";
    cout << "\n2020";
    returnOption();
    break;

  case 5:
    exit(1);
    exitProgram();
    break;
  }

  return 0;
}

int main()
{

  home();

  return 0;
}
