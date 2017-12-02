#include <iostream>
#include <cmath>

using namespace std;
#define ERROR 10e-4
void scanf_data(double & range_value, double ** &temp_a, double &x, int &n);

void hermite(double **temp_a, double x, int start, int end);
int main()
{
	double  **temp_a = NULL;
	int n = 0;
	double x = 0;
	double range_value = 0;

	scanf_data(range_value, temp_a, x, n);

	double t = (x - temp_a[0][0]) / range_value;

	int sec = t;

	if (x == temp_a[0][n - 1])
		sec = sec - 1;

	hermite(temp_a, x, sec, sec + 1);

	system("PAUSE");
}

void scanf_data(double & range_value, double ** &temp_a, double &x, int &n)
{
	cout << "********请输入数值的个数:**********\n";
	cin >> n;

	temp_a = new double *[3];

	cout << "********请输入间距的值:**********\n";
	cin >> range_value;

	cout << "********请先输入" << n << "个x,然后输入" << n << "个f(x):**********\n";
	for (size_t i = 0; i < 3; i++)
	{
		temp_a[i] = new double[n];
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> temp_a[i][j];
			//	cout << temp_a[i][j] << " ";
		}
		//cout << endl;
	}


	cout << "\n\n********需要计算的x的值**********\n";
	cin >> x;
}


void hermite(double **temp_a, double x, int start, int end)
{
	double x0 = temp_a[0][start];
	double x1 = temp_a[0][end];
	double fx0 = temp_a[1][start];
	double fx1 = temp_a[1][end];
	double f_x0 = temp_a[2][start];
	double f_x1 = temp_a[2][end];


	double a0 = (1 + 2 * (x - x0) / (x1 - x0))*pow((x - x1) / (x0 - x1), 2);
	double a1 = (1 + 2 * (x - x1) / (x0 - x1))*pow((x - x0) / (x1 - x0), 2);
	double b0 = (x - x0) * pow((x - x1) / (x0 - x1), 2);
	double b1 = (x - x1) * pow((x - x0) / (x1 - x0), 2);

	double hx = fx0 * a0 + fx1*a1 + f_x0*b0 + f_x1*b1;

	cout << "\n\n****************计算结果为************\n\n";
	cout << "\t" << "插值结果y为：" << hx << "\n\n";

}