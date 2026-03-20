   #include <iostream>
using namespace std;

void input(int n, void* arr);
void display(int n, void* arr);

int main(){

    char c;

    do{

    int n;
    cout<<"Number of students: ";
    cin>>n;
    cin.ignore();

    struct student{
        int id;
        string name;
        string course;
        double gpa;
    };

    student obj[n];

    input(n,obj);
    display(n,obj);

    cout<<"again?: ";
    cin>>c;
    cin.ignore();

    }while(c=='y'||c=='Y');

}

void input(int n, void* arr){

    struct student{
        int id;
        string name;
        string course;
        double gpa;
    };

    student* s=(student*)arr;

    for(int i=0;i<n;i++){

        int ok;

        do{
            ok=1;
            cout<<"id: ";
            cin>>s[i].id;
            cin.ignore();

            for(int j=0;j<i;j++){
                if(s[j].id==s[i].id){
                    cout<<"exists\n";
                    ok=0;
                }
            }

        }while(ok==0);

        cout<<"name: ";
        getline(cin,s[i].name);

        cout<<"course: ";
        getline(cin,s[i].course);

        do{
            cout<<"gpa: ";
            cin>>s[i].gpa;
            cin.ignore();
        }while(s[i].gpa<0||s[i].gpa>100);

    }
}

void display(int n, void* arr){

    struct student{
        int id;
        string name;
        string course;
        double gpa;
    };

    student* s=(student*)arr;

    cout<<"ID\tName\tCourse\tGPA\tStanding\n";

    for(int i=0;i<n;i++){

        cout<<s[i].id<<"\t"<<s[i].name<<"\t"<<s[i].course<<"\t"<<s[i].gpa<<"\t";

        if(s[i].gpa>=90) cout<<"Excellent";
        else if(s[i].gpa>=80) cout<<"Very Good";
        else if(s[i].gpa>=70) cout<<"Good";
        else if(s[i].gpa>=60) cout<<"Passing";
        else cout<<"Failed";

        cout<<endl;
    }
}