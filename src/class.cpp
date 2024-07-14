#include <string>
using namespace std;
#define MAX_QUESTIONS 100
class QuizQuestion
{
  string question;
  string options[4];
  int answerIndex;
  int correctOption;
};

class Quiz
{
private:
  string topic;
  // QuizQuestion questions[MAX_QUESTIONS]; // this will be dynamically allocated asking use the totalQuestions
  int totalQuestions;
  int currentQuestionIndex;
  int correctAnswersIndex;
  int wrongAnswersIndex;
  int score;
  int totalScore;

public:
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