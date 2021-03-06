#ifndef HISTS_H
#define HISTS_H

/***************************************************************************
 *
 *	FileName : Hists.h
 *	Description : Make a class to wrap histagrams we want to use 
 *	Date : 2019 Nov 8 ~
 *	Author : Chen-Yu Chuang
 *
 * ************************************************************************/

#include <string>
#include <string.h>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;


//Tool for Hist

double t_IntegralTH1( const TH1* h ) { return h->Integral(1,h->GetXaxis()->GetNbins()+1); }

void NormalizeTH1( TH1* h ) { h->Scale( (double)1./t_IntegralTH1( h ) ); }

//maybe we can use a mother class and inheritance, and the bins_No,hist_min/max are the mother member, and  Init(),WriteIn() are virtual functions! 

class Hists_Acp
{
public:

	//just for statistical!
	TH1D* h_Obs3_mu_P;
	TH1D* h_Obs3_mu_N;
	TH1D* h_Obs6_mu_P;
	TH1D* h_Obs6_mu_N;
	TH1D* h_Obs12_mu_P;
	TH1D* h_Obs12_mu_N;
	TH1D* h_Obs13_mu_P;
	TH1D* h_Obs13_mu_N;
	
	TH1D* h_Obs3_el_P;
	TH1D* h_Obs3_el_N;
	TH1D* h_Obs6_el_P;
	TH1D* h_Obs6_el_N;
	TH1D* h_Obs12_el_P;
	TH1D* h_Obs12_el_N;
	TH1D* h_Obs13_el_P;
	TH1D* h_Obs13_el_N;

	map<string, TH1D*> h_Obs3_P, h_Obs3_N, h_Obs6_P, h_Obs6_N, h_Obs12_P, h_Obs12_N, h_Obs13_P, h_Obs13_N;

	TH1D* h_Obs_mu_P;
	TH1D* h_Obs_mu_N;
	TH1D* h_Obs_el_P;
	TH1D* h_Obs_el_N;
	
	TH1D* h_Obs_t_P;
	TH1D* h_Obs_t_N;

	map<string, TH1D*> h_Obs_P, h_Obs_N;

	void Init( const string& );
	void InitMap();

	void FillIn( const string& option, const string& ch, const double& obs, const double& weight );
	void WriteIn();
};



class Hists
{
public:
	
	Hists()
	{
		bins_No = 50;
		hist_min = 0.;
		hist_max = 500.;
	}
	~Hists() {}


	int bins_No;
	double hist_min;
	double hist_max;

	vector<TH1F*> h_mu, h_el, h_l_mu, h_l_el;

	TH1F* h_TT_mu;		TH1F* h_TT_el;	
	TH1F* h_DY_mu;		TH1F* h_DY_el;
	TH1F* h_WJets_mu;	TH1F* h_WJets_el;
	TH1F* h_VV_mu;		TH1F* h_VV_el;
	TH1F* h_ST_mu;		TH1F* h_ST_el;
	TH1F* h_QCD_mu;		TH1F* h_QCD_el;
	TH1F* h_Data_mu;	TH1F* h_Data_el;

	TH1F* h_l_TT_mu;	TH1F* h_l_TT_el;
	TH1F* h_l_DY_mu;	TH1F* h_l_DY_el;
	TH1F* h_l_WJets_mu;	TH1F* h_l_WJets_el;
	TH1F* h_l_VV_mu;	TH1F* h_l_VV_el;
	TH1F* h_l_ST_mu;	TH1F* h_l_ST_el;
	TH1F* h_l_QCD_mu;	TH1F* h_l_QCD_el;
	TH1F* h_l_Data_mu;	TH1F* h_l_Data_el;

	vector<TH1F*> h_mu_c, h_el_c, h_l_mu_c, h_l_el_c;

	TH1F* h_TT_mu_c;		TH1F* h_TT_el_c;	
	TH1F* h_DY_mu_c;		TH1F* h_DY_el_c;
	TH1F* h_WJets_mu_c;		TH1F* h_WJets_el_c;
	TH1F* h_VV_mu_c;		TH1F* h_VV_el_c;
	TH1F* h_ST_mu_c;		TH1F* h_ST_el_c;
	TH1F* h_QCD_mu_c;		TH1F* h_QCD_el_c;
	TH1F* h_Data_mu_c;		TH1F* h_Data_el_c;

	TH1F* h_l_TT_mu_c;		TH1F* h_l_TT_el_c;
	TH1F* h_l_DY_mu_c;		TH1F* h_l_DY_el_c;
	TH1F* h_l_WJets_mu_c;	TH1F* h_l_WJets_el_c;
	TH1F* h_l_VV_mu_c;		TH1F* h_l_VV_el_c;
	TH1F* h_l_ST_mu_c;		TH1F* h_l_ST_el_c;
	TH1F* h_l_QCD_mu_c;		TH1F* h_l_QCD_el_c;
	TH1F* h_l_Data_mu_c;	TH1F* h_l_Data_el_c;

	vector<TH1F*> h_mu_cc, h_el_cc, h_l_mu_cc, h_l_el_cc;

	TH1F* h_TT_mu_cc;		TH1F* h_TT_el_cc;	
	TH1F* h_DY_mu_cc;		TH1F* h_DY_el_cc;
	TH1F* h_WJets_mu_cc;	TH1F* h_WJets_el_cc;
	TH1F* h_VV_mu_cc;		TH1F* h_VV_el_cc;
	TH1F* h_ST_mu_cc;		TH1F* h_ST_el_cc;
	TH1F* h_QCD_mu_cc;		TH1F* h_QCD_el_cc;
	TH1F* h_Data_mu_cc;		TH1F* h_Data_el_cc;

	TH1F* h_l_TT_mu_cc;		TH1F* h_l_TT_el_cc;
	TH1F* h_l_DY_mu_cc;		TH1F* h_l_DY_el_cc;
	TH1F* h_l_WJets_mu_cc;	TH1F* h_l_WJets_el_cc;
	TH1F* h_l_VV_mu_cc;		TH1F* h_l_VV_el_cc;
	TH1F* h_l_ST_mu_cc;		TH1F* h_l_ST_el_cc;
	TH1F* h_l_QCD_mu_cc;	TH1F* h_l_QCD_el_cc;
	TH1F* h_l_Data_mu_cc;	TH1F* h_l_Data_el_cc;

	TH2D* h_mvamax_hadmass_mu;		//with hadmass
	TH2D* h_mvamax_hadmass_el;
	TH2D* h_mvamax_lepmass_mu;		//with lepmass
	TH2D* h_mvamax_lepmass_el;
	map<string, TH2D*> h_mvamax_hadmass, h_mvamax_lepmass;
	//double algo_v_min;
	//double algo_v_max;

	TNtupleD* mvav_mass_mu;
	TNtupleD* mvav_mass_el;
	map<string, TNtupleD*> mvav_mass;

	//Set
	void SetBinInfo( const int& n, const double& m, const double& M  ){
		bins_No = n;	
		hist_min = m;	
		hist_max = M;
	}

	//for fill and use new things
	void NoCutModeON();
	void OneCutModeON();
	void TwoCutModeON();
	void InitNoCutVector();
	void InitOneCutVector();
	void InitTwoCutVector();

	void TH2ModeON( const int& algo_bins_No, const double&, const double&);

	void NtupleModeON(){
		mvav_mass_mu = new TNtupleD( "mvav_mass_mu", "store event by event", "max_mva_value:hadt_mass:lept_mass:weight:dataset" );
		mvav_mass_el = new TNtupleD( "mvav_mass_el", "store event by event", "max_mva_value:hadt_mass:lept_mass:weight:dataset" );
		mvav_mass[ "mu" ] = mvav_mass_mu;
		mvav_mass[ "el" ] = mvav_mass_el;
	}

	void WriteIn( const string& option );
	
	//for plots or some applicatin
	void GetObjs( const string& file_name, const string& option );

	void FillHist( const string&, const int&, const string&, const double&, const double&, const double& );
	//how many cut, k(which sample), channel name, hadmass, lepmass, weight

};

class Hists_bb
{
public:
	
	Hists_bb()
	{
		bins_No1 = 50;
		hist_min1 = 0.;
		hist_max1 = 1.;
		
		bins_No2 = 100;
		hist_min2 = 0.;
		hist_max2 = 500.;

		no_match_number = 0;
	}
	~Hists_bb() {}
	
	map<string,TH1F*> h_correct, h_charge_mis, h_mistag, h_lt_correct, h_lt_charge_mis, h_lt_mistag;
	map<string, TH2D*> h_mvamax_mass;
	
	TH2D* h_mvamax_mass_mu;
	TH2D* h_mvamax_mass_el;
	TH2D* h_mvamax_mass_t;

	TH1F* h_correct_t;
	TH1F* h_mistag_t;
	TH1F* h_charge_mis_t;

	TH1F* h_correct_mu;
	TH1F* h_mistag_mu;
	TH1F* h_charge_mis_mu;

	TH1F* h_correct_el;
	TH1F* h_mistag_el;
	TH1F* h_charge_mis_el;

	TH1F* h_lt_correct_t;
	TH1F* h_lt_mistag_t;
	TH1F* h_lt_charge_mis_t;

	TH1F* h_lt_correct_mu;
	TH1F* h_lt_mistag_mu;
	TH1F* h_lt_charge_mis_mu;

	TH1F* h_lt_correct_el;
	TH1F* h_lt_mistag_el;
	TH1F* h_lt_charge_mis_el;

	int no_match_number;

	//for algo value
	int bins_No1;
	double hist_min1;
	double hist_max1;
	//for Mlb
	int bins_No2;
	double hist_min2;
	double hist_max2;

	void SetAlgoBin( const int& n, const double& m, const double& M ){
		bins_No1 = n;	
		hist_min1 = m;	
		hist_max1 = M;
	}
	void Init();
	void WriteIn();
};

class Hists_cor
{
public:

	Hists_cor()
	{
		bins_No1 = 100;	
		hist_min1 = 0.;	
		hist_max1 = 1.;
	}

	~Hists_cor(){}

	//for store	mva
	map<string, TH1F*> h_max_mva, h_max_mva_cor, h_max_mva_incor;
	
	TH1F* h_max_mva_mu;
	TH1F* h_max_mva_cor_mu;
	TH1F* h_max_mva_incor_mu;
		
	TH1F* h_max_mva_el;
	TH1F* h_max_mva_cor_el;
	TH1F* h_max_mva_incor_el;

	TH1F* h_max_mva_t;
	TH1F* h_max_mva_cor_t;
	TH1F* h_max_mva_incor_t;

	int bins_No1;
	double hist_min1;
	double hist_max1;
	
	//for store to calculate Poisson error
	//chosen -> 'all': pass full-sel / 'part': pass full-sel and pass gen-matching		
	//cor -> pass 'all'/'pass' and it's correct permutation(combination)
	
	map<string, TH1F*> h_chosen, h_cor;
	
	TH1F* h_chosen_mu;
	TH1F* h_cor_mu;
		
	TH1F* h_chosen_el;
	TH1F* h_cor_el;
	
	TH1F* h_chosen_t;
	TH1F* h_cor_t;
	
	void SetAlgoBin( const int& n, const double& m, const double& M ){
		bins_No1 = n;	
		hist_min1 = m;	
		hist_max1 = M;
	}
	void Init();
	void WriteIn();

};

void
Hists_Acp::Init( const string& option = "all" )
{
	if( option.find( "div" ) != string::npos )
	{
		h_Obs3_mu_P = new TH1D( "h_Obs3_mu_P", "", 2, 0.5, 2.5 ); 
		h_Obs3_mu_N = new TH1D( "h_Obs3_mu_N", "", 2, 0.5, 2.5 );
		h_Obs6_mu_P = new TH1D( "h_Obs6_mu_P", "", 2, 0.5, 2.5 ); 
		h_Obs6_mu_N = new TH1D( "h_Obs6_mu_N", "", 2, 0.5, 2.5 );
		h_Obs12_mu_P = new TH1D( "h_Obs12_mu_P", "", 2, 0.5, 2.5 ); 
		h_Obs12_mu_N = new TH1D( "h_Obs12_mu_N", "", 2, 0.5, 2.5 );
		h_Obs13_mu_P = new TH1D( "h_Obs13_mu_P", "", 2, 0.5, 2.5 ); 
		h_Obs13_mu_N = new TH1D( "h_Obs13_mu_N", "", 2, 0.5, 2.5 );

		h_Obs3_el_P = new TH1D( "h_Obs3_el_P", "", 2, 0.5, 2.5 ); 
		h_Obs3_el_N = new TH1D( "h_Obs3_el_N", "", 2, 0.5, 2.5 );
		h_Obs6_el_P = new TH1D( "h_Obs6_el_P", "", 2, 0.5, 2.5 ); 
		h_Obs6_el_N = new TH1D( "h_Obs6_el_N", "", 2, 0.5, 2.5 );
		h_Obs12_el_P = new TH1D( "h_Obs12_el_P", "", 2, 0.5, 2.5 ); 
		h_Obs12_el_N = new TH1D( "h_Obs12_el_N", "", 2, 0.5, 2.5 );
		h_Obs13_el_P = new TH1D( "h_Obs13_el_P", "", 2, 0.5, 2.5 ); 
		h_Obs13_el_N = new TH1D( "h_Obs13_el_N", "", 2, 0.5, 2.5 );
	}
	if( option.find( "all" ) != string::npos )
	{
		h_Obs_mu_P = new TH1D( "h_Obs_mu_P", "", 5, 0, 5 ); 
		h_Obs_mu_N = new TH1D( "h_Obs_mu_N", "", 5, 0, 5 );
		h_Obs_el_P = new TH1D( "h_Obs_el_P", "", 5, 0, 5 ); 
		h_Obs_el_N = new TH1D( "h_Obs_el_N", "", 5, 0, 5 );
		h_Obs_t_P = new TH1D( "h_Obs_t_P", "", 5, 0, 5 ); 
		h_Obs_t_N = new TH1D( "h_Obs_t_N", "", 5, 0, 5 );
	}

	InitMap();
}

void 
Hists_Acp::InitMap()
{
	h_Obs3_P[ "mu" ] = h_Obs3_mu_P;			h_Obs3_N[ "mu" ] = h_Obs3_mu_N;
	h_Obs6_P[ "mu" ] = h_Obs6_mu_P;			h_Obs6_N[ "mu" ] = h_Obs6_mu_N;
	h_Obs12_P[ "mu" ] = h_Obs12_mu_P;		h_Obs12_N[ "mu" ] = h_Obs12_mu_N;
	h_Obs13_P[ "mu" ] = h_Obs13_mu_P;		h_Obs13_N[ "mu" ] = h_Obs13_mu_N;
	
	h_Obs3_P[ "el" ] = h_Obs3_el_P;			h_Obs3_N[ "el" ] = h_Obs3_el_N;
	h_Obs6_P[ "el" ] = h_Obs6_el_P;			h_Obs6_N[ "el" ] = h_Obs6_el_N;
	h_Obs12_P[ "el" ] = h_Obs12_el_P;		h_Obs12_N[ "el" ] = h_Obs12_el_N;
	h_Obs13_P[ "el" ] = h_Obs13_el_P;		h_Obs13_N[ "el" ] = h_Obs13_el_N;

	h_Obs_P[ "mu" ] = h_Obs_mu_P;			h_Obs_N[ "mu" ] = h_Obs_mu_N;
	h_Obs_P[ "el" ] = h_Obs_el_P;			h_Obs_N[ "el" ] = h_Obs_el_N;
}

void Hists_Acp::
FillIn( const string& option, const string& ch , const double& obs, const double& weight )
{

	if( obs == DBL_MAX ) return;
	int cp = 1;
	if( obs > 0 ) 
		cp = 1;
	else if( obs == 0. )
	{
		cout << "There is something wrong!" << endl; 
		return;
	}
	else	
		cp = -1;

	if( option == "Obs3" )
	{
		if( cp == 1 )
		{
			h_Obs_t_P->Fill( 1., weight );
			h_Obs_P[ ch ]->Fill( 1., weight );
		}
		else
		{
			h_Obs_t_N->Fill( 1., weight );
			h_Obs_N[ ch ]->Fill( 1., weight );
		}
	}
	else if( option == "Obs6" )
	{
		if( cp == 1 )
		{
			h_Obs_t_P->Fill( 2., weight );
			h_Obs_P[ ch ]->Fill( 2., weight );
		}
		else
		{
			h_Obs_t_N->Fill( 2., weight );
			h_Obs_N[ ch ]->Fill( 2., weight );
		}
	}
	else if( option == "Obs12" )
	{
		if( cp == 1 )
		{
			h_Obs_t_P->Fill( 3., weight );
			h_Obs_P[ ch ]->Fill( 3., weight );
		}
		else
		{
			h_Obs_t_N->Fill( 3., weight );
			h_Obs_N[ ch ]->Fill( 3., weight );
		}
	}
	else if( option == "Obs13" )
	{
		if( cp == 1 )
		{
			h_Obs_t_P->Fill( 4., weight );
			h_Obs_P[ ch ]->Fill( 4., weight );
		}
		else
		{
			h_Obs_t_N->Fill( 4., weight );
			h_Obs_N[ ch ]->Fill( 4., weight );
		}
	}
}


void
Hists_Acp::WriteIn()
{
/*
	h_Obs3_mu_P->Write(); 
	h_Obs3_mu_N->Write();
	h_Obs6_mu_P->Write(); 
	h_Obs6_mu_N->Write();
	h_Obs12_mu_P->Write(); 
	h_Obs12_mu_N->Write();
	h_Obs13_mu_P->Write(); 
	h_Obs13_mu_N->Write();
	
	h_Obs3_el_P->Write(); 
	h_Obs3_el_N->Write();
	h_Obs6_el_P->Write(); 
	h_Obs6_el_N->Write();
	h_Obs12_el_P->Write(); 
	h_Obs12_el_N->Write();
	h_Obs13_el_P->Write(); 
	h_Obs13_el_N->Write();
*/
	h_Obs_mu_P->Write();
	h_Obs_mu_N->Write();
	h_Obs_el_P->Write();
	h_Obs_el_N->Write();
	h_Obs_t_P->Write();
	h_Obs_t_N->Write();

}

void Hists::GetObjs( const string& file_name, const string& option )
{
	TFile* f = new TFile( (char*)file_name.c_str() );
	

	if( option.find("NC") != string::npos )
	{
		h_TT_mu = new TH1F();		h_TT_el = new TH1F();
		h_DY_mu = new TH1F();		h_DY_el = new TH1F();
		h_WJets_mu = new TH1F();	h_WJets_el = new TH1F();
		h_VV_mu = new TH1F();		h_VV_el = new TH1F();
		h_ST_mu = new TH1F();		h_ST_el = new TH1F();
		h_QCD_mu = new TH1F();		h_QCD_el = new TH1F();
		h_Data_mu = new TH1F();		h_Data_el = new TH1F();
		h_l_TT_mu = new TH1F();		h_l_TT_el = new TH1F();
		h_l_DY_mu = new TH1F();		h_l_DY_el = new TH1F();
		h_l_WJets_mu = new TH1F();	h_l_WJets_el = new TH1F();
		h_l_VV_mu = new TH1F();		h_l_VV_el = new TH1F();
		h_l_ST_mu = new TH1F();		h_l_ST_el = new TH1F();
		h_l_QCD_mu = new TH1F();	h_l_QCD_el = new TH1F();
		h_l_Data_mu = new TH1F();	h_l_Data_el = new TH1F();

		f->GetObject("h_TT_mu",h_TT_mu);
		f->GetObject("h_DY_mu",h_DY_mu);
		f->GetObject("h_WJets_mu",h_WJets_mu);
		f->GetObject("h_VV_mu",h_VV_mu);
		f->GetObject("h_ST_mu",h_ST_mu);
		f->GetObject("h_QCD_mu",h_QCD_mu);
		f->GetObject("h_Data_mu",h_Data_mu);

		f->GetObject("h_TT_el",h_TT_el);
		f->GetObject("h_DY_el",h_DY_el);
		f->GetObject("h_WJets_el",h_WJets_el);
		f->GetObject("h_VV_el",h_VV_el);
		f->GetObject("h_ST_el",h_ST_el);
		f->GetObject("h_QCD_el",h_QCD_el);
		f->GetObject("h_Data_el",h_Data_el);

		f->GetObject("h_l_TT_mu",h_l_TT_mu);
		f->GetObject("h_l_DY_mu",h_l_DY_mu);
		f->GetObject("h_l_WJets_mu",h_l_WJets_mu);
		f->GetObject("h_l_VV_mu",h_l_VV_mu);
		f->GetObject("h_l_ST_mu",h_l_ST_mu);
		f->GetObject("h_l_QCD_mu",h_l_QCD_mu);
		f->GetObject("h_l_Data_mu",h_l_Data_mu);

		f->GetObject("h_l_TT_el",h_l_TT_el);
		f->GetObject("h_l_DY_el",h_l_DY_el);
		f->GetObject("h_l_WJets_el",h_l_WJets_el);
		f->GetObject("h_l_VV_el",h_l_VV_el);
		f->GetObject("h_l_ST_el",h_l_ST_el);
		f->GetObject("h_l_QCD_el",h_l_QCD_el);
		f->GetObject("h_l_Data_el",h_l_Data_el);

		InitNoCutVector();
	
	}
	
	if( option.find("1C") != string::npos )
	{
		
		h_TT_mu_c = new TH1F();		h_TT_el_c = new TH1F();
		h_DY_mu_c = new TH1F();		h_DY_el_c = new TH1F();
		h_WJets_mu_c = new TH1F();	h_WJets_el_c = new TH1F();
		h_VV_mu_c = new TH1F();		h_VV_el_c = new TH1F();
		h_ST_mu_c = new TH1F();		h_ST_el_c = new TH1F();
		h_QCD_mu_c = new TH1F();		h_QCD_el_c = new TH1F();
		h_Data_mu_c = new TH1F();		h_Data_el_c = new TH1F();
		h_l_TT_mu_c = new TH1F();		h_l_TT_el_c = new TH1F();
		h_l_DY_mu_c = new TH1F();		h_l_DY_el_c = new TH1F();
		h_l_WJets_mu_c = new TH1F();	h_l_WJets_el_c = new TH1F();
		h_l_VV_mu_c = new TH1F();		h_l_VV_el_c = new TH1F();
		h_l_ST_mu_c = new TH1F();		h_l_ST_el_c = new TH1F();
		h_l_QCD_mu_c = new TH1F();	h_l_QCD_el_c = new TH1F();
		h_l_Data_mu_c = new TH1F();	h_l_Data_el_c = new TH1F();

		f->GetObject("h_TT_mu_c",h_TT_mu_c);
		f->GetObject("h_DY_mu_c",h_DY_mu_c);
		f->GetObject("h_WJets_mu_c",h_WJets_mu_c);
		f->GetObject("h_VV_mu_c",h_VV_mu_c);
		f->GetObject("h_ST_mu_c",h_ST_mu_c);
		f->GetObject("h_QCD_mu_c",h_QCD_mu_c);
		f->GetObject("h_Data_mu_c",h_Data_mu_c);

		f->GetObject("h_TT_el_c",h_TT_el_c);
		f->GetObject("h_DY_el_c",h_DY_el_c);
		f->GetObject("h_WJets_el_c",h_WJets_el_c);
		f->GetObject("h_VV_el_c",h_VV_el_c);
		f->GetObject("h_ST_el_c",h_ST_el_c);
		f->GetObject("h_QCD_el_c",h_QCD_el_c);
		f->GetObject("h_Data_el_c",h_Data_el_c);

		f->GetObject("h_l_TT_mu_c",h_l_TT_mu_c);
		f->GetObject("h_l_DY_mu_c",h_l_DY_mu_c);
		f->GetObject("h_l_WJets_mu_c",h_l_WJets_mu_c);
		f->GetObject("h_l_VV_mu_c",h_l_VV_mu_c);
		f->GetObject("h_l_ST_mu_c",h_l_ST_mu_c);
		f->GetObject("h_l_QCD_mu_c",h_l_QCD_mu_c);
		f->GetObject("h_l_Data_mu_c",h_l_Data_mu_c);

		f->GetObject("h_l_TT_el_c",h_l_TT_el_c);
		f->GetObject("h_l_DY_el_c",h_l_DY_el_c);
		f->GetObject("h_l_WJets_el_c",h_l_WJets_el_c);
		f->GetObject("h_l_VV_el_c",h_l_VV_el_c);
		f->GetObject("h_l_ST_el_c",h_l_ST_el_c);
		f->GetObject("h_l_QCD_el_c",h_l_QCD_el_c);
		f->GetObject("h_l_Data_el_c",h_l_Data_el_c);
		
		InitOneCutVector();
	}
	
	if( option.find("2C") != string::npos )
	{
		h_TT_mu_cc = new TH1F();		h_TT_el_cc = new TH1F();
		h_DY_mu_cc = new TH1F();		h_DY_el_cc = new TH1F();
		h_WJets_mu_cc = new TH1F();	h_WJets_el_cc = new TH1F();
		h_VV_mu_cc = new TH1F();		h_VV_el_cc = new TH1F();
		h_ST_mu_cc = new TH1F();		h_ST_el_cc = new TH1F();
		h_QCD_mu_cc = new TH1F();		h_QCD_el_cc = new TH1F();
		h_Data_mu_cc = new TH1F();		h_Data_el_cc = new TH1F();
		h_l_TT_mu_cc = new TH1F();		h_l_TT_el_cc = new TH1F();
		h_l_DY_mu_cc = new TH1F();		h_l_DY_el_cc = new TH1F();
		h_l_WJets_mu_cc = new TH1F();	h_l_WJets_el_cc = new TH1F();
		h_l_VV_mu_cc = new TH1F();		h_l_VV_el_cc = new TH1F();
		h_l_ST_mu_cc = new TH1F();		h_l_ST_el_cc = new TH1F();
		h_l_QCD_mu_cc = new TH1F();	h_l_QCD_el_cc = new TH1F();
		h_l_Data_mu_cc = new TH1F();	h_l_Data_el_cc = new TH1F();

		f->GetObject("h_TT_mu_cc",h_TT_mu_cc);
		f->GetObject("h_DY_mu_cc",h_DY_mu_cc);
		f->GetObject("h_WJets_mu_cc",h_WJets_mu_cc);
		f->GetObject("h_VV_mu_cc",h_VV_mu_cc);
		f->GetObject("h_ST_mu_cc",h_ST_mu_cc);
		f->GetObject("h_QCD_mu_cc",h_QCD_mu_cc);
		f->GetObject("h_Data_mu_cc",h_Data_mu_cc);

		f->GetObject("h_TT_el_cc",h_TT_el_cc);
		f->GetObject("h_DY_el_cc",h_DY_el_cc);
		f->GetObject("h_WJets_el_cc",h_WJets_el_cc);
		f->GetObject("h_VV_el_cc",h_VV_el_cc);
		f->GetObject("h_ST_el_cc",h_ST_el_cc);
		f->GetObject("h_QCD_el_cc",h_QCD_el_cc);
		f->GetObject("h_Data_el_cc",h_Data_el_cc);

		f->GetObject("h_l_TT_mu_cc",h_l_TT_mu_cc);
		f->GetObject("h_l_DY_mu_cc",h_l_DY_mu_cc);
		f->GetObject("h_l_WJets_mu_cc",h_l_WJets_mu_cc);
		f->GetObject("h_l_VV_mu_cc",h_l_VV_mu_cc);
		f->GetObject("h_l_ST_mu_cc",h_l_ST_mu_cc);
		f->GetObject("h_l_QCD_mu_cc",h_l_QCD_mu_cc);
		f->GetObject("h_l_Data_mu_cc",h_l_Data_mu_cc);

		f->GetObject("h_l_TT_el_cc",h_l_TT_el_cc);
		f->GetObject("h_l_DY_el_cc",h_l_DY_el_cc);
		f->GetObject("h_l_WJets_el_cc",h_l_WJets_el_cc);
		f->GetObject("h_l_VV_el_cc",h_l_VV_el_cc);
		f->GetObject("h_l_ST_el_cc",h_l_ST_el_cc);
		f->GetObject("h_l_QCD_el_cc",h_l_QCD_el_cc);
		f->GetObject("h_l_Data_el_cc",h_l_Data_el_cc);

		InitTwoCutVector();
	}
	if( (option.find("NC") == string::npos) && (option.find("1C") == string::npos) && (option.find("2C") == string::npos) )
	{
		cerr << "Illegal option of Hists::GetObjs(\"file_name\",\"option\") ," << endl \
			 << "option should include NC/1C/2C " << endl;
	}
}

void Hists::InitNoCutVector()
{
	h_mu.push_back(h_TT_mu);		h_mu.push_back(h_DY_mu);
	h_mu.push_back(h_WJets_mu);		h_mu.push_back(h_VV_mu);
	h_mu.push_back(h_ST_mu);		h_mu.push_back(h_QCD_mu);
	h_mu.push_back(h_Data_mu);

	h_el.push_back(h_TT_el);		h_el.push_back(h_DY_el);
	h_el.push_back(h_WJets_el);		h_el.push_back(h_VV_el);
	h_el.push_back(h_ST_el);		h_el.push_back(h_QCD_el);
	h_el.push_back(h_Data_el);
	
	h_l_mu.push_back(h_l_TT_mu);		h_l_mu.push_back(h_l_DY_mu);
	h_l_mu.push_back(h_l_WJets_mu);		h_l_mu.push_back(h_l_VV_mu);
	h_l_mu.push_back(h_l_ST_mu);		h_l_mu.push_back(h_l_QCD_mu);
	h_l_mu.push_back(h_l_Data_mu);
	
	h_l_el.push_back(h_l_TT_el);		h_l_el.push_back(h_l_DY_el);
	h_l_el.push_back(h_l_WJets_el);		h_l_el.push_back(h_l_VV_el);
	h_l_el.push_back(h_l_ST_el);		h_l_el.push_back(h_l_QCD_el);
	h_l_el.push_back(h_l_Data_el);
}

void Hists::InitOneCutVector()
{
	h_mu_c.push_back(h_TT_mu_c);		h_mu_c.push_back(h_DY_mu_c);
	h_mu_c.push_back(h_WJets_mu_c);		h_mu_c.push_back(h_VV_mu_c);
	h_mu_c.push_back(h_ST_mu_c);		h_mu_c.push_back(h_QCD_mu_c);
	h_mu_c.push_back(h_Data_mu_c);

	h_el_c.push_back(h_TT_el_c);		h_el_c.push_back(h_DY_el_c);
	h_el_c.push_back(h_WJets_el_c);		h_el_c.push_back(h_VV_el_c);
	h_el_c.push_back(h_ST_el_c);		h_el_c.push_back(h_QCD_el_c);
	h_el_c.push_back(h_Data_el_c);
	
	h_l_mu_c.push_back(h_l_TT_mu_c);		h_l_mu_c.push_back(h_l_DY_mu_c);
	h_l_mu_c.push_back(h_l_WJets_mu_c);		h_l_mu_c.push_back(h_l_VV_mu_c);
	h_l_mu_c.push_back(h_l_ST_mu_c);		h_l_mu_c.push_back(h_l_QCD_mu_c);
	h_l_mu_c.push_back(h_l_Data_mu_c);
	
	h_l_el_c.push_back(h_l_TT_el_c);		h_l_el_c.push_back(h_l_DY_el_c);
	h_l_el_c.push_back(h_l_WJets_el_c);		h_l_el_c.push_back(h_l_VV_el_c);
	h_l_el_c.push_back(h_l_ST_el_c);		h_l_el_c.push_back(h_l_QCD_el_c);
	h_l_el_c.push_back(h_l_Data_el_c);
}


void Hists::InitTwoCutVector()
{
	h_mu_cc.push_back(h_TT_mu_cc);		h_mu_cc.push_back(h_DY_mu_cc);
	h_mu_cc.push_back(h_WJets_mu_cc);		h_mu_cc.push_back(h_VV_mu_cc);
	h_mu_cc.push_back(h_ST_mu_cc);		h_mu_cc.push_back(h_QCD_mu_cc);
	h_mu_cc.push_back(h_Data_mu_cc);

	h_el_cc.push_back(h_TT_el_cc);		h_el_cc.push_back(h_DY_el_cc);
	h_el_cc.push_back(h_WJets_el_cc);		h_el_cc.push_back(h_VV_el_cc);
	h_el_cc.push_back(h_ST_el_cc);		h_el_cc.push_back(h_QCD_el_cc);
	h_el_cc.push_back(h_Data_el_cc);
	
	h_l_mu_cc.push_back(h_l_TT_mu_cc);		h_l_mu_cc.push_back(h_l_DY_mu_cc);
	h_l_mu_cc.push_back(h_l_WJets_mu_cc);		h_l_mu_cc.push_back(h_l_VV_mu_cc);
	h_l_mu_cc.push_back(h_l_ST_mu_cc);		h_l_mu_cc.push_back(h_l_QCD_mu_cc);
	h_l_mu_cc.push_back(h_l_Data_mu_cc);
	
	h_l_el_cc.push_back(h_l_TT_el_cc);		h_l_el_cc.push_back(h_l_DY_el_cc);
	h_l_el_cc.push_back(h_l_WJets_el_cc);		h_l_el_cc.push_back(h_l_VV_el_cc);
	h_l_el_cc.push_back(h_l_ST_el_cc);		h_l_el_cc.push_back(h_l_QCD_el_cc);
	h_l_el_cc.push_back(h_l_Data_el_cc);
}

void Hists::TH2ModeON( const int& algo_bins_No, const double& m, const double& M )
{
	double algo_v_min = m;
	double algo_v_max = M;
	h_mvamax_hadmass_mu = new TH2D("h_mvamax_hadmass_mu","",bins_No,hist_min,hist_max,algo_bins_No,algo_v_min,algo_v_max);
	h_mvamax_hadmass_el = new TH2D("h_mvamax_hadmass_el","",bins_No,hist_min,hist_max,algo_bins_No,algo_v_min,algo_v_max);
	h_mvamax_hadmass[ "mu" ] = h_mvamax_hadmass_mu;			
	h_mvamax_hadmass[ "el" ] = h_mvamax_hadmass_el;
	
	h_mvamax_lepmass_mu = new TH2D("h_mvamax_lepmass_mu","",bins_No,hist_min,hist_max,algo_bins_No,algo_v_min,algo_v_max);
	h_mvamax_lepmass_el = new TH2D("h_mvamax_lepmass_el","",bins_No,hist_min,hist_max,algo_bins_No,algo_v_min,algo_v_max);
	h_mvamax_lepmass[ "mu" ] = h_mvamax_lepmass_mu;			
	h_mvamax_lepmass[ "el" ] = h_mvamax_lepmass_el;
}
void Hists::NoCutModeON()
{
	h_TT_mu = new TH1F("h_TT_mu","",bins_No,hist_min,hist_max);
	h_TT_el = new TH1F("h_TT_el","",bins_No,hist_min,hist_max);
	
	h_DY_mu = new TH1F("h_DY_mu","",bins_No,hist_min,hist_max);
	h_DY_el = new TH1F("h_DY_el","",bins_No,hist_min,hist_max);

	h_WJets_mu = new TH1F("h_WJets_mu","",bins_No,hist_min,hist_max);
	h_WJets_el = new TH1F("h_WJets_el","",bins_No,hist_min,hist_max);
	
	h_VV_mu = new TH1F("h_VV_mu","",bins_No,hist_min,hist_max);
	h_VV_el = new TH1F("h_VV_el","",bins_No,hist_min,hist_max);

	h_ST_mu = new TH1F("h_ST_mu","",bins_No,hist_min,hist_max);
	h_ST_el = new TH1F("h_ST_el","",bins_No,hist_min,hist_max);
	
	h_QCD_mu = new TH1F("h_QCD_mu","",bins_No,hist_min,hist_max);
	h_QCD_el = new TH1F("h_QCD_el","",bins_No,hist_min,hist_max);
	
	h_Data_mu = new TH1F("h_Data_mu"," ;Hadronic Top Mass(GeV);Events(No.)",bins_No,hist_min,hist_max);	
	h_Data_el = new TH1F("h_Data_el"," ;Hadronic Top Mass(GeV);Events(No.)",bins_No,hist_min,hist_max);

	h_l_TT_mu = new TH1F("h_l_TT_mu","",bins_No,hist_min,hist_max);
	h_l_TT_el = new TH1F("h_l_TT_el","",bins_No,hist_min,hist_max);
	
	h_l_DY_mu = new TH1F("h_l_DY_mu","",bins_No,hist_min,hist_max);
	h_l_DY_el = new TH1F("h_l_DY_el","",bins_No,hist_min,hist_max);

	h_l_WJets_mu = new TH1F("h_l_WJets_mu","",bins_No,hist_min,hist_max);
	h_l_WJets_el = new TH1F("h_l_WJets_el","",bins_No,hist_min,hist_max);
	
	h_l_VV_mu = new TH1F("h_l_VV_mu","",bins_No,hist_min,hist_max);
	h_l_VV_el = new TH1F("h_l_VV_el","",bins_No,hist_min,hist_max);

	h_l_ST_mu = new TH1F("h_l_ST_mu","",bins_No,hist_min,hist_max);
	h_l_ST_el = new TH1F("h_l_ST_el","",bins_No,hist_min,hist_max);
	
	h_l_QCD_mu = new TH1F("h_l_QCD_mu","",bins_No,hist_min,hist_max);
	h_l_QCD_el = new TH1F("h_l_QCD_el","",bins_No,hist_min,hist_max);
	
	h_l_Data_mu = new TH1F("h_l_Data_mu"," ;Leptonic Top Mass(GeV);Events(No.)",bins_No,hist_min,hist_max);
	h_l_Data_el = new TH1F("h_l_Data_el"," ;Leptonic Top Mass(GeV);Events(No.)",bins_No,hist_min,hist_max);

	InitNoCutVector();
}

void Hists::OneCutModeON()
{
	h_TT_mu_c = new TH1F("h_TT_mu_c","",bins_No,hist_min,hist_max);
	h_TT_el_c = new TH1F("h_TT_el_c","",bins_No,hist_min,hist_max);
	
	h_DY_mu_c = new TH1F("h_DY_mu_c","",bins_No,hist_min,hist_max);
	h_DY_el_c = new TH1F("h_DY_el_c","",bins_No,hist_min,hist_max);

	h_WJets_mu_c = new TH1F("h_WJets_mu_c","",bins_No,hist_min,hist_max);
	h_WJets_el_c = new TH1F("h_WJets_el_c","",bins_No,hist_min,hist_max);
	
	h_VV_mu_c = new TH1F("h_VV_mu_c","",bins_No,hist_min,hist_max);
	h_VV_el_c = new TH1F("h_VV_el_c","",bins_No,hist_min,hist_max);

	h_ST_mu_c = new TH1F("h_ST_mu_c","",bins_No,hist_min,hist_max);
	h_ST_el_c = new TH1F("h_ST_el_c","",bins_No,hist_min,hist_max);
	
	h_QCD_mu_c = new TH1F("h_QCD_mu_c","",bins_No,hist_min,hist_max);
	h_QCD_el_c = new TH1F("h_QCD_el_c","",bins_No,hist_min,hist_max);
	
	h_Data_mu_c = new TH1F("h_Data_mu_c"," ;Hadronic Top Mass(GeV);Events(No.)",bins_No,hist_min,hist_max);	
	h_Data_el_c = new TH1F("h_Data_el_c"," ;Hadronic Top Mass(GeV);Events(No.)",bins_No,hist_min,hist_max);

	h_l_TT_mu_c = new TH1F("h_l_TT_mu_c","",bins_No,hist_min,hist_max);
	h_l_TT_el_c = new TH1F("h_l_TT_el_c","",bins_No,hist_min,hist_max);
	
	h_l_DY_mu_c = new TH1F("h_l_DY_mu_c","",bins_No,hist_min,hist_max);
	h_l_DY_el_c = new TH1F("h_l_DY_el_c","",bins_No,hist_min,hist_max);

	h_l_WJets_mu_c = new TH1F("h_l_WJets_mu_c","",bins_No,hist_min,hist_max);
	h_l_WJets_el_c = new TH1F("h_l_WJets_el_c","",bins_No,hist_min,hist_max);
	
	h_l_VV_mu_c = new TH1F("h_l_VV_mu_c","",bins_No,hist_min,hist_max);
	h_l_VV_el_c = new TH1F("h_l_VV_el_c","",bins_No,hist_min,hist_max);

	h_l_ST_mu_c = new TH1F("h_l_ST_mu_c","",bins_No,hist_min,hist_max);
	h_l_ST_el_c = new TH1F("h_l_ST_el_c","",bins_No,hist_min,hist_max);
	
	h_l_QCD_mu_c = new TH1F("h_l_QCD_mu_c","",bins_No,hist_min,hist_max);
	h_l_QCD_el_c = new TH1F("h_l_QCD_el_c","",bins_No,hist_min,hist_max);
	
	h_l_Data_mu_c = new TH1F("h_l_Data_mu_c"," ;Leptonic Top Mass(GeV);Events(No.)",bins_No,hist_min,hist_max);
	h_l_Data_el_c = new TH1F("h_l_Data_el_c"," ;Leptonic Top Mass(GeV);Events(No.)",bins_No,hist_min,hist_max);
	
	InitOneCutVector();
}

void Hists::TwoCutModeON()
{
	h_TT_mu_cc = new TH1F("h_TT_mu_cc","",bins_No,hist_min,hist_max);
	h_TT_el_cc = new TH1F("h_TT_el_cc","",bins_No,hist_min,hist_max);
	
	h_DY_mu_cc = new TH1F("h_DY_mu_cc","",bins_No,hist_min,hist_max);
	h_DY_el_cc = new TH1F("h_DY_el_cc","",bins_No,hist_min,hist_max);

	h_WJets_mu_cc = new TH1F("h_WJets_mu_cc","",bins_No,hist_min,hist_max);
	h_WJets_el_cc = new TH1F("h_WJets_el_cc","",bins_No,hist_min,hist_max);
	
	h_VV_mu_cc = new TH1F("h_VV_mu_cc","",bins_No,hist_min,hist_max);
	h_VV_el_cc = new TH1F("h_VV_el_cc","",bins_No,hist_min,hist_max);

	h_ST_mu_cc = new TH1F("h_ST_mu_cc","",bins_No,hist_min,hist_max);
	h_ST_el_cc = new TH1F("h_ST_el_cc","",bins_No,hist_min,hist_max);
	
	h_QCD_mu_cc = new TH1F("h_QCD_mu_cc","",bins_No,hist_min,hist_max);
	h_QCD_el_cc = new TH1F("h_QCD_el_cc","",bins_No,hist_min,hist_max);
	
	h_Data_mu_cc = new TH1F("h_Data_mu_cc"," ;Hadronic Top Mass(GeV);Events(No.)",bins_No,hist_min,hist_max);	
	h_Data_el_cc = new TH1F("h_Data_el_cc"," ;Hadronic Top Mass(GeV);Events(No.)",bins_No,hist_min,hist_max);

	h_l_TT_mu_cc = new TH1F("h_l_TT_mu_cc","",bins_No,hist_min,hist_max);
	h_l_TT_el_cc = new TH1F("h_l_TT_el_cc","",bins_No,hist_min,hist_max);
	
	h_l_DY_mu_cc = new TH1F("h_l_DY_mu_cc","",bins_No,hist_min,hist_max);
	h_l_DY_el_cc = new TH1F("h_l_DY_el_cc","",bins_No,hist_min,hist_max);

	h_l_WJets_mu_cc = new TH1F("h_l_WJets_mu_cc","",bins_No,hist_min,hist_max);
	h_l_WJets_el_cc = new TH1F("h_l_WJets_el_cc","",bins_No,hist_min,hist_max);
	
	h_l_VV_mu_cc = new TH1F("h_l_VV_mu_cc","",bins_No,hist_min,hist_max);
	h_l_VV_el_cc = new TH1F("h_l_VV_el_cc","",bins_No,hist_min,hist_max);

	h_l_ST_mu_cc = new TH1F("h_l_ST_mu_cc","",bins_No,hist_min,hist_max);
	h_l_ST_el_cc = new TH1F("h_l_ST_el_cc","",bins_No,hist_min,hist_max);
	
	h_l_QCD_mu_cc = new TH1F("h_l_QCD_mu_cc","",bins_No,hist_min,hist_max);
	h_l_QCD_el_cc = new TH1F("h_l_QCD_el_cc","",bins_No,hist_min,hist_max);
	
	h_l_Data_mu_cc = new TH1F("h_l_Data_mu_cc"," ;Leptonic Top Mass(GeV);Events(No.)",bins_No,hist_min,hist_max);
	h_l_Data_el_cc = new TH1F("h_l_Data_el_cc"," ;Leptonic Top Mass(GeV);Events(No.)",bins_No,hist_min,hist_max);

	InitTwoCutVector();
}

void Hists::WriteIn( const string& option = "NC" )
{
	if( option.find("NT") != string::npos )
	{
		mvav_mass_mu->Write();
		mvav_mass_el->Write();
	}
	if( option.find("NC") != string::npos )
	{
		h_TT_mu->Write();		
		h_TT_el->Write();	
		h_DY_mu->Write();		
		h_DY_el->Write();
		h_WJets_mu->Write();	
		h_WJets_el->Write();
		h_VV_mu->Write();		
		h_VV_el->Write();
		h_ST_mu->Write();		
		h_ST_el->Write();
		h_QCD_mu->Write();		
		h_QCD_el->Write();
		h_Data_mu->Write();	
		h_Data_el->Write();

		h_l_TT_mu->Write();	
		h_l_TT_el->Write();
		h_l_DY_mu->Write();	
		h_l_DY_el->Write();
		h_l_WJets_mu->Write();	
		h_l_WJets_el->Write();
		h_l_VV_mu->Write();	
		h_l_VV_el->Write();
		h_l_ST_mu->Write();	
		h_l_ST_el->Write();
		h_l_QCD_mu->Write();	
		h_l_QCD_el->Write();
		h_l_Data_mu->Write();	
		h_l_Data_el->Write();
	}	
	
	if( option.find("1C") != string::npos )
	{
		h_TT_mu_c->Write();		
		h_TT_el_c->Write();	
		h_DY_mu_c->Write();		
		h_DY_el_c->Write();
		h_WJets_mu_c->Write();	
		h_WJets_el_c->Write();
		h_VV_mu_c->Write();		
		h_VV_el_c->Write();
		h_ST_mu_c->Write();		
		h_ST_el_c->Write();
		h_QCD_mu_c->Write();		
		h_QCD_el_c->Write();
		h_Data_mu_c->Write();	
		h_Data_el_c->Write();

		h_l_TT_mu_c->Write();	
		h_l_TT_el_c->Write();
		h_l_DY_mu_c->Write();	
		h_l_DY_el_c->Write();
		h_l_WJets_mu_c->Write();	
		h_l_WJets_el_c->Write();
		h_l_VV_mu_c->Write();	
		h_l_VV_el_c->Write();
		h_l_ST_mu_c->Write();	
		h_l_ST_el_c->Write();
		h_l_QCD_mu_c->Write();	
		h_l_QCD_el_c->Write();
		h_l_Data_mu_c->Write();	
		h_l_Data_el_c->Write();
	}

	if( option.find("2C") != string::npos )
	{
		h_TT_mu_cc->Write();		
		h_TT_el_cc->Write();	
		h_DY_mu_cc->Write();		
		h_DY_el_cc->Write();
		h_WJets_mu_cc->Write();	
		h_WJets_el_cc->Write();
		h_VV_mu_cc->Write();		
		h_VV_el_cc->Write();
		h_ST_mu_cc->Write();		
		h_ST_el_cc->Write();
		h_QCD_mu_cc->Write();		
		h_QCD_el_cc->Write();
		h_Data_mu_cc->Write();	
		h_Data_el_cc->Write();

		h_l_TT_mu_cc->Write();	
		h_l_TT_el_cc->Write();
		h_l_DY_mu_cc->Write();	
		h_l_DY_el_cc->Write();
		h_l_WJets_mu_cc->Write();	
		h_l_WJets_el_cc->Write();
		h_l_VV_mu_cc->Write();	
		h_l_VV_el_cc->Write();
		h_l_ST_mu_cc->Write();	
		h_l_ST_el_cc->Write();
		h_l_QCD_mu_cc->Write();	
		h_l_QCD_el_cc->Write();
		h_l_Data_mu_cc->Write();	
		h_l_Data_el_cc->Write();
	}
	
	if( (option.find("NC") == string::npos) && (option.find("1C") == string::npos) && (option.find("2C") == string::npos) )
	{
		cerr << "Illegal option of Hists::WriteIn(\"file_name\",\"option\") ," << endl \
			 << "option should include NC/1C/2C " << endl;
	}

}

void
Hists::FillHist( const string& option, const int& k, const string& ch, const double& hadm, const double& lepm, const double& weight )
{
	if( option.find("NC") != string::npos )
	{
		if( ch == "mu" )
		{
			h_mu.at(k)->Fill(hadm, weight);
			h_l_mu.at(k)->Fill(lepm, weight);

		}
		else if( ch == "el" )
		{
			h_el.at(k)->Fill(hadm, weight);
			h_l_el.at(k)->Fill(lepm, weight);
		}
		else
			return;
	}
	else if( option.find("1C") != string::npos )
	{
		if( ch == "mu" )
		{
			h_mu_c.at(k)->Fill(hadm, weight);
			h_l_mu_c.at(k)->Fill(lepm, weight);

		}
		else if( ch == "el" )
		{
			h_el_c.at(k)->Fill(hadm, weight);
			h_l_el_c.at(k)->Fill(lepm, weight);
		}
		else
			return;
	}
	else if( option.find("2C") != string::npos )
	{
		if( ch == "mu" )
		{
			h_mu_cc.at(k)->Fill(hadm, weight);
			h_l_mu_cc.at(k)->Fill(lepm, weight);

		}
		else if( ch == "el" )
		{
			h_el_cc.at(k)->Fill(hadm, weight);
			h_l_el_cc.at(k)->Fill(lepm, weight);
		}
		else
			return;
	}
	else
	{
		cerr << "Illegal option of Hists::WriteIn(\"file_name\",\"option\") ," << endl \
			 << "option should include NC/1C/2C " << endl;
	}
}





void
Hists_bb::Init()
{
	//we want the binNo at had t mass is same as the mva values'
	h_mvamax_mass_mu = new TH2D("h_mvamax_mass_mu","",bins_No1,hist_min2,hist_max2,bins_No1,hist_min1,hist_max1);
	h_mvamax_mass_el = new TH2D("h_mvamax_mass_el","",bins_No1,hist_min2,hist_max2,bins_No1,hist_min1,hist_max1);
	h_mvamax_mass_t = new TH2D("h_mvamax_mass_t","",bins_No1,hist_min2,hist_max2,bins_No1,hist_min1,hist_max1);
	h_mvamax_mass[ "mu" ] = h_mvamax_mass_mu;			h_mvamax_mass[ "el" ] = h_mvamax_mass_el;
	
	h_correct_t = new TH1F("h_correct_t"," ;mva value;events",bins_No1,hist_min1,hist_max1);
	h_mistag_t = new TH1F("h_mistag_t"," ;mva value;events",bins_No1,hist_min1,hist_max1);
	h_charge_mis_t = new TH1F("h_charge_mis_t"," ;mva value;events",bins_No1,hist_min1,hist_max1); 

	h_correct_mu = new TH1F("h_correct_mu"," ;mva value;events",bins_No1,hist_min1,hist_max1);
	h_mistag_mu = new TH1F("h_mistag_mu"," ;mva value;events",bins_No1,hist_min1,hist_max1);
	h_charge_mis_mu = new TH1F("h_charge_mis_mu"," ;mva value;events",bins_No1,hist_min1,hist_max1); 
	h_correct_el = new TH1F("h_correct_el"," ;mva value;events",bins_No1,hist_min1,hist_max1);
	h_mistag_el = new TH1F("h_mistag_el"," ;mva value;events",bins_No1,hist_min1,hist_max1);
	h_charge_mis_el = new TH1F("h_charge_mis_el"," ;mva value;events",bins_No1,hist_min1,hist_max1);
	

	h_lt_correct_t = new TH1F("h_lt_correct_t"," ;mass;events",bins_No2,hist_min2,hist_max2);
	h_lt_mistag_t = new TH1F("h_lt_mistag_t"," ;mass;events",bins_No2,hist_min2,hist_max2);
	h_lt_charge_mis_t = new TH1F("h_lt_charge_mis_t"," ;mass;events",bins_No2,hist_min2,hist_max2); 
	
	h_lt_correct_mu = new TH1F("h_lt_correct_mu"," ;mass;events",bins_No2,hist_min2,hist_max2);
	h_lt_mistag_mu = new TH1F("h_lt_mistag_mu"," ;mass;events",bins_No2,hist_min2,hist_max2);
	h_lt_charge_mis_mu = new TH1F("h_lt_charge_mis_mu"," ;mass;events",bins_No2,hist_min2,hist_max2); 
	h_lt_correct_el = new TH1F("h_lt_correct_el"," ;mass;events",bins_No2,hist_min2,hist_max2);
	h_lt_mistag_el = new TH1F("h_lt_mistag_el"," ;mass;events",bins_No2,hist_min2,hist_max2);
	h_lt_charge_mis_el = new TH1F("h_lt_charge_mis_el"," ;mass;events",bins_No2,hist_min2,hist_max2);
	
	
	h_correct[ "mu" ] = h_correct_mu;			h_correct[ "el" ] = h_correct_el;
	h_charge_mis[ "mu" ] = h_charge_mis_mu;		h_charge_mis[ "el" ] = h_charge_mis_el;
	h_mistag[ "mu" ] = h_mistag_mu;				h_mistag[ "el" ] = h_mistag_el;
	h_lt_correct[ "mu" ] = h_lt_correct_mu;				h_lt_correct[ "el" ] = h_lt_correct_el;
	h_lt_charge_mis[ "mu" ] = h_lt_charge_mis_mu;		h_lt_charge_mis[ "el" ] = h_lt_charge_mis_el;
	h_lt_mistag[ "mu" ] = h_lt_mistag_mu;				h_lt_mistag[ "el" ] = h_lt_mistag_el;
}

void
Hists_bb::WriteIn()
{
	
	h_mvamax_mass_mu->Write();
	h_mvamax_mass_el->Write();
	h_mvamax_mass_t->Write();

	h_correct_t->Write();
	h_mistag_t->Write();
	h_charge_mis_t->Write();

	h_correct_mu->Write();
	h_mistag_mu->Write();
	h_charge_mis_mu->Write();

	h_correct_el->Write();
	h_mistag_el->Write();
	h_charge_mis_el->Write();

	h_lt_correct_t->Write();
	h_lt_mistag_t->Write();
	h_lt_charge_mis_t->Write();

	h_lt_correct_mu->Write();
	h_lt_mistag_mu->Write();
	h_lt_charge_mis_mu->Write();

	h_lt_correct_el->Write();
	h_lt_mistag_el->Write();
	h_lt_charge_mis_el->Write();
}


void Hists_cor::Init()
{
	h_max_mva_mu = new TH1F("h_max_mva_mu","",bins_No1,hist_min1,hist_max1);
	h_max_mva_cor_mu = new TH1F("h_max_mva_cor_mu","",bins_No1,hist_min1,hist_max1);
	h_max_mva_incor_mu = new TH1F("h_max_mva_incor_mu","",bins_No1,hist_min1,hist_max1);
	
	h_max_mva_el = new TH1F("h_max_mva_el","",bins_No1,hist_min1,hist_max1);
	h_max_mva_cor_el = new TH1F("h_max_mva_cor_el","",bins_No1,hist_min1,hist_max1);
	h_max_mva_incor_el = new TH1F("h_max_mva_incor_el","",bins_No1,hist_min1,hist_max1);
	
	h_max_mva_t = new TH1F("h_max_mva_t","",bins_No1,hist_min1,hist_max1);
	h_max_mva_cor_t = new TH1F( "h_max_mva_cor_t","",bins_No1,hist_min1,hist_max1);
	h_max_mva_incor_t = new TH1F( "h_max_mva_incor_t","",bins_No1,hist_min1,hist_max1);
	
	h_max_mva[ "mu" ] = h_max_mva_mu;					h_max_mva[ "el" ] = h_max_mva_el;
	h_max_mva_cor[ "mu" ] = h_max_mva_cor_mu;			h_max_mva_cor[ "el" ] = h_max_mva_cor_el;
	h_max_mva_incor[ "mu" ] = h_max_mva_incor_mu;		h_max_mva_incor[ "el" ] = h_max_mva_incor_el;
	

	h_chosen_mu = new TH1F( "h_chosen_mu","",2,0.,2. );
	h_cor_mu = new TH1F( "h_cor_mu","",2,0.,2. );

	h_chosen_el = new TH1F( "h_chosen_el","",2,0.,2. );
	h_cor_el = new TH1F( "h_cor_el","",2,0.,2. );
	
	h_chosen_t = new TH1F( "h_chosen","",2,0.,2. );
	h_cor_t = new TH1F( "h_cor","",2,0.,2. );

	h_chosen[ "mu" ] = h_chosen_mu;		h_chosen[ "el" ] = h_chosen_el;
	h_cor[ "mu" ] = h_cor_mu;			h_cor[ "el" ] = h_cor_el;
}


void Hists_cor::WriteIn()
{
	h_max_mva_mu->Write();
	h_max_mva_cor_mu->Write();
	h_max_mva_incor_mu->Write();
		
	h_max_mva_el->Write();
	h_max_mva_cor_el->Write();
	h_max_mva_incor_el->Write();

	h_max_mva_t->Write();
	h_max_mva_cor_t->Write();
	h_max_mva_incor_t->Write();
	
	h_chosen_mu->Write();
	h_cor_mu->Write();
		
	h_chosen_el->Write();
	h_cor_el->Write();
	
	h_chosen_t->Write();
	h_cor_t->Write();
}



#endif
