/***
 *	
 *	file name : Plot_Mass.cc
 *	Data : 191026
 *	Description : Modification of Plotter.h and Plotter.cc
 *	Author : Chen-Yu Chuang
 *
 * **/

#include "Plotter.h"
#include "Hists.h"

#include <string>
#include <iostream>
#include "string.h"

using namespace std;

void plot_proper( string root_file, const string& outname, const string& proper_name, string option );

void exe()
{
	plot_proper("check_deepCSV_200124_1809.root","check","deepCSV","NC");

}

void plot_proper( string root_file, const string& outname, const string& proper_name, string option )
{
	Hists hists;
	hists.GetObjs( root_file , option );


	if(option.find("NC") != string::npos)
	{
		string filename = outname + "_" + proper_name;	
		Plot_Stack( filename, hists.h_mu, hists.h_el  );
	}
	
	if(option.find("1C") != string::npos)
	{
		string filename = outname + "_" + proper_name;	
		Plot_Stack( filename, hists.h_mu_c, hists.h_el_c  );
	}
	
	if(option.find("2C") != string::npos)
	{
		string filename = outname + "_" + proper_name;	
		Plot_Stack( filename, hists.h_mu_cc, hists.h_el_cc  );
	}
	
	if( (option.find("NC") == string::npos) && (option.find("1C") == string::npos) && (option.find("2C") == string::npos) )
	{
		cerr << "Illegal option of plot_Mass ," << endl \
			 << "option should include NC/1C/2C " << endl;
	}

}


void plot_Mass( string root_file, const string& outname, string option )
{	
	
	Hists hists;
	hists.GetObjs( root_file , option );

	if(option.find("NC") != string::npos)
	{
		string filename = outname + "_HadTop";	
		Plot_Stack( filename, hists.h_mu, hists.h_el  );
	
		string filename2 = outname + "_LepTop";	
		Plot_Stack( filename2, hists.h_l_mu, hists.h_l_el  );
	}
	
	if(option.find("1C") != string::npos)
	{
		string filename = outname + "_HadTop";	
		Plot_Stack( filename, hists.h_mu_c, hists.h_el_c  );
	
		string filename2 = outname + "_LepTop";	
		Plot_Stack( filename2, hists.h_l_mu_c, hists.h_l_el_c  );
	}
	
	if(option.find("2C") != string::npos)
	{
		string filename = outname + "_HadTop";	
		Plot_Stack( filename, hists.h_mu_cc, hists.h_el_cc  );
	
		string filename2 = outname + "_LepTop";	
		Plot_Stack( filename2, hists.h_l_mu_cc, hists.h_l_el_cc  );
	}
	
	if( (option.find("NC") == string::npos) && (option.find("1C") == string::npos) && (option.find("2C") == string::npos) )
	{
		cerr << "Illegal option of plot_Mass ," << endl \
			 << "option should include NC/1C/2C " << endl;
	}
}
