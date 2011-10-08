/*
.NET/CLI wrapper around libicp

Author: Peter Brook
*/

#include "icp.h"

#include <stdio.h>
//#using <System.dll>

using namespace System;

namespace icp_net {

	public ref class ManagedICP
	{
	private:
		Icp* icp;
	public:
		ManagedICP(array<double, 2>^ ar, int M_num, int dim);
		void fit(array<double, 2>^ T,int T_num, array<double, 2>^ Rot, array<double>^ trans, int indist);
		~ManagedICP();
	};
}