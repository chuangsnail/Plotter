#include "plot_Acp_lib.h"
#include "Read_info.h"
#include <string>

using namespace std;

void
exe()
{
	const N = 11;
	string samples[N] = { "SM", "CEDM0pt5", "CEDM1", "CEDM1pt5", "CEDM2", "CEDM2pt5", "CEDM3", "CEDM3pt5", "CEDM4", "CEDM4pt5", "CEDM5"}
	string filename = "Result_ci_GVSel_j1.txt";
	Read_info r( (char*)filename.c_str());

	//cout << stod( r.second("10_7-semi_CEDM0pt5_0j_GVSel_j1_Obs6_M") ) + 1. << endl;

	string obsname = "BObs6";
	string Sel = "GVSel_j1";

	string size = "10_7-";
	string channel = "semi";
	string jets = "0j";
	

	vector<double> mY;
	vector<double> eY;

	for(int i=0;i<N;++i) {
		string m = size + channel + "_" + samples[i] + "_" + jets + "_" + Sel + "_" + obsname + "_M";
		string e = size + channel + "_" + samples[i] + "_" + jets + "_" + Sel + "_" + obsname + "_E"; 
		mY.push_back( stod( r.second(m) ) );
		eY.push_back( stod( r.second(e) ) );
	}  

}

