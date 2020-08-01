/***
 *	
 *	file name : Plot_Mass.cc
 *	Data : 191026
 *	Description : Modification of Plotter.h and Plotter.cc
 *	Author : Chen-Yu Chuang
 *
 * **/

#include "Plotter_Unc.h"
#include "Hists.h"

#include <string>
#include <iostream>
#include "string.h"

using namespace std;

void exe1()			// to produce div unc TH1
{
	Make_Unc_TH1("algo","JES_up","NC");
	Make_Unc_TH1("algo","JES_down","NC");
	Make_Unc_TH1("algo","JER_up","NC");
	Make_Unc_TH1("algo","JER_down","NC");
	Make_Unc_TH1("algo","btag_up","NC");
	Make_Unc_TH1("algo","btag_down","NC");
	Make_Unc_TH1("algo","pu_up","NC");
	Make_Unc_TH1("algo","pu_down","NC");
	Make_Unc_TH1("algo","lepsf_up","NC");
	Make_Unc_TH1("algo","lepsf_down","NC");

	Make_Unc_TH1("j1j2_delR","JES_up","NC");
	Make_Unc_TH1("j1j2_delR","JES_down","NC");
	Make_Unc_TH1("j1j2_delR","JER_up","NC");
	Make_Unc_TH1("j1j2_delR","JER_down","NC");
	Make_Unc_TH1("j1j2_delR","btag_up","NC");
	Make_Unc_TH1("j1j2_delR","btag_down","NC");
	Make_Unc_TH1("j1j2_delR","pu_up","NC");
	Make_Unc_TH1("j1j2_delR","pu_down","NC");
	Make_Unc_TH1("j1j2_delR","lepsf_up","NC");
	Make_Unc_TH1("j1j2_delR","lepsf_down","NC");

	Make_Unc_TH1("whadb_delR","JES_up","NC");
	Make_Unc_TH1("whadb_delR","JES_down","NC");
	Make_Unc_TH1("whadb_delR","JER_up","NC");
	Make_Unc_TH1("whadb_delR","JER_down","NC");
	Make_Unc_TH1("whadb_delR","btag_up","NC");
	Make_Unc_TH1("whadb_delR","btag_down","NC");
	Make_Unc_TH1("whadb_delR","pu_up","NC");
	Make_Unc_TH1("whadb_delR","pu_down","NC");
	Make_Unc_TH1("whadb_delR","lepsf_up","NC");
	Make_Unc_TH1("whadb_delR","lepsf_down","NC");

	Make_Unc_TH1("hadwlepton_delR","JES_up","NC");
	Make_Unc_TH1("hadwlepton_delR","JES_down","NC");
	Make_Unc_TH1("hadwlepton_delR","JER_up","NC");
	Make_Unc_TH1("hadwlepton_delR","JER_down","NC");
	Make_Unc_TH1("hadwlepton_delR","btag_up","NC");
	Make_Unc_TH1("hadwlepton_delR","btag_down","NC");
	Make_Unc_TH1("hadwlepton_delR","pu_up","NC");
	Make_Unc_TH1("hadwlepton_delR","pu_down","NC");
	Make_Unc_TH1("hadwlepton_delR","lepsf_up","NC");
	Make_Unc_TH1("hadwlepton_delR","lepsf_down","NC");
}

void exe2()			// to merge div unc TH1 to a total one
{
	MergeSystTH1( "algo" );
	MergeSystTH1( "j1j2_delR" );
	MergeSystTH1( "whadb_delR" );
	MergeSystTH1( "hadwlepton_delR" );
}


