#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Department
{
private:
    int capacity;
    double gpa_required;
    string name;

public:
    //--------Constructors--------//
    Department()
    {
        // Default constructor to initialize initial values ​​to the attributes.
        capacity = 100;
        gpa_required = 3.0;
        name = "CS";
    }
    Department(int capacity, double gpa_required, string name)
    {
        // Parameterized constructor to set values to the attributes.
        this->capacity = capacity;
        this->gpa_required = gpa_required;
        this->name = name;
    }
    //--------Constructors is ended-----------//

    //--------------Setters------------------//
    void set_capacity(int capacity)
    {
        this->capacity = capacity;
    }
    void set_gpa_required(double gpa_required)
    {
        this->gpa_required = gpa_required;
    }
    void set_name(string name)
    {
        this->name = name;
    }

    //--------------Getters----------------//
    int get_capacity()
    {
        return capacity;
    }
    double get_gpa_required()
    {
        return gpa_required;
    }
    string get_name()
    {
        return name;
    }
    //-----------Getters is ended-------//
    ~Department() {}
};
class Person  // Super class to Student class and Professor class
{
protected:
    int id;
    int age;
    string name;
    char gender;

public:
    //--------Constructors--------//
    Person()
    {
        // Default constructor to initialize initial values ​​to the attributes.
        id = 1;
        age = 21;
        name = "khaled";
        gender = 'm';
    }
    Person(int id, int age, string name, char gender)
    {
        // Parameterized constructor to set values to the attributes.
        this->id = id;
        this->age = age;
        this->name = name;
        this->gender = gender;
    }
    //--------Constructors is ended-----------//
    //--------Setters-------------//
    void set_id(int id)
    {
        this->id = id;
    }
    void set_age(int age)
    {
        this->age = age;
    }
    void set_name(string name)
    {
        this->name = name;
    }
    void set_gender(char gender)
    {
        this->gender = gender;
    }
    //--------Setters is ended--------//
    //---------Getters-----------//
    int get_id()
    {
        return id;
    }
    int get_age()
    {
        return age;
    }
    string get_name()
    {
        return name;
    }
    char get_gender()
    {
        return gender;
    }
    //------Getters is ended------//
    virtual void attend() = 0;
    ~Person() {}
};
class Student : public Person  // sub class from person class
{
private:
    double gpa;
    int level;

public:
    //--------Constructors--------//
    Student()
    {
        // Default constructor to initialize initial values ​​to the attributes.
        gpa = 2.5;
        level = 2;
    }
    Student(int id, int age, string name, char gender, double gpa, int level)
        : Person(id, age, name, gender)
    {
        // Parameterized constructor to set value to the attributes.
        this->gpa = gpa;
        this->level = level;
    }
    //--------Constructors is ended--------//
    //-------------Setters----------------//
    void set_gpa(double gpa)
    {
        this->gpa = gpa;
    }
    void set_level(int level)
    {
        this->level = level;
    }
    //--------Setters is ended--------//
    //-------Getters----------//
    double get_gpa()
    {
        return gpa;
    }
    int get_level()
    {
        return level;
    }
    //-------Getters is ended----------//

    void study()
    {
        cout<<"Student: "<<name<<" studied"<<endl;
    }
    void student_take_exam()
    {
         cout<<"Student: "<<name<<" took the exam"<<endl;
    }

    // override
    void attend() {
        cout<<"Student: "<<name<<" attended"<<endl;
    }
    ~Student() {}
};
class Professor : public Person  // sub class from person class
{
private:
    double salary;
    Department *department;
    string degree;

public:
    //--------Constructors--------//
    Professor()
    {
        // Default constructor to initialize initial values ​​to the attributes.
        salary = 10000.0;
        degree = "Doctoral degree";
    }
    Professor(int id, int age, string name, char gender, double salary,
              Department *department, string degree)
        : Person(id, age, name, gender)
    {
        // Parameterized constructor to set values to the attributes.
        this->salary = salary;
        this->department = department;
        this->degree = degree;
    }
    //--------Constructors is ended--------//
    //-------------Setters----------------//
    void set_salary(double salary)
    {
        this->salary = salary;
    }
    void set_department(Department *department)
    {
        this->department = department;
    }
    void set_degree(string degree)
    {
        this->degree = degree;
    }
    //--------Setters is ended--------//
    //-------Getters----------//
    double get_salary()
    {
        return salary;
    }
    Department *get_department()
    {
        return department;
    }
    string get_degree()
    {
        return degree;
    }
    //-------Getters is ended----------//
    // override
    void attend() {
    cout<<"Proffessor: "<<name<<" attended"<<endl;
    }
    ~Professor() {}
};

class Course
{
private:
    string code;
    int hours;
    string name;
    Professor *professor;
    vector<Student *> students;
    vector<Course *> prerequisites;

public:
    //--------Constructors--------//
    Course()
    {
        // Default constructor to initialize initial values ​​to the attributes.
        code = 1;
        hours = 3;
        name = "Software Engineering";
    }
    Course(string code, int hours, string name, Professor *professor,
           vector<Student *> students, vector<Course *> prerequisites)
    {
        // Parameterized constructor to set values to the attributes.
        this->code = code;
        this->hours = hours;
        this->name = name;
        this->professor = professor;
        this->students = students;
        this->prerequisites = prerequisites;
    }
    //--------Constructors is ended-----------//

    //---------------Setters-------------//
    void set_code(string code)
    {
        this->code = code;
    }
    void set_hours(int hours)
    {
        this->hours = hours;
    }
    void set_name(string name)
    {
        this->name = name;
    }
    void set_professor(Professor *professor)
    {
        this->professor = professor;
    }
    void set_students(vector<Student *> students)
    {
        this->students = students;
    }
    void set_prerequisites(vector<Course *> prerequisites)
    {
        this->prerequisites = prerequisites;
    }
    //---------------Setters is ended-------------//

    //----------------Getters--------------------//
    string get_code()
    {
        return code;
    }
    int get_hours()
    {
        return hours;
    }
    string get_name()
    {
        return name;
    }
    Professor *get_professor()
    {
        return professor;
    }
    vector<Student *> get_students()
    {
        return students;
    }
    vector<Course *> get_prerequisites()
    {
        return prerequisites;
    }
    //---------Getters is ended-----------//
    ~Course() {}
};

class University
{
private:
    static University *mini_university;  // object
    University(){
    add_data();
    }
    vector<Department> departments;
    vector<Student> students;
    vector<Professor> professors;
    vector<Course> courses;

public:
    University(const University &mini_University) = delete;
    static University *create_mini_university()
    {
        if (mini_university == NULL)
        {
            mini_university = new University();
            return mini_university;
        }
        else
        {
            return mini_university;
        }
    }
    //-----------add new---------------------//
    void add_department(int capacity, double gpa_required, string name)
    {
        Department new_department(capacity, gpa_required, name);
        departments.push_back(new_department);
    }
    void add_student(int id, int age, string name, char gender, double gpa,
                     int level)
    {
        Student new_student(id, age, name, gender, gpa, level);
        students.push_back(new_student);
    }
    void add_professor(int id, int age, string name, char gender, double salary,
                       Department *department, string degree)
    {
        Professor new_professor(id, age, name, gender, salary, department, degree);
        professors.push_back(new_professor);
    }
    void add_course(string code, int hours, string name, Professor *professor,
                    vector<Student *> students, vector<Course *> prerequisites)
    {
        Course new_course(code, hours, name, professor, students, prerequisites);
        courses.push_back(new_course);
    }
    //--------delete data------------//
    void delete_department(string name)
    {
        for (int i = 0; i < departments.size(); i++)
        {
            if(departments[i].get_name() == name)
            {
                departments.erase(departments.begin() + i);
                return ;
            }
        }
        cout<<"there is no department with this name\n";
    }
    void delete_student(int id)
    {
        for (int i = 0; i < students.size(); i++)
        {
            if(students[i].get_id() == id)
            {
                students.erase(students.begin() + i);
                return ;
            }
        }
        cout<<"there is no student with this id\n";
    }
    void delete_professor(int id)
    {
        for (int i = 0; i < professors.size(); i++)
        {
            if(professors[i].get_id() == id)
            {
                professors.erase(professors.begin() + i);
                return ;
            }
        }
        cout<<"there is no professor with this id\n";
    }
    void delete_course(string code)
    {

        for (int i = 0; i < courses.size(); i++)
        {
            if(courses[i].get_code() == code)
            {
                courses.erase(courses.begin() + i);
                return ;
            }
        }
        cout<<"there is no course with this code\n";

    }



    //-----------update data-------------//
    bool update_department(string name, int capacity)
    {
        for (int i = 0; i < departments.size(); i++)
        {
            if (departments[i].get_name() == name)
            {
                departments[i].set_capacity(capacity);
                return true;
            }
        }
        return false;
    }

    bool update_student(int id, double gpa)
    {
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].get_id() == id)
            {
                students[i].set_gpa(gpa);
                return true;
            }
        }
        return false;
    }
    bool update_professor(int id, double salary)
    {
        for (int i = 0; i < professors.size(); i++)
        {
            if (professors[i].get_id() == id)
            {
                professors[i].set_salary(salary);
                return true;
            }
        }
        return false;
    }
    bool update_course(string code, int hours)
    {
        for (int i = 0; i < courses.size(); i++)
        {
            if (courses[i].get_code() == code)
            {
                courses[i].set_hours(hours);
                return true;
            }
        }
        return false;
    }
    //----------------------------------//
    void add_data()
    {
        Department d1(50, 3.2,"Web Development");
        departments.push_back(d1);
        Department d2( 33, 3.5,"Cyber Security");
        departments.push_back(d2);
        Department d3( 20, 3.0,"Artificial Intelligence");
        departments.push_back(d3);
        Department d4( 125, 2.5,"Information Systems");
        departments.push_back(d4);

        Student s1(1,19,"Ahmed Ali", 'M', 2.74,2 );
        students.push_back(s1);
        Student s2(2,22,"Mirna Hussein",  'F', 3.68,4);
        students.push_back(s2);
        Student s3(3,28,"Hamada Hossam",  'M',2.37, 3 );
        students.push_back(s3);
        Student s4(4,20,"Taghreed Mohsen", 'F', 3, 3);
        students.push_back(s4);
        Student s5(5,18,"Yasmin Belal", 'F',3.71, 1 );
        students.push_back(s5);
        Student s6(6,50,"Amr Diab",  'M',2.01, 4);
        students.push_back(s6);
        Student s7(7,30,"Tamer Hosny",'M',2.02, 3);
        students.push_back(s7);
        Student s8(8,21,"Ahmed Alaa", 'M', 2.49,2);
        students.push_back(s8);

        Professor p1(1,56,"Mohamed Ali", 'M', 12000,&d1, "Masters");
        professors.push_back(p1);
        Professor p2(2,43,"Ehsan Ahmed", 'M', 8500, &d2, "Masters");
        professors.push_back(p2);
        Professor p3(3,68,"Ahmed Mohsen", 'M',  19380,&d3, "Masters");
        professors.push_back(p3);
        Professor p4(4,61,"Abdelhady", 'M',22728, &d4, "Masters");
        professors.push_back(p4);
        Professor p5(5,49,"Taghreed Mohsen", 'F', 11068,&d2, "Masters");
        professors.push_back(p5);


        vector<Student*> st1;
        st1.push_back(&s1);
        st1.push_back(&s2);
        st1.push_back(&s3);
        st1.push_back(&s4);
        vector<Student*> st2;
        st2.push_back(&s5);
        st2.push_back(&s6);
        st2.push_back(&s7);
        st2.push_back(&s8);
        Course c1( "HTML123", 12,"HTML", &p1, st1, vector<Course*>()); courses.push_back(c1);
        vector<Course*> crs1;
        crs1.push_back(&c1);
        Course c2("CSS123",9,"CSS", &p3, st2,crs1); courses.push_back(c2);
        Course c3( "Net521",18, "Networks", &p5, st2,crs1); courses.push_back(c3);
    }
    //--------------------------------------//
     void print_all(){
        for(int i=0;i<departments.size();i++){
            cout<<"Department: "<<departments[i].get_name()<<endl;
        }
        for(int i=0;i<professors.size();i++){
            cout<<"Professor Name: "<<professors[i].get_name()<<endl;
        }
        for(int i=0;i<students.size();i++){
            cout<<"Student Name: "<<students[i].get_name()<<endl;
        }
        for(int i=0;i<courses.size();i++){
            cout<<"Course Name: "<<courses[i].get_name()<<endl;
        }
    }
    //-----------------------------------------//

};

University *University::mini_university = NULL;
int main()
{
    University *uni = University::create_mini_university();
    uni->print_all();
    uni->delete_course("Net521");
    cout<<"---------------------------------------------------------\n";
    uni->print_all();
    return 0;
}
