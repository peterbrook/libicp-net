/*
.NET/CLI wrapper around libicp

Author: Peter Brook
*/


#include "icp_net.h"
#include "icpPointToPoint.h"
#include "matrix.h"
#include <fstream>

using namespace icp_net;

ManagedICP::ManagedICP(array<double, 2>^ ar, int M_num, int dim)
{
	pin_ptr< double > p = &ar[ 0, 0 ];
	
	icp = new IcpPointToPoint(p, M_num, dim);
}

void
ManagedICP::fit(array<double, 2>^ T,int T_num, array<double, 2>^ Rot, array<double>^ trans, int indist)
{
	pin_ptr< double > rot_ptr = &Rot[ 0, 0 ];
	Matrix R(3, 3, rot_ptr);

	pin_ptr< double > trans_ptr = &trans[0];	
	Matrix t(3, 1, trans_ptr);
	
	pin_ptr< double > data_ptr = &T[ 0, 0 ];

	icp->fit(data_ptr, T_num, R, t, indist);
	
	for (int i=0; i < 3; i++) {
		for (int j=0; j < 3; j++) {
			Rot[i, j] = R.val[i][j];
		}
		trans[i] = t.val[i][0];
	}
}

ManagedICP::~ManagedICP()
{
	delete icp;
}