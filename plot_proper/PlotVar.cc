/***
 *	
 *	file name : Plot_Mass.cc
 *	Data : 191026
 *	Description : Modification of Plotter.h and Plotter.cc
 *	Author : Chen-Yu Chuang
 *
 * **/

#include "Plotter_new.h"
#include "Hists.h"

#include <string>
#include <iostream>
#include "string.h"

using namespace std;

void plot_proper( string root_file,  const string& proper_name, string option, const double& xmin, const double& xmax, const string& xtitle, const double& lmin = 0.65, const double& lmax = 0.85 );
void plot_Mass( string root_file, const string& outname, string option );

void exe()
{/*
	
	plot_proper("a05_MLP_var/SRvars_hadblepton_delPt.root","hadblepton_delPt_NC","NC", -200., 200.,"hadronic b and lepton's #Delta P_{T}");
	plot_proper("a05_MLP_var/SRvars_hadblepton_delPt.root","hadblepton_delPt_1C","1C", -200., 200.,"hadronic b and lepton's #Delta P_{T}");

	plot_proper("a05_MLP_var/SRvars_hadblepton_sumPt.root","hadblepton_sumPt_NC","NC", 0., 500.,"hadronic b and lepton's #Sigma P_{T}");
	plot_proper("a05_MLP_var/SRvars_hadblepton_sumPt.root","hadblepton_sumPt_1C","1C", 0., 500.,"hadronic b and lepton's #Sigma P_{T}");

	plot_proper("a05_MLP_var/SRvars_hadblepton_delR.root","hadblepton_delR_NC","NC", 0., 10.,"hadronic b and lepton's #Delta R");
	plot_proper("a05_MLP_var/SRvars_hadblepton_delR.root","hadblepton_delR_1C","1C", 0., 10.,"hadronic b and lepton's #Delta R");

	plot_proper("a05_MLP_var/SRvars_hadwlepton_delPt.root","hadwlepton_delPt_NC","NC", -200., 200.,"hadronic W and lepton's #Delta P_{T}", 0.7, 0.88);
	plot_proper("a05_MLP_var/SRvars_hadwlepton_delPt.root","hadwlepton_delPt_1C","1C", -200., 200.,"hadronic W and lepton's #Delta P_{T}", 0.7, 0.88);

	plot_proper("a05_MLP_var/SRvars_hadwlepton_sumPt.root","hadwlepton_sumPt_NC","NC", 0., 500.,"hadronic W and lepton's #Sigma P_{T}");
	plot_proper("a05_MLP_var/SRvars_hadwlepton_sumPt.root","hadwlepton_sumPt_1C","1C", 0., 500.,"hadronic W and lepton's #Sigma P_{T}");

	plot_proper("a05_MLP_var/SRvars_hadwlepton_delR.root","hadwlepton_delR_NC","NC", 0., 10.,"hadronic W and lepton's #Delta R");
	plot_proper("a05_MLP_var/SRvars_hadwlepton_delR.root","hadwlepton_delR_1C","1C", 0., 10.,"hadronic W and lepton's #Delta R");

	plot_proper("a05_MLP_var/SRvars_j1j2_absdelPt.root","j1j2_absdelPt_NC","NC", 0., 200.,"jj's |#Delta P_{T}|");
	plot_proper("a05_MLP_var/SRvars_j1j2_absdelPt.root","j1j2_absdelPt_1C","1C", 0., 200.,"jj's |#Delta P_{T}|");

	plot_proper("a05_MLP_var/SRvars_j1j2_sumPt.root","j1j2_sumPt_NC","NC", 0., 500.,"jj's #Sigma P_{T}");
	plot_proper("a05_MLP_var/SRvars_j1j2_sumPt.root","j1j2_sumPt_1C","1C", 0., 500.,"jj's #Sigma P_{T}");

	plot_proper("a05_MLP_var/SRvars_j1j2_delR.root","j1j2_delR_NC","NC", 0., 10.,"jj's #Delta R");
	plot_proper("a05_MLP_var/SRvars_j1j2_delR.root","j1j2_delR_1C","1C", 0., 10.,"jj's #Delta R");
*/

	plot_proper("a05_MLP_var/SRvars_whadb_delPt.root","whadb_delPt_NC","NC", -200., 200.,"hadronic W and b's #Delta P_{T}", 0.72, 0.88);
	plot_proper("a05_MLP_var/SRvars_whadb_delPt.root","whadb_delPt_1C","1C", -200., 200.,"hadronic W and b's #Delta P_{T}", 0.72, 0.88);
/*
	plot_proper("a05_MLP_var/SRvars_whadb_sumPt.root","whadb_sumPt_NC","NC", 0., 500.,"hadronic W and b's #Sigma P_{T}");
	plot_proper("a05_MLP_var/SRvars_whadb_sumPt.root","whadb_sumPt_1C","1C", 0., 500.,"hadronic W and b's #Sigma P_{T}");

	plot_proper("a05_MLP_var/SRvars_whadb_delR.root","whadb_delR_NC","NC", 0., 10.,"hadronic W and b's #Delta R");
	plot_proper("a05_MLP_var/SRvars_whadb_delR.root","whadb_delR_1C","1C", 0., 10.,"hadronic W and b's #Delta R");

	plot_proper("a05_MLP_var/SRvars_hadbmet_delPhi.root","hadbmet_delPhi_NC","NC", -5., 5., "hadronic b and MET's #Delta #phi", 0.45, 0.55);
	plot_proper("a05_MLP_var/SRvars_hadbmet_delPhi.root","hadbmet_delPhi_1C","1C", -5., 5., "hadronic b and MET's #Delta #phi", 0.45, 0.55);

	plot_proper("a05_MLP_var/SRvars_hadbmet_delPt.root","hadbmet_delPt_NC","NC", -200., 200., "hadronic b and MET's #Delta P_{T}");
	plot_proper("a05_MLP_var/SRvars_hadbmet_delPt.root","hadbmet_delPt_1C","1C", -200., 200., "hadronic b and MET's #Delta P_{T}");

	plot_proper("a05_MLP_var/SRvars_hadbmet_sumPt.root","hadbmet_sumPt_NC","NC", 0., 500., "hadronic b and MET's #Sigma P_{T}");
	plot_proper("a05_MLP_var/SRvars_hadbmet_sumPt.root","hadbmet_sumPt_1C","1C", 0., 500., "hadronic b and MET's #Sigma P_{T}");

	plot_proper("a05_MLP_var/SRvars_hadwmet_delPhi.root","hadwmet_delPhi_NC","NC", -5., 5., "hadronic W and MET's #Delta #phi", 0.45, 0.55);
	plot_proper("a05_MLP_var/SRvars_hadwmet_delPhi.root","hadwmet_delPhi_1C","1C", -5., 5., "hadronic W and MET's #Delta #phi", 0.45, 0.55);

	plot_proper("a05_MLP_var/SRvars_hadwmet_delPt.root","hadwmet_delPt_NC","NC", -200., 200., "hadronic W and MET's #Delta P_{T}", 0.71, 0.88);
	plot_proper("a05_MLP_var/SRvars_hadwmet_delPt.root","hadwmet_delPt_1C","1C", -200., 200., "hadronic W and MET's #Delta P_{T}", 0.71, 0.88);

	plot_proper("a05_MLP_var/SRvars_hadwmet_sumPt.root","hadwmet_sumPt_NC","NC", 0., 500., "hadronic W and MET's #Sigma P_{T}");
	plot_proper("a05_MLP_var/SRvars_hadwmet_sumPt.root","hadwmet_sumPt_1C","1C", 0., 500., "hadronic W and MET's #Sigma P_{T}");
*/	
}

void plot_proper( string root_file, const string& proper_name, string option, const double& xmin, const double& xmax, const string& xtitle, const double& lmin , const double& lmax )
{
	root_file = "rootFile/" + root_file;
	string outname = "VarCheck/VarCheck";

	Hists hists;
	hists.GetObjs( root_file , option );

	Plotter plt;
	plt.SetXRange(xmin,xmax);
	plt.SetXTitle(xtitle);
	plt.SetLegXRange(lmin, lmax);



	if(option.find("NC") != string::npos)
	{
		string filename = outname + "_" + proper_name;	
		plt.Plot_Stack( filename, hists.h_mu, hists.h_el  );
	}
	
	if(option.find("1C") != string::npos)
	{
		string filename = outname + "_" + proper_name;	
		plt.Plot_Stack( filename, hists.h_mu_c, hists.h_el_c  );
	}
	
	if(option.find("2C") != string::npos)
	{
		string filename = outname + "_" + proper_name;	
		plt.Plot_Stack( filename, hists.h_mu_cc, hists.h_el_cc  );
	}
	
	if( (option.find("NC") == string::npos) && (option.find("1C") == string::npos) && (option.find("2C") == string::npos) )
	{
		cerr << "Illegal option of plot_Mass ," << endl \
			 << "option should include NC/1C/2C " << endl;
	}

}


void plot_Mass( string root_file, const string& outname, string option )
{	
	root_file = "rootFile/" + root_file;
	
	Hists hists;
	hists.GetObjs( root_file , option );

	Plotter plt;
	plt.SetXRange(50.,300.);
	plt.SetLegXRange(0.65, 0.85);

	bool is_long = false;

	if( outname.find("long") != string::npos )
	{
		is_long = true;
	}

	if(option.find("NC") != string::npos)
	{
	
		if(is_long)
			plt.SetXRange(0.,500.);
		else
			plt.SetXRange(50.,300.);
		string filename = outname + "_HadTop";	
		plt.Plot_Stack( filename, hists.h_mu, hists.h_el  );
	}
	if(option.find("NC") != string::npos)
	{
		if(is_long)
			plt.SetXRange(0.,500.);
		else
			plt.SetXRange(0.,250.);
		string filename2 = outname + "_LepTop";	
		plt.Plot_Stack( filename2, hists.h_l_mu, hists.h_l_el  );
	}
	
	if(option.find("1C") != string::npos)
	{
		if(is_long)
			plt.SetXRange(0.,500.);
		else
			plt.SetXRange(50.,300.);
		string filename = outname + "_HadTop";	
		plt.Plot_Stack( filename, hists.h_mu_c, hists.h_el_c  );
	}
	if(option.find("1C") != string::npos)
	{
		if(is_long)
			plt.SetXRange(0.,500.);
		else
			plt.SetXRange(0.,250.);
		string filename2 = outname + "_LepTop";	
		plt.Plot_Stack( filename2, hists.h_l_mu_c, hists.h_l_el_c  );
	}
	
	if(option.find("2C") != string::npos)
	{
		if(is_long)
			plt.SetXRange(0.,500.);
		else
			plt.SetXRange(50.,300.);
		string filename = outname + "_HadTop";	
		plt.Plot_Stack( filename, hists.h_mu_cc, hists.h_el_cc  );
	}
	if(option.find("2C") != string::npos)
	{
		if(is_long)
			plt.SetXRange(0.,500.);
		else
			plt.SetXRange(0.,250.);
		string filename2 = outname + "_LepTop";	
		plt.Plot_Stack( filename2, hists.h_l_mu_cc, hists.h_l_el_cc  );
	}
	
	if( (option.find("NC") == string::npos) && (option.find("1C") == string::npos) && (option.find("2C") == string::npos) )
	{
		cerr << "Illegal option of plot_Mass ," << endl \
			 << "option should include NC/1C/2C " << endl;
	}
}
