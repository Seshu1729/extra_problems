#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct matrix
{
	int **input1;
	int **input2;
	int **output;
};
int** AllocateMemory(int rows, int cols)
{
    int** ReturnArray;
    int counter1,counter2;
    ReturnArray = (int **)malloc(sizeof(int*)*(rows));
    for(counter1=0;counter1<rows;counter1++)
       *(ReturnArray+counter1) = (int *)malloc(sizeof(int)*(cols));
    return ReturnArray;
}
int **insertValues(int *input,int rows,int cols)
{
	int counter1,counter2,**array;
	array = AllocateMemory(rows,cols);
	for(counter1=0;counter1<rows;counter1++)
	{
		for(counter2=0;counter2<cols;counter2++)
		{
			array[counter1][counter2] = *((input+counter1*cols)+counter2);
		}
	}
	return array;
}
int isEqual(int **original,int **expected,int rows,int cols)
{
	int counter1,counter2;
	for(counter1=0;counter1<rows;counter1++)
	{
		for(counter2=0;counter2<cols;counter2++)
		{
			if(expected[counter1][counter2]!=original[counter1][counter2])
				return 0;
		}
	}
	return 1;
}
int **getResult(int **input1,int rows1,int cols1,int **input2,int rows2,int cols2)
{
	int** resultant_matrix;
    int counter1, counter2, counter3;
	resultant_matrix = AllocateMemory(rows1,cols2);
	for(counter1=0;counter1<rows1;counter1++)
    {
        for(counter2=0; counter2<cols2; counter2++)
        {
			resultant_matrix[counter1][counter2]=0;
		}
	}
    for(counter1=0;counter1<rows1;counter1++)
    {
        for(counter2=0; counter2<cols2; counter2++)
        {
            for(counter3=0; counter3<rows2; counter3++)
            {
                resultant_matrix[counter1][counter2]+=input1[counter1][counter3]*input2[counter3][counter2];
            }
        }
    }
    return resultant_matrix;
}
void inputTestCases()
{
	int i;
	int **matrix;
	int R[]={3,3,2},RC[]={2,3,3},C[]={3,3,2};
	int 
	input1Array1[3][2]={1,2,3,4,5,6},
    input1Array2[3][3]={1,0,0,0,1,0,0,0,1},
	input1Array3[2][3]={1,2,2,1,2,2},

	input2Array1[2][3]={1,2,3,4,5,6},
	input2Array2[3][3]={1,0,0,0,1,0,0,0,1},
	input2Array3[3][2]={1,1,2,2,2,2},

	outputArray1[3][3]={9,12,15,19,26,33,29,40,51},
	outputArray2[3][3]={1,0,0,0,1,0,0,0,1},
	outputArray3[2][2]={9,9,9,9};

	struct matrix test[3];
	for(i=0;i<3;i++)
	{
		test[i].input1 = AllocateMemory(R[i],RC[i]);
		test[i].input2 = AllocateMemory(RC[i],C[i]);
		test[i].output = AllocateMemory(R[i],C[i]);
	}
	test[0].input1 = insertValues((int *)input1Array1,3,2);
	test[1].input1 = insertValues((int *)input1Array2,3,3);
	test[2].input1 = insertValues((int *)input1Array3,2,3);
	test[0].input2 = insertValues((int *)input2Array1,2,3);
	test[1].input2 = insertValues((int *)input2Array2,3,3);
	test[2].input2 = insertValues((int *)input2Array3,3,2);
	test[0].output = insertValues((int *)outputArray1,3,3);
	test[1].output = insertValues((int *)outputArray2,3,3);
	test[2].output = insertValues((int *)outputArray3,2,2);
	for(i=0;i<3;i++)
	{
		matrix=getResult(test[i].input1,R[i],RC[i],test[i].input2,RC[i],C[i]);
		if(isEqual(matrix,test[i].output,R[i],C[i]))
			printf("pass\n");
		else
			printf("fail\n");
	}
}
int main()
{
	inputTestCases();
	getch();
	return 0;
}