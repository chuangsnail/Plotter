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

void plot_proper( string root_file, const string& outname, const string& proper_name, string option );
void plot_Mass( string root_file, const string& outname, string option );

void exe()
{
	//plot_proper("check_deepCSV_200124_1809.root","check","deepCSV","NC");
	
	/*
	plot_proper("a05_MLP_SRmass_200709_0056.root","a05_MLP","Mjjb_2C","2C");
	plot_proper("a05_MLP_SRmass_200709_0056.root","a05_MLP","Mjjb_1C","1C");
	plot_proper("a05_MLP_SRmass_200709_0056.root","a05_MLP","Mjjb_NC","NC");
	*/

	/*
	plot_Mass("a05_MLP_SRmass_200709_0056.root","a05_MLP_NC","NC");
	plot_Mass("a05_MLP_SRmass_200709_0056.root","a05_MLP_1C","1C");
	plot_Mass("a05_MLP_SRmass_200709_0056.root","a05_MLP_2C","2C");
	plot_Mass("a05_MLP_SRmass_200709_0056.root","a05_MLP_NC_long","NC");
	plot_Mass("a05_MLP_SRmass_200709_0056.root","a05_MLP_1C_long","1C");
	plot_Mass("a05_MLP_SRmass_200709_0056.root","a05_MLP_2C_long","2C");
	

	
	plot_Mass("chi2_SRmass_200709_1245.root","chi2_NC","NC");
	plot_Mass("chi2_SRmass_200709_1245.root","chi2_1C","1C");
	plot_Mass("chi2_SRmass_200709_1245.root","chi2_2C","2C");
	plot_Mass("chi2_SRmass_200709_1245.root","chi2_NC_long","NC");
	plot_Mass("chi2_SRmass_200709_1245.root","chi2_1C_long","1C");
	plot_Mass("chi2_SRmass_200709_1245.root","chi2_2C_long","2C");
	
	*/

/*
	plot_proper("check_NJetsNBJetsNTLep_all_200718_1119.root","check","NJets","NC");
	plot_proper("check_NJetsNBJetsNTLep_all_200718_1119.root","check","NBJets","1C");
	plot_proper("check_NJetsNBJetsNTLep_all_200718_1119.root","check","NLep","2C");
*/
	//plot_Mass("SR_t13_MLP_all_191108_1612.root","t13_MLP_NC","NC");
	
	/*
	plot_Mass("SR_t13_MLP_all_191108_1612.root","t13_MLP_NC","NC");
	plot_Mass("SR_t13_MLP_all_191108_1612.root","t13_MLP_1C","1C");
	plot_Mass("SR_t13_MLP_all_191108_1612.root","t13_MLP_2C","2C");
	plot_Mass("SR_t13_MLP_all_191108_1612.root","t13_MLP_NC_long","NC");
	plot_Mass("SR_t13_MLP_all_191108_1612.root","t13_MLP_1C_long","1C");
	plot_Mass("SR_t13_MLP_all_191108_1612.root","t13_MLP_2C_long","2C");
	*/
	//plot_proper("a05_MLP_SRalgo_200722_1833.root","a05_MLP","SR_algo","NC");

	/*
	plot_Mass("a04_MLP_SRmass_200723_0256.root","a04_MLP_NC","NC");
	plot_Mass("a04_MLP_SRmass_200723_0256.root","a04_MLP_1C","1C");
	plot_Mass("a04_MLP_SRmass_200723_0256.root","a04_MLP_2C","2C");
	plot_Mass("a04_MLP_SRmass_200723_0256.root","a04_MLP_NC_long","NC");
	plot_Mass("a04_MLP_SRmass_200723_0256.root","a04_MLP_1C_long","1C");
	plot_Mass("a04_MLP_SRmass_200723_0256.root","a04_MLP_2C_long","2C");
	*/
	
	/*
	plot_Mass("t13_MLP_SRmass_200723_1734.root","t13_MLP_NC","NC");
	plot_Mass("t13_MLP_SRmass_200723_1734.root","t13_MLP_1C","1C");
	plot_Mass("t13_MLP_SRmass_200723_1734.root","t13_MLP_2C","2C");
	plot_Mass("t13_MLP_SRmass_200723_1734.root","t13_MLP_NC_long","NC");
	plot_Mass("t13_MLP_SRmass_200723_1734.root","t13_MLP_1C_long","1C");
	plot_Mass("t13_MLP_SRmass_200723_1734.root","t13_MLP_2C_long","2C");
	*/

	/*
	plot_Mass("chi2_CRmass_200730_0208.root","CR_chi2_NC","NC");
	plot_Mass("chi2_CRmass_200730_0208.root","CR_chi2_1C","1C");
	plot_Mass("chi2_CRmass_200730_0208.root","CR_chi2_2C","2C");
	*/

	//plot_Mass("chi2_CRmass_200730_0507.root","CR_chi2_NC_long","NC");
	//plot_Mass("chi2_CRmass_200730_0507.root","CR_chi2_1C_long","1C");
	
	/*
	plot_Mass("a05_MLP_invCRmass_200730_1314.root","CR2mass_a05_MLP_NC_long","NC");
	plot_Mass("a05_MLP_invCRmass_200730_1314.root","CR2mass_a05_MLP_1C_long","1C");
	plot_Mass("chi2_invCRmass_200730_1313.root","CR2mass_chi2_NC_long","NC");
	plot_Mass("chi2_invCRmass_200730_1313.root","CR2mass_chi2_1C_long","1C");
	*/

	plot_Mass("results_02/chi2_CRmass_200730_1326_QCD-DD.root","DD_CRmass_chi2_NC_long","NC");
	plot_Mass("results_02/chi2_CRmass_200730_1326_QCD-DD.root","DD_CRmass_chi2_1C_long","1C");
	
	
}

void plot_proper( string root_file, const string& outname, const string& proper_name, string option )
{
	root_file = "rootFile/" + root_file;

	Hists hists;
	hists.GetObjs( root_file , option );

	Plotter plt;
	//plt.SetXRange(50.,300.);
	plt.SetXRange(0.,1.);
	plt.SetXTitle("MVA score");
	//plt.SetLegXRange(0.65, 0.85);



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
