#include <string>
#include <vector>
#include <iostream>

using namespace std;

class QuizQuestion
{
  string question;
  string options[4];
  int correctOption;

public:
  QuizQuestion(){};
  QuizQuestion(string question, string options[], int correctOption)
  {
    this->question = question;
    for (int i = 0; i < 4; i++)
    {
      this->options[i] = options[i];
    }
    this->correctOption = correctOption;
  }

  string getQuestion()
  {
    return question;
  }

  string *getOptions()
  {
    return options;
  }

  int getCorrectOption()
  {
    return correctOption;
  }
};

class Quiz
{
private:
  string topic;
  vector<QuizQuestion> questions;
  int totalQuestions;
  int currentQuestionIndex;
  vector<int> correctAnswersIndex;
  vector<int> wrongAnswersIndex;
  int score;
  int totalScore;
  vector<int> usedQuestionsIndex;

public:
  Quiz()
  {
    this->topic = "";
    this->totalQuestions = 0;
    this->currentQuestionIndex = 0;
    this->score = 0;
    this->totalScore = 0;
  };

  Quiz(string topic, int totalQuestions)
  {
    this->topic = topic;
    this->totalQuestions = totalQuestions;
    this->currentQuestionIndex = 0;
    this->score = 0;
    this->totalScore = 0;
    this->questions = getQuizDataFromDB(topic, totalQuestions);
  };
};

class Analytic
{
private:
  string date;
  int correctAnswers;
  int wrongAnswers;
  int totalScore;
  int totalQuestions;
  string topic;
};