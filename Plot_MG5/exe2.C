#include "plot_Acp_lib.h"
#include "Read_info.h"
#include <string>
#include <iostream>

using namespace std;

void
exe()
{
	const int N = 11;
	string samples[N] = { "SM", "CEDM0pt5", "CEDM1", "CEDM1pt5", "CEDM2", "CEDM2pt5", "CEDM3", "CEDM3pt5", "CEDM4", "CEDM4pt5", "CEDM5"};
	//string filename = "Result_ci_GVSel_j1.txt";
	//string filename = "readout_B1993_A2_NoSel.txt";
	//string filename = "readout_B1998_O2_B1998_semi.txt";
	//string filename = "readout_B1998_O2_GVSel.txt";
	//string filename = "Result_semi_ci_GVSel_j1.txt";
	//string filename = "Result_semi_ci_GVSel_dq.txt";

	string filename = "result_200604/result/readout_B1993_A2_NoSel.txt";
	//string filename = "result_200604/readout_B1993_A1_NoSel.txt";
	//string filename = "result_200604/readout_B1998_O1_NoSel.txt";
	//string filename = "result_200604/readout_B1998_Q1_NoSel.txt";
	

	//string filename = "result_200604/readout_OptimizedLepAsym_NoSel.txt";

	Read_info r( (char*)filename.c_str());

	//cout << stod( r.second("10_7-semi_CEDM0pt5_0j_GVSel_j1_Obs6_M") ) + 1. << endl;

	//string obsname = "B1998_O2";
	//string Sel = "B1998_semi";
	//string jets = "0j";

	//string obsname = "B1993_A2";
	//string Sel = "NoSel";
	//string Obs = "A_{2}";
	//string jets = "0j";

	//string Sel = "GVSel_j1";
	//string obsname = "Obs3";
	//string Obs = "O_{3}";

/*
	string Sel = "NoSel";
	string Obs = "A_{cp}(A_{1})";
	string obsname = "LepAsym_Acp";
	string jets = "0j";
	string size = "10_7-";
	string channel = "dilep";
*/

	string Sel = "NoSel";
	string Obs = "A_{2}";
	string obsname = "B1993_A2";
	string jets = "0j";
	string size = "10_7-";
	string channel = "semi";

/*
	string Sel = "NoSel";
	string Obs = "A_{cp}(Q_{1})";
	string obsname = "B1998_Q1";
	string jets = "0j";
	string size = "10_7-";
	string channel = "dilep";
*/
	

	vector<double> mY;
	vector<double> eY;

	for(int i=0;i<N;++i) {
		string m = size + channel + "_" + samples[i] + "_" + jets + "_" + Sel + "_" + obsname + "_M";
		string e = size + channel + "_" + samples[i] + "_" + jets + "_" + Sel + "_" + obsname + "_E";
		cout << stod(r.second(m) ) << endl; 
		mY.push_back( stod( r.second(m) ) );
		eY.push_back( stod( r.second(e) ) );
	} 

	TF1* f1 = new TF1("f1","0*x",-5,7);

	string newname = size + channel + "_" + jets + "_" + Sel + "_" + obsname;
	//draw_ci( newname ,"O_{1}",mY,eY,"NoSel evt_B1998_semi fit ",f1);
	//draw_ci( newname, Obs.c_str(), mY, eY, "evt_GV_j1_semi Xsec",f1);
	draw_ci( newname, Obs.c_str(), mY, eY, "NoSel Xsec fit",f1);
	
	//draw_ci( newname ,"A_{2}",mY,eY,"NoSel evt_B1998_semi fit",f1);

}

