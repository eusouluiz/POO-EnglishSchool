#ifndef STUDENTDB_H
#define STUDENTDB_H

#include "student.h"
#include "teacher.h"

class StudentDB
{
public:
    StudentDB();

    bool insertStudent (const Student & student);
    QList<Student> listStudents(QString selection = nullptr);
    QList<Student> listStudentsByTeacher(Teacher & currentTeacher);
    bool deleteStudent (const Student &student);
    void deleteStudentById(int id);
    bool updateStudent (const Student & student);
    bool getStudentById (int id, Student * tmpStudent);
};

#endif // STUDENTDB_H
