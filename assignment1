#include "csci152_student.h"

csci152_student::csci152_student(std::string nm,
                                std::initializer_list<unsigned int> assignments,
                                std::initializer_list<double> quizzes,
                                double final_exam): 
    name(nm),
    num_of_assignments(assignments.size()),
    num_of_quizzes(quizzes.size()),
    final_exam_score(final_exam),
    assignment_scores(new unsigned int[num_of_assignments]),
    quiz_scores(new double[num_of_quizzes])
{
    size_t i = 0;
    for (auto item: assignments)
    {
        assignment_scores[i] = item;
        i++;
    }

    i = 0;
    for (auto item: quizzes)
    {
        quiz_scores[i] = item;
        i++;
    }
}

csci152_student::csci152_student(const csci152_student& other) //copy constructor
{
    name = other.name;
    num_of_assignments = other.num_of_assignments;
    assignment_scores = new unsigned int[other.num_of_assignments];
    num_of_quizzes = other.num_of_quizzes;
    quiz_scores = new double[other.num_of_quizzes];
    final_exam_score = other.final_exam_score;

    for(size_t i = 0; i < other.num_of_assignments; i++)
    {
        assignment_scores[i] = other.assignment_scores[i];
    }
    for(size_t i = 0; i < other.num_of_assignments; i++)
    {
        quiz_scores[i] = other.quiz_scores[i];
    }
}

csci152_student& csci152_student::operator=(const csci152_student& other) //assignment
{
    
    name = other.name;
    final_exam_score = other.final_exam_score;

    if(num_of_assignments != other.num_of_assignments){
        num_of_assignments = other.num_of_assignments;
        delete[] assignment_scores;
        assignment_scores = new unsigned int[num_of_assignments];
    }
    if(num_of_quizzes != other.num_of_quizzes){
        num_of_quizzes = other.num_of_quizzes;
        delete[] quiz_scores;
        quiz_scores = new double[num_of_quizzes];
    }

    for(size_t i = 0; i < other.num_of_assignments; i++)
    {
        assignment_scores[i] = other.assignment_scores[i];
    }
    for(size_t i = 0; i < other.num_of_quizzes; i++)
    {
        quiz_scores[i] = other.quiz_scores[i];
    }

    return *this;
}

std::string csci152_student::get_name() const //name getter
{
    return name;
}

void csci152_student::change_name(std::string new_name) //name setter
{
    name = new_name;
}

double csci152_student::calculate_assignment_perc() const //calculates assignments
{
    float sum = 0;
    
    for(size_t i = 0; i < num_of_assignments; i++){
        sum += assignment_scores[i];
    }

    float assGrade = (sum/num_of_assignments) / 100 * 25;

    return assGrade;
}

double csci152_student::calculate_quiz_perc() const //calculates quizzes
{

    float sum = 0;
    float min = quiz_scores[0];

    for(size_t i = 0; i < num_of_quizzes; i++){
        if(quiz_scores[i] < min)
            min = quiz_scores[i];
        sum += quiz_scores[i];
    }

    sum = sum - min;
    float average = sum/(num_of_quizzes - 1);
    float quizGrade = (average/20) * 45;

    return quizGrade;
}

double csci152_student::get_final_exam_perc() const //getter for final exam score
{
    return final_exam_score;
}

double csci152_student::calculate_course_perc() const //outputs total course percentage
{
    float assGrade = csci152_student::calculate_assignment_perc();
    float quizGrade = csci152_student::calculate_quiz_perc();
    float finalGrade = get_final_exam_perc();
    float totalPerc = quizGrade + assGrade + finalGrade * 0.3;
    return totalPerc;
}

csci152_student::~csci152_student() //destructor, deallocates memory
{
    delete[] assignment_scores;
    delete[] quiz_scores;
};
