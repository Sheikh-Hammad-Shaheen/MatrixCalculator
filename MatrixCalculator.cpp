#include<iostream>
#include<fstream>
using namespace std;

struct matrix
{
	int row1;
	int col1;	
	int row2;
	int col2;
	int **mat;
	int **mat0;
	int **mat1;
	float *matii;
	float **matri;
};

void sum_of_all_values();
void Sum_of_two_matrices();
void option();
void product_of_All_values();
void menu();
void fill_matrix(ifstream &fin,int **data,int r_size,int c_size);
int find_clm_size(ifstream &fin);
int find_r_size(ifstream &fin,int c);
int **create_2D(int r,int c);
void display_2D(int **data,int r,int c);
int find_sum_of_matrix(int **data,int r,int c);
int ** take_input_frm_user(int &r,int &c);
int** take_input_frm_file(int &r,int &c);
double long calculate_multi(int **data,int r_size,int c_size);
void row_wise_average();
float* calculate_avg(int **data,int r,int c);
void column_wise_average();
void scalar_matrix_subtraction();
float* calculate_clm_avg(int **data,int r,int c);
void average_of_whole_matrix();
float calculate_whole_avg(int **data,int r,int c);
void row_wise_sorting_assending();
void row_wise_sorting_descending();
void find_row_wise_sorting_assending(int **data,int r,int c);
void sort_1D_assending(int *data,int size);
void find_row_wise_sorting_descending(int **data,int r,int c) ;
void column_wise_sorting_assending();
void sort_1D_descending(int *data,int size);
void find_column_wise_sorting_assending(int **data,int r,int c);
void sub_scalar(int **data,int r,int c,int no);
void scalar_matrix_subtraction();
void function(int **data,int r,int c);
void scalar_matrix_addtion();
void add_scalar(int **data,int r,int c,int no);
void addition_of_two_matrices();
int** find_addition_of_2m(int **data1,int **data2,int r,int c);
void matrix_transpose();
int ** find_transpose(int **data,int r,int c);
int** find_subtraction_of_2m(int **data1,int **data2,int r,int c);
void scalar_matrix_multiplication();
void multiplication_of_two_matrices();
void mul_scalar(int **data,int r,int c,int no);
void scalar_matrix_division();
void matrix_determinant();
int** find_determinant(int **data,int r,int c);
void div_scalar(int **data,int r,int c,int no);
int** find_division_of_2m(int **data1,int **data2,int r,int c);
int** find_multiplication_of_2m(int **data1,int **data2,int r,int c);
void find_column_wise_sorting_descending(int **data,int r,int c);
void column_wise_sorting_descending();
void function1(int **data,int r,int c);

int main()
{
	matrix matrr;
	ifstream fin;
	menu();
	option();
	
}
void Sum_of_All_values()     
{
	cout<<"Press 1 for user input  "<<endl;
	cout<<"Press 2 to read from a file  "<<endl;
	int option=0;
	cout<<"Enter Here : ";
	cin>>option;
	
	matrix matr;
	int r=0,c=0;
	if(option==1)
	{
		matr.mat=take_input_frm_user(r,c);
	}
	else if(option==2)
	{
		matr.mat=take_input_frm_file(r,c);
	}
	else
		cout<<"Invalid Entery"<<endl;
	int sum=find_sum_of_matrix(matr.mat,r,c);
	cout<<"Matrix is "<<endl;
	display_2D(matr.mat,r,c);
	cout<<endl<<"The SUM is "<<sum<<endl;		
}
int ** take_input_frm_user(int &r,int &c)
{
	matrix matr;
	cout<<"Enter row of Matrix  : ";
	cin>>r;
	cout<<" Enter col of matrix : ";
	cin>>c;
	matr.mat=new int *[r];
	for(int j=0;j<r;j++)
	{	
		matr.mat[j]=new int [c];
	}
	cout<<"Enter values of Matrix : ";	
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>matr.mat[i][j];
		}
	}
	return matr.mat;
}

int find_sum_of_matrix(int **data,int r,int c)
{
	matrix matr;
	int sum=0;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			sum=sum+data[i][j];
		}
	}
		return sum;
}
int** take_input_frm_file(int &r,int &c)
{
	matrix matr;	
	ifstream fin;
	char filename[20];
	cout<<"Enter file name :";
	cin>>filename;
	fin.open(filename);
	c=find_clm_size(fin);
	fin.close();	
			
	fin.open(filename);
	r=find_r_size(fin,c);
	fin.close();
			
	matr.mat=create_2D(r,c);
			
	fin.open(filename);
	fill_matrix(fin,matr.mat,r,c);
	fin.close();
			
	return matr.mat;
}


void display_2D(int **data,int r,int c)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<"		"<<data[i][j]<<" ";
		}
		cout<<endl;
	}
}

int **create_2D(int r,int c)
{
	int **data=new int *[r];
	for(int i=0;i<r;i++)
	{
		data[i]=new int [c];
	}
	return data;
}

void fill_matrix(ifstream &fin,int **data,int r_size,int c_size)
{
	for(int i=0;i<r_size;i++)
	{
		for(int j=0;j<c_size;j++)
		{
			fin>>data[i][j];
		}
	}
}

int find_clm_size(ifstream &fin)
{
	int c=0,no;
	char alpha=' ';
	while(fin>>no && alpha==' ')
	{
		fin.get(alpha);
		c++;
	}
	return c;
}

int find_r_size(ifstream &fin,int c)
{
	int r=0,no;
	while(fin>>no)
	{
		r++;
	}
	r=r/c;
	return r;
}

void product_of_All_values()
{
	cout<<"Press 1 for user input  "<<endl;
	cout<<"Press 2 to read from a file  "<<endl;
	int option=0;
	cout<<"Enter Here : ";
	cin>>option;
	
	matrix matr;
	int r=0,c=0;
	if(option==1)
	{
		matr.mat=take_input_frm_user(r,c);
	}
	else if(option==2)
	{
		matr.mat=take_input_frm_file(r,c);
	}
	else
		cout<<"Invalid Entery"<<endl;
	
	double long  pdt=calculate_multi(matr.mat,r,c);
	
	cout<<"Matrix is "<<endl;
	display_2D(matr.mat,r,c);
	cout<<endl<<"Product  is : "<<pdt<<endl;
	
	
}

double long calculate_multi(int **data,int r_size,int c_size)
{
	double long pdt=1;
	for(int i=0;i<r_size;i++)
	{
		for(int j=0;j<c_size;j++)
		{
			pdt=pdt*data[i][j];
		}
	}
	return pdt;
}

void row_wise_average()
{
	cout<<"Press 1 for user input  "<<endl;
	cout<<"Press 2 to read from a file  "<<endl;
	int option=0;
	cout<<"Enter Here : ";
	cin>>option;
	
	matrix matr;
	int r=0,c=0;
	if(option==1)
	{
		matr.mat=take_input_frm_user(r,c);
	}
	else if(option==2)
	{
		matr.mat=take_input_frm_file(r,c);
	}
	else
		cout<<"Invalid Entery"<<endl;
	
	matr.matii=calculate_avg(matr.mat,r,c);
	
	cout<<"Matrix is "<<endl;
	display_2D(matr.mat,r,c);
	
	cout<<"Colm wise avrge ";
	for(int i=0;i<r;i++)
	{
		cout<<matr.matii[i]<<endl;
	}
	cout<<endl;
	
	
}

float* calculate_avg(int **data,int r,int c)
{
	matrix mat;
	mat.matii= new float [r];
	float sum=0.0;
	for(int i=0;i<r;i++)
	{
		sum=0.0;
		for(int j=0;j<c;j++)
		{
			sum=sum+data[i][j];
		}
		mat.matii[i]=sum/c;
	}
	return mat.matii;
}

void column_wise_average()
{
	cout<<"Press 1 for user input  "<<endl;
	cout<<"Press 2 to read from a file  "<<endl;
	int option=0;
	cout<<"Enter Here : ";
	cin>>option;
	
	matrix matr;
	int r=0,c=0;
	if(option==1)
	{
		matr.mat=take_input_frm_user(r,c);
	}
	else if(option==2)
	{
		matr.mat=take_input_frm_file(r,c);
	}
	else
		cout<<"Invalid Entery"<<endl;
	
	matr.matii=calculate_clm_avg(matr.mat,r,c);
	
	cout<<"Matrix is "<<endl;
	display_2D(matr.mat,r,c);
	
	cout<<"Colm wise avrge ";
	for(int i=0;i<r;i++)
	{
		cout<<matr.matii[i]<<" ";
	}
	cout<<endl;

	
}

float* calculate_clm_avg(int **data,int r,int c)
{
	matrix mat;
	mat.matii= new float [c];
	float sum=0.0;
	for(int i=0;i<c;i++)
	{
		sum=0.0;
		for(int j=0;j<r;j++)
		{
			sum=sum+data[i][j];
		}
		mat.matii[i]=sum/c;
	}
	
	return mat.matii;	
}

void average_of_whole_matrix()
{
	cout<<"Press 1 for user input  "<<endl;
	cout<<"Press 2 to read from a file  "<<endl;
	int option=0;
	cout<<"Enter Here : ";
	cin>>option;
	
	matrix matr;
	int r=0,c=0;
	if(option==1)
	{
		matr.mat=take_input_frm_user(r,c);
	}
	else if(option==2)
	{
		matr.mat=take_input_frm_file(r,c);
	}
	else
		cout<<"Invalid Entery"<<endl;
	
	float avrg=calculate_whole_avg(matr.mat,r,c);
	
	cout<<"Matrix is "<<endl;
	display_2D(matr.mat,r,c);
	
	cout<<"Average of Whole MATRIX : "<<avrg;
	cout<<endl;
	
}

float calculate_whole_avg(int **data,int r,int c)
{
	float sum=find_sum_of_matrix(data,r,c);
	int mul=r*c;
	return sum/mul;

}

void row_wise_sorting_assending()
{
	cout<<"Press 1 for user input  "<<endl;
	cout<<"Press 2 to read from a file  "<<endl;
	int option=0;
	cout<<"Enter Here : ";
	cin>>option;
	
	matrix matr;
	int r=0,c=0;
	if(option==1)
	{
		matr.mat=take_input_frm_user(r,c);
	}
	else if(option==2)
	{
		matr.mat=take_input_frm_file(r,c);
	}
	else
		cout<<"Invalid Entery"<<endl;
	cout<<"Before Sorting "<<endl;
	cout<<"Matrix is "<<endl;
	display_2D(matr.mat,r,c);
	
	find_row_wise_sorting_assending(matr.mat,r,c);
	
	cout<<"After Sorting "<<endl;
	cout<<"Matrix is "<<endl;
	display_2D(matr.mat,r,c);
	
	cout<<endl;
	

}

void row_wise_sorting_descending()
{
	cout<<"Press 1 for user input  "<<endl;
	cout<<"Press 2 to read from a file  "<<endl;
	int option=0;
	cout<<"Enter Here : ";
	cin>>option;
	
	matrix matr;
	int r=0,c=0;
	if(option==1)
	{
		matr.mat=take_input_frm_user(r,c);
	}
	else if(option==2)
	{
		matr.mat=take_input_frm_file(r,c);
	}
	else
		cout<<"Invalid Entery"<<endl;
	cout<<"Before Sorting "<<endl;
	cout<<"Matrix is "<<endl;
	display_2D(matr.mat,r,c);
	
	find_row_wise_sorting_descending(matr.mat,r,c);
	
	cout<<"After Sorting "<<endl;
	cout<<"Matrix is "<<endl;
	display_2D(matr.mat,r,c);
	
	cout<<endl;
	

}
void find_row_wise_sorting_assending(int **data,int r,int c) 
{
	for(int i=0;i<r;i++)
	{
		sort_1D_assending(data[i],c);
	}
}

void sort_1D_assending(int *data,int size)
{
	for(int i=0;i<size-1;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(data[i]>data[j])
				swap(data[i],data[j]);
		}
	}
}


void find_row_wise_sorting_descending(int **data,int r,int c) 
{
	for(int i=0;i<r;i++)
	{
		sort_1D_descending(data[i],c);
	}
}

void sort_1D_descending(int *data,int size)
{
	for(int i=0;i<size-1;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(data[i]<data[j])
				swap(data[i],data[j]);
		}
	}
}
void column_wise_sorting_assending()
{
	cout<<"Press 1 for user input  "<<endl;
	cout<<"Press 2 to read from a file  "<<endl;
	int option=0;
	cout<<"Enter Here : ";
	cin>>option;
	
	matrix matr;
	int r=0,c=0;
	if(option==1)
	{
		matr.mat=take_input_frm_user(r,c);
	}
	else if(option==2)
	{
		matr.mat=take_input_frm_file(r,c);
	}
	else
		cout<<"Invalid Entery"<<endl;
	cout<<"Before Sorting "<<endl;
	cout<<"Matrix is "<<endl;
	display_2D(matr.mat,r,c);
	
	find_column_wise_sorting_assending(matr.mat,r,c);
	
	cout<<"After Sorting "<<endl;
	cout<<"Matrix is "<<endl;
	display_2D(matr.mat,r,c);
	
	cout<<endl;
	
	
	
}


void find_column_wise_sorting_assending(int **data,int r,int c)
{
	
	for(int i=0;i<c;i++)
	{
		function(data,r,i);
	
	}
}

void function(int **data,int r,int c)
{
	for(int i=0;i<r;i++)
	{
		for(int j=i+1;j<r;j++)
		{
			if(data[i][c]>data[j][c])
				swap(data[i][c],data[j][c]);
		}
	}
}



void column_wise_sorting_descending()
{
	cout<<"Press 1 for user input  "<<endl;
	cout<<"Press 2 to read from a file  "<<endl;
	int option=0;
	cout<<"Enter Here : ";
	cin>>option;
	
	matrix matr;
	int r=0,c=0;
	if(option==1)
	{
		matr.mat=take_input_frm_user(r,c);
	}
	else if(option==2)
	{
		matr.mat=take_input_frm_file(r,c);
	}
	else
		cout<<"Invalid Entery"<<endl;
	cout<<"Before Sorting "<<endl;
	cout<<"Matrix is "<<endl;
	display_2D(matr.mat,r,c);
	
	find_column_wise_sorting_descending(matr.mat,r,c);
	
	cout<<"After Sorting "<<endl;
	cout<<"Matrix is "<<endl;
	display_2D(matr.mat,r,c);
	
	cout<<endl;
	
	
	
}


void find_column_wise_sorting_descending(int **data,int r,int c)
{
	
	for(int i=0;i<c;i++)
	{
		function1(data,r,i);
	
	}
}

void function1(int **data,int r,int c)
{
	for(int i=0;i<r;i++)
	{
		for(int j=i+1;j<r;j++)
		{
			if(data[i][c]<data[j][c])
				swap(data[i][c],data[j][c]);
		}
	}
}

void scalar_matrix_addtion()
{
	cout<<"Press 1 for user input  "<<endl;
	cout<<"Press 2 to read from a file  "<<endl;
	int option=0;
	cout<<"Enter Here : ";
	cin>>option;
	
	matrix matr;
	int r=0,c=0;
	if(option==1)
	{
		matr.mat=take_input_frm_user(r,c);
	}
	else if(option==2)
	{
		matr.mat=take_input_frm_file(r,c);
	}
	else
		cout<<"Invalid Entery"<<endl;
	
	int s_no;
	cout<<"Enter The value  to add : ";
	cin>>s_no;
	
	cout<<"Before Adding "<<endl;
	cout<<"Matrix is "<<endl;
	display_2D(matr.mat,r,c);
	add_scalar(matr.mat,r,c,s_no);
	
	cout<<endl<<"After Adding "<<endl;
	cout<<"Matrix is "<<endl;
	display_2D(matr.mat,r,c);
	
	cout<<endl;
	
}

void add_scalar(int **data,int r,int c,int no)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			data[i][j]=data[i][j]+no;
	}
}

void addition_of_two_matrices()
{
	cout<<"Press 1 for user input  "<<endl;
	cout<<"Press 2 to read from a file  "<<endl;
	int option=0;
	cout<<"Enter Here : ";
	cin>>option;
	
	matrix matr;
	int r=0,c=0;
	if(option==1)
	{
		cout<<"For Matrix 1 "<<endl;
		matr.mat0=take_input_frm_user(r,c);
		cout<<"For Matrix 2 "<<endl;
		matr.mat1=take_input_frm_user(r,c);
	}
	else if(option==2)
	{
		cout<<"For Matrix 1 "<<endl;
		matr.mat0=take_input_frm_file(r,c);
		cout<<"For Matrix 2 "<<endl;
		matr.mat1=take_input_frm_file(r,c);
	}
	else
		cout<<"Invalid Entery"<<endl;
	
	

	cout<<"Matrix 1 is "<<endl;
	display_2D(matr.mat0,r,c);
	cout<<endl<<"Matrix 2 is "<<endl;
	display_2D(matr.mat1,r,c);
	
	matr.mat=create_2D(r,c);
	
	matr.mat=find_addition_of_2m(matr.mat0,matr.mat1,r,c);
	
	cout<<endl<<"After Adding "<<endl;
	cout<<"Matrix is "<<endl;
	display_2D(matr.mat,r,c);
	
	cout<<endl;
	
}


void subtraction_of_two_matrices()
{
	cout<<"Press 1 for user input  "<<endl;
	cout<<"Press 2 to read from a file  "<<endl;
	int option=0;
	cout<<"Enter Here : ";
	cin>>option;
	
	matrix matr;
	int r=0,c=0;
	if(option==1)
	{
		cout<<"For Matrix 1 "<<endl;
		matr.mat0=take_input_frm_user(r,c);
		cout<<"For Matrix 2 "<<endl;
		matr.mat1=take_input_frm_user(r,c);
	}
	else if(option==2)
	{
		cout<<"For Matrix 1 "<<endl;
		matr.mat0=take_input_frm_file(r,c);
		cout<<"For Matrix 2 "<<endl;
		matr.mat1=take_input_frm_file(r,c);
	}
	else
		cout<<"Invalid Entery"<<endl;
	
	

	cout<<"Matrix 1 is "<<endl;
	display_2D(matr.mat0,r,c);
	cout<<endl<<"Matrix 2 is "<<endl;
	display_2D(matr.mat1,r,c);
	
	matr.mat=create_2D(r,c);
	
	matr.mat=find_subtraction_of_2m(matr.mat0,matr.mat1,r,c);
	
	cout<<endl<<"After subtracting "<<endl;
	cout<<"Matrix is "<<endl;
	display_2D(matr.mat,r,c);
	
	cout<<endl;
	
}



void multiplication_of_two_matrices()
{
	cout<<"Press 1 for user input  "<<endl;
	cout<<"Press 2 to read from a file  "<<endl;
	int option=0;
	cout<<"Enter Here : ";
	cin>>option;
	
	matrix matr;
	int r=0,c=0;
	if(option==1)
	{
		cout<<"For Matrix 1 "<<endl;
		matr.mat0=take_input_frm_user(r,c);
		cout<<"For Matrix 2 "<<endl;
		matr.mat1=take_input_frm_user(r,c);
	}
	else if(option==2)
	{
		cout<<"For Matrix 1 "<<endl;
		matr.mat0=take_input_frm_file(r,c);
		cout<<"For Matrix 2 "<<endl;
		matr.mat1=take_input_frm_file(r,c);
	}
	else
		cout<<"Invalid Entery"<<endl;
	
	

	cout<<"Matrix 1 is "<<endl;
	display_2D(matr.mat0,r,c);
	cout<<endl<<"Matrix 2 is "<<endl;
	display_2D(matr.mat1,r,c);
	
	matr.mat=create_2D(r,c);
	
	matr.mat=find_multiplication_of_2m(matr.mat0,matr.mat1,r,c);
	
	cout<<endl<<"After multpyling "<<endl;
	cout<<"Matrix is "<<endl;
	display_2D(matr.mat,r,c);
	
	cout<<endl;
	
}

int** find_addition_of_2m(int **data1,int **data2,int r,int c)
{
	int **data=new int *[r];
	for(int i=0;i<r;i++)
	{
		data[i]=new int [c];
	}
	
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			data[i][j]=data1[i][j]+data2[i][j];
		}
	}
	return data;
}



void scalar_matrix_subtraction()
{
	cout<<"Press 1 for user input  "<<endl;
	cout<<"Press 2 to read from a file  "<<endl;
	int option=0;
	cout<<"Enter Here : ";
	cin>>option;
	
	matrix matr;
	int r=0,c=0;
	if(option==1)
	{
		matr.mat=take_input_frm_user(r,c);
	}
	else if(option==2)
	{
		matr.mat=take_input_frm_file(r,c);
	}
	else
		cout<<"Invalid Entery"<<endl;
	
	int s_no;
	cout<<"Enter The value  to sub : ";
	cin>>s_no;
	
	cout<<"Before subtracting "<<endl;
	cout<<"Matrix is "<<endl;
	display_2D(matr.mat,r,c);
	sub_scalar(matr.mat,r,c,s_no);
	
	cout<<endl<<"After subtracting "<<endl;
	cout<<"Matrix is "<<endl;
	display_2D(matr.mat,r,c);
	
	cout<<endl;
	
}

void sub_scalar(int **data,int r,int c,int no)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			data[i][j]=data[i][j]-no;
	}
}
int** find_subtraction_of_2m(int **data1,int **data2,int r,int c)
{
	int **data=new int *[r];
	for(int i=0;i<r;i++)
	{
		data[i]=new int [c];
	}
	
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			data[i][j]=data1[i][j]-data2[i][j];
		}
	}
	return data;
}


void scalar_matrix_multiplication()
{
	cout<<"Press 1 for user input  "<<endl;
	cout<<"Press 2 to read from a file  "<<endl;
	int option=0;
	cout<<"Enter Here : ";
	cin>>option;
	
	matrix matr;
	int r=0,c=0;
	if(option==1)
	{
		matr.mat=take_input_frm_user(r,c);
	}
	else if(option==2)
	{
		matr.mat=take_input_frm_file(r,c);
	}
	else
		cout<<"Invalid Entery"<<endl;
	
	int s_no;
	cout<<"Enter The value  to multiply : ";
	cin>>s_no;
	
	cout<<"Before multiplying "<<endl;
	cout<<"Matrix is "<<endl;
	display_2D(matr.mat,r,c);
	mul_scalar(matr.mat,r,c,s_no);
	
	cout<<endl<<"After multiplying "<<endl;
	cout<<"Matrix is "<<endl;
	display_2D(matr.mat,r,c);
	
	cout<<endl;
	
}

void mul_scalar(int **data,int r,int c,int no)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			data[i][j]=data[i][j]*no;
	}
}
int** find_multiplication_of_2m(int **data1,int **data2,int r,int c)
{
	
	int **data=new int *[r];
	for(int i=0;i<r;i++)
	{
		data[i]=new int [c];
	}
	
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			data[i][j]=data1[i][j]*data2[i][j];
		}
	}
	return data;
}


void scalar_matrix_division()
{
	cout<<"Press 1 for user input  "<<endl;
	cout<<"Press 2 to read from a file  "<<endl;
	int option=0;
	cout<<"Enter Here : ";
	cin>>option;
	
	matrix matr;
	int r=0,c=0;
	if(option==1)
	{
		matr.mat=take_input_frm_user(r,c);
	}
	else if(option==2)
	{
		matr.mat=take_input_frm_file(r,c);
	}
	else
		cout<<"Invalid Entery"<<endl;
	
	int s_no;
	cout<<"Enter The value  to divide : ";
	cin>>s_no;
	
	cout<<"Before division "<<endl;
	cout<<"Matrix is "<<endl;
	display_2D(matr.mat,r,c);
	div_scalar(matr.mat,r,c,s_no);
	
	cout<<endl<<"After division "<<endl;
	cout<<"Matrix is "<<endl;
	display_2D(matr.mat,r,c);
	
	cout<<endl;
	
}

void div_scalar(int **data,int r,int c,int no)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			data[i][j]=data[i][j]/no;
	}
}
int** find_division_of_2m(int **data1,int **data2,int r,int c)
{
	int **data=new int *[r];
	for(int i=0;i<r;i++)
	{
		data[i]=new int [c];
	}
	
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			data[i][j]=data1[i][j]/data2[i][j];
		}
	}
	return data;
}
void matrix_transpose()
{
	cout<<"Press 1 for user input  "<<endl;
	cout<<"Press 2 to read from a file  "<<endl;
	int option=0;
	cout<<"Enter Here : ";
	cin>>option;
	
	matrix matr;
	int r=0,c=0;
	if(option==1)
	{
		matr.mat=take_input_frm_user(r,c);
	}
	else if(option==2)
	{
		matr.mat=take_input_frm_file(r,c);
	}
	else
		cout<<"Invalid Entery"<<endl;
	

	cout<<"Before Transpose "<<endl;
	cout<<"Matrix is "<<endl;
	display_2D(matr.mat,r,c);
	
	matr.mat=find_transpose(matr.mat,r,c);
	
	swap(r,c);
	cout<<endl<<"After Transpose "<<endl;
	cout<<"Matrix is "<<endl;
	display_2D(matr.mat,r,c);
	
	cout<<endl;
	
}

int ** find_transpose(int **data,int r,int c)
{
	int **n_data=create_2D(c,r);
	
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			n_data[j][i]=data[i][j];
	}
	return n_data;
}


void matrix_determinant()
{
	cout<<"Press 1 for user input  "<<endl;
	cout<<"Press 2 to read from a file  "<<endl;
	int option=0;
	cout<<"Enter Here : ";
	cin>>option;
	matrix matr;
	int r=0,c=0;
	if(option==1)
	{
		matr.mat=take_input_frm_user(r,c);
	}
	else if(option==2)
	{
		matr.mat=take_input_frm_file(r,c);
	}
	else
		cout<<"Invalid Entery"<<endl;
	cout<<"Before determinant "<<endl;
	cout<<"Matrix is "<<endl;
	display_2D(matr.mat,r,c);
	matr.mat=find_determinant(matr.mat,r,c);
	cout<<endl;
}
int** find_determinant(int **data,int r,int c)
{
	matrix matr;
	matr.mat=data;
	matr.row1=3;
	matr.col1=3;
	int det=0;
	int num,num1,num2,num0;
	int b=0;
	num=matr.mat[b][b]*(matr.mat[b+1][b+1]*matr.mat[b+2][b+2]-matr.mat[b+2][b+1]*matr.mat[b+1][b+2]);
	num1=matr.mat[b][b+1]*(matr.mat[b+1][b]*matr.mat[b+2][b+2]-matr.mat[b+2][b]*matr.mat[b+1][b+2]);
	num2=matr.mat[b][b+2]*(matr.mat[b+1][b]*matr.mat[b+2][b+1]-matr.mat[b+2][b]*matr.mat[b+1][b+1]);
	num0=num-num1+num2;
	cout<<" detminant of 3 X 3 "<<num0; 	
}
void menu()
{
	cout<<" 		Enter intergers only to start working";
	cout<<"  \n \t ****************************************************************\n \t";
	cout<<" ^ Click on 1 for Sum of all value \t			^\n \t";
	cout<<" ^ Click on 2 for product of all value of matrices\t	^ \n \t";
	cout<<" ^ Click on 3 for Row Wise Average of matrices\t		^ \n \t";
	cout<<" ^ Click on 4 for Column Wise Average of matrices\t	^ \n \t";
	cout<<" ^ Click on 5 for Average of whole matrices\t		^ \n \t";
	cout<<" ^ Click on 6 for Row Wise Sorting in asscending of matrices\t^ \n \t";
	cout<<" ^ Click on 7 for Row Wise Sorting in descending of matrices\t^ \n \t";
	cout<<" ^ Click on 8 for Column Wise Sorting in assending of matrices	^ \n \t";
	cout<<" ^ Click on 9 for Column Wise Sorting in descending of matrices\t^ \n \t";
	cout<<" ^ Click on 10 for Scalar Matrix Addition\t		^ \n \t";
	cout<<" ^ Click on 11 for Addtion of two matrices\t		^ \n \t";
	cout<<" ^ Click on 12 for Scalar Matrix Subtraction of matrices	^ \n \t";
	cout<<" ^ Click on 13 for Subtraction of two matrices\t		^ \n \t";
	cout<<" ^ Click on 14 for Scaler Matrix Multiplication of two matrices\t^ \n \t";
	cout<<" ^ Click on 15 for Multiplication of two matrices\t	^ \n \t";
	cout<<" ^ Click on 16 for Scaler Matrix division\t		^ \n \t";
	cout<<" ^ Click on 17 for Matrix transpose				^ \n \t";
	cout<<" ^ Click on 18 for Matrix determinant				^ \n \t";
	cout<<" ^ Click on 19 for Matrix Inverse\t			^ \n\t";
	cout<<" ^ Click on 0 to exit \t\t\t 			^\n";
	cout<<" \t ****************************************************************\n \t";
}

void option()
{
	char opt;
	int option;
	while(true)
	{
		cout<<"Enter value: ";
		cin>>option;
		if(option==1)
		{
			Sum_of_All_values(); 
		}
		else if(option==2)
		{
			product_of_All_values(); 
		}
		else if(option==3)
		{
			row_wise_average();
		}
		else if(option==4)
		{
			column_wise_average();
		}
		else if(option==5)
		{
			average_of_whole_matrix();
		}
		else if(option==6)
		{
			row_wise_sorting_assending();
		}
		else if(option==7)
		{
			row_wise_sorting_descending();	
		}
		else if(option==8)
		{
			column_wise_sorting_assending();
		}
		else if(option==9)
		{
			column_wise_sorting_descending();
		}
		else if(option==10)
		{
			scalar_matrix_addtion();
		}
		else if(option==11)
		{
			addition_of_two_matrices();		
		}
		else if(option==12)
		{
			scalar_matrix_subtraction();
		}
		else if(option==13)
		{
			subtraction_of_two_matrices();
		}
		else if(option==14)
		{
			scalar_matrix_multiplication();
		}	
		else if(option==15)
		{
			multiplication_of_two_matrices();
		}
		else if(option==16)
		{
			scalar_matrix_division();
		}
		else if(option==17)
		{
			matrix_transpose();    
		}
		else if(option==18)
		{
			matrix_determinant();
		}
		else if(option==19)
		{
			//matrix_inverse();
		}
		else if(option<0||option>19)
		{
			cout<<"Invalid operation ";
		}
		else
		{
			if(option==0)
			{
				break;
			}
		}
	}	
}
