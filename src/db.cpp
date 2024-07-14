#include "./class.cpp"
#include <vector>
#include <iostream>
#include <fstream>
#include "../libs/csv.hpp"
using namespace csv;
#include <string>

using namespace std;
using namespace csv;
#define PATH_QUIZ "../db/quiz/"

vector<QuizQuestion> getQuizDataFromDB(string topic, int totalQuestions)
{
  vector<QuizQuestion> questions;
  string path = PATH_QUIZ + topic + ".csv";
  // Initialize CSVReader with the path to the CSV file
  CSVReader reader(path);

  // Check if the file exists by attempting to open it
  ifstream file(path);
  if (!file.is_open())
  {
    cout << "Topic not found" << endl;
    return questions; // Return the empty vector if file doesn't exist
  }
  file.close(); // Close the file as CSVReader will handle the file reading

  // Iterate through each row of the CSV file
  for (CSVRow &row : reader)
  {
    string options[4] = {row["Option1"].get<>(), row["Option2"].get<>(), row["Option3"].get<>(), row["Option4"].get<>()};
    string correctOption = row["CorrectOption"].get<>();
    string questionText = row["Question"].get<>();
    QuizQuestion question(questionText, options, stoi(correctOption));

    // Add the constructed question to the questions vector
    questions.push_back(question);

    // Optionally, break out of the loop once you've read the desired number of questions
    if (questions.size() >= totalQuestions)
      break;
  }

  return questions;
}

void saveQuizDataToDB(string topic, vector<QuizQuestion> questions)
{
  string path = PATH_QUIZ + topic + ".csv";
  // Initialize CSVWriter with the path to the CSV file
  CSV Writer(path);

  // Write the header row
  Writer << "Question" << "Option1" << "Option2" << "Option3" << "Option4" << "CorrectOption";

  // Iterate through each question and write it to the CSV file
  for (QuizQuestion &question : questions)
  {
    string *options = question.getOptions();
    Writer << question.getQuestion() << options[0] << options[1] << options[2] << options[3] << question.getCorrectOption();
  }

  // Close the CSV file after writing
  Writer.close();
}