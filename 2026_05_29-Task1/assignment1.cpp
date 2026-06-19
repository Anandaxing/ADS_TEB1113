#include <iostream>
#include <vector>
#include <iomanip>

struct Students {
    int ID;
    int age;
    std::string name;
    std::string course;
};

void SearchStudentByID(Students students[], int *ID, int *size) {
    for(int i=0;i<*size;i++) {
        if(students[i].ID == *ID) {
            std::cout<<"Student's id: "<<students[i].ID<<std::endl;
            std::cout<<"Student's name: "<<students[i].name<<std::endl;
            std::cout<<"Student's course: "<<students[i].course<<std::endl;
            std::cout<<"Student's age: "<<students[i].age<<std::endl;
            break;
        }
    }
    std::cout<<"*******************\n\n";
}

void DisplayAllRecords(Students students[], int *size) {
    std::cout<<"***** Display All Student's Record *****\n";
    for(int i=0;i<*size;i++) {
        std::cout<<i+1<<". INFOMATION: \n";
        std::cout<<"Student's id: "<<students[i].ID<<std::endl;
        std::cout<<"Student's name: "<<students[i].name<<std::endl;
        std::cout<<"Student's course: "<<students[i].course<<std::endl;
        std::cout<<"Student's age: "<<students[i].age<<std::endl;
        std::cout<<"======================\n\n";
    }
}

void UpdateByID(Students students[], int *ID, int *size, Students new_data) {
    bool found = false;
    for(int i=0;i<*size;i++) {
        if(students[i].ID == *ID) {
            students[i] = new_data;
            std::cout<<"***** Updated Student's Information *****\n";
            SearchStudentByID(students, &students[i].ID, &*size);
            found = true;
            break;
        }
    }
    if(!found) std::cout<<"There is no student with id "<<*ID<<std::endl;
}

int main() {
    // Variables initialized
    int total_students;

    std::cout<<"How many students: ";
    std::cin>>total_students;
    std::cin.ignore();

    Students students[total_students];

    // Store every students information
    for(int i=0;i<total_students;i++) {
        std::cout<<"Insert information for student #"<<i+1<<std::endl;
        std::cout<<"ID: ";
        std::cin>>students[i].ID;
        std::cout<<"Name: ";
        std::cin>>students[i].name;
        std::cout<<"Course: ";
        std::cin>>students[i].course;
        std::cout<<"Age: ";
        std::cin>>students[i].age;
        std::cout<<std::endl;
    }
    // Display all students records
    DisplayAllRecords(students, &total_students);
    
    // Search a student by id
    char option;
    int target_id;
    std::cout<<"Would like to search a student by its id (y/n): ";
    std::cin>>option;
    std::cin.ignore();
    if(tolower(option) == 'y') {
        std::cin>>target_id;
        std::cin.ignore();
        std::cout<<"***** Student's information with id "<<target_id<<" ******\n";
        SearchStudentByID(students, &target_id, &total_students);
    }
    
    // Update one student record
    int update_by_id;
    std::cout<<"Would like to change information of a student by its id (y/n): ";
    if(tolower(option) == 'y') {
        int id, age;
        std::string name, course;
        std::cout<<"Insert target id: ";
        std::cin>>update_by_id;
        std::cin.ignore();
        std::cout<<"Insert new data for id: ";
        std::cin>>id;
        std::cin.ignore();
        std::cout<<"Insert new data for name: ";
        getline(std::cin, name);
        std::cout<<"Insert new data for course: ";
        std::cin>>course;
        std::cout<<"Insert new data for age: ";
        std::cin>>age;
        std::cin.ignore();

        Students new_data = {id, age, name, course};
        UpdateByID(students, &target_id, &total_students, new_data);
    }
    
    std::cin.get();
    return 0;
}