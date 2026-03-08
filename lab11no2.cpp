#include <stdio.h>
#define NO_SCORE 5
#define NO_STD 10

typedef struct {
	char name[16];
	char surname[20];
	int score[NO_SCORE];
	float total;
} Student;

int readStudentData(Student *);
void findTotalScore();
float findAverage(Student);
void findLessThanTen(Student);

int main() {
	Student std[NO_STD];
	if(!readStudentData(&std[0])) return 0;
}

int readStudentData(Student *pStd) {
	FILE *fp;
	int i,j;
	fp = fopen("./lab11/no2/std10.dat","w");
	if (fp == NULL){
		printf("Can't open file\n");
		return 0;
	}
	fclose(fp);
	fp = fopen("./lab11/no2/std10.dat","ab");
	for (j=0; j<NO_STD; j++){
		printf("Enter student data %d\n",j+1);
		printf("\tName : ");
		scanf("%s", pStd[j].name);
		printf("\tSurname : ");
		scanf("%s", pStd[j].surname);
		for (i=0; i<NO_SCORE; i++){
			printf("\tScore %d : ", i+1);
			scanf("%d", &pStd[j].score[i]);
		}
		printf("\n");
		fwrite(&pStd[j],sizeof(Student),1,fp);			//write struct
	}
	fclose(fp);
	findTotalScore();
}

void findTotalScore() {
	int i,j;
	float avg;
	Student pStd[NO_STD];
	FILE *fp;
	fp = fopen("./lab11/no2/std10.dat","rb");
	for(j=0; j<NO_STD; j++){
		fread(&pStd[j],sizeof(Student),1,fp);			//read struct
		printf("\n\nPrint student data %d",j+1);
		printf("\n\t%s %s got score ", pStd[j].name, pStd[j].surname);
		pStd->total = 0.0;
		for (i=0; i<NO_SCORE; i++) {
			printf("%6d", pStd[j].score[i]);
			pStd[j].total += pStd[j].score[i];
		}
		printf("\n\tTotal score is %.2f", pStd[j].total);
		avg = findAverage(pStd[j]);
		printf("\n\tAverage score is %.2f", avg);
		findLessThanTen(pStd[j]);
	}
	fclose(fp);
}

float findAverage(Student s) {
	return(s.total/NO_SCORE);
}

void findLessThanTen(Student s) {
	int i,count=0;
	printf("\n\tScore less than 10");
	for (i=0; i<NO_SCORE; i++) {
		if (s.score[i] < 10) {
		printf("\n\t\tTest no.%d - %d", i+1, s.score[i]);
		count++;
	}
	}
	if (count==0)
		printf(" -> None");
}
