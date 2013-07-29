#pragma once
#ifndef IDOCK_CL_KERNEL_HPP
#define IDOCK_CL_KERNEL_HPP

#include <CL/cl.h>
#include "mc_kernel.hpp"

class cl_mc_kernel : public mc_kernel
{
public:
	// Initialize kernel.
	explicit cl_mc_kernel(const float* h_sf_e, const float* h_sf_d, const int h_sf_ns, const int h_sf_ne, const float* h_corner0, const float* h_corner1, const int* h_num_probes, const float h_granularity_inverse, const int num_mc_tasks, const int h_ng, const unsigned long long h_seed);

	// Update grid map pointers.
	void update(const vector<vector<float> > h_maps, const vector<size_t>& xs);

	// Launch the kernel.
	void launch(vector<float>& h_ex, const vector<int>& h_lig, const int nv, const int nf, const int na, const int np);

	// Free device memory.
	~cl_mc_kernel();
private:
	cl_int err;
	cl_context context;
	cl_command_queue command_queue;
	cl_program program;
	cl_kernel kernel;
	cl_mem d_sf_e;
	cl_mem d_sf_d;
	cl_mem d_maps[sf_n];
	int num_mc_tasks;
	int ng;
};

#endif
