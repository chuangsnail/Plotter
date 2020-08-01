#include "plot_Acp_lib.h"
#define N_Obs 2

using namespace std;

void exe()
{

	// B1993 A1 (dilep)
/*
	//V//
	string filename = "B1993_dilepA1_10-6-1j_NoSel";
	string name[N_Obs] = { "SM", "CEDM0.5", "CEDM1", "CEDM1.5", "CEDM2", "CEDM2.5", "CEDM3", "CEDM3.5", "CEDM4", "CEDM4.5", "CEDM5" };
	double m[N_Obs] = {-0.000849703,0.000443725,-0.00221737,-0.000361656,0.0000568091,-0.00167323,-0.00310123,-0.00181524,-0.000930677,-0.00190462,-0.000304684};
	double s[N_Obs] = {0.001,0.001,0.001,0.001,0.001,0.001,0.001,0.001,0.001,0.001,0.001};
*/
/*
	string filename = "B1993_dilepA1_10-6-1j_GVSel";
	string name[N_Obs] = { "SM", "CEDM1", "CEDM2", "CEDM3", "CEDM4", "CEDM5" };
	double m[N_Obs] = {};
	double s[N_Obs] = {0.001,0.001,0.001,0.001,0.001,0.001};
*/


	// B1993 A2 (semileptonic)
/*
	//V//
	string filename = "B1993_semiA2_10-6-1j_NoSel";
	string name[N_Obs] = { "SM", "CEDM0.5", "CEDM1", "CEDM1.5", "CEDM2", "CEDM2.5", "CEDM3", "CEDM3.5", "CEDM4", "CEDM4.5", "CEDM5" };
	double m[N_Obs] = {0.000200018,-0.00124344,-0.00188886,0.000411515,-0.000600787,0.000470331,0.00114378,-0.00121747,0.000545077,-0.000808142,0.00191738};
	double s[N_Obs] = {0.001,0.001,0.001,0.001,0.001,0.001,0.001,0.001,0.001,0.001,0.001};
*/
/*
	string filename = "B1993_semiA2_10-6-1j_GVSel";
	string name[N_Obs] = { "SM", "CEDM1", "CEDM2", "CEDM3", "CEDM4", "CEDM5" };
	double m[N_Obs] = {};
	double s[N_Obs] = {0.001,0.001,0.001,0.001,0.001,0.001,0.001,0.001,0.001,0.001,0.001};
*/


	// B1998 O1 (dilep)
/*
	string filename = "B1998_dilepO1_10-6-1j_NoSel";
	string name[N_Obs] = { "SM", "CEDM1", "CEDM2", "CEDM3", "CEDM4", "CEDM5" };
	double m[N_Obs] = {0.000200018,-0.00188886,-0.000600787,0.00114378,0.000545077,0.00191738};
	double s[N_Obs] = {0.001,0.001,0.001,0.001,0.001,0.001};
*/
/*
	//V//
	string filename = "B1998_dilepO1_10-6-1j_B1998Sel";
	string name[N_Obs] = { "SM", "CEDM0.5", "CEDM1", "CEDM1.5", "CEDM2", "CEDM2.5", "CEDM3", "CEDM3.5", "CEDM4", "CEDM4.5", "CEDM5" };
	double m[N_Obs] = {-0.00183629,0.000830594,0.000176971,0.00109588,-0.00095262,-0.0017944,0.00116988,-0.0000875396,-0.00133223,-0.000391516,0.000720184};
	double s[N_Obs] = {0.00135442,0.00135408,0.00135072,0.00134699,0.00134321,0.00133555,0.00133036,0.00132318,0.00131879,0.00131329,0.00130792};
*/
/*
	string filename = "B1998_dilepO1_10-6-1j_GVSel";
	string name[N_Obs] = { "SM", "CEDM1", "CEDM2", "CEDM3", "CEDM4", "CEDM5" };
	double m[N_Obs] = {};
	double s[N_Obs] = {};
*/

	// B1998 Q1 (semileptonic)
/*
	string filename = "B1998_semiQ1_10-6-1j_NoSel";
	string name[N_Obs] = { "SM", "CEDM0.5", "CEDM1", "CEDM1.5", "CEDM2", "CEDM2.5", "CEDM3", "CEDM3.5", "CEDM4", "CEDM4.5", "CEDM5" };
	double m[N_Obs] = {};
	double s[N_Obs] = {};
*/
/*
	//V//
	string filename = "B1998_semiQ1_10-6-1j_B1998Sel";
	string name[N_Obs] = { "SM", "CEDM0.5", "CEDM1", "CEDM1.5", "CEDM2", "CEDM2.5", "CEDM3", "CEDM3.5", "CEDM4", "CEDM4.5", "CEDM5" };
	double m[N_Obs] = {-0.00150021,0.00134679,0.000026559,-0.00502809,-0.00110201,-0.00192436,-0.00157218,-0.000999336,-0.0000428728,-0.0012934,0.000259282};
	double s[N_Obs] = {0.00234225,0.00233925,0.00232549,0.00231116,0.00228934,0.00226814,0.00224249,0.0022169,0.00219314,0.0021658,0.00213929};
*/

/*
	//V//
	string filename = "OptmizedLepAsym_NoSel";
	string name[N_Obs] = { "SM", "2HDM-d", "2HDM-A", "2HDM-B" };
	double m[N_Obs] = {-0.001548,0.000516,0.000986,0.000986};
	double s[N_Obs] = {0.001,0.001,0.001,0.001};
*/

/*
	//V//
	string filename = "2HDM_default_OptLepAsym_NoSel";
	string name[N_Obs] = { "SM", "2HDM-d" };
	double m[N_Obs] = {-3.86e-05,-0.0003366};
	double s[N_Obs] = {0.000316228,0.000316228};
*/

/*
	//V//
	string filename = "2HDM_default_B1993_A2_NoSel";
	string name[N_Obs] = { "SM", "2HDM-d" };
	double m[N_Obs] = {0.000113106,0.000136589};
	double s[N_Obs] = {0.000316228,0.000316228};
*/
/*
	//V//
	string filename = "2HDM_default_B1998_Q1_NoSel";
	string name[N_Obs] = { "SM", "2HDM-d" };
	double m[N_Obs] = {-0.000763,-0.000403};
	double s[N_Obs] = {0.000316228,0.000316228};
*/
/*
	//V//
	string filename = "2HDM_default_B1998_O1_NoSel";
	string name[N_Obs] = { "SM", "2HDM-d" };
	double m[N_Obs] = {-0.000138615,-0.000192809};
	double s[N_Obs] = {0.000570469,0.000570597};
*/
	//V//
	string filename = "2HDM_default_B1993_A1_NoSel";
	string name[N_Obs] = { "SM", "2HDM-d" };
	double m[N_Obs] = {-0.00007090,-0.000471581};
	double s[N_Obs] = {0.000316228,0.000316228};


	//string name[N_Obs] = { "SM", "CEDM0.5", "CEDM1", "CEDM1.5", "CEDM2", "CEDM2.5", "CEDM3", "CEDM3.5", "CEDM4", "CEDM4.5", "CEDM5" };


	vector<string> hists_name;
	vector<double> mean, sigma;

	for(int i=0;i<N_Obs;++i)
	{
		hists_name.push_back(name[i]);
		mean.push_back(m[i]);
		sigma.push_back(s[i]);
	}
	
	draw_known(filename, mean, sigma, hists_name);
}
