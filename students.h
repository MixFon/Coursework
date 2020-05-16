#ifndef STUDENTS_H
#define	STUDENTS_H

#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <wchar.h>
#include <windows.h>
#include <cstdlib>


#define	LENBUF 4096

using namespace std;

class Student
{
	public:
		string	surname;
		string	name;
		string	patronik;
		string	dateBirth;
		int		yearEntry;	
		string	faculty;
		string	group;
		int		numberBook;	
		float	middleBall;	
		Student *next;

	public:
		Student(void);
};

class University
{
	public:
		Student	*stud;
		Student	**oneSortStud;
		Student	**twoSortStud;
		short	countStudents;
		short	countFirstArray;


	public:
		~University(void);
		void	workingProgram(void);

	private:
		void	deleteEmptyStudent(void);
		int		calculateStudents(void);
		void	sortStudentsBall(Student **arr, int count);
		void	printTwoArrayStudents(void);
		void	printArrayStudents(Student **arr, int count);
		void	sortStudentsAlphabet(void);
		void	readStudentsFromFile(void);
		void	splitTwoLists(void);
		void	addNewStudent(void);
		void	addStudent(void);
		void	printMenu(void);
		void	deleteStudent(void);
		void	writeStudentsToFile(void);
		void	print(void);
};

#endif
