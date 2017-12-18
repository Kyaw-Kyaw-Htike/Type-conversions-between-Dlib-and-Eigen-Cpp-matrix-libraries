#ifndef TYPEEXG_DLIB_EIG_H
#define TYPEEXG_DLIB_EIG_H

// Copyright (C) 2017 Kyaw Kyaw Htike @ Ali Abdul Ghafur. All rights reserved.

#include "Eigen/Dense"
#include "dlib/image_transforms.h"
#include "dlib/matrix.h"
#include "dlib/array2d.h"
#include "dlib/array.h"

#define EIGEN_NO_DEBUG // to remove bound checking to get faster element access


// T should be generic C++ native types
// this is obviously only for 2D matrices (1 channel)
// makes deep copy
template <typename T>
void eigen2dlib(Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> mat_in, dlib::matrix<T> &mat_out)
{
	mat_out = dlib::mat(mat_in);
}

// T can be unsigned char, unsigned short, unsigned int, unsigned long,
// char, signed char, short, int, long
// output mat_in can be used as grayscale image or for any other purpose
// makes deep copy
template <typename T>
void eigen2dlib(const Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> &mat_in, dlib::array2d<T> &mat_out)
{
	int nrows = mat_in.rows();
	int ncols = mat_in.cols();

	mat_out.set_size(nrows, ncols);

	for (int j = 0; j < ncols; j++)
		for (int i = 0; i < nrows; i++)
			mat_out[i][j] = mat_in(i,j);
}

// T should be generic C++ native types
// the 2nd arg mat_out will always be a column vector
// this function makes a deep copy
template <typename T>
void eigen2dlib(const Eigen::Matrix<T, Eigen::Dynamic, 1> &mat_in, dlib::matrix<T, 0, 1> &mat_out)
{

	int nrows = mat_in.rows();
	//int ncols = mat_in.cols();
	int ncols = 1;

	mat_out.set_size(nrows);

	for (unsigned int i = 0; i < nrows; i++)
		mat_out(i) = mat_in(i);
}

// T should be generic C++ native types
// the 2nd arg mat_out will always be a row vector
// this function makes a deep copy
template <typename T>
void eigen2dlib(const Eigen::Matrix<T, 1, Eigen::Dynamic> &mat_in, dlib::matrix<T, 1, 0> &mat_out)
{
	//int nrows = mat_in.rows();
	int ncols = mat_in.cols();

	mat_out.set_size(ncols);

	for (unsigned int i = 0; i < ncols; i++)
		mat_out(i) = mat_in(i);
}


// T can be unsigned char, unsigned short, unsigned int, unsigned long,
// char, signed char, short, int, long
template <typename T>
void dlib2eigen(const dlib::array2d<T> &mat_in, Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> &mat_out)
{
	int nrows = dlib::num_rows(mat_in);
	int ncols = dlib::num_columns(mat_in);

	mat_out.setZero(nrows, ncols);

	for (int j = 0; j < ncols; j++)
		for (int i = 0; i < nrows; i++)
			mat_out(i,j) = mat_in[i][j];
}

// T should be generic C++ native types
// the 2nd arg mat_out will always be a 2D matrix with single channel
// this function makes a deep copy
template <typename T>
void dlib2eigen(const dlib::matrix<T> &mat_in, Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> &mat_out)
{
	int nrows = mat_in.nr();
	int ncols = mat_in.nc();

	mat_out.setZero(nrows, ncols);

	for (int j = 0; j < ncols; j++)
		for (int i = 0; i < nrows; i++)
			mat_out(i,j) = mat_in(i, j);
}

// T should be generic C++ native types
// the 2nd arg mat_out will always be a column vector
// this function makes a deep copy
template <typename T>
void dlib2eigen(const dlib::matrix<T, 0, 1> &mat_in, Eigen::Matrix<T, Eigen::Dynamic, 1> &mat_out)
{
	int nrows = mat_in.nr();
	//int ncols = mat_in.nc();
	int ncols = 1;

	mat_out.setZero(nrows);

	for (unsigned int i = 0; i < nrows; i++)
		mat_out(i) = mat_in(i);
}

// T should be generic C++ native types
// the 2nd arg mat_out will always be a row vector
// this function makes a deep copy
template <typename T>
void dlib2eigen(const dlib::matrix<T, 1, 0> &mat_in, Eigen::Matrix<T, 1, Eigen::Dynamic> &mat_out)
{
	//int nrows = mat_in.nr();
	int ncols = mat_in.nc();

	mat_out.setZero(ncols);

	for (unsigned int i = 0; i < ncols; i++)
		mat_out(i) = mat_in(i);
}

#undef EIGEN_NO_DEBUG 

#endif