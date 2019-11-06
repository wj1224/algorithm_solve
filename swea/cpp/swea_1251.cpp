#include <iostream>

using namespace std;

#define INF 999999999999

int T, Testcase;

int N;
double loc[1000][2];
double E;
int visit[1000];
double dist[1000];
double res;

double calc(void);
double calc_weight(double a_x, double a_y, double b_x, double b_y);

int main() {

	cin >> Testcase;

	cout << fixed;
	cout.precision(0);

	for (T = 0; T < Testcase; T++) {

		cin >> N;

		for (int i = 0; i < 2; i++) {

			for (int j = 0; j < N; j++) {

				cin >> loc[j][i];

			}

		}

		cin >> E;

		for (int i = 0; i < 1000; i++) {
			dist[i] = INF;
			visit[i] = 0;
		}

		res = calc();

		cout << "#" << T + 1 << " " << res << endl;

		res = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 1000; j++) {
				loc[j][i] = 0;
			}
		}

	}

	return 0;

}

double calc(void) {

	dist[0] = 0;
	double res = 0;

	for (int i = 0; i < N; i++) {

		double minValue = INF;
		int minInd = 0;

		for (int j = 0; j < N; j++) {

			if (visit[j] == 0 && dist[j] < minValue) {

				minValue = dist[j];
				minInd = j;

			}

		}

		visit[minInd] = 1;
		res += minValue;

		for (int j = 0; j < N; j++) {

			if (visit[j] == 0) {

				minValue = calc_weight(loc[minInd][0], loc[minInd][1], loc[j][0], loc[j][1]);

				if (dist[j] > minValue)
					dist[j] = minValue;

			}

		}

	}

	return res;

}

double calc_weight(double a_x, double a_y, double b_x, double b_y) {

	return (E * ((b_x - a_x)*(b_x - a_x) + (b_y - a_y)*(b_y - a_y)));

}