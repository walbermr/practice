#include "ArrayPractice.h"



void printSizeAcc(std::vector<std::vector<int>*> v) {
	/* This function prints the array, its size and its cumulative sum.
	*/
	for (std::vector<std::vector<int>*>::iterator i = v.begin(); i != v.end(); i++) {
		std::cout << "Vector: { ";
		for (std::vector<int>::iterator j = (*i)->begin(); j != (*i)->end(); j++) {
			std::cout << *j << " ";
		}

		std::cout << "}, Size: " << (*i)->size() <<
			" Accumulate: " << std::accumulate((*i)->begin(), (*i)->end(), 0) << std::endl;
	}
}


void maxSubTest(std::vector<int> input) {
	std::vector<int> result = maxSubArray(input);

	std::cout << "Max Sub: ";
	for (std::vector<int>::const_iterator it = result.begin(); it != result.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl << std::endl;
	std::cout << "End MaxSub." << std::endl << std::endl;
}
 

std::vector<int> maxSubArray(std::vector<int> input)
{
	/* This function returns the maximum lenght sub array of positive numbers
		between two negative numbers.
	*/
	std::vector<int> output;
	std::vector<std::vector<int>*> only_positives;
	std::vector<int> *partial = nullptr;
	//unsigned long long int sum = 0;
	bool restart = true;
	int max_size = -1, max_acc = -1, partial_acc = -1;

	for (std::vector<int>::iterator it = input.begin(); it != input.end(); it++) {
		if (restart) {
			if(partial != nullptr)
				only_positives.push_back(partial);
			restart = false;
			partial = new std::vector<int>();
		}
		if (*it < 0)
			restart = true;
		else
			partial->push_back(*it);
	}

	only_positives.push_back(partial);
	printSizeAcc(only_positives);

	for (std::vector<std::vector<int>*>::iterator i = only_positives.begin(); i != only_positives.end(); i++) {
		int size = (int) (*i)->size();
		if (size > max_size) {
			output = *(*i);
			max_size = size;
			max_acc = std::accumulate((*i)->begin(), (*i)->end(), 0);
		}

		else if (size == max_size) {
			partial_acc = std::accumulate((*i)->begin(), (*i)->end(), 0);

			if (partial_acc > max_acc) {
				output = *(*i);
				max_size = size;
				max_acc = std::accumulate((*i)->begin(), (*i)->end(), 0);
			}
		}
	}

	return output;
}


std::vector<int> rotateArray(std::vector<int> &A, int B) {
	std::vector<int> ret;
	int rotations = B % A.size();

	for (int i = 0; i < (A.size() - rotations); i++) {
		ret.push_back(A[i + rotations]);
	}

	for (int i = 0; i < rotations; i++) {
		ret.push_back(A[i]);
	}

	return ret;
}

std::vector<int> rotateArray2(std::vector<int> &A, int B) {
	std::vector<int> ret;

	for (int i = 0; i < A.size(); i++) {
		ret.push_back(A[(i + B) % A.size()]);
	}

	return ret;
}

std::vector< std::vector<int> > pascalTriangle(int A) {
	std::vector<std::vector<int>> ret;
	int val;

	for (int i = 1; i <= A; i++) {
		std::vector<int> aux;
		for (int j = 0; j < i; j++) {

			if ((i - 1) <= 0)
				val = 1;
			else {
				if (j == 0)
					val = ret[(i - 2)][j];
				else if (j > (i - 2))
					val = ret[(i - 2)][(j - 1)];
				else
					val = ret[(i - 2)][(j - 1)] + ret[(i - 2)][j];
			}
			aux.push_back(val);
		}
		ret.push_back(aux);
	}
	return ret;
}

void printArrayOfArray(std::vector<std::vector<int>> array) {
	for (std::vector<std::vector<int>>::iterator i = array.begin(); i != array.end(); i++)
		printArray(*i);
}

void printArray(std::vector<int> array) {
	for (std::vector<int>::iterator i = array.begin(); i != array.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
}

std::vector<int> spiralOrder(const std::vector<std::vector<int>> &A) {
	std:: vector<int> ret;
	int t = 0, b = A.size() - 1, l = 0, r = A[0].size() - 1;
	int i = 0, j = 0;
	int dir = 1; //1: l->r, 2: t->d, -1: r->l, -2: d->t

	while (t <= b && l <= r) {
		if (dir == 1) {
			while (j <= r) {
				ret.push_back(A[i][j]);
				j++;
			}
			t++;
			j--;
			i = t;
			dir = 2;
		}
		else if (dir == 2) {
			while (i <= b) {
				ret.push_back(A[i][j]);
				i++;
			}
			r--;
			i--;
			j = r;
			dir = -1;
		}
		else if (dir == -1) {
			while (j >= l) {
				ret.push_back(A[i][j]);
				j--;
			}
			b--;
			j++;
			i = b;
			dir = -2;
		}
		else if (dir == -2) {
			while (i >= t) {
				ret.push_back(A[i][j]);
				i--;
			}
			l++;
			i++;
			j = l;
			dir = 1;
		}
	}
	return ret;
}