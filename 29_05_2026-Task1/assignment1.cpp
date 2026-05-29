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
        std::cout<<i+1<<". INFOMARTION: \n";
        std::cout<<"Student's id: "<<students[i].ID<<std::endl;
        std::cout<<"Student's name: "<<students[i].name<<std::endl;
        std::cout<<"Student's course: "<<students[i].course<<std::endl;
        std::cout<<"Student's age: "<<students[i].age<<std::endl;
        std::cout<<"======================\n\n";
    }
}

void UpdateByID(Students students[], int *ID, int *size, Students new_data) {
    for(int i=0;i<*size;i++) {
        if(students[i].ID == *ID) {
            students[i] = new_data;
            std::cout<<"***** Updated Student's Information *****\n";
            SearchStudentByID(students, &students[i].ID, &*size);
            break;
        }
    }
}

int main() {
    // Variables initialized
    int total_students = 5;
    Students students[total_students];

    // Store 5 students information
    students[0] = {24006001, 18, "Eleanor Vance", "BCS"};
    students[1] = {24006002, 18, "Marcus Sterling", "BCS"};
    students[2] = {24006003, 19, "Chloe Chen", "BIT"};
    students[3] = {24006004, 17, "Julian Bautista", "BIT"};
    students[4] = {24006005, 20, "Sarah Jenkins", "BIS"};

    // Display all students records
    DisplayAllRecords(students, &total_students);
    
    // Search a student by id
    int target_id = 24006002;
    std::cout<<"***** Student's information with id "<<target_id<<" ******\n";
    SearchStudentByID(students, &target_id, &total_students);
    
    // Update one student record
    int update_by_id = 24006003;
    Students new_data = {24006003, 18, "Julian Batista", "BCS"};
    UpdateByID(students, &target_id, &total_students, new_data);
    
    std::cin.get();
    return 0;
}