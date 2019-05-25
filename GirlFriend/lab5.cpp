#include<iostream>
#include<iomanip>
using namespace std;
#define N 2
void inputdata();
void sortdata();
void outputdata();
void outputaverage();
struct student
{
	char name[20];
	int num;
	float score[3];
	float sum;
};
struct student stu[N];
int main()
{
	inputdata();
	sortdata();
	outputdata();
	outputaverage();
	return 0;
}
void inputdata()
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		cin >> stu[i].name >> stu[i].num;
			cin >> stu[i].score[0] >> stu[i].score[1] >> stu[i].score[2];
		stu[i].sum = stu[i].score[0] + stu[i].score[1] + stu[i].score[2];
	}
}
void sortdata()
{
	int i, j;
	student temp;
	for (i = 0; i < N - 1; i++)
		for (j = 0; j < N - 1 - i; j++)
			if (stu[j].sum < stu[j + 1].sum)
			{
				temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
			}

}
void outputdata()
{
	int i;
	cout << setw(10) << "Name" << setw(10) << "Num";
	cout << setw(10) << "Score1" << setw(10) << "Score2" << setw(10) << "Score3";
	cout << setw(10) << "Sum" << endl;
	for (i = 0; i < N; i++)
	{
		cout << setw(10) << stu[i].name;
		cout << setw(10) << stu[i].num;
		cout << setw(10) << stu[i].score[0] << setw(10) << stu[i].score[1];
		cout << setw(10) << stu[i].score[2];
		cout << setw(10) << stu[i].sum << endl;
	}
}
void outputaverage()
{
	int i, j;
	float average[3] = { 0 };
	for (i = 0; i < 3; i++)
		for (j = 0; j < N; j++)
			average[i] += stu[j].score[i];
	for (i = 0; i < 3; i++)
		cout << "The average score of subject" << i + 1 << ":" << average[i] / N << endl;
}