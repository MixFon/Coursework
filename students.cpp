#include "students.h"

University::~University(void)
{
	Student *temp;

	delete [] oneSortStud;
	delete [] twoSortStud;
	while (this->stud)
	{
		temp = this->stud;
		this->stud = this->stud->next;
		delete temp;
	}
}

Student::Student(void)
{
	memset(this, 0, sizeof(Student));
	this->next = NULL;
}

void	University::deleteEmptyStudent(void)
{
	Student	*temp;
	Student	*prev;
	Student	*stud;
	int		i = 0;

	stud = this->stud;
	prev = stud;
	while(stud)
	{
		if (stud->name[0] == '\0')
		{
			temp = stud;
			this->countStudents--;
			if (prev == stud)
			{
				stud = stud->next;
				prev = stud;
				this->stud = stud;
				delete temp;
				continue;
			}
			stud = stud->next;
			prev->next = stud;
			delete temp;
			continue;
		}
		prev = stud;
		stud = stud->next;
	}
}

void	University::addNewStudent(void)
{
	Student	*temp;

	temp = new Student();
	temp->next = this->stud;
	this->stud = temp;
	temp = NULL;
	this->countStudents++;

}

void	University::sortStudentsAlphabet(void)
{
	int		i;
	Student *iter;
	Student *temp;

	i = -1;
	iter = this->stud;
	Student	**arrStud = new Student*[this->countStudents];
	while (iter)
	{
		arrStud[++i] = iter;	
		iter = iter->next;
	}
	for (int i = 0; i < this->countStudents - 1; i++)
	{
		for (int j = 0; j < this->countStudents - 1; j++)
		{
			if (arrStud[j]->name > arrStud[j + 1]->name)
			{
				temp = arrStud[j];
				arrStud[j] = arrStud[j + 1];
				arrStud[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < this->countStudents - 1; i++)
	{
		arrStud[i]->next = arrStud[i + 1];
		arrStud[i + 1]->next = NULL;
	}
	this->stud = arrStud[0];
	delete[] arrStud; 
}

int		University::calculateStudents(void)
{
	Student *iter;
	int		i;
	union number u_num;

	i = 0;
	iter = this->stud;	
	while(iter)
	{
		u_num.buf[1] = iter->name[0];
		u_num.buf[0] = iter->name[1];
		if ((u_num.num & 0xffff) < 0xD0A0)
			i++;
		iter = iter->next;
	}
	return (i);
}

void	University::sortStudentsBall(Student **arr, int count)
{
	Student *temp;

	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - 1; j++)
		{
			if (arr[j]->middleBall > arr[j + 1]->middleBall)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void	University::printArrayStudents(Student **arrStud, int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << "������� �" << i + 1 << endl;
		cout << "���\t\t\t" << arrStud[i]->name << endl;
		cout << "���� ��������\t\t" << arrStud[i]->dateBirth << endl;
		cout << "��� �����������\t\t" << arrStud[i]->yearEntry << endl;
		cout << "���������, �������\t" << arrStud[i]->faculty << endl;
		cout << "������\t\t\t" << arrStud[i]->group << endl;
		cout << "����� �������� ������\t" << arrStud[i]->numberBook << endl;
		cout << "������� ����\t\t" << arrStud[i]->middleBall << endl;
		cout << endl;
	}
}

void	University::printTwoArrayStudents(void)
{
	cout << "\n�������� ������������� �� �������� �����." << endl;
	cout << "������ ��������� �� � �� �:" << endl;
	printArrayStudents(this->oneSortStud, this->countFirstArray);
	cout << "\n������ ��������� �� � �� �:" << endl;
	printArrayStudents(this->twoSortStud,
			this->countStudents - this->countFirstArray);
}

void	University::splitTwoLists(void)
{
	Student	*iter;
	int		i;
	int		k;
	
	i = -1;
	k = -1;
	this->countFirstArray = calculateStudents();
	oneSortStud = new Student*[this->countFirstArray];
	twoSortStud = new Student*[this->countStudents - this->countFirstArray];
	iter = this->stud;
	while(iter)
	{
		if (++i < this->countStudents)
		{
			if (i < this->countFirstArray)
				oneSortStud[i] = iter;
			else
				twoSortStud[++k] = iter;
			iter = iter->next;
		}
	}	
	sortStudentsBall(oneSortStud, this->countFirstArray);
	sortStudentsBall(twoSortStud, this->countStudents - this->countFirstArray);
	printTwoArrayStudents();
}

void University::print(void)
{
	int		i;

	i = 0;
	for (Student *iter = this->stud; iter; iter = iter->next)
	{
		cout << "������� �" << ++i << endl;
		cout << "���\t\t\t" << iter->name << endl;
		cout << "���� ��������\t\t" << iter->dateBirth << endl;
		cout << "��� �����������\t\t" << iter->yearEntry << endl;
		cout << "���������, �������\t" << iter->faculty << endl;
		cout << "������\t\t\t" << iter->group << endl;
		cout << "����� �������� ������\t" << iter->numberBook << endl;
		cout << "������� ����\t\t" << iter->middleBall << endl;
		cout << endl;
	}
	cout << "���������� ��������� " << this->countStudents << endl;
}

void	University::printMenu(void)
{
	cout << "\n�������� ���� �� ������� ����:" << endl;
	cout << "\t1. �������� ��������." << endl;
	cout << "\t2. ������� ��������." << endl;
	cout << "\t3. ���������� ���� ���������." << endl;
	cout << "\t4. ����������� �� �������� ����� � ����������." << endl;
	cout << "\t5. ������� ��������� �� �����." << endl;
	cout << "\t6. ���������." << endl;
	cout << "\t7. �����." << endl;
}

void	University::addStudent(void)
{
	string buf;

	Student *temp = new Student();
	cout << "������� ��� ��������." << endl;
	cin >> temp->name;
	cout << "������� ���� ��������." << endl;
	cin >> temp->dateBirth;
	cout << "������� ��� �����������." << endl;
	cin >> buf;
	temp->yearEntry = atoi(buf.c_str());
	cout << "������� ��������� � �����." << endl;
	cin >> temp->faculty;
	cout << "������� ������." << endl;
	cin >> temp->group;
	cout << "������� ����� �������� ������." << endl;
	cin >> buf;
	temp->numberBook = atoi(buf.c_str());
	cout << "������� ������� ���� �� ���� ���������." << endl;
	cin >> buf;
	temp->middleBall = stof(buf.substr(3));
	temp->next = this->stud;
	this->stud = temp;
	this->countStudents++;
	sortStudentsAlphabet();
}

void	University::deleteStudent(void)
{
	Student	*pre;
	Student	*iter;
	string	buf;
	int		num;
	
	cout << "������� ����� ��������, �������� ������ �������." << endl;
	cin >> buf;
	num = atoi(buf.c_str());
	pre = NULL;
	iter = this->stud;
	while (iter)
	{
		if (!(--num))
		{
			cout << "������� " <<  iter->name << " ������.\n";
			this->countStudents--;
			if (pre == NULL)
				this->stud = iter->next;
			else
				pre->next = iter->next;
			delete iter;
			return ;
		}
		pre = iter;
		iter = iter->next;
	}
	cout << "�������� ��� ����� ������� �� ����������." << endl;
}

void University::readStudentsFromFile(void)
{
	char	nameFile[100];
	string	buf;
	string	subStr;
	int		num;

	ifstream in;
	cout << "������� ��� �����." << endl;
	cin >> nameFile;
	in.open(nameFile);
	if(!in.is_open())
	{
		cout << "\n���� " << nameFile << " �� ���������.\n";
		return ;
	}
	else
		cout << "\n���� " << nameFile << " ������.\n";
	if (this->stud == NULL)
	{
		this->stud = new Student();
		this->countStudents = 1;
	}
	while (!in.eof())
	{
		getline(in, buf);
		num = atoi(buf.c_str());
		if (num == 1)
			this->stud->name = buf.substr(3);
		else if (num == 2)
			this->stud->dateBirth = buf.substr(3);
		else if (num == 3)
			this->stud->yearEntry = stoi(buf.substr(3));
		else if (num == 4)
			this->stud->faculty = buf.substr(3);
		else if (num == 5)
			this->stud->group = buf.substr(3);
		else if (num == 6)
			this->stud->numberBook = stoi(buf.substr(3));
		else if (num == 7)
			this->stud->middleBall = stof(buf.substr(2));
		else if (buf == "")
			addNewStudent();
	}
	deleteEmptyStudent();
	in.close();
	sortStudentsAlphabet();
}

void	University::writeStudentsToFile(void)
{
	char		nameFile[100];
	ofstream	out;

	cout << "������� ��� ����� ����������." << endl;
	cin >> nameFile;
	out.open(nameFile);
	if(!out.is_open())
	{
		cout << "������ �������� ����� " << nameFile << endl;
		return ;
	}
	else
		cout << "���� " << nameFile << " �������.";
	for (Student *iter = this->stud; iter; iter = iter->next)
	{
		out << "1. ";
		out << iter->name << endl;
		out << "2. ";
		out << iter->dateBirth << endl;
		out << "3. ";
		out << iter->yearEntry << endl;
		out << "4. ";
		out << iter->faculty << endl;
		out << "5. ";
		out << iter->group << endl;
		out << "6. ";
		out << iter->numberBook << endl;
		out << "7. ";
		out << iter->middleBall << endl;
		out << endl;
	}
	out.close();
}

void	University::workingProgram(void)
{
	string	str;
	int		num;

	while(1)
	{
		printMenu();
		cin >> str;
		num = atoi(str.c_str());
		if (num == 1)
			addStudent();
		else if (num == 2)
			deleteStudent();
		else if (num == 3)
			print();
		else if (num == 4)
			splitTwoLists();
		else if (num == 5)
			readStudentsFromFile();
		else if (num == 6)
			writeStudentsToFile();
		else if (num == 7)
			return ;
	}
}

int	main(void)
{
	setlocale(LC_ALL, "Russian");

	University *uni = new University();
	uni->workingProgram();
	delete uni;
	return (0);
}
