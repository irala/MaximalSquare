// MaximalSquare.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#define COL 4
#define ROW 4
using namespace std;



 int MaximalSquare(string A[]) {

	 char caracteres[ROW][COL];
	 for (size_t i = 0; i < A->size(); i++)
	 {
		 for (size_t j = 0; j < A[i].size(); j++)
		 {
			 caracteres[i][j] = A[i][j];
		 }
	 }


	int rows = ROW, cols = rows > 0 ? COL : 0;
	int maxsqlen = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (caracteres[i][j] == '1') {
				int sqlen = 1;
				bool flag = true;
				while (sqlen + i < rows && sqlen + j < cols && flag) {
					for (int k = j; k <= sqlen + j; k++) {
						if (caracteres[i + sqlen][k] == '0') {
							flag = false;
							break;
						}
					}
					for (int k = i; k <= sqlen + i; k++) {
						if (caracteres[k][j + sqlen] == '0') {
							flag = false;
							break;
						}
					}
					if (flag)
						sqlen++;
				}
				if (maxsqlen < sqlen) {
					maxsqlen = sqlen;
				}
			}
		}
	}
	return maxsqlen * maxsqlen;
}


int main()
{

	string A[] = { "0111", "1111", "1111", "1111" };
	cout << MaximalSquare(A);
	return 0;
}
