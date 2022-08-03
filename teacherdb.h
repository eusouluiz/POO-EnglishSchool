#ifndef TEACHERDB_H
#define TEACHERDB_H

#include "teacher.h"

class TeacherDB
{
public:
    TeacherDB();

    bool insertTeacher (const Teacher & teacher);
    QList<Teacher> listTeacher ();
    bool deleteTeacher (const Teacher & teacher);
    bool updateTeacher (const Teacher & teacher);
};

#endif // TEACHERDB_H
