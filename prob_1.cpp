#include <stdio.h>
struct student
{
    char name[50];
    char id[15];
    char phn[12];
    char sem[15];
    double cgpa;

};
void printSingleStudent(struct student st[], int i)
{
    printf(" Name of student : " );
    puts(st[i].name);
    printf(" Id of student : " );
    puts(st[i].id);
    printf(" Phone of student : " );
    puts(st[i].phn);
    printf(" Sem of student : " );
    puts(st[i].sem);
    printf(" CGPA of  student : " );
    printf("%.2lf\n", st[i].cgpa);
    printf("\n");
}


double averageCGPA(struct student st[], int n)
{
    double sum, avgCGPA;
    for(int i = 0; i < n ; i++ )
    {
        sum = sum +  st[i].cgpa;
    }

    avgCGPA = sum / n;

    return avgCGPA;
}


int highestCGPA(struct student st[], int n)
{

    double highCG;
    int highCGI ;
    for(int i = 0; i < n ; i++ )
    {
        if(i == 0 )
        {
            highCG = st[i].cgpa;
            highCGI = i;
        }
        else if(highCG <  st[i].cgpa)
        {
            highCG = st[i].cgpa;
            highCGI = i;
        }

    }
    return highCGI;
}


int minimumCGPA(struct student st[], int n)
{
    double miniCG;
    int miniCGI ;
    for(int i = 0; i < n ; i++ )
    {
        if(i == 0 )
        {
            miniCG = st[i].cgpa;
            miniCGI = i;
        }
        else if(miniCG >  st[i].cgpa)
        {
            miniCG = st[i].cgpa;
            miniCGI = i;
        }

    }
    return miniCGI;
}

void printStudent(struct student st[], int n)
{
    for(int i = 0; i < n ; i++ )
    {
        puts(st[i].name);
        puts(st[i].id);
        puts(st[i].phn);
        puts(st[i].sem);
        printf("%.2lf", st[i].cgpa);
        printf("\n");
    }

}

void findAirtelUser(struct student st[], int n)
{
    for(int i = 0; i < n ; i++ )
    {
        if(st[i].phn[2] == '6' )
        {
            printSingleStudent(st, i);
        }
    }
}

int searchStudent(struct student st[], int n, char id[]){
    int airUserI;
    for(int i = 0; i < n ; i++ )
    {
        int flag = 0;
        for( int j = 0; st[i].id[j] != '\0'; j++){
            if (st[i].id[j] != id[j]){
                flag = 1;

            }
        }
        if(flag == 0){
           airUserI = i;
           printSingleStudent(st, airUserI);
        }

    }
}

int main()
{
    struct student st[100];
    int n;
    char buffer[10];
    scanf("%d", &n);
    gets(buffer);

    for(int i = 0; i < n ; i++ )
    {
        printf("Enter name of student %d: ", i);
        gets(st[i].name);
        printf("Enter id of student %d: ", i);
        gets(st[i].id);
        printf("Enter phone of student %d: ", i);
        gets(st[i].phn);
        printf("Enter sem of student %d: ", i);
        gets(st[i].sem);
        printf("Enter CGPA of student %d: ", i);
        scanf("%lf", &st[i].cgpa);

        gets(buffer);
    }

    printf("Showing Information: \n");

    printStudent(st, n);


    //AVERAGE CGPA PROBLEM
    double avgCGPA = averageCGPA(st, n);
    printf("Average CGPA: %.2lf \n", avgCGPA);

    //HIGHEST CGPA
    int highCGI = highestCGPA(st, n);
    printf("Highest CGPA student Information: \n\n");
    printSingleStudent(st, highCGI);


    //MINIMUM CGPA
    int minimumCGI = minimumCGPA(st, n);
    printf("Minimum CGPA student Information: \n\n");
    printSingleStudent(st, minimumCGI);


    //AIRTEL USER INFORMATION
    printf("Showing Airtel User Information: \n");
    findAirtelUser(st, n);


    //Searching Student
    char id[15];
    printf("Enter Student Id You want to search: ");
    gets(id);

    //Search Student Of An Id
    searchStudent(st,n ,id);

/*

Rahman Mehraj
2022-6-90-182
01716517605
Spring 2022
3.90
Siam Rahman
2022-6-90-111
01716517605
Spring 2022
4.00
Fahat Rahman
2022-6-90-222
01635085937
Spring 2022
3.90
Nayeem Rahman
2022-6-90-444
01605592756
Spring 2022
3.75
Kayeem Hossain
2022-6-90-359
01999993182
Spring 2022
3.65

    */


    return 0;
}
